//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include <string>
#include "MgmtMCO.h"
#include "inet/common/ModuleAccess.h"
#include "inet/physicallayer/wireless/common/contract/packetlevel/IRadio.h"
#include "inet/common/Simsignals.h"
#include "TrafficPacket_m.h"

namespace inet {

Define_Module(MgmtMCO);

void MgmtMCO::initialize(int stage)
{
    if(stage == INITSTAGE_LOCAL) {
        inSchedulerGate = gate("inScheduler");
    } else if(stage == INITSTAGE_LINK_LAYER) {
        provider = findConnectedModule<MyScheduler>(inSchedulerGate);
        radio = check_and_cast<physicallayer::Ieee80211Radio*>(getModuleByPath("^.^.wlan.radio"));
        macDcaf = check_and_cast<ieee80211::Dcaf*>(getModuleByPath("^.^.wlan.mac.dcf.channelAccess"));

        //MCO module is subscribed to this signal which is emitted when a packet is pushed into one of the queues of the MCO
        getParentModule()->subscribe(packetPushEndedSignal, this);

        //Radio module is subscribed to this other signal which is emitted by himself when a transmission is finished
        radio->subscribe(transmissionEndedSignal, this);
    }
}

void MgmtMCO::handleMessage(cMessage *msg)
{
    if(msg->getArrivalGateId() == findGate("inWLAN")) {
        Packet *pkt = static_cast<Packet*>(msg);
        auto p = pkt->peekData<TrafficPacket>();
        send(msg, findGate("outApp", p->getAppIdentifier()));
    }
}

void MgmtMCO::receiveSignal(cComponent *source, simsignal_t signalID, cObject *obj, cObject *details) {
    //This variable is true if there are packets in the MCO queues and the Dcf don't have a frame to transmit(Dcf::hasFrameToTransmit)
    bool a = signalID == packetPushEndedSignal && !(!macDcaf->getPendingQueue()->isEmpty() || macDcaf->getInProgressFrames()->hasInProgressFrames());

    //This other variable is true if a transmission is finished and there are packets in one of the MCO queues
    bool b = signalID == transmissionEndedSignal && provider->canPullSomePacket(inSchedulerGate->getPathStartGate());

    if(a || b) {
        //In function of the queue that the packet is pulled, we have to change the channel of the radio
        radio->setChannelNumber(provider->schedulePacket());
        auto packet = provider->pullPacket(inSchedulerGate->getPathStartGate());
        take(packet);
        EV_INFO << "Collecting packet" << EV_FIELD(packet) << EV_ENDL;
        send(packet, gate("outWLAN"));
    }
}

} /* namespace inet */