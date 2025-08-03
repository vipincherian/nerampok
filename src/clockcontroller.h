#ifndef CLOCK_CONTROLLER_H
#define CLOCK_CONTROLLER_H

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "clockpanel.h"
#include "iclockcontroller.h"

// Forward declaration of the IClockMediator interface.
// We assume this interface is defined in a separate header.
class IClockMediator;

/**
 * @class ClockController
 * @brief Manages the logic for a clock display, communicating via a mediator.
 *
 * This class is designed to be a controller in a Model-View-Controller (MVC)
 * pattern. It takes a mediator in its constructor to decouple it from
 * the specific view implementation. The default constructor, copy constructor,
 * and assignment operator are all explicitly deleted to enforce the
 * intended usage.
 */
class ClockController : IClockController {
   public:
    // Main constructor that takes a reference to the IClockMediator interface.
    // This is the only way to create an instance of this class.
    explicit ClockController(IClockMediator* mediator, wxPanel* container);

    // Explicitly delete the default constructor to prevent instantiation
    // without a mediator.
    ClockController() = delete;

    // Explicitly delete the copy constructor and copy assignment operator
    // to prevent cloning.
    ClockController(const ClockController*) = delete;
    ClockController& operator=(const ClockController*) = delete;

   private:
    // A reference to the mediator, which allows the controller to
    // interact with other parts of the application.
    IClockMediator* clockMediator = nullptr;
    wxPanel* container = nullptr;
    ClockPanel* clockPanel = nullptr;
};

#endif  // CLOCK_CONTROLLER_H
