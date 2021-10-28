#ifndef MAIN_H
#define MAIN_H

#include "wx/wx.h"
#include <wx/notebook.h>

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