#include "clockpanel.h"

ClockPanel::ClockPanel(IClockController *controller, wxPanel *parent)
    : wxPanel(parent) {
    sizer = new wxBoxSizer(wxHORIZONTAL);

    SetSizer(sizer);
    cellSelect = new wxPanel(this);
    wxBoxSizer *hsSelect = new wxBoxSizer(wxHORIZONTAL);
    wxCheckBox *checkboxSelect = new wxCheckBox(cellSelect, wxID_ANY, "");
    // checkboxSelect->SetMinClientSize(wxSize(100, wxDefaultSize.GetHeight()));
    // cellSelect->SetMinClientSize(wxSize(100, wxDefaultSize.GetHeight()));
    hsSelect->Add(checkboxSelect, 0, wxLEFT | wxEXPAND, 10);
    cellSelect->SetSizer(hsSelect);
    hsSelect->Layout();

    wxPanel *cellTitle = new wxPanel(this);
    wxColour lightBlue(200, 220, 255);
    cellTitle->SetBackgroundColour(lightBlue);
    // cellTitle->SetMinClientSize(wxSize(100, wxDefaultSize.GetHeight()));
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
    sizer->Add(cellSelect, 0, wxLEFT | wxEXPAND, 10);
    sizer->Add(cellTitle, 1, wxLEFT | wxEXPAND, 10);
    sizer->Add(cellControls, 0, wxLEFT | wxEXPAND, 10);
    sizer->Layout();
}

int ClockPanel::GetSelectCellWidth() {
    return sizer->GetPosition().x + cellSelect->GetPosition().x +
           cellSelect->GetSize().GetWidth();
}