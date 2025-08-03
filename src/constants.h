#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <wx/wx.h>

#include <string>

// Window dimensions
constexpr int MAIN_WINDOW_WIDTH = 800;
constexpr int MAIN_WINDOW_HEIGHT = 600;

// UI strings
const wxString APP_TITLE = "Nerampok";
const wxString BUTTON_LABEL = "Click Me!";
const wxString STATUS_MESSAGE = "Application is ready.";

// Other application-specific constants
constexpr int MAX_ITEMS = 100;
const std::string API_ENDPOINT = "https://api.example.com/data";

#endif  // CONSTANTS_H
