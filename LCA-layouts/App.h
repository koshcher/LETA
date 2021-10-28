#ifndef APP_H
#define APP_H

#include "wx/wx.h"
#include "Main.h"

class App : public wxApp
{
private:
	Main* frame = nullptr;

public:
	virtual bool OnInit();
};

#endif