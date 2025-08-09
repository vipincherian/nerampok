#include "controller.h"

#include "preferencesreader.h"
#include "utils.h"

// enum { ID_NewTimer = 1 };

// #include "frame.h"

Controller::Controller() : IController(), IClockMediator() {
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
    // frame->Bind(wxEVT_MENU, &Controller::OnExit, this, wxID_EXIT);
    // frame->Bind(wxEVT_MENU, &Controller::OnNewTimer, this, wxID_NEW);
    // frame->Bind(wxEVT_CLOSE_WINDOW, &Controller::OnFrameClose, this);
    // this->Bind(FRAME_GREET_EVENT, &Controller::OnGreeting, this);
}

Controller::~Controller() {
    preferences.Save();
    std::cout << "Controller destructed\n";
    // Cleanup logic here
}

// void Controller::run() { std::cout << "Controller running\n"; }

// void Controller::OnExit(const wxCommandEvent &event) {
//     // frame.Close(true);
//     std::cout << "Reached OnExit\n";
//     // this->Close(true);
//     frame->Close(true);
// }

// void Controller::OnNewTimer(const wxCommandEvent &event) {
//     // frame.Close(true);
//     std::cout << "Reached OnNewTimer\n";
//     // this->Close(true);
// }

// void Controller::OnGreeting(const wxCommandEvent &event) {
//     std::cout << "Reached OnGreeting\n";
//     wxMessageBox("hello@");
// }

// void Controller::OnFrameClose(wxCloseEvent &event) {
//     // Get the current position and size of the window.
//     wxPoint pos = frame->GetPosition();
//     wxSize size = frame->GetSize();

//     preferences.setFramePosition(pos.x, pos.y);
//     preferences.setFrameDimensions(size.GetWidth(), size.GetHeight());

//     // This call is crucial to let the window close.
//     // Without it, the window would remain open.
//     event.Skip();
// }

void Controller::Quit() { std::cout << "Reached OnQuit\n"; };

void Controller::AddClock() {
    std::cout << "Reached OnAddTimer\n";
    // std::cout << "Rightmost bit set for 3 is" << util::rightmostZeroIndex(3)
    //           << "\n";
    // std::cout << "Rightmost bit set for 4 is" << util::rightmostZeroIndex(4)
    //           << "\n";

    int id = getSmallestAvailableCockId();
    ClockController *cc = new ClockController(this, frame->getContainer(), id);
    AddToUsedClockIds(id);
    clocks[id] = cc;

    // frame->getContainer()->GetSizer()->Layout();
    // frame->GetSizer()->Layout();
};
void Controller::CleanUp() {
    std::cout << "Reached OnCleanUp\n";
    // Get the current position and size of the window.
    wxPoint pos = frame->GetPosition();
    wxSize size = frame->GetSize();

    preferences.setFramePosition(pos.x, pos.y);
    preferences.setFrameDimensions(size.GetWidth(), size.GetHeight());
};
void Controller::ReportClock() {}
int Controller::getSmallestAvailableCockId() {
    return util::rightmostZeroIndex(usedClockIds);
}
void Controller::AddToUsedClockIds(int idToAdd) {
    wxASSERT(idToAdd >= 0);
    usedClockIds |= 1 << idToAdd;
}
void Controller::ResizeHeaderColumns() {}