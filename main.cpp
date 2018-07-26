#include "stdafx.h"
#include <QtWidgets/QApplication>
#include <iostream>
#include "ClanManager.h"
#include "Controller.h"

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
}