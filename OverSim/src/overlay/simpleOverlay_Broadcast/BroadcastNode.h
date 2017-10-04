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

#ifndef __OVERSIM_BROADCASTNODE_H_
#define __OVERSIM_BROADCASTNODE_H_

#include <omnetpp.h>
#include "SimpleOverlayNode.h"
#include "SimpleOverlayUtils.h"
#include "BroadcastMessage_m.h"
#include "SimplePresentationMessage_m.h"

/**
 * A class containing the logic of an overlay node in our Broadcast Example.
 */
class BroadcastNode: public SimpleOverlayNode {
private:

    bool isServer; //< Determines if the current node is a server or a client

    NodeHandle server; //< only used by clients: connection to the server

    std::list<NodeHandle> clients; //< only used by a server: connections to the clients

public:

    /**
     * Gets called when the node is initialized.
     */
    void onInitialize();

    /**
     * Gets called continuously during simulation.
     */
    void onTimeout();

    /**
     * Gets called when a message for the Overlay Protocol is received.
     */
    void onMessageReceived(BaseOverlayMessage* msg);

    /**
     * Updates the GUI. Can be overwritten.
     */
    void updateTooltip();
};

#endif
