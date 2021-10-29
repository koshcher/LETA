#ifndef MAIN_H
#define MAIN_H

#include "wx/wx.h"
#include <wx/notebook.h>

#include "TypePanel.h"
#include "CreatePanel.h"
#include "DocPanel.h"

using namespace std;

class Main : public wxFrame
{
public: // компоненты
	wxNotebook* notebook = nullptr;

	TypePanel* type_panel = nullptr;
	CreatePanel* create_panel = nullptr;
	DocPanel* doc_panel = nullptr;


public:
	Main();
	~Main();

};


#endif