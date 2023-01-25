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

package inet.applications.vehicular;
import inet.physicallayer.wireless.common.contract.packetlevel.IRadioMedium;
import inet.visualizer.contract.IIntegratedVisualizer;
///import inet.applications.vehicular.INodeManager;
///import inet.applications.vehicular.FileNodeManager;


network TraficGeneratorNetwork
{
    parameters:
        @display("bgb=1400,400");
        int nodes;

    submodules:
        radioMedium: <default("Ieee80211ScalarRadioMedium")> like IRadioMedium {
            @display("p=94.770004,84.240005");
        }
        node[nodes]: TrafficGeneratorHost {
            id = index;
        }
        visualizer: <default(firstAvailableOrEmpty("IntegratedCanvasVisualizer"))> like IIntegratedVisualizer if typename != "" {
            @display("p=257.98502,85.995");
        }
        ///        nodeManager: <default("")>  like INodeManager if typename != "" {
        ///           @display("p=226.62724,50.05918");
        ///        }
        //        destination: OpalNode {
        //            @display("p=226.62724,110.05918");
        //        }
}