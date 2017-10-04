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

#include "SimpleOverlayUtils.h"

// Define this Module for OMNet++
Define_Module(SimpleOverlayUtils);

// these maps hold a mapping from nodes <-> joinIDs
static std::map<int, NodeHandle> nodes;
static std::map<NodeHandle, int> keys;

/**
 * Needs to be implemented because this is a Simple OMNet++ module.
 */
void SimpleOverlayUtils::initialize() {
    // nothing to do here
}

/**
 * Needs to be implemented because this is a Simple OMNet++ module.
 */
void SimpleOverlayUtils::handleMessage(cMessage *msg) {
    // nothing to do here
}

/**
 * Adds a node to the tracked nodes. Returns a new unique joinID for this node.
 */
int SimpleOverlayUtils::addNode(NodeHandle& node) {
    nodes.insert(std::make_pair(nodes.size(), node));
    keys.insert(std::make_pair(node, nodes.size() - 1));
    return nodes.size() - 1;
}

/**
 * Returns the last node that has been added.
 */
NodeHandle* SimpleOverlayUtils::getLastNode() {
    return &(nodes.at(nodes.size()));
}

/**
 * Returns the node associated with the given joinID
 */
NodeHandle* SimpleOverlayUtils::getNode(int key) {
    return &(nodes.at(key));
}

/**
 * Returns the joinID of the given node.
 */
int SimpleOverlayUtils::getJoinID(NodeHandle &node) {
    return keys.at(node);
}
