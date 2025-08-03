#ifndef ICONTROLLER_H
#define ICONTROLLER_H

class IController {
   public:
    // Virtual destructor to ensure proper cleanup
    virtual ~IController() = default;

    // Pure virtual methods
    virtual void Quit() = 0;
    virtual void AddClock() = 0;
    virtual void CleanUp() = 0;
};

#endif  // ICONTROLLER_H