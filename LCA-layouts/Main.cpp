#include "Main.h"

wxBEGIN_EVENT_TABLE(Main, wxFrame)

	EVT_BUTTON(1, OnButtonClick)
	EVT_CHAR(OnChar)

wxEND_EVENT_TABLE()


Main::Main() : wxFrame(nullptr, wxID_ANY, "LCA layouts", wxPoint(30,30), wxSize(720, 480))
{
	m_btn = new wxButton(this, 1, "Start", wxPoint(10, 10), wxSize(150, 50));
	m_text = new wxStaticText(this, wxID_ANY, "Start", wxPoint(10, 70), wxSize(300, 40));
	m_list = new wxListBox(this, wxID_ANY, wxPoint(10, 120), wxSize(300, 300));
}

Main::~Main() {

}


void Main::OnButtonClick(wxCommandEvent& evt) {

	m_list->AppendString(m_text->GetLabel());

	evt.Skip();
}

void Main::OnChar(wxKeyEvent& evt) {
	if (evt.GetKeyCode() == WXK_SPACE) {
		m_list->AppendString(m_text->GetLabel());
	}
	else if (evt.GetKeyCode() == WXK_BACK) {

		m_text->SetLabel(m_text->GetLabel().erase(m_text->GetLabel().Length() - 1));
	}
	else {
		m_text->SetLabel(m_text->GetLabel() + char(evt.GetKeyCode()));
	}

	evt.Skip();
}