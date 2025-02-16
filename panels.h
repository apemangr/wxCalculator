#pragma once
#include <wx/wx.h>
#include <wx/panel.h>
#include "custom-button.h"

class TopPanel : public wxPanel
{
public:
    TopPanel(wxPanel *parent);
    void OnSetText(wxCommandEvent &event);
    wxTextCtrl *m_text;
};

class PrevPanel : public wxPanel
{
public:
    PrevPanel(wxPanel *parent);
    void OnSetText(wxCommandEvent &event);
    wxTextCtrl *m_text;
};

class BotPanel : public wxPanel
{
public:
    BotPanel(wxPanel *parent);
    void OnPlus(wxCommandEvent & event);
    void OnMinus(wxCommandEvent & event);
    void OnMul(wxCommandEvent & event);

    CustomButton *m_plus;
    wxButton *m_minus;
    wxButton *m_mul;
    wxPanel  *m_parent;
    int count;
};

enum{
    ID_PLUS = 100,
    ID_MINUS,
    ID_MUL
};
