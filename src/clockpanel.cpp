#include "clockpanel.h"

#include <wx/dcbuffer.h>

#include "constants.h"
#include "preferencesreader.h"

ClockPanel::ClockPanel(IClockController *controller, wxPanel *parent)
    : wxPanel(parent) {
    sizer = new wxBoxSizer(wxHORIZONTAL);

    SetSizer(sizer);
    cellSelect = new wxPanel(this);
    wxBoxSizer *sizerSelect = new wxBoxSizer(wxHORIZONTAL);
    checkboxSelect = new wxCheckBox(cellSelect, wxID_ANY, "");
    // checkboxSelect->SetMinClientSize(wxSize(100, wxDefaultSize.GetHeight()));
    // cellSelect->SetMinClientSize(wxSize(100, wxDefaultSize.GetHeight()));
    sizerSelect->Add(checkboxSelect, 0, wxLEFT | wxRIGHT | wxEXPAND,
                     //   wxSizerFlags::GetDefaultBorder());
                     Constants::getInstance().getBorder());
    cellSelect->SetSizer(sizerSelect);
    sizerSelect->Layout();

    cellTitle = new wxPanel(this);
    wxBoxSizer *sizerTitle = new wxBoxSizer(wxHORIZONTAL);
    // wxColour lightBlue(200, 220, 255);
    // cellTitle->SetBackgroundColour(lightBlue);
    // cellTitle->SetMinClientSize(wxSize(100, wxDefaultSize.GetHeight()));

    titleDisplay = new wxPanel(cellTitle, wxID_ANY, wxDefaultPosition,
                               wxDefaultSize, wxBORDER_SUNKEN);
    // wxColour lightCol(250, 0, 255);
    // titleDisplay->SetBackgroundColour(lightCol);
    titleDisplay->SetBackgroundStyle(wxBG_STYLE_PAINT);
    titleDisplay->Bind(wxEVT_PAINT, &ClockPanel::OnTitlePaint, this);
    sizerTitle->Add(titleDisplay, 1, wxLEFT | wxRIGHT | wxEXPAND,
                    PreferencesReader::getInstance().getBorder());

    cellTitle->SetSizer(sizerTitle);
    sizerTitle->Layout();

    wxPanel *cellControls = new wxPanel(this);
    wxBoxSizer *hsControls = new wxBoxSizer(wxHORIZONTAL);

    wxButton *buttonStart = new wxButton(cellControls, wxID_ANY, "Start",
                                         wxDefaultPosition, wxDefaultSize);
    wxButton *buttonStop = new wxButton(cellControls, wxID_ANY, "Stop",
                                        wxDefaultPosition, wxDefaultSize);

    hsControls->Add(buttonStart, 0, wxLEFT | wxEXPAND,
                    wxSizerFlags::GetDefaultBorder());
    hsControls->Add(buttonStop, 0, wxLEFT | wxEXPAND,
                    wxSizerFlags::GetDefaultBorder());
    cellControls->SetSizer(hsControls);
    hsControls->Layout();

    cellSelect->SetClientSize(wxSize(200, 100));
    sizer->Add(cellSelect, 0, wxLEFT | wxEXPAND,
               wxSizerFlags::GetDefaultBorder());
    sizer->Add(cellTitle, 1, wxLEFT | wxEXPAND,
               wxSizerFlags::GetDefaultBorder());
    sizer->Add(cellControls, 0, wxLEFT | wxEXPAND,
               wxSizerFlags::GetDefaultBorder());
    sizer->Layout();
}

int ClockPanel::GetSelectColumnWidth() {
    // return GetPosition().x + cellSelect->GetPosition().x +
    //    cellSelect->GetSize().GetWidth();
    return PreferencesReader::getInstance().getBorder() +
           cellSelect->GetSize().GetWidth();
}

int ClockPanel::GetTitleColumnWidth() {
    return (2 * PreferencesReader::getInstance().getBorder()) +
           cellTitle->GetSize().GetWidth();
}

void ClockPanel ::OnTitlePaint(wxPaintEvent &event) {
    wxAutoBufferedPaintDC dc(titleDisplay);
    dc.Clear();

    wxRect rect = titleDisplay->GetClientRect();

    dc.SetFont(GetFont());
    dc.SetBackgroundMode(wxBRUSHSTYLE_TRANSPARENT);

    // Determine text size
    wxCoord textW, textH;
    dc.GetTextExtent(titleText, &textW, &textH);

    int x = rect.x + PreferencesReader::getInstance().getBorder();  // Left edge
    int y = rect.y + (rect.height - textH) / 2;  // Vertically centered

    dc.DrawText(titleText, x, y);
}