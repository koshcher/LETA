#include "DocPanel.h"

DocPanel::DocPanel(wxWindow* parent) : wxPanel(parent, wxID_ANY)
{
	doc = new wxStaticText();
}

DocPanel::~DocPanel() {

}