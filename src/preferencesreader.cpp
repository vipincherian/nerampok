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
PreferencesReader::PreferencesReader()
    : m_preferences(std::make_unique<Preferences>()), m_isLoaded(false) {}

/**
 * @brief Loads preferences from an XML file using the Preferences object.
 * @param filename The name of the XML file.
 * @return true if the file was loaded successfully, false otherwise.
 */
bool PreferencesReader::Load(const wxString& filename) {
    m_isLoaded = m_preferences->Load(filename);
    return m_isLoaded;
}

/**
 * @brief Checks if the preferences have been loaded from a file.
 * @return true if loaded, false otherwise.
 */
bool PreferencesReader::isLoaded() const { return m_isLoaded; }

// Getter methods that provide read-only access.
wxString PreferencesReader::getUsername() const {
    if (m_isLoaded) {
        return m_preferences->getUsername();
    }
    // Return a default or empty string if not loaded.
    return "";
}

int PreferencesReader::getVolume() const {
    if (m_isLoaded) {
        return m_preferences->getVolume();
    }
    // Return a default value if not loaded.
    return 50;
}

bool PreferencesReader::isDarkModeEnabled() const {
    if (m_isLoaded) {
        return m_preferences->isDarkModeEnabled();
    }
    // Return a default value if not loaded.
    return false;
}

// New getter methods for window geometry.
int PreferencesReader::getWindowX() const {
    if (m_isLoaded) {
        return m_preferences->getWindowX();
    }
    // Return default or a special value if not loaded.
    return -1;
}

int PreferencesReader::getWindowY() const {
    if (m_isLoaded) {
        return m_preferences->getWindowY();
    }
    // Return default or a special value if not loaded.
    return -1;
}

int PreferencesReader::getWindowWidth() const {
    if (m_isLoaded) {
        return m_preferences->getWindowWidth();
    }
    // Return default value if not loaded.
    return 800;
}

int PreferencesReader::getWindowHeight() const {
    if (m_isLoaded) {
        return m_preferences->getWindowHeight();
    }
    // Return default value if not loaded.
    return 600;
}
