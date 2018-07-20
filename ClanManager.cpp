#include "stdafx.h"
#include "ClanManager.h"

ClanManager::ClanManager(Controller* controller, QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->controller = controller;
	int numberOfPlayers = controller->getSize();
	playerList = findChild<QTableView*>("playerList");
	model = new QStandardItemModel(50, 7, this);

	bindWidgets();

	addHeaders();
	update();
	populateRows();
}

void ClanManager::notify()
{
	/*
		Something changed in the controller, request update for the views
	*/
	populateRows();
}

void ClanManager::bindWidgets()
{
	donations = findChild<QRadioButton*>("donationsRadio");
	requests = findChild<QRadioButton*>("requestsRadio");
	attacks = findChild<QRadioButton*>("attacksRadio");
	defenses = findChild<QRadioButton*>("defensesRadio");
	ratio = findChild<QRadioButton*>("ratioRadio");
	warStars = findChild<QRadioButton*>("warStarsRadio");
	trophies = findChild<QRadioButton*>("trophiesRadio");
	versusTrophies = findChild<QRadioButton*>("versusTrophiesRadio");
	legendTrophies = findChild<QRadioButton*>("legendRadio");
	adjRatio = findChild<QRadioButton*>("adjRatioRadio");
	contribution = findChild<QRadioButton*>("contributionRadio");
	activity = findChild<QRadioButton*>("activityRadio");

	CGScore = findChild<QLineEdit*>("CGScore");
	addCGScore = findChild<QPushButton*>("addCGScore");

	noShowFirst = findChild<QCheckBox*>("noShowFirst");
	first1Star = findChild<QRadioButton*>("first1star");
	first2Star = findChild<QRadioButton*>("first2star");
	first3Star = findChild<QRadioButton*>("first3star");

	firstPercent = findChild<QLineEdit*>("firstPercent");
	firstEnemy = findChild<QSpinBox*>("firstEnemy");

	noShowSecond = findChild<QCheckBox*>("noShowSecond");
	second1Star = findChild<QRadioButton*>("second1star");
	second2Star = findChild<QRadioButton*>("second2star");
	second3Star = findChild<QRadioButton*>("second3star");

	secondPercent = findChild<QLineEdit*>("secondPercent");
	secondEnemy = findChild<QSpinBox*>("secondEnemy");
	addWarAttackButton = findChild<QPushButton*>("addWarAttackButton");

	memberCounter = findChild<QLCDNumber*>("counter");

	removePlayerButton = findChild<QPushButton*>("removePlayer");

	connect(donations, &QRadioButton::clicked, this, &ClanManager::onDonationsSelected);
	connect(requests, &QRadioButton::clicked, this, &ClanManager::onRequestsSelected);
	connect(attacks, &QRadioButton::clicked, this, &ClanManager::onAttacksSelected);
	connect(defenses, &QRadioButton::clicked, this, &ClanManager::onDefensesSelected);
	connect(ratio, &QRadioButton::clicked, this, &ClanManager::onRatioSelected);
	connect(warStars, &QRadioButton::clicked, this, &ClanManager::onWarStarsSelected);
	connect(trophies, &QRadioButton::clicked, this, &ClanManager::onTrophiesSelected);
	connect(versusTrophies, &QRadioButton::clicked, this, &ClanManager::onVersusTrophiesSelected);
	connect(legendTrophies, &QRadioButton::clicked, this, &ClanManager::onLegendTrophiesSelected);
	connect(adjRatio, &QRadioButton::clicked, this, &ClanManager::onAdjRatioSelected);
	connect(contribution, &QRadioButton::clicked, this, &ClanManager::onContributionSelected);
	connect(activity, &QRadioButton::clicked, this, &ClanManager::onActivitySelected);

	connect(addWarAttackButton, &QPushButton::clicked, this, &ClanManager::onAddWarAttack);
	connect(addCGScore, &QPushButton::clicked, this, &ClanManager::onAddCGScore);
	connect(noShowFirst, &QCheckBox::clicked, this, &ClanManager::onNoShowFirst);
	connect(first1Star, &QRadioButton::clicked, this, &ClanManager::onFirst1Star);
	connect(first2Star, &QRadioButton::clicked, this, &ClanManager::onFirst2Star);
	connect(first3Star, &QRadioButton::clicked, this, &ClanManager::onFirst3Star);
	connect(noShowSecond, &QCheckBox::clicked, this, &ClanManager::onNoShowSecond);
	connect(second1Star, &QRadioButton::clicked, this, &ClanManager::onSecond1Star);
	connect(second2Star, &QRadioButton::clicked, this, &ClanManager::onSecond2Star);
	connect(second3Star, &QRadioButton::clicked, this, &ClanManager::onSecond3Star);

	connect(removePlayerButton, &QPushButton::clicked, this, &ClanManager::onRemove);
}

void ClanManager::addHeaders()
{
	vector<string> header{ "Name", "Role", "Trophies", "Attacks", "Defenses", "Donations", "Requests", "Ratio", "Adj.Ratio", "Activity", "Contribution" };
	for (int i = 0; i < header.size(); i++) {
		model->setHorizontalHeaderItem(i, new QStandardItem(QString::fromStdString(header[i])));
	}

	playerList->setModel(model);
	playerList->setColumnWidth(1, 75);
	playerList->setColumnWidth(2, 60);
	playerList->setColumnWidth(3, 55);
	playerList->setColumnWidth(4, 63);
	playerList->setColumnWidth(5, 70); 
	playerList->setColumnWidth(6, 65);
	
}

void ClanManager::update()
{

}

void ClanManager::populateRows()
{	
	int index = 0;
	for (const Player& p : controller->getAll()) {
		QStandardItem* name = new QStandardItem(QString::fromStdString(p.getName()));
		model->setItem(index, 0, name);

		QStandardItem* role = new QStandardItem(QString::fromStdString(p.getRole()));
		model->setItem(index, 1, role);

		QStandardItem* trophies = new QStandardItem(QString::fromStdString(to_string(p.getTrophies())));
		model->setItem(index, 2, trophies);

		QStandardItem* attacks = new QStandardItem(QString::fromStdString(to_string(p.getAttackWins())));
		model->setItem(index, 3, attacks);

		QStandardItem* defenses = new QStandardItem(QString::fromStdString(to_string(p.getDefenseWins())));
		model->setItem(index, 4, defenses);

		QStandardItem* donations = new QStandardItem(QString::fromStdString(to_string(p.getTroopsDonated())));
		model->setItem(index, 5, donations);

		QStandardItem* requests = new QStandardItem(QString::fromStdString(to_string(p.getTroopsRequested())));
		model->setItem(index, 6, requests);
		index++;
	}
}

void ClanManager::onDonationsSelected()
{
	controller->sort(Controller::SortMode::donationDec);
}

void ClanManager::onRequestsSelected()
{
	controller->sort(Controller::SortMode::requestDec);
}

void ClanManager::onAttacksSelected()
{
	controller->sort(Controller::SortMode::attackWins);
}

void ClanManager::onDefensesSelected()
{
	controller->sort(Controller::SortMode::defenseWins);
}

void ClanManager::onRatioSelected()
{
	controller->sort(Controller::SortMode::ratioDec);
}

void ClanManager::onWarStarsSelected()
{
	controller->sort(Controller::SortMode::warStars);
}

void ClanManager::onTrophiesSelected()
{
	controller->sort(Controller::SortMode::trophies);
}

void ClanManager::onVersusTrophiesSelected()
{
	controller->sort(Controller::SortMode::versusTrophies);
}

void ClanManager::onLegendTrophiesSelected()
{
	controller->sort(Controller::SortMode::legendTrophies);
}

void ClanManager::onAdjRatioSelected()
{
	controller->sort(Controller::SortMode::ratioAdj);
}

void ClanManager::onContributionSelected()
{
	controller->sort(Controller::SortMode::contribution);
}

void ClanManager::onActivitySelected()
{
	controller->sort(Controller::SortMode::activityMetric);
}

void ClanManager::onAddWarAttack()
{
	/*
		Add war attack(s) to the selected player
	*/
}

void ClanManager::onAddCGScore()
{
	int score = atoi(CGScore->text().toStdString().c_str());
}

void ClanManager::onFirst1Star()
{
	first2Star->setChecked(false);
	first3Star->setChecked(false);
}

void ClanManager::onFirst2Star()
{
	first1Star->setChecked(false);
	first3Star->setChecked(false);
}

void ClanManager::onFirst3Star()
{
	first1Star->setChecked(false);
	first2Star->setChecked(false);
}

void ClanManager::onSecond1Star()
{
	second2Star->setChecked(false);
	second3Star->setChecked(false);

}

void ClanManager::onSecond2Star()
{
	second1Star->setChecked(false);
	second3Star->setChecked(false);
}

void ClanManager::onSecond3Star()
{
	second1Star->setChecked(false);
	second2Star->setChecked(false);
}

void ClanManager::onNoShowFirst()
{
}

void ClanManager::onNoShowSecond()
{
}

void ClanManager::onRemove()
{
	QModelIndexList indexes;
	indexes = playerList->selectionModel()->selectedIndexes();

	for (QModelIndex idx : indexes) {
		QString str = playerList->model()->data(idx).toString();
		qDebug() << str << endl;
		//controller->removePlayer();
	}
}
	
