#include "containerpanel.h"

ContainerPanel::ContainerPanel(IController *controller, wxFrame *parent)
    : wxPanel(parent) {
    // Set a sunken border for the panel
    SetWindowStyle(wxSUNKEN_BORDER);

    // We cannot use wxHD_DEFAULT_STYLE here as this allows re-ordering of
    // header columns. So instead, 0x0000 is passed as STYLE.
    header =
        new wxHeaderCtrlSimple(this, wxID_ANY, wxDefaultPosition, wxDefaultSize,
                               0x0000);  // wxHD_DEFAULT_STYLE);
    // While creating columns, argument _flags_ is passed as 0x0000 in order
    // to disable resizing
    headerColSelect = new wxHeaderColumnSimple("", 100, wxALIGN_CENTER, 0x0000);
    headerColTitle =
        new wxHeaderColumnSimple("Title", 100, wxALIGN_CENTER, 0x0000);
    headerColDuration =
        new wxHeaderColumnSimple("Duration", 150, wxALIGN_CENTER, 0x0000);
    headerColControls =
        new wxHeaderColumnSimple("Controls", 200, wxALIGN_CENTER, 0x0000);
    header->AppendColumn(*headerColSelect);
    header->AppendColumn(*headerColTitle);
    header->AppendColumn(*headerColDuration);
    header->AppendColumn(*headerColControls);

    // 2. Main vertical sizer
    wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(header, 0, wxEXPAND);
    SetSizer(sizer);
}
ClockPanel *ContainerPanel::AddClockPanel(IClockController *parentController) {
    // container->GetSizer()->Layout();
    ClockPanel *clockPanel = new ClockPanel(parentController, this);
    GetSizer()->Add(clockPanel, 0, wxTOP | wxEXPAND, 10);
    GetSizer()->Layout();
    return clockPanel;
}