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

// Include guard
#ifndef __OVERSIM_SIMPLEOVERLAYNODE_H_
#define __OVERSIM_SIMPLEOVERLAYNODE_H_

// includes needed for this class
#include <omnetpp.h>
#include "BaseOverlay.h"
#include "SimpleOverlayUtils.h"
#include "SimplePresentationMessage_m.h"
#include "BootstrapList.h"
#include "GlobalNodeList.h"


/**
 * A simple overlay node that can be used as superclass in order to simplify the implementation of Overlay Protocols.
 */
class SimpleOverlayNode: public BaseOverlay {

private:

    TransportAddress bootstrapNode; //< The node which is presented first to this node.


    simtime_t timeoutDelay; //< The delay in seconds between two calls of onTimout().

    simtime_t failureDelay; //< The delay in seconds after which a failing node will fail.

    /**
     * Is called when the Overlay is intialized. This method is called more than once.
     */
    void initializeOverlay(int stage);

    /**
     * Handles the event of self-messages which are used to simulate timeouts.
     */
    void handleTimerEvent(cMessage* msg);

    /**
     * Gets called when a Message is received via UDP for this Overlay node.
     */
    void handleUDPMessage(BaseOverlayMessage* msg);

    /**
     * Gets called when the Overlay is destroyed. Cleanup (of self-messages) is done here.
     */
    void finishOverlay();

    /**
     * Is called then the node joins the Overlay Network.
     */
    void joinOverlay();

    // obligatory: Set the maximum number of siblings that can be queried about in isSiblingFor(usually 1)
    int getMaxNumSiblings();

    // obligatory: Set the maximum number of redundant nodes that can be queried about in isSiblingFor (usually 1)
    int getMaxNumRedundantNodes();

    // obligatory: called when we need the next hop to route a packet to the given key
    NodeVector* findNode(const OverlayKey& key, // key to route to
            int numRedundantNodes, // next hop candidates to return if we're not responsible for "key"
            int numSiblings, // how many siblings to return if we're responsible for "key"
            BaseOverlayMessage* msg); // message being routed

    // obligatory: In general, called when we need to know whether "node" is amongst numSiblings closest nodes to "key".
    // But normally it is called with "node" set to "thisNode", and asking whether we are responsible for "key"
    bool isSiblingFor(const NodeHandle& node, // which node (usually thisNode) we're referring to
            const OverlayKey& key, // key in question
            int numSiblings, // how many siblings we're querying about
            bool* err);

protected:

    cMessage* stabilize_Timer; //< Self-message used to call onTimeout() continuously.

    cMessage* failure_Timer; //< Self-message used to make a node fail upon reception.

    bool willFail; //< Boolean that determines whether or not the node will fail after a certain period of time

    /**
     * Called when the state of the current node changed (e.g. INIT, JOIN, READY).
     */
    void changeState(int state);

public:

    int joinID; //< Unique id with which the node joined.

    /**
     * Implement this in subclass!
     * Gets called when the node is initialized.
     */
    virtual void onInitialize();

    /**
     * Implement this in subclass!
     * Gets called continuously during simulation.
     */
    virtual void onTimeout();

    /**
     * Implement this in subclass!
     * Gets called when a message for the Overlay Protocol is received.
     */
    virtual void onMessageReceived(BaseOverlayMessage* msg);

    /**
     * Use this to send Messages to other Overlay nodes!
     * Sends a Message to a given node.
     */
    void sendMessage(BaseOverlayMessage* msg, NodeHandle &node);

    /**
     * Updates the GUI. Can be overwritten.
     */
    void updateTooltip();

    /**
     * Shows a speech bubble with the given text at this node in the GUI.
     */
    void yell(const char* text);

    /**
     * Use this to present node1 to node2 in the Overlay.
     */
    void presentNode(NodeHandle node1, NodeHandle node2);

    /**
     * Changes the name of this module in the GUI.
     */
    void updateName(const char* text);

    /**
     * Changes the text that is displayed on hovering over the module in the GUI.
     */
    void updateMouseOver(const char* text);

    /**
     * Removes all Overlay Arrows that have been drawn on this module.
     */
    void clearOverlayArrows();
};

#endif
