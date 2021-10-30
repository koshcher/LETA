#ifndef TYPE_PANEL_H
#define TYPE_PANEL_H

#include "wx/wx.h"
#include "Generator.h"
#include "Test.h"
#include <time.h>

class TypePanel : public wxPanel
{
public:
	// Components
	Generator gen;

	wxStaticText* text_to_type = nullptr;
	wxTextCtrl* type_word = nullptr;

	wxStaticText* result = nullptr;

	Test test;
	time_t timer;
	bool is_going = false;
	int word_index = 0;


	wxBoxSizer* vsizer = nullptr;
	wxBoxSizer* hsizer = nullptr;


	// Functions
	TypePanel(wxWindow* parent);
	~TypePanel();

	void OnChar(wxKeyEvent& evt);
};

#endif