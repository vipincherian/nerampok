#include "clockpanel.h"

#include <wx/dcbuffer.h>

#include "artprovider.h"
#include "constants.h"
#include "preferencesreader.h"

ClockPanel::ClockPanel(IClockController *controller, wxPanel *parent)
    : wxPanel(parent), parentController(controller) {
    sizer = new wxBoxSizer(wxHORIZONTAL);
    SetSizer(sizer);

    // Create the panel for the select checkbox

    cellSelect = new wxPanel(this);
    wxBoxSizer *sizerSelect = new wxBoxSizer(wxHORIZONTAL);
    checkboxSelect = new wxCheckBox(cellSelect, wxID_ANY, "");
    sizerSelect->Add(checkboxSelect, 0, wxLEFT | wxRIGHT | wxEXPAND,
                     Constants::getInstance().getBorder());
    cellSelect->SetSizer(sizerSelect);
    sizerSelect->Layout();

    // Create the panel for title

    cellTitle = new wxPanel(this);
    wxBoxSizer *sizerTitle = new wxBoxSizer(wxHORIZONTAL);
    // wxColour lightBlue(200, 220, 255);
    // cellTitle->SetBackgroundColour(lightBlue);
    // cellTitle->SetMinClientSize(wxSize(100, wxDefaultSize.GetHeight()));
    // wxButton *buttonEdit = new wxButton(cellTitle, wxID_ANY, "Edit",
    // wxDefaultPosition, wxDefaultSize);
    buttonEdit = new wxBitmapButton(
        cellTitle, wxID_ANY,
        wxArtProvider::GetBitmap("CLOCK_EDIT", wxART_OTHER, wxSize(24, 24)),
        wxDefaultPosition, wxDefaultSize);
    // buttonEdit->Disable();
    titleDisplay = new wxPanel(cellTitle, wxID_ANY, wxDefaultPosition,
                               wxDefaultSize, wxBORDER_SUNKEN);
    sizerTitle->Add(buttonEdit, 0, wxLEFT | wxEXPAND);
    // wxColour lightCol(250, 0, 255);
    // titleDisplay->SetBackgroundColour(lightCol);
    titleDisplay->SetBackgroundStyle(wxBG_STYLE_PAINT);
    titleDisplay->Bind(wxEVT_PAINT, &ClockPanel::OnTitlePaint, this);
    sizerTitle->Add(titleDisplay, 1, wxLEFT | wxRIGHT | wxEXPAND,
                    PreferencesReader::getInstance().getBorder());
    cellTitle->SetSizer(sizerTitle);
    sizerTitle->Layout();

    // Panel for controls

    cellControls = new wxPanel(this);
    wxBoxSizer *hsControls = new wxBoxSizer(wxHORIZONTAL);

    buttonStart = new wxBitmapButton(
        cellControls, wxID_ANY,
        wxArtProvider::GetBitmap("CLOCK_START", wxART_OTHER, wxSize(24, 24)),
        wxDefaultPosition, wxDefaultSize);
    buttonStop = new wxBitmapButton(
        cellControls, wxID_ANY,
        wxArtProvider::GetBitmap("CLOCK_STOP", wxART_OTHER, wxSize(24, 24)),
        wxDefaultPosition, wxDefaultSize);
    buttonFix = new wxBitmapButton(
        cellControls, wxID_ANY,
        wxArtProvider::GetBitmap("CLOCK_FIX", wxART_OTHER, wxSize(24, 24)),
        wxDefaultPosition, wxDefaultSize);
    // wxButton *buttonStop = new wxButton(cellControls, wxID_ANY, "Stop",
    // wxDefaultPosition, wxDefaultSize);

    hsControls->Add(buttonStart, 0, wxLEFT | wxEXPAND,
                    wxSizerFlags::GetDefaultBorder());
    hsControls->Add(buttonStop, 0, wxLEFT | wxEXPAND,
                    wxSizerFlags::GetDefaultBorder());
    hsControls->Add(buttonFix, 0, wxLEFT | wxEXPAND,
                    wxSizerFlags::GetDefaultBorder());
    cellControls->SetSizer(hsControls);
    hsControls->Layout();
    buttonStart->Bind(wxEVT_BUTTON, &ClockPanel::OnPlayButtonClick, this);

    // Panel for report
    cellReport = new wxPanel(this);
    wxBoxSizer *sizerReport = new wxBoxSizer(wxHORIZONTAL);
    checkboxReport = new wxCheckBox(cellReport, wxID_ANY, "");
    sizerReport->Add(checkboxReport, 0, wxLEFT | wxRIGHT | wxEXPAND,
                     Constants::getInstance().getBorder());
    cellReport->SetSizer(sizerReport);
    sizerReport->Layout();

    // cellSelect->SetClientSize(wxSize(200, 100));
    sizer->Add(cellSelect, 0, wxLEFT | wxEXPAND,
               wxSizerFlags::GetDefaultBorder());
    sizer->Add(cellTitle, 1, wxLEFT | wxEXPAND,
               wxSizerFlags::GetDefaultBorder());
    sizer->Add(cellControls, 0, wxLEFT | wxEXPAND,
               wxSizerFlags::GetDefaultBorder());
    sizer->Add(cellReport, 0, wxLEFT | wxEXPAND,
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
    return PreferencesReader::getInstance().getBorder() +
           cellTitle->GetSize().GetWidth();
}

int ClockPanel::GetControlsColumnWidth() {
    return (2 * PreferencesReader::getInstance().getBorder()) +
           cellControls->GetSize().GetWidth();
}

int ClockPanel::GetReportColumnWidth() {
    return (2 * PreferencesReader::getInstance().getBorder()) +
           cellReport->GetSize().GetWidth();
}

void ClockPanel ::OnTitlePaint(const wxPaintEvent &event) {
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

void ClockPanel::EnableStopButton() { buttonStop->Enable(); }
void ClockPanel::DisableStopButton() { buttonStop->Disable(); }
void ClockPanel::EnableFixButton() { buttonFix->Enable(); }
void ClockPanel::DisableFixButton() { buttonFix->Disable(); }
void ClockPanel::EnableEditButton() { buttonEdit->Enable(); }
void ClockPanel::DisableEditButton() { buttonEdit->Disable(); }
void ClockPanel::OnPlayButtonClick(const wxCommandEvent &event) {
    std::cout << "clicked\n";
    wxASSERT(parentController != nullptr);
    parentController->Play();
}