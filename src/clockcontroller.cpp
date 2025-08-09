#include "clockcontroller.h"

// We assume that the IClockMediator header is available.
#include "iclockmediator.h"

/**
 * @brief Constructs a ClockController with a reference to a mediator.
 * @param mediator A reference to an IClockMediator object.
 */
ClockController::ClockController(IClockMediator *mediator,
                                 ContainerPanel *continer, int id)
    : IClockController(), clockMediator(mediator), container(continer) {
    // The constructor is empty as the member variable is initialized in the
    // initializer list.
    this->id = id;
    // clockPanel = new ClockPanel(this, container);
    // TODO: Controller should not go GUI. Move this to TopFrame
    // container->GetSizer()->Add(clockPanel, 0, wxTOP | wxEXPAND, 10);
    // container->GetSizer()->Layout();
    clockPanel = container->AddClockPanel(this);
}
