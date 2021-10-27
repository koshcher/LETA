#ifndef MAIN_H
#define MAIN_H

#include "wx/wx.h"
#include <wx/caret.h>

class Main : public wxFrame
{
public: // компоненты
	wxButton* m_btn = nullptr;
	wxStaticText* m_text = nullptr;
	wxListBox* m_list = nullptr;

	wxDECLARE_EVENT_TABLE();

public:
	Main();
	~Main();

	void OnButtonClick(wxCommandEvent& evt);
	void OnChar(wxKeyEvent& evt);
};

#endif