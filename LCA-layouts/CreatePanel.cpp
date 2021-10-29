#include "CreatePanel.h"


CreatePanel::CreatePanel(wxWindow* parent) : wxPanel(parent, wxID_ANY)
{
	create_row_sizer = new wxBoxSizer(wxVERTICAL);

	keys.insert(pair<wxBoxSizer*, wxButton**>(new wxBoxSizer(wxHORIZONTAL), new wxButton * [14]));
	keys.insert(pair<wxBoxSizer*, wxButton**>(new wxBoxSizer(wxHORIZONTAL), new wxButton * [13]));
	keys.insert(pair<wxBoxSizer*, wxButton**>(new wxBoxSizer(wxHORIZONTAL), new wxButton * [12]));

	map<wxBoxSizer*, wxButton**>::iterator keys_iter = keys.begin();

	// First row
	keys_iter->second[0] = new wxButton(this, -1, "Tab", wxDefaultPosition, wxSize(-1, 90));
	keys_iter->second[0]->Enable(false);
	keys_iter->second[1] = new wxButton(this, 1, "q");
	keys_iter->second[1]->SetBackgroundColour(wxColor(129, 197, 197));
	keys_iter->second[2] = new wxButton(this, 2, "w");
	keys_iter->second[2]->SetBackgroundColour(wxColor(203, 129, 203));
	keys_iter->second[3] = new wxButton(this, 3, "e");
	keys_iter->second[3]->SetBackgroundColour(wxColor(129, 184, 129));
	keys_iter->second[4] = new wxButton(this, 4, "r");
	keys_iter->second[4]->SetBackgroundColour(wxColor(123, 148, 193));
	keys_iter->second[5] = new wxButton(this, 5, "t");
	keys_iter->second[5]->SetBackgroundColour(wxColor(123, 148, 193));
	keys_iter->second[6] = new wxButton(this, 6, "y");
	keys_iter->second[6]->SetBackgroundColour(wxColor(129, 129, 203));
	keys_iter->second[7] = new wxButton(this, 7, "u");
	keys_iter->second[7]->SetBackgroundColour(wxColor(129, 129, 203));
	keys_iter->second[8] = new wxButton(this, 8, "i");
	keys_iter->second[8]->SetBackgroundColour(wxColor(129, 184, 129));
	keys_iter->second[9] = new wxButton(this, 9, "o");
	keys_iter->second[9]->SetBackgroundColour(wxColor(203, 129, 203));
	keys_iter->second[10] = new wxButton(this, 10, "p");
	keys_iter->second[10]->SetBackgroundColour(wxColor(129, 197, 197));
	keys_iter->second[11] = new wxButton(this, 11, "[");
	keys_iter->second[11]->SetBackgroundColour(wxColor(129, 197, 197));
	keys_iter->second[12] = new wxButton(this, 12, "]");
	keys_iter->second[12]->SetBackgroundColour(wxColor(129, 197, 197));
	keys_iter->second[13] = new wxButton(this, 13, "\\");
	keys_iter->second[13]->SetBackgroundColour(wxColor(129, 197, 197));

	for (int i = 0; i < 14; i++) {
		keys_iter->second[i]->Bind(wxEVT_BUTTON, &CreatePanel::OnKeyClicked, this);
	}

	keys_iter->first->Add(keys_iter->second[0], 5, wxEXPAND);
	for (int col = 1; col < 13; col++) {
		keys_iter->first->Add(keys_iter->second[col], 3, wxEXPAND);
	}
	keys_iter->first->Add(keys_iter->second[13], 5, wxEXPAND);
	keys_iter++;

	// Second row
	keys_iter->second[0] = new wxButton(this, -1, "Caps", wxDefaultPosition, wxSize(-1, 90));
	keys_iter->second[0]->Enable(false);
	keys_iter->second[1] = new wxButton(this, 14, "a");
	keys_iter->second[1]->SetBackgroundColour(wxColor(129, 197, 197));
	keys_iter->second[2] = new wxButton(this, 15, "s");
	keys_iter->second[2]->SetBackgroundColour(wxColor(203, 129, 203));
	keys_iter->second[3] = new wxButton(this, 16, "d");
	keys_iter->second[3]->SetBackgroundColour(wxColor(129, 184, 129));
	keys_iter->second[4] = new wxButton(this, 17, "f");
	keys_iter->second[4]->SetBackgroundColour(wxColor(123, 148, 193));
	keys_iter->second[5] = new wxButton(this, 18, "g");
	keys_iter->second[5]->SetBackgroundColour(wxColor(123, 148, 193));
	keys_iter->second[6] = new wxButton(this, 19, "h");
	keys_iter->second[6]->SetBackgroundColour(wxColor(129, 129, 203));
	keys_iter->second[7] = new wxButton(this, 20, "j");
	keys_iter->second[7]->SetBackgroundColour(wxColor(129, 129, 203));
	keys_iter->second[8] = new wxButton(this, 21, "k");
	keys_iter->second[8]->SetBackgroundColour(wxColor(129, 184, 129));
	keys_iter->second[9] = new wxButton(this, 22, "l");
	keys_iter->second[9]->SetBackgroundColour(wxColor(203, 129, 203));
	keys_iter->second[10] = new wxButton(this, 23, ";");
	keys_iter->second[10]->SetBackgroundColour(wxColor(129, 197, 197));
	keys_iter->second[11] = new wxButton(this, 24, "'");
	keys_iter->second[11]->SetBackgroundColour(wxColor(129, 197, 197));
	keys_iter->second[12] = new wxButton(this, -1, "Enter");
	keys_iter->second[12]->Enable(false);

	for (int i = 0; i < 13; i++) {
		keys_iter->second[i]->Bind(wxEVT_BUTTON, &CreatePanel::OnKeyClicked, this);
	}

	keys_iter->first->Add(keys_iter->second[0], 6, wxEXPAND);
	for (int col = 1; col < 12; col++) {
		keys_iter->first->Add(keys_iter->second[col], 3, wxEXPAND);
	}
	keys_iter->first->Add(keys_iter->second[12], 7, wxEXPAND);
	keys_iter++;

	// Third row
	keys_iter->second[0] = new wxButton(this, -1, "Shift", wxDefaultPosition, wxSize(-1, 90));
	keys_iter->second[0]->Enable(false);
	keys_iter->second[1] = new wxButton(this, 25, "z");
	keys_iter->second[1]->SetBackgroundColour(wxColor(129, 197, 197));
	keys_iter->second[2] = new wxButton(this, 26, "x");
	keys_iter->second[2]->SetBackgroundColour(wxColor(203, 129, 203));
	keys_iter->second[3] = new wxButton(this, 27, "c");
	keys_iter->second[3]->SetBackgroundColour(wxColor(129, 184, 129));
	keys_iter->second[4] = new wxButton(this, 28, "v");
	keys_iter->second[4]->SetBackgroundColour(wxColor(123, 148, 193));
	keys_iter->second[5] = new wxButton(this, 29, "b");
	keys_iter->second[5]->SetBackgroundColour(wxColor(123, 148, 193));
	keys_iter->second[6] = new wxButton(this, 30, "n");
	keys_iter->second[6]->SetBackgroundColour(wxColor(129, 129, 203));
	keys_iter->second[7] = new wxButton(this, 31, "m");
	keys_iter->second[7]->SetBackgroundColour(wxColor(129, 129, 203));
	keys_iter->second[8] = new wxButton(this, 32, ",");
	keys_iter->second[8]->SetBackgroundColour(wxColor(129, 184, 129));
	keys_iter->second[9] = new wxButton(this, 33, ".");
	keys_iter->second[9]->SetBackgroundColour(wxColor(203, 129, 203));
	keys_iter->second[10] = new wxButton(this, 34, "/");
	keys_iter->second[10]->SetBackgroundColour(wxColor(129, 197, 197));
	keys_iter->second[11] = new wxButton(this, -1, "Shift");
	keys_iter->second[11]->Enable(false);

	for (int i = 0; i < 12; i++) {
		keys_iter->second[i]->Bind(wxEVT_BUTTON, &CreatePanel::OnKeyClicked, this);
	}

	keys_iter->first->Add(keys_iter->second[0], 8, wxEXPAND);
	for (int col = 1; col < 11; col++) {
		keys_iter->first->Add(keys_iter->second[col], 3, wxEXPAND);

		keys_iter->second[col]->Bind(wxEVT_BUTTON, &CreatePanel::OnKeyClicked, this); // Bind OnKeyClicked function to buttons
	}
	keys_iter->first->Add(keys_iter->second[11], 8, wxEXPAND);

	// Connect sizers
	keys_iter = keys.begin();
	for (; keys_iter != keys.end(); keys_iter++) {
		create_row_sizer->Add(keys_iter->first, 1, wxALIGN_CENTER_HORIZONTAL);
	}

	// Control
	wxBoxSizer* control_sizer = new wxBoxSizer(wxHORIZONTAL);

	analyze_btn = new wxButton(this, 60, "Analyze");
	export_btn = new wxButton(this, 60, "Export");
	layout_name = new wxTextCtrl(this, wxID_ANY, "");

	control_sizer->Add(analyze_btn, wxEXPAND, wxALIGN_CENTER_VERTICAL);
	control_sizer->Add(export_btn, wxEXPAND, wxALIGN_CENTER_VERTICAL);
	control_sizer->Add(layout_name, wxEXPAND, wxALIGN_CENTER_VERTICAL);

	create_row_sizer->Add(control_sizer, 1, wxALIGN_CENTER);

	this->SetSizer(create_row_sizer);
	this->Center();
}

CreatePanel::~CreatePanel() {

}

void CreatePanel::OnKeyClicked(wxCommandEvent& evt) {
	if (isKeyPressed == false) {
		isKeyPressed = true;
		previous_key = this->FindItem(evt.GetId());
	}
	else {
		wxWindow* current_key = this->FindItem(evt.GetId());
		wxString previous_str = previous_key->GetLabel();
		previous_key->SetLabel(current_key->GetLabel());
		current_key->SetLabel(previous_str);
		isKeyPressed = false;
	}

	evt.Skip();
}