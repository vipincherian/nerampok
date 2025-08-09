#include "preferences.h"

#include <wx/dir.h>
#include <wx/file.h>
#include <wx/stdpaths.h>
#include <wx/xml/xml.h>

#include <iostream>

#include "constants.h"

// Public constructor initializes default values.
Preferences::Preferences()
    : m_username("DefaultUser"),
      m_volume(50),
      m_darkModeEnabled(false),
      framePositionX(-1),  // Use -1 to indicate position is not set
      framePositionY(-1),
      frameWidth(800),
      frameHeight(600) {
    wxStandardPaths::Get().SetFileLayout(wxStandardPaths::FileLayout_XDG);

    // Get the full path to the user's config directory.
    configFilePath.Assign(wxStandardPaths::Get().GetUserConfigDir() +
                          wxFileName::GetPathSeparator() +
                          Constants::getInstance().getAppConfigDirName() +
                          wxFileName::GetPathSeparator() + PREF_FILE_NAME);
    std::cout << "User configuration directory "
              << configFilePath.GetFullPath();
    border = Constants::getInstance().getBorder();
}

/**
 * @brief Loads preferences from an XML file in the user's config directory.
 * @param filename The name of the XML file.
 * @return true if the file was loaded successfully, false otherwise.
 */
bool Preferences::Load(const wxString& filename) {
    // Check if the file exists.
    if (!configFilePath.FileExists()) {
        wxLogWarning("Preferences file not found. Using default values.");
        return false;
    }

    // Create an XML document object.
    wxXmlDocument doc;
    if (!doc.Load(configFilePath.GetFullPath())) {
        wxLogError("Failed to load preferences from XML file.");
        return false;
    }

    // Get the root node.
    wxXmlNode* root = doc.GetRoot();
    if (!root || root->GetName() != "Preferences") {
        wxLogError(
            "Invalid XML file format: 'Preferences' root node not found.");
        return false;
    }

    // Read the preference values from the XML nodes.
    wxXmlNode* node = root->GetChildren();
    while (node) {
        if (node->GetName() == "Username") {
            m_username = node->GetNodeContent();
        } else if (node->GetName() == "Volume") {
            long volume;
            if (node->GetNodeContent().ToLong(&volume)) {
                m_volume = static_cast<int>(volume);
            }
        } else if (node->GetName() == "DarkModeEnabled") {
            m_darkModeEnabled = (node->GetNodeContent().CmpNoCase("true") == 0);
        } else if (node->GetName() == "WindowX") {
            long x;
            if (node->GetNodeContent().ToLong(&x)) {
                framePositionX = static_cast<int>(x);
            }
        } else if (node->GetName() == "WindowY") {
            long y;
            if (node->GetNodeContent().ToLong(&y)) {
                framePositionY = static_cast<int>(y);
            }
        } else if (node->GetName() == "WindowWidth") {
            long width;
            if (node->GetNodeContent().ToLong(&width)) {
                frameWidth = static_cast<int>(width);
            }
        } else if (node->GetName() == "WindowHeight") {
            long height;
            if (node->GetNodeContent().ToLong(&height)) {
                frameHeight = static_cast<int>(height);
            }
        }
        node = node->GetNext();
    }

    // wxLogMessage("Preferences loaded successfully from '%s'.",
    //              configFilePath.GetFullPath());
    return true;
}

/**
 * @brief Saves current preferences to an XML file.
 * @param filename The name of the XML file.
 * @return true if the file was saved successfully, false otherwise.
 */
bool Preferences::Save(const wxString& filename) {
    wxString configDir = configFilePath.GetPath();

    // Create the directory if it doesn't exist.
    if (!wxDir::Exists(configDir)) {
        if (!wxDir::Make(configDir, wxS_DIR_DEFAULT, wxDIR_DEFAULT)) {
            wxLogError("Failed to create user config directory: '%s'.",
                       configDir);
            return false;
        }
    }

    // Create the XML document and root node.
    wxXmlDocument doc;
    wxXmlNode* root = new wxXmlNode(nullptr, wxXML_ELEMENT_NODE, "Preferences");
    doc.SetRoot(root);

    // Add preference nodes to the root by creating element nodes and child text
    // nodes.
    wxXmlNode* usernameNode =
        new wxXmlNode(root, wxXML_ELEMENT_NODE, "Username");
    new wxXmlNode(usernameNode, wxXML_TEXT_NODE, "", m_username);

    wxXmlNode* volumeNode = new wxXmlNode(root, wxXML_ELEMENT_NODE, "Volume");
    new wxXmlNode(volumeNode, wxXML_TEXT_NODE, "",
                  wxString::Format("%d", m_volume));

    wxXmlNode* darkModeNode =
        new wxXmlNode(root, wxXML_ELEMENT_NODE, "DarkModeEnabled");
    new wxXmlNode(darkModeNode, wxXML_TEXT_NODE, "",
                  m_darkModeEnabled ? "true" : "false");

    wxXmlNode* windowXNode = new wxXmlNode(root, wxXML_ELEMENT_NODE, "WindowX");
    new wxXmlNode(windowXNode, wxXML_TEXT_NODE, "",
                  wxString::Format("%d", framePositionX));

    wxXmlNode* windowYNode = new wxXmlNode(root, wxXML_ELEMENT_NODE, "WindowY");
    new wxXmlNode(windowYNode, wxXML_TEXT_NODE, "",
                  wxString::Format("%d", framePositionY));

    wxXmlNode* windowWidthNode =
        new wxXmlNode(root, wxXML_ELEMENT_NODE, "WindowWidth");
    new wxXmlNode(windowWidthNode, wxXML_TEXT_NODE, "",
                  wxString::Format("%d", frameWidth));

    wxXmlNode* windowHeightNode =
        new wxXmlNode(root, wxXML_ELEMENT_NODE, "WindowHeight");
    new wxXmlNode(windowHeightNode, wxXML_TEXT_NODE, "",
                  wxString::Format("%d", frameHeight));

    // Save the XML document to the file.
    if (!doc.Save(configFilePath.GetFullPath())) {
        wxLogError("Failed to save preferences to XML file.");
        return false;
    }

    // wxLogMessage("Preferences saved successfully to '%s'.",
    //              configFilePath.GetFullPath());
    return true;
}

// Getter methods for the preference values.
wxString Preferences::getUsername() const { return m_username; }

int Preferences::getVolume() const { return m_volume; }

bool Preferences::isDarkModeEnabled() const { return m_darkModeEnabled; }

// New getter methods.
int Preferences::getFramePositionX() const { return framePositionX; }

int Preferences::getFramePositionY() const { return framePositionY; }

int Preferences::getFrameWidth() const { return frameWidth; }

int Preferences::getFrameHeight() const { return frameHeight; }

void Preferences::setFramePosition(int x, int y) {
    wxASSERT(x >= 0);
    wxASSERT(y >= 0);
    // TODO: Handle multi-monitor scenario - save display too?
    framePositionX = x;
    framePositionY = y;
}

void Preferences::setFrameDimensions(int w, int h) {
    wxASSERT(w > 0);
    wxASSERT(h > 0);
    frameWidth = w;
    frameHeight = h;
}
int Preferences::getBorder() const { return border; }