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

#include "DoesNothingApp.h"

// Connect this code with the module
Define_Module(DoesNothingApp);

/**
 * Constructor of this application
 */
DoesNothingApp::DoesNothingApp() {

}

/**
 * Destructor of this application
 */
DoesNothingApp::~DoesNothingApp() {

}

/**
 * Called when the module is being created
 */
void DoesNothingApp::initializeApp(int stage) {
    if (stage != MIN_STAGE_APP)
        return;
}

/**
 * called when the module is about to be destroyed
 */
void DoesNothingApp::finishApp() {

}

/**
 * called when we received a timer message
 */
void DoesNothingApp::handleTimerEvent(cMessage* msg) {

}

/**
 * called when the application receives a UDP message
 */
void DoesNothingApp::handleUDPMessage(cMessage* msg) {

}
