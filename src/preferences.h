#ifndef PREFERENCES_H
#define PREFERENCES_H

#include <wx/filename.h>
#include <wx/wx.h>

// #include <string>

/**
 * @class Preferences
 * @brief Simple data class for storing application preferences.
 *
 * This class is not a singleton. It is a plain data container that
 * also contains the logic for loading and saving its data from a file.
 */
class Preferences {
   public:
    // Public constructor with default values.
    Preferences();

    // Methods to save and load preferences from an XML file.
    bool Load(const wxString& filename = "preferences.xml");
    bool Save(const wxString& filename = "preferences.xml");

    // Getter methods for the preference values.
    wxString getUsername() const;
    int getVolume() const;
    bool isDarkModeEnabled() const;

    // New getters for window position and size.
    int getFramePositionX() const;
    int getFramePositionY() const;
    int getFrameWidth() const;
    int getFrameHeight() const;

    void setFramePosition(int x, int y);
    void setFrameDimensions(int w, int h);

   private:
    wxFileName configFilePath;
    // Member variables to hold the preferences.

    wxString m_username;
    int m_volume;
    bool m_darkModeEnabled;

    // New member variables for window geometry.
    int framePositionX;
    int framePositionY;
    int frameWidth;
    int frameHeight;
};

#endif  // PREFERENCES_H
