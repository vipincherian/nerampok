#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <wx/wx.h>

// #include <string>

// Window dimensions
constexpr int MAIN_WINDOW_WIDTH = 800;
constexpr int MAIN_WINDOW_HEIGHT = 600;

// UI strings
const wxString APP_TITLE = "Nerampok";
const wxString APP_VERSION = "0.1a";
const wxString PREF_FILE_NAME = "preferences.xml";
const wxString STATUS_MESSAGE = "Application is ready.";

// Other application-specific constants
constexpr int MAX_ITEMS = 100;
const std::string API_ENDPOINT = "https://api.example.com/data";

/**
 * @class Constants
 * @brief A singleton class to hold application-wide constants.
 *
 * The singleton pattern ensures that there is only one instance of this
 * class, providing a single point of access for all constant values.
 */
class Constants {
   public:
    // This is the static method that provides access to the single instance.
    static Constants& getInstance();

    // Getter methods for accessing the constant values.
    wxString getAppTitle() const;
    wxString getAppConfigDirName() const;

   private:
    // Private constructor to prevent direct instantiation.
    Constants();

    // Private copy constructor and assignment operator to prevent cloning.
    Constants(const Constants&) = delete;
    Constants& operator=(const Constants&) = delete;

    // Member variables to hold the constant values.
    wxString appTitle = APP_TITLE;
    wxString appConfigDirName = APP_TITLE;
};

#endif  // CONSTANTS_H
