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
    // TODO: Make these inline?
    void SetLastUpdatedAt(long at);
    void SetPending(long pending);
    void Update(long at);
    long GetLastUpdatedAt();
    long GetPending();

   private:
    long at, pending = 0;
};