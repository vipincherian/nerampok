#include "playingclock.h"

PlayingClock::PlayingClock(IClockContext *controller, ClockPanel *panel)
    : IClockState(), controller(controller), panel(panel) {
    wxASSERT(controller != nullptr);
    wxASSERT(panel != nullptr);
}

void PlayingClock::Enter() {
    wxASSERT(panel != nullptr);
    panel->EnableStopButton();
    panel->EnableFixButton();
    panel->DisableEditButton();
    panel->ShowPauseButton();
}
void PlayingClock::Play() {
    std::cout << "Pausing clock\n";
    controller->ChangeStateToPaused();
}
void PlayingClock::Stop() {
    std::cout << "Stopping clock\n";
    controller->ChangeStateToStopped();
}