#include "TypePanel.h"

TypePanel::TypePanel(wxWindow* parent) : wxPanel(parent, wxID_ANY)
{
	this->SetBackgroundColour(wxColor(87, 87, 87));
	this->SetForegroundColour(wxColor(200, 200, 200));
	text_to_type = new wxStaticText(this, -1, "Сдесь генерируемый текст i you the me upper down back apple man work juice dad father mum house chicken open door window house rare heigh");
	type_word = new wxTextCtrl(this, wxID_ANY);

	vsizer = new wxBoxSizer(wxVERTICAL);
	hsizer = new wxBoxSizer(wxHORIZONTAL);

	vsizer->Add(text_to_type, 1, wxALL | wxEXPAND, 50);
	hsizer->Add(type_word, 1, wxALIGN_CENTER_VERTICAL);
	vsizer->Add(hsizer, 1, wxALIGN_CENTER_HORIZONTAL);
	this->SetSizer(vsizer);

	type_word->Bind(wxEVT_CHAR, &TypePanel::OnChar, this);
}

TypePanel::~TypePanel() {

}

void TypePanel::OnChar(wxKeyEvent& evt) {
	if (evt.GetKeyCode() == WXK_SPACE) {
		text_to_type->SetLabel(text_to_type->GetLabel() + " " + type_word->GetValue());
		type_word->SetValue("");
	}

	evt.Skip();
}