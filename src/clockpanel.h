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
    int GetControlsColumnWidth();
    int GetReportColumnWidth();
    void EnableStopButton();
    void DisableStopButton();
    void EnableFixButton();
    void DisableFixButton();
    void EnableEditButton();
    void DisableEditButton();
    void EnablePlayButton();
    void DisablePlayButton();
    void ShowPlayButton();
    void ShowPauseButton();

   private:
    IClockController *parentController = NULL;
    // wxPanel *containerPanel;
    // void Chumma();
    wxPanel *cellSelect, *cellTitle, *cellControls, *cellReport = nullptr;
    wxPanel *titleDisplay = nullptr;
    wxPanel *countdownDisplay = nullptr;
    wxString titleText =
        "TimerTimerTimerTimerTimerTimerTimerTimerTimerTimerTimerTimerTimerTime"
        "r";
    wxBoxSizer *sizer = nullptr;
    wxCheckBox *checkboxSelect = nullptr;
    wxCheckBox *checkboxReport = nullptr;
    wxBitmapButton *buttonEdit = nullptr;
    wxBitmapButton *buttonStart = nullptr;
    wxBitmapButton *buttonStop = nullptr;
    wxBitmapButton *buttonFix = nullptr;
    wxCoord widestRepeatedDigitExtent = 0;
    wxCoord timeSeparatorExtent = 0;

    void OnTitlePaint(const wxPaintEvent &event);
    void OnCountdownPaint(const wxPaintEvent &event);
    void OnPlayButtonClick(const wxCommandEvent &event);
    void OnStopButtonClick(const wxCommandEvent &event);
    wxCoord FindWidestRepeatedDigitExtent();
    wxCoord FindTimeSeparatorExtent();
};

#endif