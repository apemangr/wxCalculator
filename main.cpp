#include "main.h"
#include "calculator.h"

IMPLEMENT_APP(CalculatorApp)

bool CalculatorApp::OnInit()
{
    Calculator *calculator = new Calculator(wxT("wxCalculator"));
    calculator->Show(true);
    
    return true;
}
