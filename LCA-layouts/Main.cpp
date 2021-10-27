#include "Main.h"

wxBEGIN_EVENT_TABLE(Main, wxFrame)

	EVT_BUTTON(1, OnButtoClick)

wxEND_EVENT_TABLE()


Main::Main() : wxFrame(nullptr, wxID_ANY, "LCA layouts", wxPoint(30,30), wxSize(720, 480))
{
	m_btn = new wxButton(this, 1, "Start", wxPoint(10, 10), wxSize(150, 50));
	m_text = new wxTextCtrl(this, wxID_ANY, "Start", wxPoint(10, 70), wxSize(300, 30));
	m_list = new wxListBox(this, wxID_ANY, wxPoint(10, 110), wxSize(300, 300));
}

Main::~Main() {

}


void Main::OnButtoClick(wxCommandEvent& evt) {
	m_list->AppendString(m_text->GetValue());
	evt.Skip();
}