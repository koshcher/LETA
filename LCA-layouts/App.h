/*
	* File: App.h
	* Description: header of app class for Init (start program)
	* Created: 27 October 2021
	* Author: Roman Koshchey
*/

#ifndef APP_H
#define APP_H

#include "wx/wx.h"
#include "Main.h"

class App : public wxApp
{
private:
	Main* _frame = nullptr;

public:
	virtual bool OnInit();
};

#endif