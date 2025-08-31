#include "pausedclock.h"

PausedClock::PausedClock(IClockContext *controller, ClockPanel *panel,
                         TickCounter *ticks)
    : IClockState(), controller(controller), panel(panel), ticks(ticks) {
    wxASSERT(controller != nullptr);
    wxASSERT(panel != nullptr);
    wxASSERT(ticks != nullptr);
}

void PausedClock::Enter() {
    wxASSERT(panel != nullptr);
    panel->EnableStopButton();
    panel->DisableFixButton();
    panel->DisableEditButton();
    panel->ShowPlayButton();
}
void PausedClock::Play() {
    std::cout << "Restarting clock\n";
    controller->ChangeStateToPlaying();
}
void PausedClock::Stop() {
    std::cout << "Stopping clock\n";
    controller->ChangeStateToStopped();
}