#include "CreatePanel.h"
#include <filesystem>
#include "AnalyzeDialog.h"
#include "Exporter.h"

CreatePanel::CreatePanel(wxWindow* parent) : wxPanel(parent, wxID_ANY)
{
	_createRowSizer = new wxBoxSizer(wxVERTICAL);

	_keys.insert(pair<wxBoxSizer*, vector<wxButton*>>(new wxBoxSizer(wxHORIZONTAL), {}));
	_keys.insert(pair<wxBoxSizer*, vector<wxButton*>>(new wxBoxSizer(wxHORIZONTAL), {}));
	_keys.insert(pair<wxBoxSizer*, vector<wxButton*>>(new wxBoxSizer(wxHORIZONTAL), {}));

	map<wxBoxSizer*, vector<wxButton*>>::iterator keys_iter = _keys.begin();

	// First row
	keys_iter->second.push_back(new wxButton(this, -1, "Tab", wxDefaultPosition, wxSize(-1, 90)));
	keys_iter->second[0]->Enable(false);
	keys_iter->second.push_back(new wxButton(this, 24, "q"));
	keys_iter->second[1]->SetBackgroundColour(wxColor(129, 197, 197));
	keys_iter->second.push_back(new wxButton(this, 25, "w"));
	keys_iter->second[2]->SetBackgroundColour(wxColor(203, 129, 203));
	keys_iter->second.push_back(new wxButton(this, 26, "e"));
	keys_iter->second[3]->SetBackgroundColour(wxColor(129, 184, 129));
	keys_iter->second.push_back(new wxButton(this, 27, "r"));
	keys_iter->second[4]->SetBackgroundColour(wxColor(123, 148, 193));
	keys_iter->second.push_back(new wxButton(this, 28, "t"));
	keys_iter->second[5]->SetBackgroundColour(wxColor(123, 148, 193));
	keys_iter->second.push_back(new wxButton(this, 29, "y"));
	keys_iter->second[6]->SetBackgroundColour(wxColor(129, 129, 203));
	keys_iter->second.push_back(new wxButton(this, 30, "u"));
	keys_iter->second[7]->SetBackgroundColour(wxColor(129, 129, 203));
	keys_iter->second.push_back(new wxButton(this, 31, "i"));
	keys_iter->second[8]->SetBackgroundColour(wxColor(129, 184, 129));
	keys_iter->second.push_back(new wxButton(this, 32, "o"));
	keys_iter->second[9]->SetBackgroundColour(wxColor(203, 129, 203));
	keys_iter->second.push_back(new wxButton(this, 33, "p"));
	keys_iter->second[10]->SetBackgroundColour(wxColor(129, 197, 197));
	keys_iter->second.push_back(new wxButton(this, 34, "["));
	keys_iter->second[11]->SetBackgroundColour(wxColor(129, 197, 197));
	keys_iter->second.push_back(new wxButton(this, 35, "]"));
	keys_iter->second[12]->SetBackgroundColour(wxColor(129, 197, 197));
	keys_iter->second.push_back(new wxButton(this, 51, "\\"));
	keys_iter->second[13]->Enable(false);

	for (int i = 0; i < 14; i++) 
	{
		keys_iter->second[i]->Bind(wxEVT_BUTTON, &CreatePanel::OnKeyClicked, this);
	}

	keys_iter->first->Add(keys_iter->second[0], 5, wxEXPAND);
	for (int col = 1; col < 13; col++)
	{
		keys_iter->first->Add(keys_iter->second[col], 3, wxEXPAND);
	}
	keys_iter->first->Add(keys_iter->second[13], 5, wxEXPAND);
	keys_iter++;

	// Second row
	keys_iter->second.push_back(new wxButton(this, -1, "Caps", wxDefaultPosition, wxSize(-1, 90)));
	keys_iter->second[0]->Enable(false);
	keys_iter->second.push_back(new wxButton(this, 38, "a"));
	keys_iter->second[1]->SetBackgroundColour(wxColor(129, 197, 197));
	keys_iter->second.push_back(new wxButton(this, 39, "s"));
	keys_iter->second[2]->SetBackgroundColour(wxColor(203, 129, 203));
	keys_iter->second.push_back(new wxButton(this, 40, "d"));
	keys_iter->second[3]->SetBackgroundColour(wxColor(129, 184, 129));
	keys_iter->second.push_back(new wxButton(this, 41, "f"));
	keys_iter->second[4]->SetBackgroundColour(wxColor(123, 148, 193));
	keys_iter->second.push_back(new wxButton(this, 42, "g"));
	keys_iter->second[5]->SetBackgroundColour(wxColor(123, 148, 193));
	keys_iter->second.push_back(new wxButton(this, 43, "h"));
	keys_iter->second[6]->SetBackgroundColour(wxColor(129, 129, 203));
	keys_iter->second.push_back(new wxButton(this, 44, "j"));
	keys_iter->second[7]->SetBackgroundColour(wxColor(129, 129, 203));
	keys_iter->second.push_back(new wxButton(this, 45, "k"));
	keys_iter->second[8]->SetBackgroundColour(wxColor(129, 184, 129));
	keys_iter->second.push_back(new wxButton(this, 46, "l"));
	keys_iter->second[9]->SetBackgroundColour(wxColor(203, 129, 203));
	keys_iter->second.push_back(new wxButton(this, 47, ";"));
	keys_iter->second[10]->SetBackgroundColour(wxColor(129, 197, 197));
	keys_iter->second.push_back(new wxButton(this, 48, "'"));
	keys_iter->second[11]->SetBackgroundColour(wxColor(129, 197, 197));
	keys_iter->second.push_back(new wxButton(this, -1, "Enter"));
	keys_iter->second[12]->Enable(false);

	for (int i = 0; i < 13; i++) 
	{
		keys_iter->second[i]->Bind(wxEVT_BUTTON, &CreatePanel::OnKeyClicked, this);
	}

	keys_iter->first->Add(keys_iter->second[0], 6, wxEXPAND);
	for (int col = 1; col < 12; col++) 
	{
		keys_iter->first->Add(keys_iter->second[col], 3, wxEXPAND);
	}
	keys_iter->first->Add(keys_iter->second[12], 7, wxEXPAND);
	keys_iter++;

	// Third row
	keys_iter->second.push_back(new wxButton(this, -1, "Shift", wxDefaultPosition, wxSize(-1, 90)));
	keys_iter->second[0]->Enable(false);
	keys_iter->second.push_back(new wxButton(this, 52, "z"));
	keys_iter->second[1]->SetBackgroundColour(wxColor(129, 197, 197));
	keys_iter->second.push_back(new wxButton(this, 53, "x"));
	keys_iter->second[2]->SetBackgroundColour(wxColor(203, 129, 203));
	keys_iter->second.push_back(new wxButton(this, 54, "c"));
	keys_iter->second[3]->SetBackgroundColour(wxColor(129, 184, 129));
	keys_iter->second.push_back(new wxButton(this, 55, "v"));
	keys_iter->second[4]->SetBackgroundColour(wxColor(123, 148, 193));
	keys_iter->second.push_back(new wxButton(this, 56, "b"));
	keys_iter->second[5]->SetBackgroundColour(wxColor(123, 148, 193));
	keys_iter->second.push_back(new wxButton(this, 57, "n"));
	keys_iter->second[6]->SetBackgroundColour(wxColor(129, 129, 203));
	keys_iter->second.push_back(new wxButton(this, 58, "m"));
	keys_iter->second[7]->SetBackgroundColour(wxColor(129, 129, 203));
	keys_iter->second.push_back(new wxButton(this, 59, ","));
	keys_iter->second[8]->SetBackgroundColour(wxColor(129, 184, 129));
	keys_iter->second.push_back(new wxButton(this, 60, "."));
	keys_iter->second[9]->SetBackgroundColour(wxColor(203, 129, 203));
	keys_iter->second.push_back(new wxButton(this, 61, "/"));
	keys_iter->second[10]->SetBackgroundColour(wxColor(129, 197, 197));
	keys_iter->second.push_back(new wxButton(this, -1, "Shift"));
	keys_iter->second[11]->Enable(false);

	for (int i = 0; i < 12; i++) 
	{
		keys_iter->second[i]->Bind(wxEVT_BUTTON, &CreatePanel::OnKeyClicked, this);
	}

	keys_iter->first->Add(keys_iter->second[0], 8, wxEXPAND);
	for (int col = 1; col < 11; col++) 
	{
		keys_iter->first->Add(keys_iter->second[col], 3, wxEXPAND);

		keys_iter->second[col]->Bind(wxEVT_BUTTON, &CreatePanel::OnKeyClicked, this); // Bind OnKeyClicked function to buttons
	}
	keys_iter->first->Add(keys_iter->second[11], 8, wxEXPAND);

	// Connect sizers
	keys_iter = _keys.begin();
	for (; keys_iter != _keys.end(); keys_iter++)
	{
		_createRowSizer->Add(keys_iter->first, 1, wxALIGN_CENTER_HORIZONTAL);
	}

	// Control
	wxBoxSizer* control_sizer = new wxBoxSizer(wxHORIZONTAL);

	_analyzeBtn = new wxButton(this, 100, "Analyze");
	_analyzeBtn->Bind(wxEVT_BUTTON, &CreatePanel::Analyze, this);
	_exportBtn = new wxButton(this, 60, "Export");
	_exportBtn->Bind(wxEVT_BUTTON, &CreatePanel::Export, this);
	_layoutName = new wxTextCtrl(this, wxID_ANY, "");

	control_sizer->Add(_analyzeBtn, wxEXPAND, wxALIGN_CENTER_VERTICAL);
	control_sizer->Add(_exportBtn, wxEXPAND, wxALIGN_CENTER_VERTICAL);
	control_sizer->Add(_layoutName, wxEXPAND, wxALIGN_CENTER_VERTICAL);

	_createRowSizer->Add(control_sizer, 1, wxALIGN_CENTER);

	this->SetSizer(_createRowSizer);
	this->Center();
}

CreatePanel::~CreatePanel() 
{
	delete _previousKey;
	delete _analyzeBtn;
	delete _exportBtn;
	delete _layoutName;
}

void CreatePanel::OnKeyClicked(wxCommandEvent& evt) 
{
	if (_isKeyPressed == false)
	{
		_isKeyPressed = true;
		_previousKey = this->FindItem(evt.GetId());
	}
	else 
	{
		wxWindow* current_key = this->FindItem(evt.GetId());
		wxString previous_str = _previousKey->GetLabel();
		_previousKey->SetLabel(current_key->GetLabel());
		current_key->SetLabel(previous_str);
		_isKeyPressed = false;
	}
	evt.Skip();
}

void CreatePanel::Analyze(wxCommandEvent& evt)
{
	WriteForAnalyze();

	string cmd = "genkey.exe a " + _layoutName->GetValue().ToStdString();
	system(cmd.c_str());
	remove("layouts/" + _layoutName->GetValue());

	AnalyzeDialog* dial = new AnalyzeDialog();
}

void CreatePanel::WriteForAnalyze()
{
	if (_layoutName->GetValue() == "") 
	{
		_layoutName->SetValue("tmp");
	}
	wxString path = "layouts/" + _layoutName->GetValue();
	ofstream f(path.ToStdString());
	
	if (f.is_open()) 
	{
		f << _layoutName->GetValue() << endl;

		map<wxBoxSizer*, vector<wxButton*>>::iterator iter = _keys.begin();
		
		for (int i = 1; i < 13; i++) 
		{
			f << iter->second[i]->GetLabel() << " ";
		}
		f << endl;
		iter++;

		for (int i = 1; i < 12; i++) 
		{
			f << iter->second[i]->GetLabel() << " ";
		}
		f << endl;
		iter++;

		for (int i = 1; i < 11; i++) 
		{
			f << iter->second[i]->GetLabel() << " ";
		}
		f << endl;

		f << "0 1 2 3 3 4 4 5 6 7 7 7" << endl << "0 1 2 3 3 4 4 5 6 7 7" << endl << "0 1 2 3 3 4 4 5 6 7";

		f.close();
	}
}

void CreatePanel::Export(wxCommandEvent& evt)
{
	if (_layoutName->GetValue() == "")
	{
		_layoutName->SetValue("tmp");
	}

	vector<wxButton*> keys_vector;
	map<wxBoxSizer*, vector<wxButton*>>::iterator iter = _keys.begin();
	for (; iter != _keys.end(); iter++)
	{
		for (int i = 0; i < iter->second.size(); i++)
		{
			if (iter->second[i]->GetId() > 0)
			{
				keys_vector.push_back(iter->second[i]);
			}
		}
	}

	Exporter ex(_layoutName->GetValue().ToStdString(), keys_vector);
	ex.Export();
}