#include "App.h"

wxIMPLEMENT_APP(App);

bool App::OnInit() 
{
	m_frame = new Main();
	m_frame->Show();

	return true;
}