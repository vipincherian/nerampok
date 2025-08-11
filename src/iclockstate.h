#ifndef ICLOCKSTATE_H
#define ICLOCKSTATE_H

class IClockContext {
   public:
    // Virtual destructor to ensure proper cleanup
    virtual ~IClockContext() = default;

    // Pure virtual methods
    virtual void ChangeStateToStopped() = 0;
    virtual void ChangeStateToPlaying() = 0;
    virtual void ChangeStateToPaused() = 0;
    virtual void ChangeStateToAlerting() = 0;
    virtual void StartTimerSubscription() = 0;
    virtual void StopTimerSubscription() = 0;
};

class IClockState {
   public:
    // Virtual destructor to ensure proper cleanup
    virtual ~IClockState() = default;

    // Pure virtual methods
    virtual void Play() = 0;
    virtual void Pause() = 0;
    virtual void Stop() = 0;
    virtual void Enter() = 0;
    virtual void Exit() = 0;
};

#endif  // ICLOCKSTATE_H