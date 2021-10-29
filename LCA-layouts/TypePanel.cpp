#include "TypePanel.h"

TypePanel::TypePanel(wxWindow* parent) : wxPanel(parent, wxID_ANY)
{

	text_to_type = new wxStaticText(this, -1, "Сдесь генерируемый текст i you the me upper down back apple man work juice dad father mum house chicken open door window house rare heigh");
	type_word = new wxStaticText(this, -1, "|");
	sizer = new wxBoxSizer(wxVERTICAL);

	sizer->Add(text_to_type, 1, wxALL | wxEXPAND, 50);
	sizer->Add(type_word, 1, wxALL | wxEXPAND, 50);
	this->SetSizer(sizer);

	Bind(wxEVT_CHAR_HOOK, &TypePanel::OnChar, this);
}

TypePanel::~TypePanel() {

}

void TypePanel::OnChar(wxKeyEvent& evt) {
	if (evt.GetKeyCode() == WXK_SPACE) {
	}
	else if (evt.GetKeyCode() == WXK_BACK) {
		if (type_word->GetLabel().Length() >= 1) {
			type_word->SetLabel(type_word->GetLabel().erase(type_word->GetLabel().Length() - 1));
		}
	}
	else {
		type_word->SetLabel(type_word->GetLabel() + char(evt.GetKeyCode()));
	}
	evt.Skip();
}