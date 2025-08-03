#include "controller.h"

#include "preferencesreader.h"

// enum { ID_NewTimer = 1 };

// #include "frame.h"

Controller::Controller() : wxEvtHandler() {
    std::cout << "Controller constructed\n";

    // Load preferences
    // wxStandardPa
    preferences.Load();
    PreferencesReader::getInstance().SetPreferences(&preferences);

    // Initialization logic here
    // frame = new MyFrame();
    // frame->Show(true);
    // frame.SetController(this);
    frame = new TopFrame(this);
    frame->Show(true);
    // frame->SetController(this);
    // frame->Bind(wxEVT_MENU, &Controller::OnGreeting, this, ID_Hello);
    frame->Bind(wxEVT_MENU, &Controller::OnExit, this, wxID_EXIT);
    frame->Bind(wxEVT_MENU, &Controller::OnNewTimer, this, wxID_NEW);
    frame->Bind(wxEVT_CLOSE_WINDOW, &Controller::OnFrameClose, this);
    this->Bind(FRAME_GREET_EVENT, &Controller::OnGreeting, this);
}

Controller::~Controller() {
    preferences.Save();
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

void Controller::OnNewTimer(const wxCommandEvent &event) {
    // frame.Close(true);
    std::cout << "Reached OnNewTimer\n";
    // this->Close(true);
}

void Controller::OnGreeting(const wxCommandEvent &event) {
    std::cout << "Reached OnGreeting\n";
    wxMessageBox("hello@");
}

void Controller::OnFrameClose(wxCloseEvent &event) {
    // Get the current position and size of the window.
    wxPoint pos = frame->GetPosition();
    wxSize size = frame->GetSize();

    preferences.setFramePosition(pos.x, pos.y);
    preferences.setFrameDimensions(size.GetWidth(), size.GetHeight());

    // This call is crucial to let the window close.
    // Without it, the window would remain open.
    event.Skip();
}