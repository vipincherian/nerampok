#include "constants.h"

// The single static instance of the Constants class.

// The implementation of the getInstance() method.
Constants& Constants::getInstance() {
    // The single static instance of the Constants class.
    static Constants instance;
    return instance;
}

// Private constructor where all the constants are initialized.
Constants::Constants() : appTitle(APP_TITLE + " " + APP_VERSION) {
    // appTitle = APP_TITLE + " " + APP_VERSION;
}

// Implementations of the getter methods.
wxString Constants::getAppTitle() const { return appTitle; }

wxString Constants::getAppConfigDirName() const { return APP_TITLE.Lower(); }
