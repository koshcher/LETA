#ifndef MAIN_H
#define MAIN_H

#include "wx/wx.h"

class Main : public wxFrame
{
public: // компоненты
	wxButton* m_btn = nullptr;
	wxTextCtrl* m_text = nullptr;
	wxListBox* m_list = nullptr;

	wxDECLARE_EVENT_TABLE();

public:
	Main();
	~Main();

	void OnButtoClick(wxCommandEvent& evt);

};

#endif