#include "stdafx.h"
#include "ClanManager.h"

ClanManager::ClanManager(Controller* controller, QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	this->controller = controller;
	int numberOfPlayers = controller->getSize();

	try {
		controller->loadStats();
	}
	catch (const ControllerException& e) {
		//stats file not yet created. It means no data was imported into the app or the stat files were deleted, attempt to load from the fresh data file
			onLoadFreshData();
	}
	bindWidgets();
	addHeaders();
	update();
}

void ClanManager::notify()
{
	/*
		Something changed in the controller, request update for the views
	*/
	update();
}

void ClanManager::bindWidgets()
{
	model = new QStandardItemModel(50, 7, this);

	playerList = findChild<QTableView*>("playerList");
	playerList->setEditTriggers(QAbstractItemView::NoEditTriggers);

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
	firstEnemy = findChild<QSpinBox*>("enemyFirst");

	noShowSecond = findChild<QCheckBox*>("noShowSecond");
	second1Star = findChild<QRadioButton*>("second1star");
	second2Star = findChild<QRadioButton*>("second2star");
	second3Star = findChild<QRadioButton*>("second3star");

	secondPercent = findChild<QLineEdit*>("secondPercent");
	secondEnemy = findChild<QSpinBox*>("enemySecond");
	addWarAttackButton = findChild<QPushButton*>("addWarAttacks");

	memberCounter = findChild<QLCDNumber*>("counter");

	removePlayerButton = findChild<QPushButton*>("removePlayer");

	loadFreshData = findChild<QAction*>("actionLoadFreshData");

	connect(playerList, &QTableView::doubleClicked, this, &ClanManager::onDetails);

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
	//in the menu:
	connect(loadFreshData, &QAction::triggered, this, &ClanManager::onLoadFreshData);
}

void ClanManager::addHeaders()
{
	vector<string> header{ "Name", "Role", "Trophies", "Attacks", "Defenses", "Donations", "Requests", "Ratio", "Adj.Ratio", "Activity", "Contribution" };
	for (int i = 0; i < header.size(); i++) {
		model->setHorizontalHeaderItem(i, new QStandardItem(QString::fromStdString(header[i])));
	}

	playerList->setModel(model);
}

void ClanManager::update()
{
	memberCounter->display(controller->getSize());
	//maintain this order
	//controller->computeMetrics();
	populateRows();

	playerList->setColumnWidth(1, 75);
	playerList->setColumnWidth(2, 60);
	playerList->setColumnWidth(3, 55);
	playerList->setColumnWidth(4, 63);
	playerList->setColumnWidth(5, 65);
	playerList->setColumnWidth(6, 70);
	playerList->setColumnWidth(7, 70);
	playerList->setColumnWidth(8, 70);
	playerList->setColumnWidth(9, 70);
	playerList->setColumnWidth(10, 85);
}

void ClanManager::populateRows()
{	
	int index = 0;
	for (const Player& p : controller->getAll()) {
		QStandardItem* name = new QStandardItem(QString::fromStdString(p.getName()));
		name->setSelectable(true);
		model->setItem(index, 0, name);

		QStandardItem* role = new QStandardItem(QString::fromStdString(p.getRole()));
		role->setSelectable(false);
		model->setItem(index, 1, role);

		QStandardItem* trophies = new QStandardItem(QString::fromStdString(to_string(p.getTrophies())));
		trophies->setSelectable(false);
		model->setItem(index, 2, trophies);

		QStandardItem* attacks = new QStandardItem(QString::fromStdString(to_string(p.getAttackWins())));
		attacks->setSelectable(false);
		model->setItem(index, 3, attacks);

		QStandardItem* defenses = new QStandardItem(QString::fromStdString(to_string(p.getDefenseWins())));
		defenses->setSelectable(false);
		model->setItem(index, 4, defenses);

		QStandardItem* donations = new QStandardItem(QString::fromStdString(to_string(p.getTroopsDonated())));
		donations->setSelectable(false);
		model->setItem(index, 5, donations);

		QStandardItem* requests = new QStandardItem(QString::fromStdString(to_string(p.getTroopsRequested())));
		requests->setSelectable(false);
		model->setItem(index, 6, requests);

		QStandardItem* ratio = new QStandardItem(QString::fromStdString(p.getRatioStr()));
		ratio->setSelectable(false);
		model->setItem(index, 7, ratio);

		QStandardItem* ratioAdj = new QStandardItem(QString::fromStdString(p.getRatioAdjustedStr()));
		ratioAdj->setSelectable(false);
		model->setItem(index, 8, ratioAdj);

		QStandardItem* activity = new QStandardItem(QString::fromStdString(p.getActivityMetricStr()));
		activity->setSelectable(false);
		model->setItem(index, 9, activity);

		QStandardItem* contribution = new QStandardItem(QString::fromStdString(p.getContributionStr()));
		contribution->setSelectable(false);
		model->setItem(index, 10, contribution);

		index++;
	}
}

int ClanManager::getStar1Selected()
{
	if (first1Star->isChecked()) {
		return 1;
	}
	if (first2Star->isChecked()) {
		return 2;
	}
	if (first3Star->isChecked()) {
		return 3;
	}
}

int ClanManager::getStar2Selected()
{
	if (second1Star->isChecked()) {
		return 1;
	}
	if (second2Star->isChecked()) {
		return 2;
	}
	if (second3Star->isChecked()) {
		return 3;
	}
}

int ClanManager::getEnemy1Level()
{
	int percent = atoi(firstEnemy->text().toStdString().c_str());

	return percent;
}

int ClanManager::getEnemy2Level()
{
	int percent = atoi(secondEnemy->text().toStdString().c_str());
	return percent;
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
	string date = controller->getTime("D/M/Y");

	//get selected player
	QModelIndexList indexes;
	indexes = playerList->selectionModel()->selectedIndexes();

	for (QModelIndex idx : indexes) {
		string name = playerList->model()->data(idx).toString().toStdString();
		AttackPair show{ controller->getPlayerThLevel(name), date };

		int stars1, stars2, enemy1, enemy2, percent1, percent2;
		bool noShow1, noShow2;

		stars1 = getStar1Selected();
		stars2 = getStar2Selected();

		enemy1 = getEnemy1Level();
		enemy2 = getEnemy2Level();

		percent1 = atoi(firstPercent->text().toStdString().c_str());
		percent2 = atoi(secondPercent->text().toStdString().c_str());

		noShow1 = noShowFirst->isChecked();
		noShow2 = noShowSecond->isChecked();

		//handle the no show situation
		if (!noShow1) {
			show.addAttack(stars1, enemy1, percent1);
		}
		if (!noShow2) {
			show.addAttack(stars2, enemy2, percent2);
		}
		controller->addWarAttacks(name, show);
	}
}

void ClanManager::onAddCGScore()
{
	int score = atoi(CGScore->text().toStdString().c_str());
	//get selected player
	QModelIndexList indexes;
	indexes = playerList->selectionModel()->selectedIndexes();

	for (QModelIndex idx : indexes) {
		string name = playerList->model()->data(idx).toString().toStdString();
		controller->addClanGamesScore(name, score);
	}
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
		controller->removePlayer(str.toStdString());
	}
}

void ClanManager::onLoadFreshData()
{ 
	QStringList fileNames;
	do {
		fileNames = QFileDialog::getOpenFileNames(this, tr("Select Fresh Data file"), "", tr("CSV files (*.csv)"));

		if (fileNames.size() == 0) {
			QMessageBox msgBox;
			msgBox.setWindowTitle("No file selected");
			msgBox.setInformativeText("You must select a stats file. Select Cancel to close the application");
			msgBox.setStandardButtons(QMessageBox::Retry | QMessageBox::Cancel);
			msgBox.setDefaultButton(QMessageBox::Retry);
			msgBox.raise();
			int code = msgBox.exec();

			//let the user try again or exit the application
			switch (code) {
			case QMessageBox::Retry: continue;		
			case QMessageBox::Cancel: exit(0);
			}
		}
	} while (fileNames.size() == 0);
	string path = fileNames[0].toStdString();
	try {
		controller->importUpdatedData(path);
	}
	catch (const IOException& e) {
		QMessageBox::warning(this, "Invalid format in file. The application will now exit", QString::fromStdString(e.getMessage()));
		exit(0);
	}
}

void ClanManager::onDetails(const QModelIndex & index)
{
	if (index.column() == 0) {
		QString name = playerList->model()->data(index).toString();
		Player& player = controller->getPlayer(name.toStdString());

		if (detailWindow != nullptr) {
			delete detailWindow;
			detailWindow = nullptr;
		}

		detailWindow = new DetailWindow{ controller, player };
		detailWindow->show();
	}
}
	
