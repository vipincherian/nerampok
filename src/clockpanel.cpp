#include "clockpanel.h"

ClockPanel::ClockPanel(IClockController *controller, wxPanel *parent)
    : wxPanel(parent) {
    wxBoxSizer *hs = new wxBoxSizer(wxHORIZONTAL);

    SetSizer(hs);
    wxPanel *cellSelect = new wxPanel(this);
    wxBoxSizer *hsSelect = new wxBoxSizer(wxHORIZONTAL);
    wxCheckBox *checkboxSelect = new wxCheckBox(cellSelect, wxID_ANY, "");
    checkboxSelect->SetMinClientSize(wxSize(100, 10));
    hsSelect->Add(checkboxSelect, 0, wxLEFT | wxEXPAND, 10);
    cellSelect->SetSizer(hsSelect);
    hsSelect->Layout();

    wxPanel *cellTitle = new wxPanel(this);
    wxColour lightBlue(200, 220, 255);
    cellTitle->SetBackgroundColour(lightBlue);
    cellTitle->SetMinClientSize(wxSize(100, 10));
    cellTitle->Refresh();

    wxPanel *cellControls = new wxPanel(this);
    wxBoxSizer *hsControls = new wxBoxSizer(wxHORIZONTAL);

    wxButton *buttonStart = new wxButton(cellControls, wxID_ANY, "Start",
                                         wxDefaultPosition, wxDefaultSize);
    wxButton *buttonStop = new wxButton(cellControls, wxID_ANY, "Stop",
                                        wxDefaultPosition, wxDefaultSize);

    hsControls->Add(buttonStart, 0, wxLEFT | wxEXPAND, 10);
    hsControls->Add(buttonStop, 0, wxLEFT | wxEXPAND, 10);
    cellControls->SetSizer(hsControls);
    hsControls->Layout();

    cellSelect->SetClientSize(wxSize(200, 100));
    hs->Add(cellSelect, 0, wxLEFT | wxEXPAND, 10);
    hs->Add(cellTitle, 1, wxLEFT | wxEXPAND, 10);
    hs->Add(cellControls, 0, wxLEFT | wxEXPAND, 10);
    hs->Layout();
}