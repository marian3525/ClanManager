#include "stdafx.h"
#include "ClanManager.h"
#include <QtWidgets/QApplication>
#include <tchar.h>
#include <urlmon.h>
#include "Controller.h"
#include <iostream>
using namespace std;
#pragma comment(lib, "urlmon.lib")
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Controller* controller = new Controller{};
	ClanManager w{controller};
	controller->registerObserver((Observer*)&w);
	w.show();
	const int retCode = a.exec();
	controller->onExit();
	delete controller;
	return retCode;
	//HRESULT hr = URLDownloadToFile(NULL, _T("https://www.clashofstats.com/clans/atheist-clan-2-LR0LGRVR/download/members"), _T("clanData.csv"), 0, NULL);
}
