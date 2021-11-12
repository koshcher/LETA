#include "Main.h"

Main::Main() : wxFrame(nullptr, wxID_ANY, "LCA layouts", wxPoint(-1, -1), wxSize(1450, 768))
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

	// Typing panel

	// Create panel

	// Documentation panel


	/*
	wxImage type_img;
	type_img.AddHandler(new wxPNGHandler);
	type_img.LoadFile("img/type_text.png");

	wxImage create_img;
	create_img.AddHandler(new wxPNGHandler);
	create_img.LoadFile("img/writing.png");

	wxImage documentation_img;
	documentation_img.AddHandler(new wxPNGHandler);
	documentation_img.LoadFile("img/documentation.png");
	*/

}

Main::~Main() {
	/*
	map<wxBoxSizer*, wxButton**>::iterator keys_iter = keys.begin();

	for (; keys_iter != keys.end(); keys_iter++) {
		delete[] keys_iter->second;
	}
	*/
}
