#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <iostream>
#include <map>

#include "clockcontroller.h"
#include "frame.h"
#include "iclockmediator.h"
#include "icontroller.h"
#include "preferences.h"

class Controller : IController, IClockMediator {
   private:
    TopFrame *frame;
    Preferences preferences;
    unsigned long long usedClockIds = 0;
    std::unordered_map<int, ClockController *> clocks;
    // wxFrame *frame;

   public:
    Controller();            // Constructor declaration
    ~Controller() override;  // Destructor declaration
    // Explicitly delete the copy constructor and copy assignment operator
    // to prevent cloning.
    Controller &operator=(const Controller *) = delete;
    Controller(const Controller &) = delete;
    // void OnGreeting(const wxCommandEvent &event);
    // void OnExit(const wxCommandEvent &event);
    // void OnNewTimer(const wxCommandEvent &event);
    // void OnFrameClose(wxCloseEvent &event);
    void Quit() override;
    void AddClock() override;
    void CleanUp() override;
    void ReportClock() override;
    int getSmallestAvailableCockId();
    void AddToUsedClockIds(int idToAdd);
    void ResizeHeaderColumns();
    // void run();  // Example method declaration
};

#endif  // CONTROLLER_H