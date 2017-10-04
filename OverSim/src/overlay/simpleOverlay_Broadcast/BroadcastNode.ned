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

package oversim.overlay.simpleOverlay_Broadcast;

import oversim.overlay.simpleOverlay.SimpleOverlayNode;
import oversim.common.IOverlay;

//
// The Overlay node as an OMNet++ Module.
//
simple BroadcastNode extends SimpleOverlayNode
{
    parameters:
        @class(BroadcastNode); //< Connect the OMNet++ Module with our c++ class
}

//
// This module embeds our overlay module in the simulation node.
// 
module BroadcastNodeModule like IOverlay {
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
        broadcastNode: BroadcastNode;
    // connects the overlay module with the other layers  
    connections allowunconnected:
        udpIn --> broadcastNode.udpIn;
        udpOut <-- broadcastNode.udpOut;
        appIn --> broadcastNode.appIn;
        appOut <-- broadcastNode.appOut;
}
