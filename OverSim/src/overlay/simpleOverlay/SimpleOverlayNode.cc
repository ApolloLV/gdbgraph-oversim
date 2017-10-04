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

#include "SimpleOverlayNode.h"

// Define the module for OMNet++
Define_Module(SimpleOverlayNode);

/**
 * Is called when the Overlay is intialized. This method is called more than once.
 */
void SimpleOverlayNode::initializeOverlay(int stage) {

    // because of IPAddressResolver, we need to wait until interfaces
    // are registered, address auto-assignment takes place etc.
    if (stage != MIN_STAGE_OVERLAY)
        return;

    // get a key
    thisNode.setKey(OverlayKey::random());

    updateTooltip();

    // add the current node to the overlay utils class
    joinID = SimpleOverlayUtils::addNode(thisNode);

    // read parameters
    timeoutDelay = par("timeoutDelay");

    // initialize stabilize timer
    stabilize_Timer = new cMessage("stabilize_timer");

    // setup the failure
    double failureR = ((double) rand() / (RAND_MAX)); //Gives a random number between 0 and 1
    double timerR = ((double) rand() / (RAND_MAX)); //Gives a random number between 0 and 1
    double failureProbability = par("failureProbability");

    failureDelay = par("failureDelay");
    if(failureR <= failureProbability){
        failureDelay = failureDelay + 5.0*timerR*failureDelay;
    }else{
        failureDelay = -1;
    }

    WATCH(failureDelay);

    // rename this terminal
    updateName("Node ");

    // call initialize for subclasses
    onInitialize();
}

/**
 * Handles the event of self-messages which are used to simulate timeouts.
 */
void SimpleOverlayNode::handleTimerEvent(cMessage *msg) {

    if(failureDelay>0 && simTime()>failureDelay){
        changeState(FAILED);
        finishOverlay();
    }else{
        // cancel and reschedule the stabilize timer
        cancelEvent(stabilize_Timer);

        scheduleAt(simTime() + timeoutDelay, msg);

        // fire onTimeout of subclasses
        onTimeout();
    }
}

/**
 * Gets called when a Message is received via UDP for this Overlay node.
 */
void SimpleOverlayNode::handleUDPMessage(BaseOverlayMessage* msg) {
    // simply forward
    onMessageReceived(msg);
}

/**
 * Gets called when the Overlay is destroyed. Cleanup (of self-messages) is done here.
 */
void SimpleOverlayNode::finishOverlay() {
    if (stabilize_Timer->isScheduled()) {
        // cancel the stabilization
        cancelEvent(stabilize_Timer);
        delete stabilize_Timer;
    }
}

/**
 * Is called then the node joins the Overlay Network.
 */
void SimpleOverlayNode::joinOverlay() {
    // debug output
    std::ostringstream s;
    s << thisNode.getKey().toDouble();
    EV << "Node with key " << s.str() << " joins the Overlay!";

    changeState(INIT);
    changeState(JOIN);
}

// Set the maximum number of siblings that can be queried about in isSiblingFor(usually 1)
int SimpleOverlayNode::getMaxNumSiblings() {
    return 1;
}

// Return the max amount of redundant that can be queried about
int SimpleOverlayNode::getMaxNumRedundantNodes() {
    return 1;
}

// Return the next step for the routing of the given message
// Currently not implemented because SimpleOverlayNode does not offer a predecessor / successor because this might not be common for all Overlays.
NodeVector *SimpleOverlayNode::findNode(const OverlayKey& key,
        int numRedundantNodes, int numSiblings, BaseOverlayMessage* msg) {

    NodeVector* nextHops;

    // numRedundantNodes and numSiblings are both maximal 1
    nextHops = new NodeVector(1);

    if (key == thisNode.getKey()) { // are we responsible? next step is this node
        nextHops->add(thisNode);
    } else if (key < thisNode.getKey()) { // is the key behind us? next step is the previous node
        //nextHops->add(predecessorNode);
    } else { // otherwise, the next step is the next node
        //nextHops->add(successorNode);
    }
    return nextHops;
}

// Return whether we know if the given node is responsible for the key
bool SimpleOverlayNode::isSiblingFor(const NodeHandle& node,
        const OverlayKey& key, int numSiblings, bool* err) {
    if (node == thisNode && key == thisNode.getKey()) { // is it our node and our key?
        return true;
    }
    return false; // we don't know otherwise
}

/**
 * Called when the state of the current node changed (e.g. INIT, JOIN, READY).
 */
void SimpleOverlayNode::changeState(int toState) {

    switch (toState) {
    case INIT:
        // the node is initialized
        state = INIT;

        break;
    case JOIN:
        // the node joins
        state = JOIN;

        // get a bootstrap node
        bootstrapNode = (bootstrapList->getBootstrapNode(overlayId));

        // is this the first node?
        if (bootstrapNode.isUnspecified()) {
            yell("I am the first node!");
            bootstrapNode = thisNode;
            changeState(READY);
        } else {
            // present the node
            presentNode(*(globalNodeList->getNodeHandle(bootstrapNode.getIp())),
                    thisNode);
            changeState(READY);
        }

        break;
    case READY:
        // the node is ready
        state = READY;
        setOverlayReady(true);

        // if stabilization is used, schedule the timeout
        if (par("useStabilization")) {
            double r = ((double) rand() / (RAND_MAX)); //Gives a random number between 0 and 1
            scheduleAt(simTime() + timeoutDelay + r*timeoutDelay, stabilize_Timer);
        }
        break;
    case FAILED:
        // the node has failed
        state = FAILED;
        getParentModule()->getParentModule()->setDisplayString("i=device/laptop,red,30");
        break;
    }
}

/**
 * Implement this in subclass!
 * Gets called when the node is initialized.
 */
void SimpleOverlayNode::onInitialize() {
}

/**
 * Implement this in subclass!
 * Gets called continuously during simulation.
 */
void SimpleOverlayNode::onTimeout() {
}

/**
 * Implement this in subclass!
 * Gets called when a message for the Overlay Protocol is received.
 */
void SimpleOverlayNode::onMessageReceived(BaseOverlayMessage* msg) {
}

/**
 * Use this to send Messages to other Overlay nodes!
 * Sends a Message to a given node.
 */
void SimpleOverlayNode::sendMessage(BaseOverlayMessage* msg, NodeHandle &node) {
    // simply pass the message to the UDP connection
    if(state!=FAILED){
        sendMessageToUDP(node, msg);
    }
}

/**
 * Updates the GUI. Can be overwritten.
 */
void SimpleOverlayNode::updateTooltip() {
    if (ev.isGUI()) {
        std::stringstream ttString;

        // show this node in the tooltip
        ttString << endl << thisNode;

        updateMouseOver(ttString.str().c_str());
    }
}

/**
 * Shows a speech bubble with the given text at this node in the GUI.
 */
void SimpleOverlayNode::yell(const char* text) {
    if(state!=FAILED){
        getParentModule()->getParentModule()->bubble(text);
    }
}

/**
 * Use this to present node1 to node2 in the Overlay.
 */
void SimpleOverlayNode::presentNode(NodeHandle node1, NodeHandle node2) {
    if(state!=FAILED){
        SimplePresentationMessage* msg = new SimplePresentationMessage();
        msg->setContent(node1);
        sendMessage(msg, node2);
    }
}

/**
 * Changes the name of this module in the GUI.
 */
void SimpleOverlayNode::updateName(const char* text) {
    getParentModule()->getParentModule()->setName(text);
}

/**
 * Changes the text that is displayed on hovering over the module in the GUI.
 */
void SimpleOverlayNode::updateMouseOver(const char* text) {
    getParentModule()->getParentModule()->getDisplayString().setTagArg("tt", 0,
            text);
    getParentModule()->getDisplayString().setTagArg("tt", 0, text);
    getDisplayString().setTagArg("tt", 0, text);
}

/**
 * Removes all Overlay Arrows that have been drawn on this module.
 */
void SimpleOverlayNode::clearOverlayArrows() {
    showOverlayNeighborArrow(thisNode, true, "m=m,50,0,50,0;ls=red,1");
}
