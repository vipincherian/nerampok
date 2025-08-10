#include "stoppedclock.h"

StoppedClock::StoppedClock(IClockContext *controller, ClockPanel *panel)
    : IClockState(), controller(controller), panel(panel) {
    wxASSERT(controller != nullptr);
    wxASSERT(panel != nullptr);
}

void StoppedClock::Play() {
    std::cout << "Starting clock.\n";
    // Transition to PlayingState
    controller->ChangeStateToPlaying();
}

void StoppedClock::Enter() {
    wxASSERT(panel != nullptr);
    panel->ShowPlayButton();
    panel->EnablePlayButton();
    panel->DisableStopButton();
    panel->DisableFixButton();
    panel->EnableEditButton();
}