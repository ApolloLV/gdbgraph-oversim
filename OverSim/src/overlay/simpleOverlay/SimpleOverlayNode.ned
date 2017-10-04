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

package oversim.overlay.simpleOverlay;

import oversim.common.BaseOverlay;

//
// This class simplifies the definition of Overlay Nodes by abstracting BaseOverlay.
//
simple SimpleOverlayNode extends BaseOverlay
{
    parameters:
        // Connects the Module to its c++ definition
        @class(SimpleOverlayNode);
        
        // indicates whether or not stabilization should be used (and onTimeout() is called continuously)
        bool useStabilization = default(true); 
        
        // indicates the delay between two onTimout() calls in seconds
        int timeoutDelay @unit(s) = default(20s);
        
        // indicates the delay after which a failing node will fail
        int failureDelay @unit(s) = default(200s);
        
        // indicates the probability with which a node will fail
        double failureProbability = default(0.0);
}


