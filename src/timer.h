#pragma once

#include <wx/stopwatch.h>
#include <wx/timer.h>

#include <iostream>
// #include <vector>

#include "itimerobserver.h"

WX_DECLARE_LIST(ITimerObserver, TimerObserverList);

class Timer : public wxEvtHandler {
   public:
    static Timer& GetInstance();

    void Start(int intervalMs = 100);  // Default to 1 second
    void Stop();
    bool IsRunning() const;

    void AddObserver(ITimerObserver* observer);
    void RemoveObserver(ITimerObserver* observer);
    long GetTickCount();

   private:
    Timer();  // Private constructor for singleton
    ~Timer();
    Timer(const Timer&) = delete;
    Timer& operator=(const Timer&) = delete;

    void OnTimer(wxTimerEvent& event);

    wxTimer timer;
    wxStopWatch stopwatch;
    // std::vector<ITimerObserver*> observers;
    TimerObserverList observers;
};