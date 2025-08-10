#ifndef ART_PROVIDER_H
#define ART_PROVIDER_H

#include <wx/artprov.h>
#include <wx/bitmap.h>
#include <wx/bmpbndl.h>

#include <iostream>

class ArtProvider : public wxArtProvider {
   public:
    // Constructor takes SVG file path and the art ID (string identifier)
    ArtProvider();

   protected:
    wxBitmap CreateBitmap(const wxArtID& id, const wxArtClient& client,
                          const wxSize& size) override;

   private:
    // wxString m_svgPath;
    // wxArtID m_artId;
    wxString GetSvgPathForId(const wxArtID& id) const;
};
#endif  // ART_PROVIDER_H
