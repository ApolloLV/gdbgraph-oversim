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

#ifndef __OVERSIM_CLIQUENODE_H_
#define __OVERSIM_CLIQUENODE_H_

#include <omnetpp.h>
#include "SimpleOverlayNode.h"
#include <list>
#include "SimplePresentationMessage_m.h"
#include "SimpleOverlayUtils.h"

/**
 * A class representing out clique overlay node.
 * Implements all logic for the clique example.
 */
class CliqueNode: public SimpleOverlayNode {

private:

    std::list<NodeHandle> neighbors; //< The neighbors of this node

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
