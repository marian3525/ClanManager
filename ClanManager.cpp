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
		onLoadCycleData();
	}
	bindWidgets();
	addHeaders();
	update();
	onRatioSelected();
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
	warScore = findChild<QRadioButton*>("warScoreRadio");
	versusTrophies = findChild<QRadioButton*>("versusTrophiesRadio");
	legendTrophies = findChild<QRadioButton*>("legendRadio");
	contribution = findChild<QRadioButton*>("contributionRadio");
	activity = findChild<QRadioButton*>("activityRadio");

	CGScore = findChild<QLineEdit*>("CGScore");
	addCGScore = findChild<QPushButton*>("addCGScore");

	noShowFirst = findChild<QCheckBox*>("noShowFirst");
	first0Star = findChild<QRadioButton*>("first0Star");
	first1Star = findChild<QRadioButton*>("first1star");
	first2Star = findChild<QRadioButton*>("first2star");
	first3Star = findChild<QRadioButton*>("first3star");

	firstPercent = findChild<QLineEdit*>("firstPercent");
	firstEnemy = findChild<QSpinBox*>("enemyFirst");

	noShowSecond = findChild<QCheckBox*>("noShowSecond");
	second0Star = findChild<QRadioButton*>("second0Star");
	second1Star = findChild<QRadioButton*>("second1star");
	second2Star = findChild<QRadioButton*>("second2star");
	second3Star = findChild<QRadioButton*>("second3star");

	secondPercent = findChild<QLineEdit*>("secondPercent");
	secondEnemy = findChild<QSpinBox*>("enemySecond");
	addWarAttackButton = findChild<QPushButton*>("addWarAttacks");

	memberCounter = findChild<QLCDNumber*>("counter");

	removePlayerButton = findChild<QPushButton*>("removePlayer");

	loadCycleData = findChild<QAction*>("actionLoadCycleData");
	loadUpdatedData = findChild<QAction*>("actionLoadUpdatedData");
	createTableFile = findChild<QAction*>("actionCreateTableFile");
	help = findChild<QAction*>("actionHelp");
	about = findChild<QAction*>("actionAbout");

	cycleIndicator = findChild<QLabel*>("cycleLabel");


	connect(playerList, &QTableView::doubleClicked, this, &ClanManager::onDetails);
	connect(donations, &QRadioButton::clicked, this, &ClanManager::onDonationsSelected);
	connect(requests, &QRadioButton::clicked, this, &ClanManager::onRequestsSelected);
	connect(attacks, &QRadioButton::clicked, this, &ClanManager::onAttacksSelected);
	connect(defenses, &QRadioButton::clicked, this, &ClanManager::onDefensesSelected);
	connect(ratio, &QRadioButton::clicked, this, &ClanManager::onRatioSelected);
	connect(warStars, &QRadioButton::clicked, this, &ClanManager::onWarStarsSelected);
	connect(trophies, &QRadioButton::clicked, this, &ClanManager::onTrophiesSelected);
	connect(warScore, &QRadioButton::clicked, this, &ClanManager::onWarScoreSelected);
	connect(versusTrophies, &QRadioButton::clicked, this, &ClanManager::onVersusTrophiesSelected);
	connect(legendTrophies, &QRadioButton::clicked, this, &ClanManager::onLegendTrophiesSelected);
	connect(contribution, &QRadioButton::clicked, this, &ClanManager::onContributionSelected);
	connect(activity, &QRadioButton::clicked, this, &ClanManager::onActivitySelected);

	connect(addWarAttackButton, &QPushButton::clicked, this, &ClanManager::onAddWarAttack);
	connect(addCGScore, &QPushButton::clicked, this, &ClanManager::onAddCGScore);
	connect(noShowFirst, &QCheckBox::clicked, this, &ClanManager::onNoShowFirst);
	connect(first0Star, &QRadioButton::clicked, this, &ClanManager::onFirst0Star);
	connect(first1Star, &QRadioButton::clicked, this, &ClanManager::onFirst1Star);
	connect(first2Star, &QRadioButton::clicked, this, &ClanManager::onFirst2Star);
	connect(first3Star, &QRadioButton::clicked, this, &ClanManager::onFirst3Star);
	connect(noShowSecond, &QCheckBox::clicked, this, &ClanManager::onNoShowSecond);
	connect(second0Star, &QRadioButton::clicked, this, &ClanManager::onSecond0Star);
	connect(second1Star, &QRadioButton::clicked, this, &ClanManager::onSecond1Star);
	connect(second2Star, &QRadioButton::clicked, this, &ClanManager::onSecond2Star);
	connect(second3Star, &QRadioButton::clicked, this, &ClanManager::onSecond3Star);
	connect(removePlayerButton, &QPushButton::clicked, this, &ClanManager::onRemove);
	//in the menu:
	connect(loadCycleData, &QAction::triggered, this, &ClanManager::onLoadCycleData);
	connect(loadUpdatedData, &QAction::triggered, this, &ClanManager::onLoadUpdatedData);
	connect(createTableFile, &QAction::triggered, this, &ClanManager::onCreateTableFile);
	connect(help, &QAction::triggered, this, &ClanManager::onHelp);
	connect(about, &QAction::triggered, this, &ClanManager::onAbout);
}

void ClanManager::addHeaders()
{
	vector<string> header{ "Name", "Role", "Trophies", "Attacks", "Defenses", "Donations", "Requests", "Ratio", "Activity", "Contribution" };
	for (int i = 0; i < header.size(); i++) {
		model->setHorizontalHeaderItem(i, new QStandardItem(QString::fromStdString(header[i])));
	}

	playerList->setModel(model);
}

void ClanManager::update()
{
	memberCounter->display(controller->getSize());
	cycleIndicator->setText(QString::number(controller->getCycle()));
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
	playerList->setColumnWidth(9, 85);
}

void ClanManager::populateRows()
{	
	int index = 0;
	for (const Player& p : controller->getAllPlayers()) {
		QStandardItem* name = new QStandardItem(QString::fromStdString(p.getName()));
		name->setSelectable(true);
		model->setItem(index, 0, name);

		QStandardItem* role = new QStandardItem(QString::fromStdString(p.getRole()));
		role->setSelectable(false);
		model->setItem(index, 1, role);

		QStandardItem* trophies = new QStandardItem(QString::fromStdString(to_string(p.getTrophies())));
		trophies->setSelectable(false);
		model->setItem(index, 2, trophies);

		QStandardItem* attacks = new QStandardItem(QString::fromStdString(to_string(p.getLastAttackWins())));
		attacks->setSelectable(false);
		model->setItem(index, 3, attacks);

		QStandardItem* defenses = new QStandardItem(QString::fromStdString(to_string(p.getLastDefenseWins())));
		defenses->setSelectable(false);
		model->setItem(index, 4, defenses);

		QStandardItem* donations = new QStandardItem(QString::fromStdString(to_string(p.getLastTroopsDonated())));
		donations->setSelectable(false);
		model->setItem(index, 5, donations);

		QStandardItem* requests = new QStandardItem(QString::fromStdString(to_string(p.getLastTroopsRequested())));
		requests->setSelectable(false);
		model->setItem(index, 6, requests);

		QStandardItem* ratio = new QStandardItem(QString::fromStdString(to_string(p.getLastRatio())));
		ratio->setSelectable(false);
		model->setItem(index, 7, ratio);

		QStandardItem* activity = new QStandardItem(QString::fromStdString(to_string(p.getLastActivityMetric())));
		activity->setSelectable(false);
		model->setItem(index, 8, activity);

		QStandardItem* contribution = new QStandardItem(QString::fromStdString(to_string(p.getLastContribution())));
		contribution->setSelectable(false);
		model->setItem(index, 9, contribution);

		index++;
	}
}

int ClanManager::getStar1Selected()
{
	if (first0Star->isChecked()) {
		return 0;
	}
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
	if (second0Star->isChecked()) {
		return 0;
	}
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
	lastSort = Controller::SortMode::donationDec;
}

void ClanManager::onRequestsSelected()
{
	controller->sort(Controller::SortMode::requestDec);
	lastSort = Controller::SortMode::requestDec;
}

void ClanManager::onAttacksSelected()
{
	controller->sort(Controller::SortMode::attackWins);
	lastSort = Controller::SortMode::attackWins;
}

void ClanManager::onDefensesSelected()
{
	controller->sort(Controller::SortMode::defenseWins);
	lastSort = Controller::SortMode::defenseWins;
}

void ClanManager::onRatioSelected()
{
	controller->sort(Controller::SortMode::ratioDec);
	lastSort = Controller::SortMode::ratioDec;
}

void ClanManager::onWarStarsSelected()
{
	controller->sort(Controller::SortMode::warStars);
	lastSort = Controller::SortMode::warStars;
}

void ClanManager::onTrophiesSelected()
{
	controller->sort(Controller::SortMode::trophies);
	lastSort = Controller::SortMode::trophies;
}

void ClanManager::onWarScoreSelected()
{
	controller->sort(Controller::SortMode::warScore);
	lastSort = Controller::SortMode::warScore;
}

void ClanManager::onVersusTrophiesSelected()
{
	controller->sort(Controller::SortMode::versusTrophies);
	lastSort = Controller::SortMode::versusTrophies;
}

void ClanManager::onLegendTrophiesSelected()
{
	controller->sort(Controller::SortMode::legendTrophies);
	lastSort = Controller::SortMode::legendTrophies;
}

void ClanManager::onContributionSelected()
{
	controller->sort(Controller::SortMode::contribution);
	lastSort = Controller::SortMode::contribution;
}

void ClanManager::onActivitySelected()
{
	controller->sort(Controller::SortMode::activityMetric);
	lastSort = Controller::SortMode::activityMetric;
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
		AttackPair show{ controller->getPlayerThLevel(name), date, controller->getCycle()};

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
		break;
	}
	noShowFirst->setChecked(false);
	noShowSecond->setChecked(false);
	controller->sort(lastSort);
}


void ClanManager::onNoShowFirst()
{

}

void ClanManager::onNoShowSecond()
{
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
	//sort again
	controller->sort(lastSort);
}

void ClanManager::onFirst0Star()
{
	first1Star->setChecked(false);
	first2Star->setChecked(false);
	first3Star->setChecked(false);
}

void ClanManager::onFirst1Star()
{
	first0Star->setChecked(false);
	first2Star->setChecked(false);
	first3Star->setChecked(false);
}

void ClanManager::onFirst2Star()
{
	first0Star->setChecked(false);
	first1Star->setChecked(false);
	first3Star->setChecked(false);
}

void ClanManager::onFirst3Star()
{
	first0Star->setChecked(false);
	first1Star->setChecked(false);
	first2Star->setChecked(false);
}

void ClanManager::onSecond0Star() {
	second1Star->setChecked(false);
	second2Star->setChecked(false);
	second3Star->setChecked(false);
}

void ClanManager::onSecond1Star()
{
	second0Star->setChecked(false);
	second2Star->setChecked(false);
	second3Star->setChecked(false);
}

void ClanManager::onSecond2Star()
{
	second0Star->setChecked(false);
	second1Star->setChecked(false);
	second3Star->setChecked(false);
}

void ClanManager::onSecond3Star()
{
	second0Star->setChecked(false);
	second1Star->setChecked(false);
	second2Star->setChecked(false);
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

void ClanManager::onLoadCycleData()
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
		controller->importCycleData(path);
	}
	catch (const IOException& e) {
		QMessageBox::warning(this, "Invalid format in file. The application will now exit", QString::fromStdString(e.getMessage()));
		exit(0);
	}
}

void ClanManager::onLoadUpdatedData()
{
	/*
		When loading a fresh file from the menu
	*/
	QStringList fileNames;
	fileNames = QFileDialog::getOpenFileNames(this, tr("Select Fresh Data file"), "", tr("CSV files (*.csv)"));
	if (fileNames.size() != 0) {
		string path = fileNames[0].toStdString();
		try {
			controller->importUpdatedData(path);
		}
		catch (const IOException& e) {
			QMessageBox::warning(this, "Invalid format in file. Data will not be loaded", QString::fromStdString(e.getMessage()));
		}
	}
}

void ClanManager::onCreateTableFile()
{
	controller->storeTable();
}

void ClanManager::onHelp()
{
}

void ClanManager::onAbout()
{
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
	
