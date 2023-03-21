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

#ifndef __INET4_4_UNIFORMSLOTTEDTRAFFICGENERATOR_H_
#define __INET4_4_UNIFORMSLOTTEDTRAFFICGENERATOR_H_

#include <omnetpp.h>
#include "TrafficGenerator.h"

using namespace omnetpp;

namespace inet {

class UniformSlottedTrafficGenerator : public TrafficGenerator
{
  protected:
    virtual void initialize(int stage) override;
    virtual void handleMessage(cMessage *msg) override;
    void generateSlots();

    int maximumPacketsPerSecond;
    double generatedPacketsFraction;
    double minimumPacketDuration;
    simtime_t generateSlotsPeriod;

    int packetsToGenerate;
    int currentSlot;
    cMessage *generateSlotsTimer;
    std::vector<simtime_t> slots;

  public:
    UniformSlottedTrafficGenerator();
    virtual ~UniformSlottedTrafficGenerator();

};

} //namespace inet

#endif /* __INET4_4_UNIFORMSLOTTEDTRAFFICGENERATOR_H_ */