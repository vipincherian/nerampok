#ifndef ICLOCKMEDIATOR_H
#define ICLOCKMEDIATOR_H

class IClockMediator {
   public:
    // Virtual destructor to ensure proper cleanup
    virtual ~IClockMediator() = default;

    // Pure virtual methods
    virtual void ReportClock() = 0;
};

#endif  // ICLOCKMEDIATOR_H