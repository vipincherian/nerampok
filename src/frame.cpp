#include "frame.h"

#include "constants.h"
enum { ID_NewTimer = 1 };

wxDEFINE_EVENT(FRAME_GREET_EVENT, wxCommandEvent);

TopFrame::TopFrame(wxEvtHandler *controller)
    : wxFrame(NULL, wxID_ANY, Constants::getInstance().getAppTitle()) {
    parentController = controller;
    wxMenu *menuTimer = new wxMenu;
    menuTimer->Append(ID_NewTimer, "&New\tCtrl-N", "Create a new timer");
    menuTimer->AppendSeparator();
    menuTimer->Append(wxID_EXIT);

    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuTimer, "&Timer");
    menuBar->Append(menuHelp, "&Help");

    SetMenuBar(menuBar);

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

    Bind(wxEVT_MENU, &TopFrame::OnNewTimer, this, ID_NewTimer);
    Bind(wxEVT_MENU, &TopFrame::OnAbout, this, wxID_ABOUT);
    // Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);
    button->Bind(wxEVT_BUTTON, &TopFrame::OnButtonClick, this);
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
    // double scaleFactor = wxWindow::GetDPIScaleFactor();
    const wxSize sizeM = this->GetTextExtent("M");
    wxString message = wxString::Format("Scaling facator is %d", sizeM.y);
    wxMessageBox(message);
    wxASSERT(parentController != NULL);
    wxCommandEvent customEvent(FRAME_GREET_EVENT);
    customEvent.SetString("Custom event string");
    // Post the custom event to the panel (send a message to it)
    wxPostEvent(parentController, customEvent);
}

// void MyFrame::SetController(wxEvtHandler *controller) {
//     parentController = controller;
//     // this->PushEventHandler(parentController);
// }

void TopFrame::OnButtonClick(const wxCommandEvent &event) {
    std::cout << "On MyFrame::OnButtonClick";
    if (parentController != NULL) {
        wxCommandEvent customEvent(FRAME_GREET_EVENT);
        customEvent.SetString("Custom event string");
        // Post the custom event to the panel (send a message to it)
        wxPostEvent(parentController, customEvent);
    }
}