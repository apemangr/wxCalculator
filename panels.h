#pragma once
#include "custom-button.h"
#include <wx/panel.h>
#include <wx/wx.h>

class TopPanel : public wxPanel
{
public:
    TopPanel(wxPanel* parent);

    void OnSetText(wxCommandEvent& event);
    wxTextCtrl* m_text;
};

class PrevPanel : public wxPanel
{
public:
    PrevPanel(wxPanel* parent);
    void OnSetText(wxCommandEvent& event);
    wxTextCtrl* m_text;
};

class BotPanel : public wxPanel
{
public:
    BotPanel(wxPanel* parent);

    void OnNumpad0(wxCommandEvent& event);
    void OnNumpad1(wxCommandEvent& event);
    void OnNumpad2(wxCommandEvent& event);
    void OnNumpad3(wxCommandEvent& event);
    void OnNumpad4(wxCommandEvent& event);
    void OnNumpad5(wxCommandEvent& event);
    void OnNumpad6(wxCommandEvent& event);
    void OnNumpad7(wxCommandEvent& event);
    void OnNumpad8(wxCommandEvent& event);
    void OnNumpad9(wxCommandEvent& event);
    void OnDot(wxCommandEvent& event);
    void OnPlus(wxCommandEvent& event);

    void OnMinus(wxCommandEvent& event);
    void OnMul(wxCommandEvent& event);

    CustomButton* m_ac;
    CustomButton* m_pm;
    CustomButton* m_percent;
    CustomButton* m_div;
    CustomButton* m_7;
    CustomButton* m_8;
    CustomButton* m_9;
    CustomButton* m_mul;
    CustomButton* m_4;
    CustomButton* m_5;
    CustomButton* m_6;
    CustomButton* m_minus;
    CustomButton* m_1;
    CustomButton* m_2;
    CustomButton* m_3;
    CustomButton* m_plus;
    CustomButton* m_0;
    CustomButton* m_point;
    CustomButton* m_equals;

    wxPanel* m_parent;
};

enum
{
    ID_0 = 1000,
    ID_1,
    ID_2,
    ID_3,
    ID_4,
    ID_5,
    ID_6,
    ID_7,
    ID_8,
    ID_9,
    ID_PLUS,
    ID_MINUS,
    ID_MUL,
    ID_DOT
};
