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
    unsigned long long usedCockIds = 0;
    std::unordered_map<int, ClockController *> clocks;
    // wxFrame *frame;

   public:
    Controller();   // Constructor declaration
    ~Controller();  // Destructor declaration
    // void OnGreeting(const wxCommandEvent &event);
    // void OnExit(const wxCommandEvent &event);
    // void OnNewTimer(const wxCommandEvent &event);
    // void OnFrameClose(wxCloseEvent &event);
    void Quit();
    void AddClock();
    void CleanUp();
    void ReportClock();
    int getSmallestAvailableCockId();
    void AddToUsedClockIds(int idToAdd);
    // void run();  // Example method declaration
};

#endif  // CONTROLLER_H