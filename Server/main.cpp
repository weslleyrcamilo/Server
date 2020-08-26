#include "ServerGUI.h"
#include "NewCarForm.h"
#include <iostream>

using namespace Server;

[STAThreadAttribute]
int main (){

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew ServerGUI());

	system("pause");
	return 0;
	 
}
