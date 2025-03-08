#include "panels.h"
#include "calculator.h"
#include <wx/filename.h>
#include <wx/font.h>
#include <wx/gbsizer.h>
#include <wx/numformatter.h>
#include <wx/stattext.h>
#include <wx/stdpaths.h>
#include <wx/valtext.h>

PrevPanel::PrevPanel(wxPanel* parent)
    : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxSize(258, 30), wxBORDER_NONE)
{
    m_text = new wxTextCtrl(
        this, -1, "0", wxDefaultPosition, wxDefaultSize, wxTE_READONLY | wxTE_RIGHT | wxNO_BORDER);
    m_text->SetBackgroundColour(wxColor(68, 70, 72));
    m_text->SetForegroundColour(*wxWHITE);
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(m_text, 0, wxEXPAND | wxALL, 5);
    this->SetSizer(sizer);
}

TopPanel::TopPanel(wxPanel* parent)
    : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxSize(258, 50), wxBORDER_NONE)
{
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    m_text = new wxTextCtrl(
        this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_RIGHT | wxNO_BORDER);

    // Crear un validador personalizado
    wxTextValidator validator(wxFILTER_DIGITS);
    validator.AddCharIncludes('+');
    validator.AddCharIncludes('.');
    // validator.AddCharIncludes('-');
    // validator.AddCharIncludes('*');
    // validator.AddCharIncludes('/');
    //
    // Establecer el validador en el control de texto
    m_text->SetValidator(validator);
    sizer->Add(m_text, 0, wxEXPAND | wxALL, 5);
    wxString fontPath = wxStandardPaths::Get().GetDataDir();
    fontPath = wxFileName(fontPath).GetPath() + "/assets/SFPRODISPLAYMEDIUM.otf";

    if (!wxFont::AddPrivateFont(fontPath))
    {
        wxLogError("No se pudo cargar la fuente: %s", fontPath);
    }
    m_text->SetFont(wxFont(24,
                           wxFONTFAMILY_DEFAULT,
                           wxFONTSTYLE_NORMAL,
                           wxFONTWEIGHT_MEDIUM,
                           false,
                           "SF Pro Display"));
    m_text->SetBackgroundColour(wxColor(68, 70, 72));
    m_text->SetForegroundColour(*wxWHITE);
    this->SetSizer(sizer);
    this->Layout();
    this->Centre(wxBOTH);

    // Bind(wxEVT_MENU, &TopPanel::OnNumpad7, this, ID_7);
}

BotPanel::BotPanel(wxPanel* parent)
    : wxPanel(parent, -1, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE)
{
    wxGridBagSizer* sizer = new wxGridBagSizer(1, 1);

    SetBackgroundColour(wxColor(32, 32, 32));
    CustomButton* m_ac = new CustomButton(this, wxID_ANY, "A/C");
    CustomButton* m_pm = new CustomButton(this, wxID_ANY, "+/-");
    CustomButton* m_percent = new CustomButton(this, wxID_ANY, "%");
    CustomButton* m_div = new CustomButton(this, wxID_ANY, wxString::FromUTF8("\xC3\xB7"));
    CustomButton* m_7 = new CustomButton(this, wxID_ANY, "7");
    CustomButton* m_8 = new CustomButton(this, wxID_ANY, "8");
    CustomButton* m_9 = new CustomButton(this, wxID_ANY, "9");
    CustomButton* m_mul = new CustomButton(this, wxID_ANY, wxString::FromUTF8("\xC3\x97"));
    CustomButton* m_4 = new CustomButton(this, wxID_ANY, "4");
    CustomButton* m_5 = new CustomButton(this, wxID_ANY, "5");
    CustomButton* m_6 = new CustomButton(this, wxID_ANY, "6");
    CustomButton* m_minus = new CustomButton(this, wxID_ANY, "-");
    CustomButton* m_1 = new CustomButton(this, wxID_ANY, "1");
    CustomButton* m_2 = new CustomButton(this, wxID_ANY, "2");
    CustomButton* m_3 = new CustomButton(this, wxID_ANY, "3");
    CustomButton* m_plus = new CustomButton(this, wxID_ANY, "+");
    CustomButton* m_0 = new CustomButton(this, wxID_ANY, "0");
    CustomButton* m_point = new CustomButton(this, wxID_ANY, ".");
    CustomButton* m_equals = new CustomButton(this, wxID_ANY, "=");

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
    sizer->Add(m_0,
               wxGBPosition(4, 0),
               wxGBSpan(1, 2),
               wxEXPAND | wxALL,
               1); // Span de 1 fila y 2 columnas
    sizer->Add(m_point, wxGBPosition(4, 2), wxDefaultSpan, wxEXPAND | wxALL, 1);
    sizer->Add(m_equals, wxGBPosition(4, 3), wxDefaultSpan, wxEXPAND | wxALL, 1);

    // Hacer que todas las filas y columnas se expandan
    for (int i = 0; i < 5; ++i)
        sizer->AddGrowableRow(i);
    for (int j = 0; j < 4; ++j)
        sizer->AddGrowableCol(j);

    this->SetSizer(sizer);
    m_parent = parent;

    // m_minus->Bind(wxEVT_BUTTON, &BotPanel::OnMinus, this);
    // m_mul->Bind(wxEVT_BUTTON, &BotPanel::OnMul, this);
    wxAcceleratorEntry entries[11];
    entries[0].Set(wxACCEL_NORMAL, WXK_NUMPAD0, ID_0);
    entries[1].Set(wxACCEL_NORMAL, WXK_NUMPAD1, ID_1);
    entries[2].Set(wxACCEL_NORMAL, WXK_NUMPAD2, ID_2);
    entries[3].Set(wxACCEL_NORMAL, WXK_NUMPAD3, ID_3);
    entries[4].Set(wxACCEL_NORMAL, WXK_NUMPAD4, ID_4);
    entries[5].Set(wxACCEL_NORMAL, WXK_NUMPAD5, ID_5);
    entries[6].Set(wxACCEL_NORMAL, WXK_NUMPAD6, ID_6);
    entries[7].Set(wxACCEL_NORMAL, WXK_NUMPAD7, ID_7);
    entries[8].Set(wxACCEL_NORMAL, WXK_NUMPAD8, ID_8);
    entries[9].Set(wxACCEL_NORMAL, WXK_NUMPAD9, ID_9);
    entries[10].Set(wxACCEL_NORMAL, WXK_NUMPAD_ADD, ID_PLUS);
    entries[11].Set(wxACCEL_NORMAL, WXK_NUMPAD_DECIMAL, ID_DOT);

    wxAcceleratorTable accel(12, entries);

    // Asignar el objeto wxAcceleratorTable a la ventana
    SetAcceleratorTable(accel);

    Bind(wxEVT_MENU, &BotPanel::OnNumpad0, this, ID_0);
    Bind(wxEVT_MENU, &BotPanel::OnNumpad1, this, ID_1);
    Bind(wxEVT_MENU, &BotPanel::OnNumpad2, this, ID_2);
    Bind(wxEVT_MENU, &BotPanel::OnNumpad3, this, ID_3);
    Bind(wxEVT_MENU, &BotPanel::OnNumpad4, this, ID_4);
    Bind(wxEVT_MENU, &BotPanel::OnNumpad5, this, ID_5);
    Bind(wxEVT_MENU, &BotPanel::OnNumpad6, this, ID_6);
    Bind(wxEVT_MENU, &BotPanel::OnNumpad7, this, ID_7);
    Bind(wxEVT_MENU, &BotPanel::OnNumpad8, this, ID_8);
    Bind(wxEVT_MENU, &BotPanel::OnNumpad9, this, ID_9);
    Bind(wxEVT_MENU, &BotPanel::OnPlus, this, ID_PLUS);
    Bind(wxEVT_MENU, &BotPanel::OnDot, this, ID_DOT);
}

void BotPanel::OnNumpad0(wxCommandEvent& event)
{
    Calculator* comm = (Calculator*) m_parent->GetParent();
    wxString valorActual = comm->m_tp->m_text->GetValue();

    // 1. Eliminar separadores de miles y decimales temporales
    wxChar thousandsSep, decimalSep;
    bool hasThousandsSep = wxNumberFormatter::GetThousandsSeparatorIfUsed(&thousandsSep);
    decimalSep = wxNumberFormatter::GetDecimalSeparator();

    if (hasThousandsSep)
    {
        valorActual.Replace(wxString(thousandsSep), ""); // Eliminar puntos (ej: "1.000" → "1000")
    }

    // 2. Agregar el dígito "0" al número actual
    valorActual += "0";

    // 3. Convertir a double (maneja comas decimales)
    double numero;
    if (!wxNumberFormatter::FromString(valorActual, &numero))
    {
        numero = 0.0; // Si hay error, reiniciar a 0
    }

    // 4. Formatear el número con separadores
    wxString valorFormateado;

    // Determinar si el número tiene decimales
    int posDecimal = valorActual.Find(decimalSep);
    int decimales = (posDecimal != wxNOT_FOUND) ? (valorActual.length() - posDecimal - 1) : 0;

    // Formatear con separadores de miles y decimales
    valorFormateado = wxNumberFormatter::ToString(numero, decimales);

    comm->m_tp->m_text->SetValue(valorFormateado);
}

void BotPanel::OnNumpad1(wxCommandEvent& event)
{
    Calculator* comm = (Calculator*) m_parent->GetParent();
    wxString valor = comm->m_tp->m_text->GetValue();
    valor += "1";
    comm->m_tp->m_text->SetValue(valor);
}

void BotPanel::OnNumpad2(wxCommandEvent& event)
{
    Calculator* comm = (Calculator*) m_parent->GetParent();
    wxString valor = comm->m_tp->m_text->GetValue();
    valor += "2";
    comm->m_tp->m_text->SetValue(valor);
}

void BotPanel::OnNumpad3(wxCommandEvent& event)
{
    Calculator* comm = (Calculator*) m_parent->GetParent();
    wxString valor = comm->m_tp->m_text->GetValue();
    valor += "3";
    comm->m_tp->m_text->SetValue(valor);
}

void BotPanel::OnNumpad4(wxCommandEvent& event)
{
    Calculator* comm = (Calculator*) m_parent->GetParent();
    wxString valor = comm->m_tp->m_text->GetValue();
    valor += "4";
    comm->m_tp->m_text->SetValue(valor);
}

void BotPanel::OnNumpad5(wxCommandEvent& event)
{
    Calculator* comm = (Calculator*) m_parent->GetParent();
    wxString valor = comm->m_tp->m_text->GetValue();
    valor += "5";
    comm->m_tp->m_text->SetValue(valor);
}

void BotPanel::OnNumpad6(wxCommandEvent& event)
{
    Calculator* comm = (Calculator*) m_parent->GetParent();
    wxString valor = comm->m_tp->m_text->GetValue();
    valor += "6";
    comm->m_tp->m_text->SetValue(valor);
}

void BotPanel::OnNumpad7(wxCommandEvent& event)
{
    Calculator* comm = (Calculator*) m_parent->GetParent();
    wxString valor = comm->m_tp->m_text->GetValue();
    valor += "7";
    comm->m_tp->m_text->SetValue(valor);
}

void BotPanel::OnNumpad8(wxCommandEvent& event)
{
    Calculator* comm = (Calculator*) m_parent->GetParent();
    wxString valor = comm->m_tp->m_text->GetValue();
    valor += "8";
    comm->m_tp->m_text->SetValue(valor);
}

void BotPanel::OnNumpad9(wxCommandEvent& event)
{
    Calculator* comm = (Calculator*) m_parent->GetParent();
    wxString valor = comm->m_tp->m_text->GetValue();
    valor += "9";
    comm->m_tp->m_text->SetValue(valor);
}

void BotPanel::OnDot(wxCommandEvent& event)
{
    Calculator* comm = (Calculator*) m_parent->GetParent();
    wxString valor = comm->m_tp->m_text->GetValue();
    valor += ".";
    comm->m_tp->m_text->SetValue(valor);
}

void BotPanel::OnPlus(wxCommandEvent& event)
{
    Calculator* comm = (Calculator*) m_parent->GetParent();
    wxString prevText = comm->m_tp->m_text->GetValue();
    prevText += " + ";
    comm->m_pp->m_text->SetLabel(prevText);
    comm->m_tp->m_text->SetLabel(wxString(""));
}

void BotPanel::OnMinus(wxCommandEvent& event)
{
    wxMessageBox("Se hizo clic en el boton -");
}

void BotPanel::OnMul(wxCommandEvent& event)
{
    wxMessageBox("Se hizo clic en el boton *");
}
