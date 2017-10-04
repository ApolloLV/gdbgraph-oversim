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

#include "ListNode.h"

// Define the module for OMNeT++
Define_Module(ListNode);

/**
 * Gets called when the node is initialized.
 */
void ListNode::onInitialize() {

    // places the list nodes distributed for a better graphic representation

    int positionX = (110 * (joinID + 1));

    if (joinID % 2 == 0) {
        setPosition(positionX, 400);
    } else {
        setPosition(positionX, 300);
    }

    left = NodeHandle::UNSPECIFIED_NODE;
    right = NodeHandle::UNSPECIFIED_NODE;

    // set a key. For Example: this nodes join id
    thisNode.setKey(OverlayKey(joinID));
}

/**
 * Gets called continuously during simulation.
 */
void ListNode::onTimeout() {
    std::string output = "onTimeout() called";
    yell(output.c_str());
    if (!left.isUnspecified()) {
        if (left.getKey() < thisNode.getKey()) {
            // present this node to our left neighbor
            presentNode(thisNode, left);
        } else {
            // reinsert our left neighbor
            linearize(&left);
            left = NodeHandle::UNSPECIFIED_NODE;
        }
    }
    if (!right.isUnspecified()) {
        if (right.getKey() > thisNode.getKey()) {
            presentNode(thisNode, right);
        } else {
            linearize(&right);
            right = NodeHandle::UNSPECIFIED_NODE;
        }
    }
    updateTooltip();
}

/**
 * Gets called when a message for the Overlay Protocol is received.
 */
void ListNode::onMessageReceived(BaseOverlayMessage* msg) {
    if (SimplePresentationMessage* message=dynamic_cast<SimplePresentationMessage*>(msg)) {
        // we received a simple presentation message

        // get the NodeHandle containing this message
        NodeHandle* content = &(message->getContent());

        // call linearize
        linearize(content);
        delete msg;
    }
}

/**
 * Linearizes based on the current right node, left node and the given node
 */
void ListNode::linearize(NodeHandle* node) {

    if (!left.isUnspecified() && node->getKey() < left.getKey()) {
        // present the node to the current left
        presentNode(*node, left);
    }

    if ((left.isUnspecified() && node->getKey() < thisNode.getKey())
            || (!left.isUnspecified() && left.getKey() < node->getKey()
                    && node->getKey() < thisNode.getKey())) {

        if (!left.isUnspecified()) {
            // present the left to the node
            presentNode(left, *node);
        }
        // set new left
        left = *node;

        std::stringstream output;
        output << "New left node: " << left.getKey().toDouble();
        yell(output.str().c_str());
    }

    if ((right.isUnspecified() && thisNode.getKey() < node->getKey())
            || (!right.isUnspecified() && thisNode.getKey() < node->getKey()
                    && node->getKey() < right.getKey())) {

        if (!right.isUnspecified()) {
            // present the right node to the node
            presentNode(right, *node);
        }
        // set the new right node
        right = *node;

        // make a bubble
        std::stringstream output;
        output << "New right node: " << right.getKey().toDouble();
        yell(output.str().c_str());
    }

    if (!right.isUnspecified() && right.getKey() < node->getKey()) {
        // delegate the node
        presentNode(*node, right);
    }

    // update GUI :)
    updateTooltip();
}

/**
 * used to update the GUI
 */
void ListNode::updateTooltip() {
    // are we displayed?
    if (ev.isGUI()) {
        clearOverlayArrows();
        // draw a red arrow to our right node
        if (!right.isUnspecified()) {
            showOverlayNeighborArrow(right, false, "m=m,50,0,50,0;ls=red,1");
        }
        if (!left.isUnspecified()) {
            // draw a red arrow to our left node
            showOverlayNeighborArrow(left, false,
                    "m=m,50,100,50,100;ls=green,1");
        }
    }
}


/**
 * Places the module at the given coordinates
 */
void ListNode::setPosition(int x, int y) {
    std::stringstream positionX;
    positionX << x;
    std::stringstream positionY;
    positionY << y;
    getParentModule()->getParentModule()->getDisplayString().setTagArg("p", 0, positionX.str().c_str());
    getParentModule()->getParentModule()->getDisplayString().setTagArg("p", 1, positionY.str().c_str());
}
