#pragma once

class ITimerObserver {
public:
    virtual ~ITimerObserver() = default;
    virtual void OnTimerTick(long milliseconds) = 0;
};

