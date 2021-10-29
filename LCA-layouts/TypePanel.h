#ifndef TYPE_PANEL_H
#define TYPE_PANEL_H

#include "wx/wx.h"

class TypePanel : public wxPanel
{
public:
	// Components
	wxStaticText* text_to_type = nullptr;
	wxStaticText* type_word = nullptr;
	wxBoxSizer* sizer = nullptr;


	// Functions
	TypePanel(wxWindow* parent);
	~TypePanel();

	void OnChar(wxKeyEvent& evt);

};

#endif