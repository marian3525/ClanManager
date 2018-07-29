#pragma once
#include <QWidget>
#include <QListView>
#include <QStringListModel.h>
#include <QTextEdit.h>
#include <QPushButton.h>
#include "ui_DetailWindow.h"
#include "Player.h"
#include "Controller.h"

class DetailWindow : public QWidget
{
	Q_OBJECT

public:
	DetailWindow(Controller* controller, Player& player, QWidget *parent = Q_NULLPTR);
private:
	void setValues();
	void bindWidgets();
	void populateWarAttacks();
	Ui::DetailWindow ui;
	Player& player = Player();
	Controller* controller;
	QStringListModel* model;
	QListView* warAttacksList;

	QLabel* donations;
	QLabel* requests;
	QLabel* ratios;
	QLabel* contributions;
	QLabel* avgWarScore;
	QLabel* avgWarStars;
	QLabel* cgScores;
	QLabel* avgCGScore;
	QLabel* activities;
	QLabel* role;
	QLineEdit* specialRole;
	QTextEdit* notes;
public slots:
	void onNotesUpdate();
	void onSpecialRoleChanged();
};
