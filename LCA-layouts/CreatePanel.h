#ifndef CREATE_PANEL_H
#define CREATE_PANEL_H

#include "wx/wx.h"
#include <map>

using namespace std;

class CreatePanel : public wxPanel
{
public:
	// Components
	wxBoxSizer* create_row_sizer = nullptr;
	map<wxBoxSizer*, wxButton**> keys;

	bool isKeyPressed = false;
	wxWindow* previous_key = nullptr;

	wxButton* analyze_btn = nullptr;
	wxButton* export_btn = nullptr;
	wxTextCtrl* layout_name = nullptr;


	// Functions
	CreatePanel(wxWindow* parent);
	~CreatePanel();

	void OnKeyClicked(wxCommandEvent& evt);
};

#endif