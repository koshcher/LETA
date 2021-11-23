#include "DocPanel.h"

DocPanel::DocPanel(wxWindow* parent) : wxPanel(parent, wxID_ANY)
{
	_doc = new wxStaticText(this, wxID_ANY, "");
	_doc->SetLabel("");
}

DocPanel::~DocPanel() 
{
	delete _doc;
}
