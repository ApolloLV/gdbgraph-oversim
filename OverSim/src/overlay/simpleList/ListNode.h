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

#ifndef __OVERSIM_SKELETONNODE_H_
#define __OVERSIM_SKELETONNODE_H_

#include <omnetpp.h>
#include "SimpleOverlayNode.h"
#include "SimplePresentationMessage_m.h"

/**
 * This class represents a node that follows a protocol to form a self-stabilizing list.
 */
class ListNode: public SimpleOverlayNode {
private:

    NodeHandle right; //< the right neighbor of this node

    NodeHandle left; //< the left neighbor of this node

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
     * Linearizes based on the current left node, right node and the given node
     */
    void linearize(NodeHandle* node);

    /**
     * used to update the gui
     */
    void updateTooltip();

    /**
     * Places the module at the given coordinates
     */
    void setPosition(int x, int y);
};

#endif
