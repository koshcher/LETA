#ifndef MAIN_H
#define MAIN_H

#include "wx/wx.h"
#include <wx/notebook.h>
#include <map>

using namespace std;

class Main : public wxFrame
{
public: // компоненты
	wxNotebook* notebook = nullptr;

	// Typing panel
	wxPanel* type_panel = nullptr;
	wxStaticText* text_to_type = nullptr;
	wxBoxSizer* type_sizer = nullptr;

	// Create panel
	wxPanel* create_panel = nullptr;
	wxBoxSizer* create_row_sizer = nullptr;
	
	map<wxBoxSizer*, wxButton**> keys;

	wxButton** row1;
	wxGridSizer* row1_sizer = nullptr;

	wxButton** row2;
	wxBoxSizer* row2_sizer = nullptr;

	vector<wxButton*> row3;
	wxBoxSizer* row3_sizer = nullptr;

	// Documentation panel
	wxPanel* doc_panel = nullptr;

	/*
	wxStaticText* text_to_type = nullptr;
	wxListBox* listb = nullptr;

	wxButton* start = nullptr;

	wxBoxSizer* hbox = nullptr;
	wxFlexGridSizer* fgs = nullptr;
	*/
	
	wxDECLARE_EVENT_TABLE();

public:
	Main();
	~Main();


	//void OnChar(wxKeyEvent& evt);
};


#endif