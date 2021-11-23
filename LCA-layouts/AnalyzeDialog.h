/*
	* File: AnalyzeDialog.h
	* Description: Read file with analyze results, and show it in Dialog window 
	* Created: 02 November 2021
	* Author: Roman Koshchey
*/

#ifndef ANALYZE_DIALOG_H
#define ANALYZE_DIALOG_H

#include "wx/wx.h"
#include <fstream>

using namespace std;

class AnalyzeDialog : wxDialog
{
public:
	// Components
	wxPanel* _panel = nullptr;
	wxStaticText* _text = nullptr;
	wxBoxSizer* _sizer = nullptr;

	// Functions
	AnalyzeDialog() : wxDialog(NULL, wxID_ANY, "Analyze", wxDefaultPosition, wxSize(600, 640))
	{
		_panel = new wxPanel(this);
		_text = new wxStaticText(_panel, wxID_ANY, ReadLayout());
		_sizer = new wxBoxSizer(wxHORIZONTAL);

		_sizer->Add(_text, 1, wxALL | wxEXPAND, 20);
		_panel->SetSizer(_sizer);

		Show();
	}

	string ReadLayout() {
		string res = "";
		string tmp = "";
		ifstream f("layout.txt");
		if (f.is_open()) {

			while (f) {
				getline(f, tmp);
				res += tmp + "\n";
			}

			f.close();
		}
		return res;
	}
};

#endif