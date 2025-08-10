#ifndef PAUSED_CLOCK_H
#define PAUSED_CLOCK_H

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <iostream>

#include "clockpanel.h"
// #include "containerpanel.h"
#include "iclockcontroller.h"
// #include "iclockmediator.h"
#include "iclockstate.h"

class PausedClock : public IClockState {
   private:
    IClockContext* controller = nullptr;
    ClockPanel* panel = nullptr;

   public:
    explicit PausedClock(IClockContext* controller, ClockPanel* panel);
    void Play() override {
        std::cout << "Starting clock.\n";
        // Transition to PlayingState
    }
    void Pause() override { std::cout << "Cannot pause. Clock is stopped.\n"; }
    void Stop() override { std::cout << "Already stopped.\n"; }
    void Enter() override { std::cout << "Enter.\n"; }
    void Exit() override { std::cout << "Exit.\n"; }
};

#endif  // PAUSED_CLOCK_H