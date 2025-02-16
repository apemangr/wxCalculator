#ifndef CUSTOM_BUTTON_H
#define CUSTOM_BUTTON_H

#include <wx/wx.h>

class CustomButton : public wxButton {
public:
    CustomButton(wxWindow* parent, wxWindowID id, const wxString& label,
                 const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(10, 10),
                 long style = 0, const wxValidator& validator = wxDefaultValidator,
                 const wxString& name = wxButtonNameStr);

    void SetNormalColor(const wxColour& color);
    void SetHoverColor(const wxColour& color);
    void SetPressedColor(const wxColour& color);
    void SetTextColor(const wxColour& color);

protected:
    wxColour m_normalColor;
    wxColour m_hoverColor;
    wxColour m_pressedColor;
    wxColour m_textColor;
    bool m_isHovered = false;
    bool m_isPressed = false;

    void OnPaint(wxPaintEvent& event);
    void OnMouseEnter(wxMouseEvent& event);
    void OnMouseLeave(wxMouseEvent& event);
    void OnMouseLeftDown(wxMouseEvent& event);
    void OnMouseLeftUp(wxMouseEvent& event);
    void OnButtonClick(wxCommandEvent& event);

    wxDECLARE_EVENT_TABLE();
};

#endif  // CUSTOM_BUTTON_H
