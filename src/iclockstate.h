#ifndef ICLOCKSTATE_H
#define ICLOCKSTATE_H

class IClockState {
   public:
    // Virtual destructor to ensure proper cleanup
    virtual ~IClockState() = default;

    // Pure virtual methods
    virtual void Play() = 0;
    virtual void Pause() = 0;
    virtual void Stop() = 0;
};

#endif  // ICLOCKSTATE_H