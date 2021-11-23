#include "App.h"

wxIMPLEMENT_APP(App);

bool App::OnInit() 
{
	_frame = new Main();
	_frame->Show();

	return true;
}
