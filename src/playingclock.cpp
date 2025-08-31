#include "playingclock.h"

PlayingClock::PlayingClock(IClockContext *controller, ClockPanel *panel,
                           TickCounter *ticks)
    : IClockState(), controller(controller), panel(panel), ticks(ticks) {
    wxASSERT(controller != nullptr);
    wxASSERT(panel != nullptr);
    wxASSERT(ticks != nullptr);
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
    controller->StopTimerSubscription();
}
void PlayingClock::InterimUpdate(long milliseconds) {
    std::cout << "Interim update" << milliseconds << "\n";
}