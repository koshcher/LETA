#ifndef MAIN_H
#define MAIN_H

#include "wx/wx.h"
#include <wx/caret.h>

class Main : public wxFrame
{
public: // компоненты
	wxPanel* panel = nullptr;
	wxStaticText* text_to_type = nullptr;
	wxListBox* listb = nullptr;

	wxButton* start = nullptr;

	wxBoxSizer* hbox = nullptr;
	wxFlexGridSizer* fgs = nullptr;

	wxMenuBar* menubar;
	wxMenu* type;
	wxMenu* create;
	wxMenu* doc;

	wxDECLARE_EVENT_TABLE();

public:
	Main();
	~Main();

	void OnChar(wxKeyEvent& evt);
};

#endif