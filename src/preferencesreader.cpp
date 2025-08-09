#include "preferencesreader.h"

#include <wx/file.h>
#include <wx/filename.h>
#include <wx/stdpaths.h>
#include <wx/xml/xml.h>

// Implementation of the singleton instance.
PreferencesReader& PreferencesReader::getInstance() {
    static PreferencesReader instance;
    return instance;
}

// Private constructor: The single Preferences object is created here.
PreferencesReader::PreferencesReader() {}

/**
 * @brief Loads preferences from an XML file using the Preferences object.
 * @param filename The name of the XML file.
 * @return true if the file was loaded successfully, false otherwise.
 */
// bool PreferencesReader::Load(const wxString& filename) {
//     m_isLoaded = m_preferences->Load(filename);
//     return m_isLoaded;
// }

/**
 * @brief Checks if the preferences have been loaded from a file.
 * @return true if loaded, false otherwise.
 */
// bool PreferencesReader::isLoaded() const { return m_isLoaded; }

// Getter methods that provide read-only access.
// wxString PreferencesReader::getUsername() const {
//     if (m_isLoaded) {
//         return m_preferences->getUsername();
//     }
//     // Return a default or empty string if not loaded.
//     return "";
// }

// int PreferencesReader::getVolume() const {
//     if (m_isLoaded) {
//         return m_preferences->getVolume();
//     }
//     // Return a default value if not loaded.
//     return 50;
// }

// bool PreferencesReader::isDarkModeEnabled() const {
//     if (m_isLoaded) {
//         return m_preferences->isDarkModeEnabled();
//     }
//     // Return a default value if not loaded.
//     return false;
// }

// New getter methods for window geometry.
int PreferencesReader::getFramePositionX() const {
    if (preferences) {
        return preferences->getFramePositionX();
    }
    // Return default or a special value if not loaded.
    return -1;
}

int PreferencesReader::getFramePositionY() const {
    if (preferences) {
        return preferences->getFramePositionY();
    }
    // Return default or a special value if not loaded.
    return -1;
}

int PreferencesReader::getFrameWidth() const {
    if (preferences) {
        return preferences->getFrameWidth();
    }
    // Return default value if not loaded.
    return 800;
}

int PreferencesReader::getFrameHeight() const {
    if (preferences) {
        return preferences->getFrameHeight();
    }
    // Return default value if not loaded.
    return 600;
}

int PreferencesReader::getBorder() const {
    if (preferences) {
        return preferences->getBorder();
    }
    // Return default value if not loaded.
    return 600;
}
void PreferencesReader::SetPreferences(Preferences* prefs) {
    this->preferences = prefs;
}