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
    wxPanel *getContainer();

   private:
    IClockController *parentController = NULL;
    // wxPanel *containerPanel;
    // void Chumma();
};

#endif