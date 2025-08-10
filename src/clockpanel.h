#ifndef CLOCKPANEL_H
#define CLOCKPANEL_H

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include <iostream>

#include "iclockcontroller.h"

class ClockPanel : public wxPanel {
   public:
    explicit ClockPanel(IClockController *controller, wxPanel *parent);
    // void SetController(wxEvtHandler *controller);
    // wxPanel *getContainer();
    int GetSelectColumnWidth();
    int GetTitleColumnWidth();

   private:
    IClockController *parentController = NULL;
    // wxPanel *containerPanel;
    // void Chumma();
    wxPanel *cellSelect, *cellTitle, *cellReport = nullptr;
    wxPanel *titleDisplay = nullptr;
    wxString titleText =
        "TimerTimerTimerTimerTimerTimerTimerTimerTimerTimerTimerTimerTimerTime"
        "r";
    wxBoxSizer *sizer = nullptr;
    wxCheckBox *checkboxSelect = nullptr;
    wxCheckBox *checkboxReport = nullptr;
    void OnTitlePaint(wxPaintEvent &event);
};

#endif