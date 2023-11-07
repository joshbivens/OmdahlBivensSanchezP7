/*Section done by:
Name: Alexsia Omdahl
Email: aomdahl1@cnm.edu
Program: C++ Craps Game Group Project
File Name: OmdahlBivensSanchezP7*/

#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThread]
void Main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	OmdahlBivensSanchezP7::MyForm form;
	Application::Run(% form);
}