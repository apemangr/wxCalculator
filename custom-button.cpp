#include "custom-button.h"
#include <wx/filename.h>
#include <wx/font.h>
#include <wx/fontenum.h>
#include <wx/stdpaths.h>

wxBEGIN_EVENT_TABLE(CustomButton, wxButton) EVT_PAINT(CustomButton::OnPaint)
    EVT_ENTER_WINDOW(CustomButton::OnMouseEnter) EVT_LEAVE_WINDOW(CustomButton::OnMouseLeave)
        EVT_LEFT_DOWN(CustomButton::OnMouseLeftDown) EVT_LEFT_UP(CustomButton::OnMouseLeftUp)
            EVT_BUTTON(wxID_ANY, CustomButton::OnButtonClick) wxEND_EVENT_TABLE()

                CustomButton::CustomButton(wxWindow* parent,
                                           wxWindowID id,
                                           const wxString& label,
                                           const wxPoint& pos,
                                           const wxSize& size,
                                           long style,
                                           const wxValidator& validator,
                                           const wxString& name)
    : wxButton(parent, id, label, pos, size, style, validator, name)
{
    SetBackgroundColour(wxColour(68, 70, 72));

    wxString fontPath = wxStandardPaths::Get().GetDataDir();
    fontPath = wxFileName(fontPath).GetPath() + "/assets/SFPRODISPLAYMEDIUM.otf";

    if (!wxFont::AddPrivateFont(fontPath))
    {
        wxLogError("No se pudo cargar la fuente: %s", fontPath);
    }
    SetFont(wxFont(14,
                   wxFONTFAMILY_DEFAULT,
                   wxFONTSTYLE_NORMAL,
                   wxFONTWEIGHT_MEDIUM,
                   false,
                   "SF Pro Display"));

    m_normalColor = wxColour(115, 115, 115);
    m_hoverColor = wxColour(90, 90, 90);
    m_pressedColor = wxColour(30, 30, 30);
    m_textColor = wxColour(255, 255, 255);
}

void CustomButton::SetNormalColor(const wxColour& color)
{
    m_normalColor = color;
    Refresh();
}
void CustomButton::SetHoverColor(const wxColour& color)
{
    m_hoverColor = color;
    Refresh();
}
void CustomButton::SetPressedColor(const wxColour& color)
{
    m_pressedColor = color;
    Refresh();
}
void CustomButton::SetTextColor(const wxColour& color)
{
    m_textColor = color;
    Refresh();
}

void CustomButton::OnPaint(wxPaintEvent& event)
{
    wxPaintDC dc(this);

    // Establecer el color de fondo según el estado
    wxColour bgColor = m_normalColor;
    if (m_isPressed)
    {
        bgColor = m_pressedColor;
    }
    else if (m_isHovered)
    {
        bgColor = m_hoverColor;
    }

    // Establecer el color de fondo
    dc.SetBrush(wxBrush(bgColor));
    dc.SetPen(wxPen(bgColor));

    // Dibujar un rectángulo con esquinas redondeadas
    int borderRadius =
        2; // Puedes ajustar este valor para hacer las esquinas más o menos redondeadas
    dc.DrawRoundedRectangle(GetClientRect(), borderRadius);

    // Dibujar el texto
    dc.SetTextForeground(m_textColor);
    dc.SetFont(GetFont());
    dc.DrawLabel(GetLabel(), GetClientRect(), wxALIGN_CENTER);
}

void CustomButton::OnMouseEnter(wxMouseEvent& event)
{
    m_isHovered = true;
    Refresh();
    event.Skip();
}

void CustomButton::OnMouseLeave(wxMouseEvent& event)
{
    m_isHovered = false;
    Refresh();
    event.Skip();
}

void CustomButton::OnMouseLeftDown(wxMouseEvent& event)
{
    m_isPressed = true;
    Refresh();
    event.Skip();
}

void CustomButton::OnMouseLeftUp(wxMouseEvent& event)
{
    m_isPressed = false;
    Refresh();
    event.Skip();
}

void CustomButton::OnButtonClick(wxCommandEvent& event)
{
    // wxMessageBox("¡Botón presionado!", "Mensaje", wxOK | wxICON_INFORMATION, this);
}
