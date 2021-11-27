#include "DocPanel.h"

DocPanel::DocPanel(wxWindow* parent) : wxPanel(parent, wxID_ANY)
{
	this->SetBackgroundColour(wxColor(87, 87, 87));
	this->SetForegroundColour(wxColor(255, 255, 255));

	_sizer = new wxBoxSizer(wxVERTICAL);

	_typeDoc = new wxStaticText(this, wxID_ANY, "Type panel:\n\tSpeed test starts when you type any first letter into the box. WPM - words per minut, ACC - percentage of words entered correctly. Text is generated from words.txt file.");
	_createDoc = new wxStaticText(this, wxID_ANY, "Create panel:\n\tPress 2 keys in sequence and they will swap places. Type layout name into input box. Button 'Analyze' with show you stats of layout using genkey analyzer. Button 'Export' will create zip with files of layout for different OS. Zip will be at directory where the app is situated.");
	
	_sizer->Add(_typeDoc, 1, wxRIGHT | wxLEFT | wxTOP | wxEXPAND, 50);
	_sizer->Add(_createDoc, 1, wxRIGHT | wxLEFT | wxEXPAND, 50);
	this->SetSizer(_sizer);
}

DocPanel::~DocPanel() 
{
	
}
