#include "playingclock.h"

PlayingClock::PlayingClock(IClockController *controller, ClockPanel *panel)
    : IClockState(), controller(controller), panel(panel) {
    wxASSERT(controller != nullptr);
    wxASSERT(panel != nullptr);
}
