#include "alertingclock.h"

AlertingClock::AlertingClock(IClockContext *controller, ClockPanel *panel)
    : IClockState(), controller(controller), panel(panel) {
    wxASSERT(controller != nullptr);
    wxASSERT(panel != nullptr);
}
