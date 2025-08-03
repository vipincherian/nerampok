#include "controller.h"

enum { ID_Hello = 1 };

// #include "frame.h"

Controller::Controller() : wxEvtHandler() {
    std::cout << "Controller constructed\n";
    // Initialization logic here
    // frame = new MyFrame();
    // frame->Show(true);
    // frame.SetController(this);
    frame = new MyFrame();
    frame->Show(true);
    frame->SetController(this);
    // frame->Bind(wxEVT_MENU, &Controller::OnGreeting, this, ID_Hello);
    frame->Bind(wxEVT_MENU, &Controller::OnExit, this, wxID_EXIT);
    this->Bind(FRAME_GREET_EVENT, &Controller::OnGreeting, this);

    // frame = new wxFrame(NULL, wxID_ANY, "Main Frame");

    // wxMenu *menuFile = new wxMenu;
    // menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
    //                  "Help string shown in status bar for this menu item");
    // menuFile->AppendSeparator();
    // menuFile->Append(wxID_EXIT);

    // wxMenu *menuHelp = new wxMenu;
    // menuHelp->Append(wxID_ABOUT);

    // wxMenuBar *menuBar = new wxMenuBar;
    // menuBar->Append(menuFile, "&File");
    // menuBar->Append(menuHelp, "&Help");

    // frame->SetMenuBar(menuBar);

    // wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);

    // // Create a panel inside the frame which will
    // wxPanel *containerPanel = new wxPanel(frame, wxID_ANY, wxDefaultPosition,
    //                                       wxSize(350, 200), wxBORDER_SUNKEN);
    // // Set a sunken border for the panel
    // containerPanel->SetWindowStyle(wxSUNKEN_BORDER);

    // // Add the panel to the sizer, making it expand and fill available space
    // // wxEXPAND ensures it takes up available width/height
    // // wxALL and 10 add a 10-pixel border around the panel within the sizer
    // vbox->Add(containerPanel, 1, wxEXPAND | wxALL, 10);

    // // Create a button below the panel inside the frame
    // wxButton *button = new wxButton(frame, wxID_ANY, "Click Me",
    //                                 wxDefaultPosition, wxSize(100, 30));

    // // Add the button to the vertical sizer
    // vbox->Add(button, 0, wxALL | wxCENTER, 10);

    // // Set the sizer for the frame
    // frame->SetSizer(vbox);

    // // Fit the frame to the sizer's minimum size
    // vbox->Fit(frame);

    // frame->CreateStatusBar();
    // frame->SetStatusText("Welcome to wxWidgets!");

    // frame->Bind(wxEVT_MENU, &Controller::OnGreeting, this, ID_Hello);
    // // Bind(wxEVT_MENU, &Controller::OnAbout, this, wxID_ABOUT);
    // frame->Bind(wxEVT_MENU, &Controller::OnExit, this, wxID_EXIT);

    // frame->Show();
}

Controller::~Controller() {
    std::cout << "Controller destructed\n";
    // Cleanup logic here
}

// void Controller::run() { std::cout << "Controller running\n"; }

void Controller::OnExit(const wxCommandEvent &event) {
    // frame.Close(true);
    std::cout << "Reached OnExit\n";
    // this->Close(true);
    frame->Close(true);
}

void Controller::OnGreeting(const wxCommandEvent &event) {
    std::cout << "Reached OnGreeting\n";
    wxMessageBox("hello@");
}