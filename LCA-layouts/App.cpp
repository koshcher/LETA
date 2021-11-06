#include "App.h"

wxIMPLEMENT_APP(App);

bool App::OnInit() 
{
	frame = new Main();
	frame->Show();

	return true;
}
