#include "stoppedclock.h"

StoppedClock::StoppedClock(IClockController *controller, ClockPanel *panel)
    : IClockState(), controller(controller), panel(panel) {
    wxASSERT(controller != nullptr);
    wxASSERT(panel != nullptr);
}

void StoppedClock::Enter() {
    wxASSERT(panel != nullptr);
    panel->DisableStopButton();
    panel->DisableFixButton();
}