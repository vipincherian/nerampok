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
#include "tickcounter.h"

class PausedClock : public IClockState {
   private:
    IClockContext* controller = nullptr;
    ClockPanel* panel = nullptr;
    TickCounter* ticks = nullptr;

   public:
    explicit PausedClock(IClockContext* controller, ClockPanel* panel,
                         TickCounter* ticks);
    void Play() override;
    void Pause() override { std::cout << "Cannot pause. Clock is stopped.\n"; }
    void Stop() override;
    void Enter() override;
    void Exit() override { std::cout << "Exit.\n"; }
    void InterimUpdate(long milliseconds) override {};
};

#endif  // PAUSED_CLOCK_H