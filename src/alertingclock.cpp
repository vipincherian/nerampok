#include "alertingclock.h"

AlertingClock::AlertingClock(IClockContext *controller, ClockPanel *panel,
                             TickCounter *ticks)
    : IClockState(), controller(controller), panel(panel), ticks(ticks) {
    wxASSERT(controller != nullptr);
    wxASSERT(panel != nullptr);
    wxASSERT(ticks != nullptr);
}
