#include "calculator.h"

Calculator::Calculator(const wxString &title) :
    wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(300, 400)) {
    this->SetMinSize(wxSize(300, 400));

    m_parent = new wxPanel(this, wxID_ANY);
    m_parent->SetBackgroundColour(wxColor(68, 70, 72));

    wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);  // Vertical para apilar elementos

    // Crear los paneles necesarios
    m_tp = new TopPanel(m_parent);   // Panel superior (barra superior)
    m_pp = new PrevPanel(m_parent);  // Panel de en medio (barra inferior)
    m_bp = new BotPanel(m_parent);   // Panel inferior grande
    m_bp->SetBackgroundColour(wxColor(68, 70, 72));

    // Agregar los paneles al sizer con proporciones adecuadas
    vbox->Add(m_pp, 0, wxEXPAND | wxLEFT | wxRIGHT | wxUP, 5);

    vbox->Add(m_tp, 0, wxEXPAND | wxLEFT | wxRIGHT | wxBOTTOM, 5);  // Margen abajo
    //vbox->Add(m_tp, 0, wxEXPAND | wxLEFT | wxRIGHT, 5);
    vbox->Add(m_bp, 1, wxEXPAND | wxLEFT | wxRIGHT | wxBOTTOM, 5);
    // Establecer el sizer en el panel padre
    m_parent->SetSizer(vbox);
    this->Centre();
}
