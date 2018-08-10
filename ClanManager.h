#pragma once

#include <QtWidgets/QMainWindow>
#include <QListView.h>
#include <QTableView.h>
#include <QStandardItemModel.h>
#include "ui_ClanManager.h"
#include "Controller.h"
#include "Observer.h"
#include "DetailWindow.h"

class ClanManager : public QMainWindow, Observer
{
	Q_OBJECT

public:
	ClanManager(Controller* controller, QWidget *parent = Q_NULLPTR);
	void notify() override;

private:
	Ui::ClanManagerClass ui;
	DetailWindow* detailWindow=nullptr;
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
	QRadioButton* warScore;
	QRadioButton* legendTrophies;
	QRadioButton* versusTrophies;
	QRadioButton* contribution;
	QRadioButton* activity;

	QLineEdit* CGScore;
	QPushButton* addCGScore;

	QCheckBox* noShowFirst;
	QRadioButton* first0Star;
	QRadioButton* first1Star;
	QRadioButton* first2Star;
	QRadioButton* first3Star;

	QLineEdit* firstPercent;
	QSpinBox* firstEnemy;

	QCheckBox* noShowSecond;
	QRadioButton* second0Star;
	QRadioButton* second1Star;
	QRadioButton* second2Star;
	QRadioButton* second3Star;

	QLineEdit* secondPercent;
	QSpinBox* secondEnemy;

	QPushButton* addWarAttackButton;

	QLCDNumber* memberCounter;

	QPushButton* removePlayerButton;

	QLabel* cycleIndicator;

	QAction* loadCycleData;
	QAction* loadUpdatedData;
	QAction* createTableFile;
	QAction* help;
	QAction* about;

	Controller::SortMode lastSort;

	void bindWidgets();
	void addHeaders();
	void update();
	void populateRows();

	int getStar1Selected();
	int getStar2Selected();
	int getEnemy1Level();
	int getEnemy2Level();

public slots:
	void onDonationsSelected();
	void onRequestsSelected();
	void onAttacksSelected();
	void onDefensesSelected();
	void onRatioSelected();
	void onWarStarsSelected();
	void onTrophiesSelected();
	void onWarScoreSelected();
	void onVersusTrophiesSelected();
	void onLegendTrophiesSelected();
	void onContributionSelected();
	void onActivitySelected();
	void onAddWarAttack();
	void onAddCGScore();

	void onFirst0Star();
	void onFirst1Star();
	void onFirst2Star();
	void onFirst3Star();

	void onSecond0Star();
	void onSecond1Star();
	void onSecond2Star();
	void onSecond3Star();

	void onNoShowFirst();
	void onNoShowSecond();

	void onRemove();

	void onLoadUpdatedData();
	void onLoadCycleData();
	void onCreateTableFile();
	void onHelp();
	void onAbout();
	void onDetails(const QModelIndex& index);
};
