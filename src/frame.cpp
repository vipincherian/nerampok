#include "frame.h"

#include <wx/artprov.h>
#include <wx/headercol.h>
#include <wx/headerctrl.h>  // Include for wxHeaderCtrl

#include "constants.h"
#include "preferencesreader.h"
// enum { ID_NewTimer = 1 };

wxDEFINE_EVENT(FRAME_GREET_EVENT, wxCommandEvent);

TopFrame::TopFrame(IController *controller)
    : wxFrame(NULL, wxID_ANY, Constants::getInstance().getAppTitle()) {
    parentController = controller;

    // Creation of the main menu
    wxMenu *menuTimer = new wxMenu;
    menuTimer->Append(wxID_NEW, "&New\tCtrl-N", "Create a new timer");
    menuTimer->AppendSeparator();
    menuTimer->Append(wxID_EXIT);

    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuTimer, "&Timer");
    menuBar->Append(menuHelp, "&Help");

    SetMenuBar(menuBar);

    // Creation of the toolbar

    wxToolBar *toolbar = CreateToolBar();

    // 2. Add tools to the toolbar. Each tool needs an ID and a label.
    // wxART_FILE_OPEN and wxART_FILE_SAVE are standard stock icons.
    toolbar->AddTool(wxID_NEW, "Open",
                     wxArtProvider::GetBitmap(wxART_FILE_OPEN, wxART_TOOLBAR));
    toolbar->AddTool(wxID_SAVE, "Save",
                     wxArtProvider::GetBitmap(wxART_FILE_SAVE, wxART_TOOLBAR));

    // 3. Realize the toolbar to make it visible.
    toolbar->Realize();

    wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);

    // Create a panel inside the frame which will
    wxPanel *containerPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition,
                                          wxSize(350, 200), wxBORDER_SUNKEN);
    // Set a sunken border for the panel
    containerPanel->SetWindowStyle(wxSUNKEN_BORDER);

    // Add the panel to the sizer, making it expand and fill available space
    // wxEXPAND ensures it takes up available width/height
    // wxALL and 10 add a 10-pixel border around the panel within the sizer
    vbox->Add(containerPanel, 1, wxEXPAND | wxALL, 10);

    //
    // Container panel
    //

    // We cannot use wxHD_DEFAULT_STYLE here as this allows re-ordering of
    // header columns. So instead, 0x0000 is passed as STYLE.
    wxHeaderCtrlSimple *header =
        new wxHeaderCtrlSimple(containerPanel, wxID_ANY, wxDefaultPosition,
                               wxDefaultSize, 0x0000);  // wxHD_DEFAULT_STYLE);
    // Append exactly three columns
    wxHeaderColumnSimple headerColTitle("Title", 100, wxALIGN_CENTER);
    wxHeaderColumnSimple headerColDuration("Duration", 150, wxALIGN_CENTER);
    wxHeaderColumnSimple headerColControls("Controls", 200, wxALIGN_CENTER);
    header->AppendColumn(headerColTitle);
    header->AppendColumn(headerColDuration);
    header->AppendColumn(headerColControls);

    // 2. Main vertical sizer
    wxBoxSizer *vsizer = new wxBoxSizer(wxVERTICAL);
    vsizer->Add(header, 0, wxEXPAND);
    containerPanel->SetSizer(vsizer);

    //
    // Container panel end
    //

    // Create a button below the panel inside the frame
    wxButton *button = new wxButton(this, wxID_ANY, "Click Me",
                                    wxDefaultPosition, wxSize(100, 30));

    // Add the button to the vertical sizer
    vbox->Add(button, 0, wxALL | wxCENTER, 10);

    // Set the sizer for the frame
    SetSizer(vbox);

    // Fit the frame to the sizer's minimum size
    vbox->Fit(this);

    CreateStatusBar();
    SetStatusText("Welcome to wxWidgets!");

    Bind(wxEVT_MENU, &TopFrame::OnNewTimer, this, wxID_NEW);
    Bind(wxEVT_MENU, &TopFrame::OnAbout, this, wxID_ABOUT);
    // Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);
    button->Bind(wxEVT_BUTTON, &TopFrame::OnButtonClick, this);
    Bind(wxEVT_CLOSE_WINDOW, &TopFrame::OnFrameClose, this);
    Bind(wxEVT_SHOW, &TopFrame::OnShow, this);
}

void TopFrame::OnExit(const wxCommandEvent &event) {
    std::cout << "On MyFrame:;OnExit";
    Close(true);
    // wxMessageBox("hello");

    // if (parentController != NULL) {
    //     wxCommandEvent customEvent;
    //     // Post the custom event to the panel (send a message to it)
    //     wxPostEvent(parentController, customEvent);
    // }
}

void TopFrame::OnAbout(const wxCommandEvent &event) {
    wxMessageBox("This is a wxWidgets Hello World example", "About Hello World",
                 wxOK | wxICON_INFORMATION);
}

void TopFrame::OnNewTimer(const wxCommandEvent &event) {
    // // double scaleFactor = wxWindow::GetDPIScaleFactor();
    // const wxSize sizeM = this->GetTextExtent("M");
    // wxString message = wxString::Format("Scaling facator is %d", sizeM.y);
    // wxMessageBox(message);
    // wxASSERT(parentController != NULL);
    // wxCommandEvent customEvent(FRAME_GREET_EVENT);
    // customEvent.SetString("Custom event string");
    // // Post the custom event to the panel (send a message to it)
    // wxPostEvent(parentController, customEvent);
    parentController->AddTimer();
}

// void MyFrame::SetController(wxEvtHandler *controller) {
//     parentController = controller;
//     // this->PushEventHandler(parentController);
// }

void TopFrame::OnButtonClick(const wxCommandEvent &event) {
    std::cout << "On MyFrame::OnButtonClick";
    // if (parentController != NULL) {
    //     wxCommandEvent customEvent(FRAME_GREET_EVENT);
    //     customEvent.SetString("Custom event string");
    //     // Post the custom event to the panel (send a message to it)
    //     wxPostEvent(parentController, customEvent);
    // }
}

void TopFrame::OnFrameClose(wxCloseEvent &event) {
    parentController->CleanUp();
    event.Skip();
}

void TopFrame::OnShow(wxShowEvent &event) {
    std::cout << "On MyFrame::OnShow";
    // Restore saved position and dimensions

    SetPosition(wxPoint(PreferencesReader::getInstance().getFramePositionX(),
                        PreferencesReader::getInstance().getFramePositionY()));
    SetSize(wxSize(PreferencesReader::getInstance().getFrameWidth(),
                   PreferencesReader::getInstance().getFrameHeight()));
    // Always skip the event to allow default processing to continue.
    event.Skip();
}