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

#include "ChainNode.h"

// Define the module for OMNet++
Define_Module(ChainNode);

/**
 * Gets called when the node is initialized.
 */
void ChainNode::onInitialize() {
    // set the child to an empty node
    successor = NodeHandle::UNSPECIFIED_NODE;

    // We want to keep track of the successor in the GUI
    WATCH(successor);

    // are we the head of the chain?
    head = false;

    if (par("nodeNumber").doubleValue() == joinID + 1) {
        // we are the head
        yell("I am the head!");
        head = true;
    }

    if (joinID > 0) {
        // we are not the first node!

        // get the successor
        successor = *(SimpleOverlayUtils::getNode(joinID - 1));

        // yell the good news!
        yell("I found a successor!");

        EV << "My successor is node "
                << SimpleOverlayUtils::getJoinID(successor) << endl;
    }

    // update the GUI
    updateTooltip();
}

/**
 * Gets called continuously during simulation.
 */
void ChainNode::onTimeout() {
    // If we are the head of the chain, we will send  a "cheers"
    if (head) {
        // we are the head node
        yell("Send CHEERS");
        CheersMessage* msg = new CheersMessage();
        sendMessage(msg, successor);
    }
}

/**
 * Gets called when a message for the Overlay Protocol is received.
 */
void ChainNode::onMessageReceived(BaseOverlayMessage* msg) {
    // determine message type
    if (SimplePresentationMessage* message=dynamic_cast<SimplePresentationMessage*>(msg)) {
        // we received a presentation message
        EV << "Received Message!";
        // This will be some node of the network that has been introduced to us as anchor
        // We don't need it in this example
        // delete the message
        delete msg;

    } else if (CheersMessage* message=dynamic_cast<CheersMessage*>(msg)) {
        // we received a cheers message! Join in!
        yell("CHEERS!");
        // if we have a successor, forward the message
        if (!successor.isUnspecified()) {
            // Debug output
            EV << "Node " << SimpleOverlayUtils::getJoinID(thisNode)
                    << " is forwarding Cheer Message" << endl;
            sendMessage(msg, successor);
        } else {
            // we are at the end of the chain :( delete the message
            delete msg;
        }
    }
}

/**
 * Updates the GUI.
 */
void ChainNode::updateTooltip() {
    // is this module displayed?
    if (ev.isGUI()) {
        // show this node in the tooltip

        std::stringstream ttString;

        if (!successor.isUnspecified()) {
            ttString << "This: " << joinID << endl << "Succ: "
                 << SimpleOverlayUtils::getJoinID(successor);
        } else {
            ttString << "This: " << joinID;
        }

        updateMouseOver(ttString.str().c_str());

        // draw a red arrow to our successor
        showOverlayNeighborArrow(successor, true, "m=m,50,0,50,0;ls=red,1");
    }
}
