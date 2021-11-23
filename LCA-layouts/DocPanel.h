#ifndef DOC_PANEL_H
#define DOC_PANEL_H

#include "wx/wx.h"

class DocPanel : public wxPanel
{
public:
	// Components
	wxStaticText* _doc;

	// Functions
	DocPanel(wxWindow* parent);
	~DocPanel();
};

#endif