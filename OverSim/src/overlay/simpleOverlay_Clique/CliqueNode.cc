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

#include "CliqueNode.h"

// Define the OMNet++ Module
Define_Module(CliqueNode);

/**
 * Gets called when the node is initialized.
 */
void CliqueNode::onInitialize() {
    // add the current node
    neighbors.push_back(thisNode);
}

/**
 * Gets called continuously during simulation.
 */
void CliqueNode::onTimeout() {
}

/**
 * Gets called when a message for the Overlay Protocol is received.
 */
void CliqueNode::onMessageReceived(BaseOverlayMessage* msg) {
    // check message type
    if (SimplePresentationMessage* message=dynamic_cast<SimplePresentationMessage*>(msg)) {

        EV << "Received Presentation Message!" << endl;
        // we received a SimplePresentationMessage
        NodeHandle content = message->getContent();

        // check if we already know the node
        bool isKnown = false;
        for (std::list<NodeHandle>::iterator it = neighbors.begin();
                it != neighbors.end(); ++it) {
            if ((*it).getKey() == content.getKey()) {
                isKnown = true;
            }
        }

        // if we do not know the node
        if (!isKnown) {
            // present it
            for (std::list<NodeHandle>::iterator it = neighbors.begin();
                    it != neighbors.end(); ++it) {
                // present the received node to the neighbor
                presentNode(content, *it);

                // present the neighbor to the received node
                presentNode(*it, content);

            }

            // add the node to our neighborhood
            neighbors.push_back(content);

            std::stringstream outString;
            outString << "Received Node "
                    << SimpleOverlayUtils::getJoinID(content);
            yell(outString.str().c_str());

            // update gui
            updateTooltip();
        }

        delete msg;
    }
}

/**
 * Updates the GUI. Can be overwritten.
 */
void CliqueNode::updateTooltip() {
    // is this module displayed?
    if (ev.isGUI()) {
        // show this node in the tooltip

        std::stringstream ttString;
        ttString << "This: " << thisNode;

        updateMouseOver(ttString.str().c_str());

        // reset drawing
        clearOverlayArrows();

        // draw an arrow to each successor
        for (std::list<NodeHandle>::iterator it = neighbors.begin();
                it != neighbors.end(); ++it) {
            NodeHandle current = *it;
            showOverlayNeighborArrow(current, false, "m=m,50,0,50,0;ls=red,1");
        }
    }
}
