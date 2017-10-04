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

package oversim.overlay.simpleOverlay_Clique;

import oversim.overlay.simpleOverlay.SimpleOverlayNode;
import oversim.common.IOverlay;

//
// A module for a node which is used to form a clique.
//
simple CliqueNode extends SimpleOverlayNode
{
    parameters:
        @class(CliqueNode); //< connects the OMNet++ module with our c++ class
}
//
// A Module to embed our overlay node with the simulation node-
//
module CliqueNodeModule like IOverlay
{
    // gates to the other layers of a node
    gates:
        input udpIn;   // gate from the UDP layer
        output udpOut;    // gate to the UDP layer
        input tcpIn;    // gate from the TCP layer
        output tcpOut;    // gate to the TCP layer
        input appIn;   // gate from the application
        output appOut;    // gate to the application

    // the module that holds the overlay protocol    
    submodules:
        cliqueNode: CliqueNode;
    // connects the overlay module with the other layers  
    connections allowunconnected:
        udpIn --> cliqueNode.udpIn;
        udpOut <-- cliqueNode.udpOut;
        appIn --> cliqueNode.appIn;
        appOut <-- cliqueNode.appOut;
}

