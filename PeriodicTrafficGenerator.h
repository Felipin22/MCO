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

#ifndef INET_APPLICATIONS_VEHICULAR_PERIODICTRAFFICGENERATOR_H_
#define INET_APPLICATIONS_VEHICULAR_PERIODICTRAFFICGENERATOR_H_

#include "TrafficGenerator.h"

namespace inet {

class PeriodicTrafficGenerator: public TrafficGenerator {
protected:
    virtual void initialize(int stage) override;
    virtual int numInitStages() const override {return NUM_INIT_STAGES;}
    virtual void handleMessage(cMessage *msg) override;

    double initialOffset;

public:
    PeriodicTrafficGenerator();
    virtual ~PeriodicTrafficGenerator();
};

} /* namespace inet */

#endif /* INET_APPLICATIONS_VEHICULAR_PERIODICTRAFFICGENERATOR_H_ */
