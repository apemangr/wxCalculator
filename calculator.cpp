#include "calculator.h"

Calculator::Calculator(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(300, 400))
{
    copiedToPrevPanel = false;
    this->SetMinSize(wxSize(300, 400));

    m_parent = new wxPanel(this, wxID_ANY);
    m_parent->SetBackgroundColour(wxColor(68, 70, 72));

    wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL); // Vertical para apilar elementos

    // Crear los paneles necesarios
    m_tp = new TopPanel(m_parent);  // Panel superior (barra superior)
    m_pp = new PrevPanel(m_parent); // Panel de en medio (barra inferior)
    m_bp = new BotPanel(m_parent);  // Panel inferior grande
    m_bp->SetBackgroundColour(wxColor(68, 70, 72));
    m_bp->SetFocus();
    // Agregar los paneles al sizer con proporciones adecuadas
    vbox->Add(m_pp, 0, wxEXPAND | wxLEFT | wxRIGHT | wxUP, 5);

    vbox->Add(m_tp, 0, wxEXPAND | wxLEFT | wxRIGHT | wxBOTTOM, 5); // Margen abajo
    // vbox->Add(m_tp, 0, wxEXPAND | wxLEFT | wxRIGHT, 5);
    vbox->Add(m_bp, 1, wxEXPAND | wxLEFT | wxRIGHT | wxBOTTOM, 5);
    // Establecer el sizer en el panel padre
    m_parent->SetSizer(vbox);
    this->Centre();

    Bind(wxEVT_KEY_DOWN, &Calculator::OnKeyDown, this);
    // Bind(wxEVT_MENU, &TopPanel::OnNumpad7, this, ID_7);
    //  Bind(wxEVT_MENU, &BotPanel::On7Press, this, ID_7);

    //  Crear
}
void Calculator::OnKeyDown(wxKeyEvent& event)
{
    // Propagar el evento de teclado a los aceleradores globales
    event.Skip();
}
