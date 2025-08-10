#include "artprovider.h"

#include <wx/filefn.h>  // For wxFileExists
#include <wx/log.h>

ArtProvider::ArtProvider() {}

wxBitmap ArtProvider::CreateBitmap(const wxArtID& id, const wxArtClient& client,
                                   const wxSize& size) {
    wxString svgPath = GetSvgPathForId(id);

    if (svgPath.empty() || !wxFileExists(svgPath)) {
        // wxLogWarning("SVG file for art ID '%s' not found: %s", id, svgPath);
        std::cout << "SVG file for art ID " << id << " not found\n";
        return wxNullBitmap;
    }

    wxBitmapBundle bundle = wxBitmapBundle::FromSVGFile(svgPath, size);
    if (!bundle.IsOk()) {
        std::cout << "Failed to load SVG for art ID '%s' from %s", id, svgPath;
        return wxNullBitmap;
    }

    return bundle.GetBitmap(size);
}
wxString ArtProvider::GetSvgPathForId(const wxArtID& id) const {
    // Switch-like mapping — change according to your needs
    if (id == "CLOCK_EDIT") return "./src/build/edit.svg";
    if (id == "CLOCK_START") return "./src/build/start.svg";
    if (id == "CLOCK_STOP") return "./src/build/stop.svg";
    if (id == "CLOCK_FIX") return "./src/build/hammer.svg";
    if (id == "OTHER_ICON_SVG") return "icons/other_icon.svg";
    return "";
}
