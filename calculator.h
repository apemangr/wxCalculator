#pragma once
#include "panels.h"
#include <wx/wxprec.h>

class Calculator : public wxFrame
{
public:
    Calculator(const wxString& title);
    void OnKeyDown(wxKeyEvent& event);
    PrevPanel* m_pp;
    TopPanel* m_tp;
    BotPanel* m_bp;

    wxPanel* m_parent;
    wxPanel* m_top_parent;
    bool copiedToPrevPanel;
};
