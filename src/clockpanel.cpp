#include "clockpanel.h"

ClockPanel::ClockPanel(IClockController *controller, wxPanel *parent)
    : wxPanel(parent) {
    wxBoxSizer *hs = new wxBoxSizer(wxHORIZONTAL);

    SetSizer(hs);
    wxPanel *cellTitle = new wxPanel(this);
    wxButton *button = new wxButton(this, wxID_ANY, "Click Me",
                                    wxDefaultPosition, wxSize(100, 30));
    wxColour lightBlue(200, 220, 255);
    cellTitle->SetBackgroundColour(lightBlue);
    cellTitle->SetMinClientSize(wxSize(10, 10));
    cellTitle->Refresh();
    hs->Add(cellTitle, 1, wxRIGHT | wxEXPAND, 10);
    hs->Add(button, 0, wxRIGHT, 10);
    hs->Layout();
}