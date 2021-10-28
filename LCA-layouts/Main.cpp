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

	type_sizer->Add(text_to_type, 1, wxALL | wxEXPAND, 30);
	type_panel->SetSizer(type_sizer);

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