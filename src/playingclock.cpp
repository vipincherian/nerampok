#include "playingclock.h"

PlayingClock::PlayingClock(IClockContext *controller, ClockPanel *panel)
    : IClockState(), controller(controller), panel(panel) {
    wxASSERT(controller != nullptr);
    wxASSERT(panel != nullptr);
}

void PlayingClock::Enter() {
    wxASSERT(panel != nullptr);
    panel->EnableFixButton();
    panel->DisableEditButton();
}