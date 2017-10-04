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

#include "BroadcastNode.h"

// Define the OMNet++ Module in this class
Define_Module(BroadcastNode);

/**
 * Gets called when the node is initialized.
 */
void BroadcastNode::onInitialize() {
    // are we a server?
    if (joinID == 0) {
        // this node was the first node to join, let's make him a server
        isServer = true;

        // change name
        updateName("Server ");
    } else {
        isServer = false;
    }

    // if we are a client, notify the server
    if (!isServer) {

        // save the server
        server = *(SimpleOverlayUtils::getNode(0));

        // update gui
        updateTooltip();

        // present to the server
        presentNode(thisNode, server);
    }
}

/**
 * Gets called continuously during simulation.
 */
void BroadcastNode::onTimeout() {
    // are we a client?
    if (!isServer) {

        // only send a message to the server with probability 1/20
        if (rand() % 100 < 20) {
            // send a broadcast Message to the server
            std::stringstream text;
            text << "Broadcast from Node " << joinID;
            BroadcastMessage* msg = new BroadcastMessage();
            msg->setText(text.str().c_str());

            sendMessage(msg, server);

            std::stringstream output;
            output << "Sending Broadcast!";
            yell(output.str().c_str());
        }
    }
}

/**
 * Gets called when a message for the Overlay Protocol is received.
 */
void BroadcastNode::onMessageReceived(BaseOverlayMessage* msg) {
    // check the message type
    if (SimplePresentationMessage* message=dynamic_cast<SimplePresentationMessage*>(msg)) {
        // we received a presentation message
        // are we the server?
        if (isServer) {
            NodeHandle content = message->getContent();
            clients.push_back(content);

            std::stringstream output;
            output << "Received Node "
                    << SimpleOverlayUtils::getJoinID(content);
            yell(output.str().c_str());

            // update gui
            updateTooltip();
        }
        delete msg;

    } else if (BroadcastMessage* message=dynamic_cast<BroadcastMessage*>(msg)) {
        // are we the server?
        if (isServer) {
            // we want to distribute this
            for (std::list<NodeHandle>::iterator it = clients.begin();
                    it != clients.end(); ++it) {
                // send a message to each client
                BroadcastMessage* toSend = new BroadcastMessage();
                toSend->setText(message->getText());
                sendMessage(toSend, *it);

                std::stringstream output;
                output << "Broadcasting " << message->getText();
                yell(output.str().c_str());
            }
        } else {
            // we are a client
            std::stringstream output;
            output << "Received " << message->getText();
            yell(output.str().c_str());
        }

        delete msg;
    }
}

/**
 * Updates the GUI. Can be overwritten.
 */
void BroadcastNode::updateTooltip() {
    if (ev.isGUI()) {
        std::stringstream ttString;

        // show this node in the tooltip
        ttString << endl << thisNode;

        updateMouseOver(ttString.str().c_str());

        // draw connections
        // reset drawing
        clearOverlayArrows();

        if (isServer) {
            // draw connection to every client
            for (std::list<NodeHandle>::iterator it = clients.begin();
                    it != clients.end(); ++it) {
                showOverlayNeighborArrow(*it, false, "m=m,50,0,50,0;ls=red,1");
            }
        } else {
            // draw connection to server
            showOverlayNeighborArrow(server, false,
                    "m=m,50,100,50,100;ls=green,1");
        }

    }
}
