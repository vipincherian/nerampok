#ifndef CLOCK_CONTROLLER_H
#define CLOCK_CONTROLLER_H

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <iostream>

#include "clockpanel.h"
#include "containerpanel.h"
#include "iclockcontroller.h"
#include "iclockmediator.h"
#include "iclockstate.h"

class StoppedClock : public IClockState {
   private:
    IClockController* controller = nullptr;
    ClockPanel* panel = nullptr;

   public:
    explicit StoppedClock(IClockController* controller, ClockPanel* panel);
    void Play() override {
        std::cout << "Starting clock.\n";
        // Transition to PlayingState
    }
    void Pause() override { std::cout << "Cannot pause. Clock is stopped.\n"; }
    void Stop() override { std::cout << "Already stopped.\n"; }
};

class PlayingClock : public IClockState {
   private:
    IClockController* controller = nullptr;
    ClockPanel* panel = nullptr;

   public:
    explicit PlayingClock(IClockController* controller, ClockPanel* panel);
    void Play() override {
        std::cout << "Starting clock.\n";
        // Transition to PlayingState
    }
    void Pause() override { std::cout << "Cannot pause. Clock is stopped.\n"; }
    void Stop() override { std::cout << "Already stopped.\n"; }
};

class PausedClock : public IClockState {
   private:
    IClockController* controller = nullptr;
    ClockPanel* panel = nullptr;

   public:
    explicit PausedClock(IClockController* controller, ClockPanel* panel);
    void Play() override {
        std::cout << "Starting clock.\n";
        // Transition to PlayingState
    }
    void Pause() override { std::cout << "Cannot pause. Clock is stopped.\n"; }
    void Stop() override { std::cout << "Already stopped.\n"; }
};

// Forward declaration of the IClockMediator interface.
// We assume this interface is defined in a separate header.
// class IClockMediator;

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
    explicit ClockController(IClockMediator* mediator,
                             ContainerPanel* container, int id);
    ~ClockController();

    // Explicitly delete the default constructor to prevent instantiation
    // without a mediator.
    ClockController() = delete;

    // Explicitly delete the copy constructor and copy assignment operator
    // to prevent cloning.
    ClockController& operator=(const ClockController*) = delete;
    ClockController(const ClockController&) = delete;

   private:
    // A reference to the mediator, which allows the controller to
    // interact with other parts of the application.
    IClockMediator* clockMediator = nullptr;
    ContainerPanel* container = nullptr;
    int id = -1;
    ClockPanel* clockPanel = nullptr;
    IClockState* currentState = nullptr;

    StoppedClock* stoppedClock = nullptr;
};

#endif  // CLOCK_CONTROLLER_H
