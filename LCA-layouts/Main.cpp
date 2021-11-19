#include "Main.h"

Main::Main() : wxFrame(nullptr, wxID_ANY, "LETA", wxPoint(-1, -1), wxSize(1450, 768))
{
	this->SetMinSize(wxSize(480, 360));
	this->SetFont(wxFont(17, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));

	notebook = new wxNotebook(this, wxID_ANY, wxDefaultPosition, wxSize(300, 200));

	// Create and add the pages
	type_panel = new TypePanel(notebook);
	create_panel = new CreatePanel(notebook);
	doc_panel = new DocPanel(notebook);

	notebook->AddPage(type_panel, wxT("Typing"), true);
	notebook->AddPage(create_panel, wxT("Create"), false);
	notebook->AddPage(doc_panel, wxT("Documentation"), false);
}

Main::~Main() 
{
	delete type_panel;
	delete create_panel;
	delete doc_panel;
	delete notebook;
}
