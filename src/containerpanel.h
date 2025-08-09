#ifndef CONTAINERPANEL_H
#define CONTAINERPANEL_H

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include <wx/headercol.h>
#include <wx/headerctrl.h>  // Include for wxHeaderCtrl

#include <iostream>

#include "clockpanel.h"
#include "iclockcontroller.h"
#include "icontroller.h"

class ContainerPanel : public wxPanel {
   public:
    explicit ContainerPanel(IController *controller, wxFrame *parent);
    // void SetController(wxEvtHandler *controller);
    // wxPanel *getContainer();
    ClockPanel *AddClockPanel(IClockController *parentController);

   private:
    IController *parentController = NULL;
    // wxPanel *containerPanel;
    // void Chumma();
    // wxBoxSizer *sizer = nullptr;
    wxHeaderCtrlSimple *header = nullptr;
    wxHeaderColumnSimple *headerColSelect = nullptr;
    wxHeaderColumnSimple *headerColTitle = nullptr;
    wxHeaderColumnSimple *headerColDuration = nullptr;
    wxHeaderColumnSimple *headerColControls = nullptr;
};

#endif