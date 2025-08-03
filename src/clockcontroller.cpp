#include "clockcontroller.h"

// We assume that the IClockMediator header is available.
#include "iclockmediator.h"

/**
 * @brief Constructs a ClockController with a reference to a mediator.
 * @param mediator A reference to an IClockMediator object.
 */
ClockController::ClockController(IClockMediator& mediator)
    : m_mediator(mediator) {
    // The constructor is empty as the member variable is initialized in the
    // initializer list.
}
