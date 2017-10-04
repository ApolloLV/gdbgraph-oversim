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

#ifndef __OVERSIM_SIMPLEOVERLAYUTILS_H_
#define __OVERSIM_SIMPLEOVERLAYUTILS_H_

#include <omnetpp.h>
#include <NodeHandle.h>

/**
 * A class that offers Simple utilities for overlay nodes.
 * For example: Every SimpleOverlayNode is saved together with his joinID.
 * This class enables a node to find another node based only on the joinID.
 * (Useful for example to initially form a List)
 */
class SimpleOverlayUtils: public cSimpleModule {

protected:

    /**
     * Needs to be implemented because this is a Simple OMNet++ module.
     */
    virtual void initialize();

    /**
     * Needs to be implemented because this is a Simple OMNet++ module.
     */
    virtual void handleMessage(cMessage *msg);

public:

    /**
     * Adds a node to the tracked nodes. Returns a new unique joinID for this node.
     */
    static int addNode(NodeHandle &node);

    /**
     * Returns the last node that has been added.
     */
    static NodeHandle* getLastNode();

    /**
     * Returns the node associated with the given joinID
     */
    static NodeHandle* getNode(int key);

    /**
     * Returns the joinID of the given node.
     */
    static int getJoinID(NodeHandle &node);
};

#endif
