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

#include "SkeletonNode.h"

// Define the module for OMNeT++
Define_Module(SkeletonNode);

/**
 * Gets called when the node is initialized.
 */
void SkeletonNode::onInitialize() {

}

/**
 * Gets called continuously during simulation.
 */
void SkeletonNode::onTimeout() {

}

/**
 * Gets called when a message for the Overlay Protocol is received.
 */
void SkeletonNode::onMessageReceived(BaseOverlayMessage* msg) {
    if (SimplePresentationMessage* message=dynamic_cast<SimplePresentationMessage*>(msg)) {
        // we received a simple presentation message
    }
}
