#ifndef PREFERENCES_READER_H
#define PREFERENCES_READER_H

#include <memory>

// #include "ipreferencesreader.h"
#include "preferences.h"

/**
 * @class PreferencesReader
 * @brief Singleton class that provides read-only access to application
 * preferences.
 *
 * This class is the single point of access for all preferences. It owns a
 * Preferences object and handles loading, but not saving.
 */
class PreferencesReader {
   public:
    // Static method to get the single instance of the class.
    static PreferencesReader& getInstance();

    // Method to load preferences. It calls the Preferences object's load
    // method.
    // bool Load(const wxString& filename = "preferences.xml");

    // Method to check if preferences have been loaded.
    bool isLoaded() const;

    // Getter methods that provide read-only access to the preference values.
    wxString getUsername() const;
    int getVolume() const;
    bool isDarkModeEnabled() const;

    // New getters for window position and size.
    int getFramePositionX() const;
    int getFramePositionY() const;
    int getFrameWidth() const;
    int getFrameHeight() const;

    void SetPreferences(Preferences* prefs);

   private:
    // Private constructor to prevent direct instantiation.
    Preferences* preferences = nullptr;
    PreferencesReader();

    // Prevent copying and assignment.
    PreferencesReader(const PreferencesReader&) = delete;
    PreferencesReader& operator=(const PreferencesReader&) = delete;

    // A pointer to the Preferences data object. The singleton is responsible
    // for its lifetime.
    std::unique_ptr<Preferences> m_preferences;

    // Flag to track if the preferences have been successfully loaded.
    bool m_isLoaded;
};

#endif  // PREFERENCES_READER_H
