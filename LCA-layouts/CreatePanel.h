/*
	* File: CreatePanel.h
	* Description: header of panel for layout creating, analyze and export
	* Created: 29 October 2021
	* Author: Roman Koshchey
*/

#ifndef CREATE_PANEL_H
#define CREATE_PANEL_H

#include "wx/wx.h"
#include <map>
#include <vector>

using namespace std;

class CreatePanel : public wxPanel
{
public:
	// Components UI
	wxBoxSizer* _createRowSizer = nullptr;
	map<wxBoxSizer*, vector<wxButton*>> _keys;

	bool _isKeyPressed = false;
	wxWindow* _previousKey = nullptr;

	wxButton* _analyzeBtn = nullptr;
	wxButton* _exportBtn = nullptr;
	wxTextCtrl* _layoutName = nullptr;


	// Functions
	CreatePanel(wxWindow* parent);
	~CreatePanel();

	void OnKeyClicked(wxCommandEvent& evt);
	void Analyze(wxCommandEvent& evt);
	void WriteForAnalyze();
	void Export(wxCommandEvent& evt);

};

#endif