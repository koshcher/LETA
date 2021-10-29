#ifndef TYPE_PANEL_H
#define TYPE_PANEL_H

#include "wx/wx.h"
#include "Generator.h"

class TypePanel : public wxPanel
{
public:
	// Components
	Generator gen;

	wxStaticText* text_to_type = nullptr;
	wxTextCtrl* type_word = nullptr;


	wxBoxSizer* vsizer = nullptr;
	wxBoxSizer* hsizer = nullptr;


	// Functions
	TypePanel(wxWindow* parent);
	~TypePanel();

	void OnChar(wxKeyEvent& evt);

};

#endif