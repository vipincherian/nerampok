#ifndef ICLOCKCONTROLLER_H
#define ICLOCKCONTROLLER_H

class IClockController {
   public:
    // Virtual destructor to ensure proper cleanup
    virtual ~IClockController() = default;

    // Pure virtual methods
    // virtual void Chumma() = 0;
    virtual void Play() = 0;
    virtual void Stop() = 0;
};

#endif  // ICONTROLLER_H