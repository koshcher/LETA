#include "Main.h"

wxBEGIN_EVENT_TABLE(Main, wxFrame)

	EVT_CHAR(OnChar)

wxEND_EVENT_TABLE()


Main::Main() : wxFrame(nullptr, wxID_ANY, "LCA layouts", wxPoint(-1, -1), wxSize(720, 480))
{
	// меню
	menubar = new wxMenuBar();
	type = new wxMenu;
	create = new wxMenu;
	doc = new wxMenu;

	menubar->Append(type, "&Type");
	menubar->Append(create, "&Create");
	menubar->Append(doc, "&Documentation");
	SetMenuBar(menubar);

	// Panel
	panel = new wxPanel(this, -1);

	hbox = new wxBoxSizer(wxVERTICAL);

	text_to_type = new wxStaticText(panel, -1, "Сдесь генерируемый текст i you the me upper down back apple man work juice dad father mum house chicken open door window house rare heigh"); //, wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL | wxTE_RICH2 | wxTE_MULTILINE);
	start = new wxButton(panel, wxID_ANY, "Start"); //, wxPoint(-1, -1), wxSize(100, 100));

//fgs = new wxFlexGridSizer(2, 1, 9, 25);
	//fgs->Add(text_to_type, wxALL, 15);
	//fgs->Add(start);

	//hbox->Add(fgs, 1, wxALL | wxEXPAND, 15);
	hbox->Add(text_to_type, 1, wxALIGN_TOP | wxALL | wxEXPAND, 50);
	hbox->Add(start);

	panel->SetSizer(hbox);

	//Center();
	/*
	panel = new wxPanel(this, -1);
	wxBoxSizer* hbox = new wxBoxSizer(wxHORIZONTAL); wxHORIZONTAL | wxVERTICAL
	wxFlexGridSizer* fgs = new wxFlexGridSizer(3, 2, 9, 25);

	wxStaticText* title = new wxStaticText(panel, -1, wxT("Titleddddddddddddddddddddddddddddddd"), wxPoint(-1, -1), wxSize(-1, -1), wxTE_MULTILINE);
	wxStaticText* author = new wxStaticText(panel, -1, wxT("Author"));
	wxStaticText* review = new wxStaticText(panel, -1, wxT("Review"));

	wxTextCtrl* tc1 = new wxTextCtrl(panel, -1);
	wxTextCtrl* tc2 = new wxTextCtrl(panel, -1);
	wxTextCtrl* tc3 = new wxTextCtrl(panel, -1, wxT(""), wxPoint(-1, -1), wxSize(-1, -1), wxTE_MULTILINE);

	fgs->Add(title);
	fgs->Add(tc1, 1, wxEXPAND);
	fgs->Add(author);
	fgs->Add(tc2, 1, wxEXPAND);
	fgs->Add(review);
	fgs->Add(tc3, 1, wxEXPAND);

	fgs->AddGrowableRow(2, 1);
	fgs->AddGrowableCol(1, 1);

	hbox->Add(fgs, 1, wxALL | wxEXPAND, 15);
	panel->SetSizer(hbox);
	Center();
	*/
}

Main::~Main() {

}



void Main::OnChar(wxKeyEvent& evt) {
	if (evt.GetKeyCode() == WXK_SPACE) {
	}
	else if (evt.GetKeyCode() == WXK_BACK) {

		text_to_type->SetLabel(text_to_type->GetLabel().erase(text_to_type->GetLabel().Length() - 1));
	}
	else {
		text_to_type->SetLabel(text_to_type->GetLabel() + char(evt.GetKeyCode()));
	}

	evt.Skip();
}