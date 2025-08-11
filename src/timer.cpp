#include "timer.h"

// #include <algorithm>

Timer& Timer::GetInstance() {
    static Timer instance;
    return instance;
}

Timer::Timer() : timer(this) { Bind(wxEVT_TIMER, &Timer::OnTimer, this); }

Timer::~Timer() {
    Stop();
    timer.Unbind(wxEVT_TIMER, &Timer::OnTimer, this);
}

void Timer::Start(int intervalMs) {
    if (!timer.IsRunning() && !observers.empty()) {
        std::cout << "Timer started\n";
        stopwatch.Start();
        auto started = timer.Start(intervalMs);
        std::cout << "timer.Start returned " << started << "\n";
    }
}

void Timer::Stop() {
    if (timer.IsRunning()) {
        timer.Stop();
    }
    stopwatch.Pause();
}

bool Timer::IsRunning() const { return timer.IsRunning(); }

void Timer::AddObserver(ITimerObserver* observer) {
    std::cout << "Inside addObserver\n";
    if (observer && std::find(observers.begin(), observers.end(), observer) ==
                        observers.end()) {
        observers.push_back(observer);
    }

    if (!IsRunning()) {
        Start();  // Start timer if at least one observer exists now
    }
}

void Timer::RemoveObserver(ITimerObserver* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer),
                    observers.end());

    if (observers.empty()) {
        Stop();  // No observers left — stop the timer
    }
}

void Timer::OnTimer(wxTimerEvent& event) {
    std::cout << "Inside OnTimer\n";
    if (observers.empty()) {
        Stop();
        return;
    }

    long elapsedMs = stopwatch.Time();

    for (ITimerObserver* observer : observers) {
        if (observer) {
            observer->OnTimerTick(elapsedMs);
        }
    }
}
