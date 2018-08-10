#include <stdafx.h>
#include "DetailWindow.h"

DetailWindow::DetailWindow(Controller* controller, Player& player, QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->player = player;
	this->controller = controller;
	this->setWindowTitle(QString::fromStdString(player.getName()));
	this->model = new QStringListModel{ this };
	bindWidgets();
	populateWarAttacks();
	setValues();
}

void DetailWindow::setValues()
{
	vector<int> donations = player.getDonationHistory();
	vector<int> requests = player.getRequestHistory();
	vector<float> ratios = player.getRatioHistory();
	vector<int> contributions = player.getContributionHistory();
	vector<ClanGamesScore> cgScores = player.getCgScoreHistory();
	vector<int> activities = player.getActivityHistory();
	string str;

	//donations
	for (int i = 0; i < donations.size(); i++) {
		if (i == 3)
			break;
		str.append(to_string(donations[i]));
		str.append(", ");
	}
	if (str.size() > 1) {
		str.pop_back();
		str.pop_back();
	}

	this->donations->setText(QString::fromStdString(str));

	str.clear();
	//requests
	for (int i = 0; i < requests.size(); i++) {
		if (i == 3)
			break;
		str.append(to_string(requests[i]));
		str.append(", ");
	}
	if (str.size() > 1) {
		str.pop_back();
		str.pop_back();
	}
	this->requests->setText(QString::fromStdString(str));

	str.clear();
	//ratios
	for (int i = 0; i < ratios.size(); i++) {
		if (i == 3)
			break;
		str.append(to_string(ratios[i]));
		str.append(", ");
	}
	if (str.size() > 1) {
		str.pop_back();
		str.pop_back();
	}
	this->ratios->setText(QString::fromStdString(str));

	str.clear();
	//contributions
	for (int i = 0; i < contributions.size(); i++) {
		if (i == 3)
			break;
		str.append(to_string(contributions[i]));
		str.append(", ");
	}
	if (str.size() > 1) {
		str.pop_back();
		str.pop_back();
	}
	this->contributions->setText(QString::fromStdString(str));
	str.clear();
	//avg war score
	avgWarScore->setText(QString::number(player.getAvgWarScore()));
	//avg war stars this season
	avgWarStars->setText(QString::number(player.getAvgWarStars()));
	//CG scores for each season
	for (int i = 0; i < cgScores.size(); i++) {
		if (i == 3)
			break;
		str.append(to_string(cgScores[i].getScore()));
		str.append(", ");
	}
	if (str.size() > 1) {
		str.pop_back();
		str.pop_back();
	}
	this->cgScores->setText(QString::fromStdString(str));

	//avg CG scores
	avgCGScore->setText(QString::number(player.getAvgCgScore()));

	str.clear();
	//activities
	for (int i = 0; i < activities.size(); i++) {
		if (i == 3)
			break;
		str.append(to_string(activities[i]));
		str.append(", ");
	}
	if (str.size() > 1) {
		str.pop_back();
		str.pop_back();
	}
	this->activities->setText(QString::fromStdString(str));

	//roles
	role->setText(QString::fromStdString(player.getRole()));

	//special role
	specialRole->setText(QString::fromStdString(player.getSpecialRole()));

	//and notes
	notes->setText(QString::fromStdString(controller->getComments(player)));
}

void DetailWindow::bindWidgets()
{
	warAttacksList = findChild<QListView*>("warAttacksList");
	warAttacksList->setEditTriggers(QAbstractItemView::NoEditTriggers);
	warAttacksList->setModel(model);

	donations = findChild<QLabel*>("donationsLabel");
	requests = findChild<QLabel*>("requestsLabel");
	ratios = findChild<QLabel*>("ratiosLabel");
	contributions = findChild<QLabel*>("contributionsLabel");
	avgWarScore = findChild<QLabel*>("avgWarScoreLabel");
	avgWarStars = findChild<QLabel*>("avgWarStarsLabel");
	cgScores = findChild<QLabel*>("cgScores");
	avgCGScore = findChild<QLabel*>("avgCgScoreLabel");
	activities = findChild<QLabel*>("activitiesLabel");
	role = findChild<QLabel*>("roleLabel");
	specialRole = findChild<QLineEdit*>("specialRoleInput");
	notes = findChild<QTextEdit*>("notes");
	connect(notes, &QTextEdit::textChanged, this, &DetailWindow::onNotesUpdate);
	connect(specialRole, &QLineEdit::textChanged, this, &DetailWindow::onSpecialRoleChanged);
}

void DetailWindow::populateWarAttacks()
{
	QStringList strList;
	string output;
	pair<int, int> stars;
	pair<int, int> percent;
	pair<int, int> enemy;
	int performance;
	string date;

	for (AttackPair& show : player.getWarAttacks()) {
		stars = show.getStars();
		percent = show.getPercent();
		enemy = show.getEnemy();
		performance = show.getPerformance();
		date = show.getDate();
		//lazy formatting
		output.append("Attack 1: ");
		output.append(to_string(stars.first));
		output.append("             Attack 2: ");
		output.append(to_string(stars.second));
		output.append("\n");

		output.append("Percentage 1: ");
		output.append(to_string(percent.first));
		output.append("    Percentage 2: ");
		output.append(to_string(percent.second));
		output.append("\n");

		output.append("Townhall 1: ");
		output.append(to_string(enemy.first));
		output.append("        Townhall 2: ");
		output.append(to_string(enemy.second));
		output.append("\n");

		output.append("Performance: ");
		output.append(to_string(performance));
		output.append(" @ "+date);


		strList.push_back(QString::fromStdString(output));
		output.clear();
	}
	model->setStringList(strList);
}

void DetailWindow::onSpecialRoleChanged()
{
	string str = specialRole->text().toStdString();
	controller->updateSpecialRole(player, str);
}

void DetailWindow::onNotesUpdate() {
	/*
		send the new text to the controller
	*/
	string str = notes->toPlainText().toStdString();
	if(str.c_str() != "None")
		controller->updateComments(player, str);
}