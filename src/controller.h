#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <iostream>

#include "frame.h"

class Controller : wxEvtHandler {
   private:
    TopFrame *frame;
    // wxFrame *frame;

   public:
    Controller();   // Constructor declaration
    ~Controller();  // Destructor declaration
    void OnGreeting(const wxCommandEvent &event);
    void OnExit(const wxCommandEvent &event);
    void OnNewTimer(const wxCommandEvent &event);

    // void run();  // Example method declaration
};

#endif  // CONTROLLER_H