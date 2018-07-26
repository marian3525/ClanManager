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
	vector<float> ratioAdj = player.getAdjustedRatioHistory();
	vector<int> contributions = player.getContributionHistory();
	vector<int> cgScores = player.getCgScoreHistory();
	vector<int> activities = player.getActivityHistory();
	string str;

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
	for (int i = 0; i < ratioAdj.size(); i++) {
		if (i == 3)
			break;
		str.append(to_string(ratioAdj[i]));
		str.append(", ");
	}
	if (str.size() > 1) {
		str.pop_back();
		str.pop_back();
	}
	this->ratiosAdj->setText(QString::fromStdString(str));

	str.clear();
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

	avgWarScore->setText(QString::number(player.getAvgWarScore()));
	avgWarStars->setText(QString::number(player.getAvgWarStars()));
	avgCGScore->setText(QString::number(player.getAvgCgScore()));
	str.clear();
	for (int i = 0; i < cgScores.size(); i++) {
		if (i == 3)
			break;
		str.append(to_string(cgScores[i]));
		str.append(", ");
	}
	if (str.size() > 1) {
		str.pop_back();
		str.pop_back();
	}
	this->cgScores->setText(QString::fromStdString(str));

	str.clear();
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
	
	role->setText(QString::fromStdString(player.getRole()));
	specialRole->setText(QString::fromStdString(player.getSpecialRole()));
	notes->setText(QString::fromStdString(controller->getComments(player)));
}

void DetailWindow::bindWidgets()
{
	warAttacksList = findChild<QListView*>("warAttacksList");
	warAttacksList->setModel(model);

	donations = findChild<QLabel*>("donationsLabel");
	requests = findChild<QLabel*>("requestsLabel");
	ratios = findChild<QLabel*>("ratiosLabel");
	ratiosAdj = findChild<QLabel*>("ratiosAdjLabel");
	contributions = findChild<QLabel*>("contributionsLabel");
	avgWarScore = findChild<QLabel*>("avgWarScoreLabel");
	avgWarStars = findChild<QLabel*>("avgWarStarsLabel");
	cgScores = findChild<QLabel*>("cgScores");
	avgCGScore = findChild<QLabel*>("avgCgScoreLabel");
	activities = findChild<QLabel*>("activitiesLabel");
	role = findChild<QLabel*>("roleLabel");
	specialRole = findChild<QLabel*>("specialRoleLabel");
	notes = findChild<QTextEdit*>("notes");
	connect(notes, &QTextEdit::textChanged, this, &DetailWindow::onNotesUpdate);
}

void DetailWindow::populateWarAttacks()
{
	QStringList strList;
	string output;
	pair<int, int> stars;
	pair<int, int> percent;
	pair<int, int> enemy;
	int performance;

	for (AttackPair& show : player.getWarAttacks()) {
		stars = show.getStars();
		percent = show.getPercent();
		enemy = show.getEnemy();
		performance = show.getPerformance();
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

		strList.push_back(QString::fromStdString(output));
		output.clear();
	}
	model->setStringList(strList);
}

void DetailWindow::onNotesUpdate() {
	/*
		send the new text to the controller
	*/
	string str = notes->toPlainText().toStdString();
	if(str.c_str() != "None")
		controller->updateComments(player, str);
}