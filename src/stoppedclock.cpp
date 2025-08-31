#include "stoppedclock.h"

#include "timer.h"

StoppedClock::StoppedClock(IClockContext *controller, ClockPanel *panel,
                           TickCounter *ticks)
    : IClockState(), controller(controller), panel(panel), ticks(ticks) {
    wxASSERT(controller != nullptr);
    wxASSERT(panel != nullptr);
    wxASSERT(ticks != nullptr);
}

void StoppedClock::Play() {
    std::cout << "Starting clock.\n";

    // Transition to PlayingState
    controller->ChangeStateToPlaying();
    controller->StartTimerSubscription();
}

void StoppedClock::Enter() {
    wxASSERT(panel != nullptr);
    panel->ShowPlayButton();
    panel->EnablePlayButton();
    panel->DisableStopButton();
    panel->DisableFixButton();
    panel->EnableEditButton();
}