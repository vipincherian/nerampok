#pragma once

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <iostream>

class TickCounter {
   public:
    TickCounter() {};
    ~TickCounter() {};
    inline void SetLastUpdatedAt(long at);
    inline void SetPending(long pending);
    inline void Update(long at);

   private:
    long at, pending = 0;
};