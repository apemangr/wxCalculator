#include <wx/gbsizer.h>
#include <wx/stattext.h>
#include <wx/stdpaths.h>
#include <wx/filename.h>
#include <wx/font.h>
#include "calculator.h"
#include "panels.h"

PrevPanel::PrevPanel(wxPanel* parent) :
    wxPanel(parent, wxID_ANY, wxDefaultPosition, wxSize(258, 30), wxBORDER_NONE) {
    m_text = new wxTextCtrl(this, -1, "0", wxDefaultPosition, wxDefaultSize, wxTE_READONLY | wxTE_RIGHT | wxNO_BORDER);
    m_text->SetBackgroundColour(wxColor(68, 70, 72));
    m_text->SetForegroundColour(*wxWHITE);

    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(m_text, 0, wxEXPAND | wxALL, 5);
    this->SetSizer(sizer);
}

TopPanel::TopPanel(wxPanel* parent) :
    wxPanel(parent, wxID_ANY, wxDefaultPosition, wxSize(258, 50), wxBORDER_NONE) {
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    m_text            = new wxTextCtrl(this, wxID_ANY, "0", wxDefaultPosition, wxDefaultSize, wxTE_RIGHT | wxNO_BORDER);
    sizer->Add(m_text, 0, wxEXPAND | wxALL, 5);
    wxString fontPath = wxStandardPaths::Get().GetDataDir();
    fontPath          = wxFileName(fontPath).GetPath() + "/assets/SFPRODISPLAYMEDIUM.otf";

    if (!wxFont::AddPrivateFont(fontPath)) {
        wxLogError("No se pudo cargar la fuente: %s", fontPath);
    }
    m_text->SetFont(wxFont(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_MEDIUM, false, "SF Pro Display"));
    m_text->SetBackgroundColour(wxColor(68, 70, 72));
    m_text->SetForegroundColour(*wxWHITE);
    this->SetSizer(sizer);
    this->Layout();
    this->Centre(wxBOTH);
}

BotPanel::BotPanel(wxPanel* parent) :
    wxPanel(parent, -1, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE) {
    wxGridBagSizer* sizer = new wxGridBagSizer(1, 1);

    SetBackgroundColour(wxColor(32, 32, 32));
    CustomButton* m_ac      = new CustomButton(this, wxID_ANY, "A/C");
    CustomButton* m_pm      = new CustomButton(this, wxID_ANY, "+/-");
    CustomButton* m_percent = new CustomButton(this, wxID_ANY, "%");
    CustomButton* m_div     = new CustomButton(this, wxID_ANY, wxString::FromUTF8("\xC3\xB7"));
    CustomButton* m_7       = new CustomButton(this, wxID_ANY, "7");
    CustomButton* m_8       = new CustomButton(this, wxID_ANY, "8");
    CustomButton* m_9       = new CustomButton(this, wxID_ANY, "9");
    CustomButton* m_mul     = new CustomButton(this, wxID_ANY, wxString::FromUTF8("\xC3\x97"));
    CustomButton* m_4       = new CustomButton(this, wxID_ANY, "4");
    CustomButton* m_5       = new CustomButton(this, wxID_ANY, "5");
    CustomButton* m_6       = new CustomButton(this, wxID_ANY, "6");
    CustomButton* m_minus   = new CustomButton(this, wxID_ANY, "-");
    CustomButton* m_1       = new CustomButton(this, wxID_ANY, "1");
    CustomButton* m_2       = new CustomButton(this, wxID_ANY, "2");
    CustomButton* m_3       = new CustomButton(this, wxID_ANY, "3");
    CustomButton* m_plus    = new CustomButton(this, wxID_ANY, "+");
    CustomButton* m_0       = new CustomButton(this, wxID_ANY, "0");
    CustomButton* m_point   = new CustomButton(this, wxID_ANY, ".");
    CustomButton* m_equals  = new CustomButton(this, wxID_ANY, "=");

    m_ac->SetNormalColor(wxColor(86, 88, 89));
    m_pm->SetNormalColor(wxColor(86, 88, 89));
    m_percent->SetNormalColor(wxColor(86, 88, 89));

    m_ac->SetHoverColor(wxColor(36, 37, 37));
    m_pm->SetHoverColor(wxColor(36, 37, 37));
    m_percent->SetHoverColor(wxColor(36, 37, 37));

    m_div->SetNormalColor(wxColor(255, 159, 10));
    m_mul->SetNormalColor(wxColor(255, 159, 10));
    m_minus->SetNormalColor(wxColor(255, 159, 10));
    m_plus->SetNormalColor(wxColor(255, 159, 10));
    m_equals->SetNormalColor(wxColor(255, 159, 10));

    m_div->SetHoverColor(wxColor(204, 127, 8));
    m_mul->SetHoverColor(wxColor(204, 127, 8));
    m_minus->SetHoverColor(wxColor(204, 127, 8));
    m_plus->SetHoverColor(wxColor(204, 127, 8));
    m_equals->SetHoverColor(wxColor(204, 127, 8));

    // Agregar botones al sizer con posiciones y spans
    // Fila 0
    sizer->Add(m_ac, wxGBPosition(0, 0), wxDefaultSpan, wxEXPAND | wxALL, 1);
    sizer->Add(m_pm, wxGBPosition(0, 1), wxDefaultSpan, wxEXPAND | wxALL, 1);
    sizer->Add(m_percent, wxGBPosition(0, 2), wxDefaultSpan, wxEXPAND | wxALL, 1);
    sizer->Add(m_div, wxGBPosition(0, 3), wxDefaultSpan, wxEXPAND | wxALL, 1);

    // Fila 1
    sizer->Add(m_7, wxGBPosition(1, 0), wxDefaultSpan, wxEXPAND | wxALL, 1);
    sizer->Add(m_8, wxGBPosition(1, 1), wxDefaultSpan, wxEXPAND | wxALL, 1);
    sizer->Add(m_9, wxGBPosition(1, 2), wxDefaultSpan, wxEXPAND | wxALL, 1);
    sizer->Add(m_mul, wxGBPosition(1, 3), wxDefaultSpan, wxEXPAND | wxALL, 1);

    // Fila 2
    sizer->Add(m_4, wxGBPosition(2, 0), wxDefaultSpan, wxEXPAND | wxALL, 1);
    sizer->Add(m_5, wxGBPosition(2, 1), wxDefaultSpan, wxEXPAND | wxALL, 1);
    sizer->Add(m_6, wxGBPosition(2, 2), wxDefaultSpan, wxEXPAND | wxALL, 1);
    sizer->Add(m_minus, wxGBPosition(2, 3), wxDefaultSpan, wxEXPAND | wxALL, 1);

    // Fila 3
    sizer->Add(m_1, wxGBPosition(3, 0), wxDefaultSpan, wxEXPAND | wxALL, 1);
    sizer->Add(m_2, wxGBPosition(3, 1), wxDefaultSpan, wxEXPAND | wxALL, 1);
    sizer->Add(m_3, wxGBPosition(3, 2), wxDefaultSpan, wxEXPAND | wxALL, 1);
    sizer->Add(m_plus, wxGBPosition(3, 3), wxDefaultSpan, wxEXPAND | wxALL, 1);

    // Fila 4:
    sizer->Add(m_0, wxGBPosition(4, 0), wxGBSpan(1, 2), wxEXPAND | wxALL, 1);  // Span de 1 fila y 2 columnas
    sizer->Add(m_point, wxGBPosition(4, 2), wxDefaultSpan, wxEXPAND | wxALL, 1);
    sizer->Add(m_equals, wxGBPosition(4, 3), wxDefaultSpan, wxEXPAND | wxALL, 1);

    // Hacer que todas las filas y columnas se expandan
    for (int i = 0; i < 5; ++i)
        sizer->AddGrowableRow(i);
    for (int j = 0; j < 4; ++j)
        sizer->AddGrowableCol(j);

    this->SetSizer(sizer);
    count    = 0;
    m_parent = parent;

    // m_plus = new CustomButton(this, ID_PLUS, "+", wxPoint(50,50),
    // wxSize(150,40));
    // m_plus->SetFont(wxFont(16, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL,
    // wxFONTWEIGHT_LIGHT));
    //
    // m_minus = new wxButton(this, ID_MINUS, "-");
    // m_mul = new wxButton(this, ID_MUL, "*");
    //
    // sizer->Add(m_plus, 0, wxEXPAND | wxALL, 5);
    // sizer->Add(m_minus, 0, wxEXPAND | wxALL, 5);
    // sizer->Add(m_mul, 0, wxEXPAND | wxALL, 5);
    //
    // this->SetSizer(sizer);
    //
    // m_plus->Bind(wxEVT_BUTTON, &BotPanel::OnPlus, this);
    // m_minus->Bind(wxEVT_BUTTON, &BotPanel::OnMinus, this);
    // m_mul->Bind(wxEVT_BUTTON, &BotPanel::OnMul, this);
}

void BotPanel::OnPlus(wxCommandEvent& WXUNUSED(event)) {
    count++;
    Calculator* comm = (Calculator*) m_parent->GetParent();
    comm->m_tp->m_text->SetLabel(wxString::Format("%d", count));
}

void BotPanel::OnMinus(wxCommandEvent& event) {
    wxMessageBox("Se hizo clic en el boton -");
}

void BotPanel::OnMul(wxCommandEvent& event) {
    wxMessageBox("Se hizo clic en el boton *");
}
