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

//
// This module creates dynamically the nodes. The number of nodes corresponds with the number of rows in the file and each row contains the initial position
// of the node. Is intended for nodes that use a StationaryMobility module.
//

simple FileNodeManager like INodeManager
{
    parameters:
        @display("i=block/network2");
        string moduleType = default("inet.applications.vehicular.TrafficGeneratorHost");  // module type to be used in the simulation for each managed vehicle
        string moduleName = default("node");  // module name to be used in the simulation for each managed vehicle
        string moduleDisplayString = default("i=misc/node2;is=vs");
        string filename;
}
