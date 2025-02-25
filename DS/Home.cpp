#include "Home.h"
#include "Graph.h"
#include "CreateNewGraph.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main() {

    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew DS::Home);
    
}