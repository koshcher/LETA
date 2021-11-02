#ifndef ANALYZE_DIALOG_H
#define ANALYZE_DIALOG_H

#include "wx/wx.h"
#include <fstream>

using namespace std;

class AnalyzeDialog : wxDialog
{
public:
	// Components
	wxPanel* panel = nullptr;
	wxStaticText* text = nullptr;
	wxBoxSizer* sizer = nullptr;

	// Functions
	AnalyzeDialog() : wxDialog(NULL, wxID_ANY, "Analyze", wxDefaultPosition, wxSize(600, 640))
	{
		panel = new wxPanel(this);
		text = new wxStaticText(panel, wxID_ANY, ReadLayout());
		sizer = new wxBoxSizer(wxHORIZONTAL);

		sizer->Add(text, 1, wxALL | wxEXPAND, 20);
		panel->SetSizer(sizer);

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