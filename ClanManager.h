#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ClanManager.h"
#include "Controller.h"
#include "Observer.h"
#include "QListView.h"
#include "QTableView.h"
#include "QStandardItemModel.h"

class ClanManager : public QMainWindow, Observer
{
	Q_OBJECT

public:
	ClanManager(Controller* controller, QWidget *parent = Q_NULLPTR);
	void notify() override;

private:
	Ui::ClanManagerClass ui;
	Controller* controller;
	QTableView* playerList;
	QStandardItemModel* model;

	QRadioButton* donations;
	QRadioButton* requests;
	QRadioButton* attacks;
	QRadioButton* defenses;
	QRadioButton* ratio;
	QRadioButton* warStars;
	QRadioButton* trophies;
	QRadioButton* legendTrophies;
	QRadioButton* versusTrophies;
	QRadioButton* adjRatio;
	QRadioButton* contribution;
	QRadioButton* activity;

	QLineEdit* CGScore;
	QPushButton* addCGScore;

	QCheckBox* noShowFirst;
	QRadioButton* first1Star;
	QRadioButton* first2Star;
	QRadioButton* first3Star;

	QLineEdit* firstPercent;
	QSpinBox* firstEnemy;

	QCheckBox* noShowSecond;
	QRadioButton* second1Star;
	QRadioButton* second2Star;
	QRadioButton* second3Star;

	QLineEdit* secondPercent;
	QSpinBox* secondEnemy;

	QPushButton* addWarAttackButton;

	QLCDNumber* memberCounter;

	QPushButton* removePlayerButton;

	QAction* loadFreshData;

	void bindWidgets();
	void addHeaders();
	void update();
	void populateRows();
public slots:
	void onDonationsSelected();
	void onRequestsSelected();
	void onAttacksSelected();
	void onDefensesSelected();
	void onRatioSelected();
	void onWarStarsSelected();
	void onTrophiesSelected();
	void onVersusTrophiesSelected();
	void onLegendTrophiesSelected();
	void onAdjRatioSelected();
	void onContributionSelected();
	void onActivitySelected();
	void onAddWarAttack();
	void onAddCGScore();

	void onFirst1Star();
	void onFirst2Star();
	void onFirst3Star();

	void onSecond1Star();
	void onSecond2Star();
	void onSecond3Star();

	void onNoShowFirst();
	void onNoShowSecond();

	void onRemove();

	void onLoadFreshData();
};
