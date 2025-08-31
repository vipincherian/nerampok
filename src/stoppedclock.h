#ifndef STOPPED_CLOCK_H
#define STOPPED_CLOCK_H

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
#include "tickcounter.h"

class StoppedClock : public IClockState {
   private:
    // IClockController* controller = nullptr;
    IClockContext* controller = nullptr;
    ClockPanel* panel = nullptr;
    TickCounter* ticks = nullptr;

   public:
    explicit StoppedClock(IClockContext* controller, ClockPanel* panel,
                          TickCounter* ticks);
    void Play() override;
    void Pause() override { wxFAIL_MSG("Cannot pause when clock is stopped."); }
    void Stop() override { wxFAIL_MSG("Already stopped."); }
    void Enter() override;
    void Exit() override { std::cout << "Exit.\n"; }
    void InterimUpdate(long milliseconds) override {};
};

#endif  // STOPPED_CLOCK_H