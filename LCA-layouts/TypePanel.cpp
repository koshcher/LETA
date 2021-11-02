#include "TypePanel.h"

TypePanel::TypePanel(wxWindow* parent) : wxPanel(parent, wxID_ANY)
{
	this->SetBackgroundColour(wxColor(87, 87, 87));
	this->SetForegroundColour(wxColor(200, 200, 200));

	gen.GenText(10);

	text_to_type = new wxStaticText(this, wxID_ANY, gen.GetText(), wxDefaultPosition, wxDefaultSize, wxST_ELLIPSIZE_END | wxST_NO_AUTORESIZE);
	type_word = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(380, -1));
	result = new wxStaticText(this, wxID_ANY, wxEmptyString);


	vsizer = new wxBoxSizer(wxVERTICAL);
	hsizer = new wxBoxSizer(wxHORIZONTAL);
	to_type_sizer = new wxBoxSizer(wxHORIZONTAL);

	//to_type_sizer->Add(text_to_type);
	hsizer->Add(type_word, 1, wxALIGN_CENTER_VERTICAL);

	vsizer->Add(text_to_type, 1, wxALL | wxEXPAND, 50);
//	vsizer->Add(to_type_sizer, 1, wxALIGN_CENTER_HORIZONTAL);
	vsizer->Add(hsizer, 1, wxALIGN_CENTER_HORIZONTAL);
	vsizer->Add(result, 1, wxALIGN_CENTER_HORIZONTAL);

	this->SetSizer(vsizer);

	type_word->Bind(wxEVT_CHAR, &TypePanel::OnChar, this);
}

TypePanel::~TypePanel() {

}

void TypePanel::OnChar(wxKeyEvent& evt) {
	if (is_going == false) {
		is_going = true;
		word_index = 0;
		test.SetWords(gen.GetCount());
		timer = time(NULL);
		word_index = 0;
	}
	if (evt.GetKeyCode() == WXK_SPACE) {
		if (type_word->GetValue() == gen.GetWords()[word_index]) {
			test++;
		}

		wxString str = text_to_type->GetLabel();
		str.erase(0, (str.find(" ") + 1));
		text_to_type->SetLabel(str);

		type_word->SetValue(wxEmptyString);
		word_index++;
	}
	else {
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
		word_index = 0;
	}

	evt.Skip();
}