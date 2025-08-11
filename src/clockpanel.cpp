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
    sizerTitle->Add(buttonEdit, 0, wxLEFT | wxEXPAND);
    titleDisplay = new wxPanel(cellTitle, wxID_ANY, wxDefaultPosition,
                               wxDefaultSize, wxBORDER_SUNKEN);
    // wxColour lightCol(250, 0, 255);
    // titleDisplay->SetBackgroundColour(lightCol);
    titleDisplay->SetBackgroundStyle(wxBG_STYLE_PAINT);
    titleDisplay->Bind(wxEVT_PAINT, &ClockPanel::OnTitlePaint, this);
    countdownDisplay = new wxPanel(cellTitle, wxID_ANY, wxDefaultPosition,
                                   wxDefaultSize, wxBORDER_SUNKEN);
    countdownDisplay->SetBackgroundStyle(wxBG_STYLE_PAINT);

    widestRepeatedDigitExtent = FindWidestRepeatedDigitExtent();
    timeSeparatorExtent = FindTimeSeparatorExtent();

    // countdownDisplay->SetMinClientSize(
    //     wxSize((widestRepeatedDigitExtent * 3) + (timeSeparatorExtent * 2) +
    //                (PreferencesReader::getInstance().getBorder() * 2),
    //            wxDefaultSize.GetHeight()));
    countdownDisplay->SetMinSize(
        wxSize(widestRepeatedDigitExtent +
                   (PreferencesReader::getInstance().getBorder() * 2),
               wxDefaultCoord));
    countdownDisplay->Bind(wxEVT_PAINT, &ClockPanel::OnCountdownPaint, this);

    sizerTitle->Add(titleDisplay, 1, wxLEFT | wxRIGHT | wxEXPAND,
                    PreferencesReader::getInstance().getBorder());
    sizerTitle->Add(countdownDisplay, 0, wxLEFT | wxRIGHT | wxEXPAND,
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
    buttonStop->Bind(wxEVT_BUTTON, &ClockPanel::OnStopButtonClick, this);

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

void ClockPanel::OnCountdownPaint(const wxPaintEvent &event) {
    wxAutoBufferedPaintDC dc(countdownDisplay);
    dc.Clear();

    wxRect rect = countdownDisplay->GetClientRect();

    dc.SetFont(GetFont());
    dc.SetBackgroundMode(wxBRUSHSTYLE_TRANSPARENT);

    // Determine text size
    wxCoord textW, textH;
    dc.GetTextExtent(wxString("00:00:00"), &textW, &textH);

    int x = rect.x + PreferencesReader::getInstance().getBorder();  // Left edge
    int y = rect.y + (rect.height - textH) / 2;  // Vertically centered

    dc.DrawText("00:00:00", x, y);
}
wxCoord ClockPanel::FindWidestRepeatedDigitExtent() {
    wxClientDC dc(countdownDisplay);
    dc.SetFont(GetFont());

    wxString widest = "";
    wxCoord maxWidth = 0, maxHeight = 0;

    for (int digit = 0; digit <= 9; ++digit) {
        wxString s = wxString::Format("%1d%1d:%1d%1d;%1d%1d", digit, digit,
                                      digit, digit, digit, digit);
        // wxString s = wxString::Format("%1d%1d", digit, digit);

        wxCoord w, h;
        dc.GetTextExtent(s, &w, &h);

        if (w > maxWidth) {
            maxWidth = w;
            maxHeight = h;
            widest = s;
        }
    }

    // outWidth = maxWidth;
    // outHeight = maxHeight;
    return maxWidth;
}
wxCoord ClockPanel::FindTimeSeparatorExtent() {
    wxClientDC dc(countdownDisplay);
    dc.SetFont(GetFont());

    wxCoord w, h;
    dc.GetTextExtent(":", &w, &h);
    return w;
}

void ClockPanel::EnableStopButton() { buttonStop->Enable(); }
void ClockPanel::DisableStopButton() { buttonStop->Disable(); }
void ClockPanel::EnableFixButton() { buttonFix->Enable(); }
void ClockPanel::DisableFixButton() { buttonFix->Disable(); }
void ClockPanel::EnableEditButton() { buttonEdit->Enable(); }
void ClockPanel::DisableEditButton() { buttonEdit->Disable(); }
void ClockPanel::EnablePlayButton() { buttonStart->Enable(); }
void ClockPanel::DisablePlayButton() { buttonStart->Disable(); }
void ClockPanel::OnPlayButtonClick(const wxCommandEvent &event) {
    std::cout << "Play button clicked\n";
    wxASSERT(parentController != nullptr);
    parentController->Play();
}
void ClockPanel::OnStopButtonClick(const wxCommandEvent &event) {
    std::cout << "Stop button clicked\n";
    wxASSERT(parentController != nullptr);
    parentController->Stop();
}
void ClockPanel::ShowPlayButton() {
    buttonStart->SetBitmap(
        wxArtProvider::GetBitmap("CLOCK_START", wxART_OTHER, wxSize(24, 24)));
}
void ClockPanel::ShowPauseButton() {
    buttonStart->SetBitmap(
        wxArtProvider::GetBitmap("CLOCK_PAUSE", wxART_OTHER, wxSize(24, 24)));
}