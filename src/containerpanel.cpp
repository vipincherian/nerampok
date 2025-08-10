#include "containerpanel.h"

#include <wx/listimpl.cpp>

#include "constants.h"

WX_DEFINE_LIST(ClockPanelList);

ContainerPanel::ContainerPanel(IController *controller, wxFrame *parent)
    : wxPanel(parent) {
    // Set a sunken border for the panel
    SetWindowStyle(wxSUNKEN_BORDER);

    // We cannot use wxHD_DEFAULT_STYLE here as this allows re-ordering of
    // header columns. So instead, 0x0000 is passed as STYLE.
    header = new wxHeaderCtrlSimple(this, wxID_ANY, wxDefaultPosition,
                                    wxDefaultSize, wxHD_DEFAULT_STYLE);
    //    0x0000);  // wxHD_DEFAULT_STYLE);
    // While creating columns, argument _flags_ is passed as 0x0000 in order
    // to disable resizing
    headerColSelect = new wxHeaderColumnSimple("", 100, wxALIGN_CENTER, 0x0000);
    headerColTitle =
        new wxHeaderColumnSimple("Title", 100, wxALIGN_CENTER, 0x0000);
    headerColControls =
        new wxHeaderColumnSimple("Controls", 200, wxALIGN_CENTER, 0x0000);
    headerColReport = new wxHeaderColumnSimple(REPORT_COLUMN_TITLE, 150,
                                               wxALIGN_CENTER, 0x0000);
    header->AppendColumn(*headerColSelect);
    header->AppendColumn(*headerColTitle);
    header->AppendColumn(*headerColControls);
    header->AppendColumn(*headerColReport);

    minWidthHeaderColReport = GetColMinWidth(header, REPORT_COLUMN_TITLE);
    wxASSERT(minWidthHeaderColReport > 0);

    // 2. Main vertical sizer
    wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(header, 0, wxEXPAND);
    SetSizer(sizer);
    Bind(wxEVT_SIZE, &ContainerPanel::OnSize, this);
}
ClockPanel *ContainerPanel::AddClockPanel(IClockController *parentController) {
    // container->GetSizer()->Layout();
    ClockPanel *newClockPanel = new ClockPanel(parentController, this);
    GetSizer()->Add(newClockPanel, 0, wxTOP | wxEXPAND, 10);
    GetSizer()->Layout();

    panels.Append(newClockPanel);

    ResizeHeaderColumns();

    return newClockPanel;
}
void ContainerPanel::OnSize(wxSizeEvent &event) {
    std::cout << "Inside ContainerPanel::OnSize\n";
    // headerColSelect->SetWidth()
    ResizeHeaderColumns();
    event.Skip();
}

void ContainerPanel::ResizeHeaderColumns() {
    if (!panels.IsEmpty()) {
        auto it = panels.GetFirst();
        ClockPanel *firstClockPanel = it->GetData();
        int widthSelect = firstClockPanel->GetSelectColumnWidth();
        headerColSelect->SetWidth(widthSelect);
        int widthTitle = firstClockPanel->GetTitleColumnWidth();
        headerColTitle->SetWidth(widthTitle);
        int widthControls = firstClockPanel->GetControlsColumnWidth();
        headerColControls->SetWidth(widthControls);
        int widthReport = firstClockPanel->GetReportColumnWidth();
        widthReport = std::max({minWidthHeaderColReport, widthReport});
        headerColReport->SetWidth(widthReport);

        // header->Update();
        // header->InvalidateBestSize();
        // header->Refresh();
        // header->Update();

        // This is the only way to resize columns, delete and add

        header->DeleteAllColumns();
        header->AppendColumn(*headerColSelect);
        header->AppendColumn(*headerColTitle);
        header->AppendColumn(*headerColControls);
        header->AppendColumn(*headerColReport);
    }
}
wxCoord ContainerPanel::GetColMinWidth(wxHeaderCtrl *headerCtrl,
                                       const wxString &title) {
    // Use a device context to measure how wide the text will be
    wxClientDC dc(headerCtrl);
    dc.SetFont(headerCtrl->GetFont());

    wxCoord textW, textH;
    dc.GetTextExtent(title, &textW,
                     &textH);  // measure the title size
                               // :contentReference[oaicite:0]{index=0}

    // Add a padding buffer to avoid clipping/margins
    const int padding = 10;
    wxCoord minWidth = textW + padding;

    return minWidth;
}