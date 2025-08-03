// wxWidgets "Hello World" Program

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "controller.h"

class MyApp : public wxApp {
   private:
    Controller *controller = NULL;

   public:
    virtual bool OnInit();
    virtual int OnExit();
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
    // MyFrame *frame = new MyFrame();
    // frame->Show(true);
    controller = new Controller();

    return true;
}

int MyApp::OnExit() {
    delete controller;
    return wxApp::OnExit();
}