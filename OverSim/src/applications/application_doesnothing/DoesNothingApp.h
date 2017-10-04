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

#ifndef __OVERSIM_DOESNOTHINGAPP_H_
#define __OVERSIM_DOESNOTHINGAPP_H_

#include <omnetpp.h>
#include <BaseApp.h>

/**
 * A simple Application that does nothing.
 */
class DoesNothingApp: public BaseApp {

public:

    /**
     * Constructor of this application
     */
    DoesNothingApp();

    /**
     * Destructor of this application
     */
    ~DoesNothingApp();

    /**
     * Called when the module is being created
     */
    virtual void initializeApp(int stage);

    /**
     * called when the module is about to be destroyed
     */
    virtual void finishApp();

    /**
     * called when we received a timer message
     */
    virtual void handleTimerEvent(cMessage* msg);

    /**
     * called when the application receives a UDP message
     */
    virtual void handleUDPMessage(cMessage* msg);
};

#endif
