#include "Main.h"

wxBEGIN_EVENT_TABLE(Main, wxFrame)


wxEND_EVENT_TABLE()


Main::Main() : wxFrame(nullptr, wxID_ANY, "LCA layouts", wxPoint(-1, -1), wxSize(720, 480))
{
	this->SetMinSize(wxSize(480, 360));
	//this->SetFont(wxFont(13, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));

	notebook = new wxNotebook(this, wxID_ANY, wxDefaultPosition, wxSize(300, 200));

	// Create and add the pages
	type_panel = new wxPanel(notebook, wxID_ANY);
	create_panel = new wxPanel(notebook, wxID_ANY);
	doc_panel = new wxPanel(notebook, wxID_ANY);

	notebook->AddPage(type_panel, wxT("Typing"), true);
	notebook->AddPage(create_panel, wxT("Create"), false);
	notebook->AddPage(doc_panel, wxT("Documentation"), false);

	// Typing panel
	text_to_type = new wxStaticText(type_panel, -1, "Сдесь генерируемый текст i you the me upper down back apple man work juice dad father mum house chicken open door window house rare heigh");
	type_sizer = new wxBoxSizer(wxVERTICAL);

	type_sizer->Add(text_to_type, 1, wxALL | wxEXPAND, 50);
	type_panel->SetSizer(type_sizer);


	// Create panel
	create_row_sizer = new wxBoxSizer(wxVERTICAL);

	keys.insert(pair<wxBoxSizer*, wxButton**>( new wxBoxSizer(wxHORIZONTAL), new wxButton* [14]));
	keys.insert(pair<wxBoxSizer*, wxButton**>(new wxBoxSizer(wxHORIZONTAL), new wxButton * [13]));
	keys.insert(pair<wxBoxSizer*, wxButton**>(new wxBoxSizer(wxHORIZONTAL), new wxButton * [12]));

	map<wxBoxSizer*, wxButton**>::iterator keys_iter = keys.begin();
	
	// First row
	keys_iter->second[0] = new wxButton(create_panel, -1, "Tab");
	keys_iter->second[1] = new wxButton(create_panel, 1, "q");
	keys_iter->second[2] = new wxButton(create_panel, 2, "w");
	keys_iter->second[3] = new wxButton(create_panel, 3, "e");
	keys_iter->second[4] = new wxButton(create_panel, 4, "r");
	keys_iter->second[5] = new wxButton(create_panel, 5, "t");
	keys_iter->second[6] = new wxButton(create_panel, 6, "y");
	keys_iter->second[7] = new wxButton(create_panel, 7, "u");
	keys_iter->second[8] = new wxButton(create_panel, 8, "i");
	keys_iter->second[9] = new wxButton(create_panel, 9, "o");
	keys_iter->second[10] = new wxButton(create_panel, 10, "p");
	keys_iter->second[11] = new wxButton(create_panel, 11, "[");
	keys_iter->second[12] = new wxButton(create_panel, 12, "]");
	keys_iter->second[13] = new wxButton(create_panel, 13, "\\");

	keys_iter->first->Add(keys_iter->second[0], 5, wxEXPAND | wxALL);
	for (int col = 1; col < 13; col++) {
		keys_iter->first->Add(keys_iter->second[col], 3, wxEXPAND | wxALL);
	}
	keys_iter->first->Add(keys_iter->second[13], 5, wxEXPAND | wxALL);
	keys_iter++;

	// Second row
	keys_iter->second[0] = new wxButton(create_panel, -1, "Caps lock");
	keys_iter->second[1] = new wxButton(create_panel, 14, "a");
	keys_iter->second[2] = new wxButton(create_panel, 15, "s");
	keys_iter->second[3] = new wxButton(create_panel, 16, "d");
	keys_iter->second[4] = new wxButton(create_panel, 17, "f");
	keys_iter->second[5] = new wxButton(create_panel, 18, "g");
	keys_iter->second[6] = new wxButton(create_panel, 19, "h");
	keys_iter->second[7] = new wxButton(create_panel, 20, "j");
	keys_iter->second[8] = new wxButton(create_panel, 21, "k");
	keys_iter->second[9] = new wxButton(create_panel, 22, "l");
	keys_iter->second[10] = new wxButton(create_panel, 23, ";");
	keys_iter->second[11] = new wxButton(create_panel, 24, "'");
	keys_iter->second[12] = new wxButton(create_panel, -1, "Enter");

	keys_iter->first->Add(keys_iter->second[0], 6, wxEXPAND | wxALL);
	for (int col = 1; col < 12; col++) {
		keys_iter->first->Add(keys_iter->second[col], 3, wxEXPAND | wxALL);
	}
	keys_iter->first->Add(keys_iter->second[12], 7, wxEXPAND | wxALL);
	keys_iter++;

	// Third row
	keys_iter->second[0] = new wxButton(create_panel, -1, "Shift");
	keys_iter->second[1] = new wxButton(create_panel, 25, "z");
	keys_iter->second[2] = new wxButton(create_panel, 26, "x");
	keys_iter->second[3] = new wxButton(create_panel, 27, "c");
	keys_iter->second[4] = new wxButton(create_panel, 28, "v");
	keys_iter->second[5] = new wxButton(create_panel, 29, "b");
	keys_iter->second[6] = new wxButton(create_panel, 30, "n");
	keys_iter->second[7] = new wxButton(create_panel, 31, "m");
	keys_iter->second[8] = new wxButton(create_panel, 32, ",");
	keys_iter->second[9] = new wxButton(create_panel, 33, ".");
	keys_iter->second[10] = new wxButton(create_panel, 34, "/");
	keys_iter->second[11] = new wxButton(create_panel, -1, "Shift");

	keys_iter->first->Add(keys_iter->second[0], 8, wxEXPAND | wxALL);
	for (int col = 1; col < 11; col++) {
		keys_iter->first->Add(keys_iter->second[col], 3, wxEXPAND | wxALL);
	}
	keys_iter->first->Add(keys_iter->second[11], 8, wxEXPAND | wxALL);

	keys_iter++;

	// Connect sizers
	keys_iter = keys.begin();
	for (; keys_iter != keys.end(); keys_iter++) {
		create_row_sizer->Add(keys_iter->first, wxEXPAND | wxALL);
	}

	create_panel->SetSizer(create_row_sizer);

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

}


/*
void Main::OnChar(wxKeyEvent& evt) {
	if (evt.GetKeyCode() == WXK_SPACE) {
	}
	else if (evt.GetKeyCode() == WXK_BACK) {

		//text_to_type->SetLabel(text_to_type->GetLabel().erase(text_to_type->GetLabel().Length() - 1));
	}
	else {
		//text_to_type->SetLabel(text_to_type->GetLabel() + char(evt.GetKeyCode()));
	}

	evt.Skip();
}
*/