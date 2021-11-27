#ifndef DOC_PANEL_H
#define DOC_PANEL_H

#include "wx/wx.h"

class DocPanel : public wxPanel
{
public:
	// Components
	wxStaticText* _typeDoc;
	wxStaticText* _createDoc;
	wxBoxSizer* _sizer;

	// Functions
	DocPanel(wxWindow* parent);
	~DocPanel();
};

#endif