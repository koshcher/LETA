#include "DocPanel.h"

DocPanel::DocPanel(wxWindow* parent) : wxPanel(parent, wxID_ANY)
{
	doc = new wxStaticText(this, wxID_ANY, "");
	doc->SetLabel("");
}

DocPanel::~DocPanel() {
	delete doc;
}
