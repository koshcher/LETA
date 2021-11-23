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
	wxNotebook* _notebook = nullptr;

	TypePanel* _typePanel = nullptr;
	CreatePanel* _createPanel = nullptr;
	DocPanel* _docPanel = nullptr;


public:
	Main();
	~Main();

};


#endif