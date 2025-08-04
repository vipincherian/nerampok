#ifndef FRAME_H
#define FRAME_H

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include <wx/headercol.h>
#include <wx/headerctrl.h>  // Include for wxHeaderCtrl

#include <iostream>

#include "icontroller.h"

wxDECLARE_EVENT(FRAME_GREET_EVENT, wxCommandEvent);

class TopFrame : public wxFrame {
   public:
    explicit TopFrame(IController *controller);
    // void SetController(wxEvtHandler *controller);
    wxPanel *getContainer();

   private:
    IController *parentController = NULL;
    wxPanel *containerPanel = nullptr;

    // wxPanel *containerPanel;
    wxHeaderCtrlSimple *header = nullptr;
    wxHeaderColumnSimple *headerColSelect = nullptr;
    wxHeaderColumnSimple *headerColTitle = nullptr;
    wxHeaderColumnSimple *headerColDuration = nullptr;
    wxHeaderColumnSimple *headerColControls = nullptr;

    void OnNewTimer(const wxCommandEvent &event);
    void OnExit(const wxCommandEvent &event);
    void OnAbout(const wxCommandEvent &event);
    void OnButtonClick(const wxCommandEvent &event);
    void OnFrameClose(wxCloseEvent &event);
    void OnShow(wxShowEvent &event);
};

#endif