#include "clockcontroller.h"

// We assume that the IClockMediator header is available.
#include "iclockmediator.h"

/**
 * @brief Constructs a ClockController with a reference to a mediator.
 * @param mediator A reference to an IClockMediator object.
 */
ClockController::ClockController(IClockMediator *mediator,
                                 ContainerPanel *continer, int id)
    : IClockController(),
      IClockContext(),
      clockMediator(mediator),
      container(continer) {
    // The constructor is empty as the member variable is initialized in the
    // initializer list.
    wxASSERT(id >= 0);
    this->id = id;
    // clockPanel = new ClockPanel(this, container);
    // TODO: Controller should not go GUI. Move this to TopFrame
    // container->GetSizer()->Add(clockPanel, 0, wxTOP | wxEXPAND, 10);
    // container->GetSizer()->Layout();
    clockPanel = container->AddClockPanel(this);
    wxASSERT(clockPanel != nullptr);

    stoppedClock = new StoppedClock(this, clockPanel);
    playingClock = new PlayingClock(this, clockPanel);
    pausedClock = new PausedClock(this, clockPanel);
    alertingClock = new AlertingClock(this, clockPanel);

    ChangeStateToStopped();
}
ClockController::~ClockController() {
    std::cout << "Inside ~ClockController\n";
    wxASSERT(stoppedClock != nullptr);
    delete stoppedClock;
    wxASSERT(playingClock != nullptr);
    delete playingClock;
    wxASSERT(pausedClock != nullptr);
    delete pausedClock;
    wxASSERT(alertingClock != nullptr);
    delete alertingClock;
}

void ClockController::ChangeStateToStopped() {
    if (clock != nullptr) clock->Exit();
    wxASSERT(stoppedClock);
    clock = stoppedClock;
    clock->Enter();
}
void ClockController::ChangeStateToPlaying() {
    if (clock != nullptr) clock->Exit();
    wxASSERT(playingClock);
    clock = playingClock;
    clock->Enter();
}
void ClockController::ChangeStateToPaused() {
    if (clock != nullptr) clock->Exit();
    wxASSERT(pausedClock);
    clock = pausedClock;
    clock->Enter();
}
void ClockController::ChangeStateToAlerting() {
    if (clock != nullptr) clock->Exit();
    wxASSERT(alertingClock);
    clock = alertingClock;
    clock->Enter();
}
void ClockController::Play() { clock->Play(); }
void ClockController::Stop() { clock->Stop(); }