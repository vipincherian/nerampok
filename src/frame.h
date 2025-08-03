#ifndef FRAME_H
#define FRAME_H

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include <iostream>

wxDECLARE_EVENT(FRAME_GREET_EVENT, wxCommandEvent);

class MyFrame : public wxFrame {
   public:
    MyFrame(wxEvtHandler *controller);
    // void SetController(wxEvtHandler *controller);

   private:
    wxEvtHandler *parentController = NULL;
    // wxPanel *containerPanel;
    void OnHello(const wxCommandEvent &event);
    void OnExit(const wxCommandEvent &event);
    void OnAbout(const wxCommandEvent &event);
    void OnButtonClick(const wxCommandEvent &event);
};

#endif