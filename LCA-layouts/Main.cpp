#include "Main.h"

Main::Main() : wxFrame(nullptr, wxID_ANY, "LETA", wxPoint(-1, -1), wxSize(1450, 768))
{
	this->SetMinSize(wxSize(480, 360));
	this->SetFont(wxFont(17, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));

	_notebook = new wxNotebook(this, wxID_ANY, wxDefaultPosition, wxSize(300, 200));

	// Create and add the pages
	_typePanel = new TypePanel(_notebook);
	_createPanel = new CreatePanel(_notebook);
	_docPanel = new DocPanel(_notebook);

	_notebook->AddPage(_typePanel, wxT("Typing"), true);
	_notebook->AddPage(_createPanel, wxT("Create"), false);
	_notebook->AddPage(_docPanel, wxT("Documentation"), false);
}

Main::~Main() 
{
	delete _typePanel;
	delete _createPanel;
	delete _docPanel;
	delete _notebook;
}
