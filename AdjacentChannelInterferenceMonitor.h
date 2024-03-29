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

#ifndef __INET4_4_ADJACENTCHANNELINTERFERENCEMONITOR_H_
#define __INET4_4_ADJACENTCHANNELINTERFERENCEMONITOR_H_

#include <omnetpp.h>
#include "inet/common/InitStages.h"
#include "inet/physicallayer/wireless/common/radio/packetlevel/Radio.h"

using namespace omnetpp;

namespace inet {

class AdjacentChannelInterferenceMonitor : public cSimpleModule, public cListener
{
  protected:
      virtual void initialize(int stage) override;
      virtual int numInitStages() const override {return NUM_INIT_STAGES;}
      virtual void receiveSignal(cComponent *source, simsignal_t signalID, cObject *obj, cObject *details) override;
      virtual double getInterferencePower(const physicallayer::IRadio* radio, const physicallayer::ITransmission* transmission, const physicallayer::IRadioMedium* medium, double loss);
      virtual void createSignals();
      virtual simsignal_t createAndRegisterSignal(std::string sname, std::string tname);

      int numChannels;
      int maxChannelSeparation;
      std::vector<double> adjacentLoss;
      bool interferenceOnTransmission;

      int myNode;
      std::vector<physicallayer::Radio*> radios;

      //Signals
      std::map<int,std::map<int,simsignal_t>> interferenceFractionSignals;
      std::map<int,std::map<int,simsignal_t>> interferenceOverlapSignals;
      std::map<int,std::map<int,simsignal_t>> interferenceCountSignals;
      std::map<int,std::map<int,simsignal_t>> interferencePowerSignals;
};

} //namespace inet

#endif
