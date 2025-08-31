#include "tickcounter.h"

inline void TickCounter::SetLastUpdatedAt(long currentTicks) {
    at = currentTicks;
    wxASSERT(at >= 0);
    wxASSERT(pending >= 0);
}
inline void TickCounter::SetPending(long currentTicks) {
    pending = currentTicks;
    wxASSERT(at >= 0);
    wxASSERT(pending >= 0);
}
inline void TickCounter::Update(long currentTickCount) {
    wxASSERT(currentTickCount >= at);
    long diff = at - currentTickCount;
    if (pending > diff) {
        pending -= diff;
    } else {
        pending = 0;
    }
    wxASSERT(at >= 0);
    wxASSERT(pending >= 0);
}