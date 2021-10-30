#include "TypePanel.h"

TypePanel::TypePanel(wxWindow* parent) : wxPanel(parent, wxID_ANY)
{
	this->SetBackgroundColour(wxColor(87, 87, 87));
	this->SetForegroundColour(wxColor(200, 200, 200));

	gen.GenText(2);

	text_to_type = new wxStaticText(this, -1, gen.GetText());
	type_word = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(380, -1));
	result = new wxStaticText(this, -1, wxEmptyString);


	vsizer = new wxBoxSizer(wxVERTICAL);
	hsizer = new wxBoxSizer(wxHORIZONTAL);

	vsizer->Add(text_to_type, 1, wxALL | wxEXPAND, 50);
	hsizer->Add(type_word, 1, wxALIGN_CENTER_VERTICAL);
	vsizer->Add(hsizer, 1, wxALIGN_CENTER_HORIZONTAL);
	vsizer->Add(result, 1);

	this->SetSizer(vsizer);

	type_word->Bind(wxEVT_CHAR, &TypePanel::OnChar, this);
}

TypePanel::~TypePanel() {

}

void TypePanel::OnChar(wxKeyEvent& evt) {
	if (evt.GetKeyCode() == WXK_SPACE) {
		if (type_word->GetValue() == gen.GetWords()[word_index]) {
			test++;
		}

		type_word->SetValue(wxEmptyString);
		word_index++;
	}
	else {
		if (is_going == false) {
			is_going = true;
			word_index = 0;
			test.SetWords(gen.GetCount());
			timer = time(NULL);
			
		}
		if (type_word->GetValue() == " ") {
			type_word->SetValue(wxEmptyString);
		}
	}

	if (word_index == gen.GetWords().size()) {
		is_going = false;
		test.SetTime(difftime(timer, time(NULL)));
		test.Result();
		result->SetLabel("wpm: " + to_string(test.WPM()) + " acc: " + to_string(test.ACC()) + "%");

		test.Reset();
		gen.GenText(10);
		text_to_type->SetLabel(gen.GetText());
	}

	evt.Skip();
}