#include "stdafx.h"
#include "Controller.h"
#include <fstream>
#include <algorithm>

Controller::Controller()
{	
	//TODO add a menu to select the absolute path in a file browser
	string fname = "#LR0LGRVR - 2018-07-18 16-00-52.csv";
	importUpdatedData(fname);
	computeMetrics();
	writeCSV();
}

void Controller::loadStats()
{
	/*
		Load stats from a file (war performances & long term behaviour)
	*/
	ifstream f("playerStats.stats");
}

void Controller::storeStats()
{
	/*
		Store stats in a file as persistent storage
	*/
	ofstream f("playerStats.stats");
	/*
		Store each player's stats
	*/
	for (const Player& player : repo.getAll()) {
		f << player.toString() << endl;
	}
}

void Controller::removePlayer(string tag)
{
	repo.remove(tag);
	notifyObservers();
}

void Controller::updatePlayer(const Player & player)
{
	Player& p = repo.getByName(player.getName());

	p = player;

	notifyObservers();
}

void Controller::importUpdatedData(string path)
{
	/*
		Load fresh data from the .csv dowloaded from clashofstats
	*/
	//convert the separators from / to //
	path.replace(path.begin(), path.end(), '/', '//');

	ifstream f(path);
	if (!f.is_open())
		return;

	char* line = new char[1300];

	char* char_ptr;				//ptr to the current token in the line
	string tag, name, role, league;
	int townHall, rank, experience, trophies, versusTrophies, warStars, legendThophies, attackWins, defenseWins,
		troopsDonated, troopReceived;

	//read the first line with the headers, we don't need it
	f.getline(line, 1298);

	while (!f.eof()) {
		f.getline(line, 1298);

		char_ptr = strtok(line, ",");
		tag = string(char_ptr + 1, strlen(char_ptr) - 2);		//strip the first and the last chars which are '"' and not needed

		char_ptr = strtok(NULL, ",");
		name = string(char_ptr + 1, strlen(char_ptr) - 2);

		char_ptr = strtok(NULL, ",");
		townHall = atoi(char_ptr);

		char_ptr = strtok(NULL, ",");
		role = string(char_ptr + 1, strlen(char_ptr) - 2);

		char_ptr = strtok(NULL, ",");
		rank = atoi(char_ptr);

		char_ptr = strtok(NULL, ",");
		experience = atoi(char_ptr);

		char_ptr = strtok(NULL, ",");
		league = string(char_ptr + 1, strlen(char_ptr) - 2);

		char_ptr = strtok(NULL, ",");
		trophies = atoi(char_ptr);

		char_ptr = strtok(NULL, ",");
		versusTrophies = atoi(char_ptr);

		char_ptr = strtok(NULL, ",");
		warStars = atoi(char_ptr);

		//0 legend trophies do not exist in the file. No trophies is marked by nothing, so prev_attr,,next_attr
		//if after the prev token there is a , then there are 0 legend trophies. Else, parse as usual
		if (*(char_ptr + strlen(char_ptr) + 1) == ',') {
			legendThophies = 0;
		}
		else {
			char_ptr = strtok(NULL, ",");
			legendThophies = atoi(char_ptr);
		}

		char_ptr = strtok(NULL, ",");
		attackWins = atoi(char_ptr);

		char_ptr = strtok(NULL, ",");
		defenseWins = atoi(char_ptr);

		char_ptr = strtok(NULL, ",");
		troopsDonated = atoi(char_ptr);

		char_ptr = strtok(NULL, ",");
		troopReceived = atoi(char_ptr);

		Player p{ tag, name, townHall, role, rank, experience, league, trophies, versusTrophies, warStars, legendThophies,
			attackWins, defenseWins, troopsDonated, troopReceived };

		if (repo.existsByName(name))
			updatePlayer(p);
		else
			repo.add(p);
	}
	f.close();
	delete line;
}

void Controller::computeMetrics()
{
	float ratio;
	float ratio_adjusted;
	float activity_metric;
	float contribution;

	
	for (Player& p : repo.getAll()) {
		//the common ratio
		if (p.getTroopsRequested() != 0) {
			ratio = (float) p.getTroopsDonated() / p.getTroopsRequested();
		}
		else {
			ratio = p.getTroopsDonated();
		}
		p.setRatio(ratio);
		
		//adjusted ratio
		float ratioAdj = computeRatioAdj(p);
		p.setRatioAdjusted(ratioAdj);

		//activity masurement
		float activityMetric = computeActivityMetric(p);
		p.setActivityMetric(activityMetric);
	}
}

void Controller::addWarAttacks(string playerName, AttackPair warShow)
{
	Player& player = repo.getByName(playerName);
	player.addWarShow(warShow);
}

void Controller::writeCSV()
{
	/*
		Debug use only!
	*/
	ofstream o("stats.csv");
	ofstream t("table.csv");
	if (!o.is_open() || !t.is_open())
		return;

	//header used to make the table more readable
	string header = "Tag,Name,TH level,Role,Rank,Level,League,Trophies,versusTrophies,War Stars,Legend Trophies,Attacks Won,Defenses Won,\
Troops Donated,Troops requested,Ratio,Ratio Adjusted,Activity,Contribution";
	t << header <<endl;

	for (Player p : repo.getAll()) {
		o << p.toStringDebug() << endl;
		t << p.toStringTable() << endl;
	}
	o.close();
	t.close();
}

int Controller::getSize()
{
	return repo.getSize();
}

void Controller::registerObserver(Observer * observer)
{
	observers.push_back(observer);
}

void Controller::onExit()
{
	/*
		Save data in files
	*/
	writeCSV();
	//save persistent player data

}

vector<Player> Controller::getAll()
{
	return repo.getAll();
}

void Controller::sort(SortMode mode)
{
	std::function<bool(const Player& a, const Player& b)> cmp;

	switch (mode) {
	case donationInc:
		cmp = [](const Player& a, const Player& b) {return a.getTroopsDonated() < b.getTroopsDonated(); };
		break;
	case donationDec:
		cmp = [](const Player& a, const Player& b) {return a.getTroopsDonated() > b.getTroopsDonated(); };
		break;
	case requestInc:
		cmp = [](const Player& a, const Player& b) {return a.getTroopsRequested() < b.getTroopsRequested(); };
		break;
	case requestDec:
		cmp = [](const Player& a, const Player& b) {return a.getTroopsRequested() > b.getTroopsRequested(); };
		break;
	case xp:
		cmp = [](const Player& a, const Player& b) {return a.getExperience() > b.getExperience(); };
		break;
	case townhall:
		cmp = [](const Player& a, const Player& b) {return a.getTownHall() > b.getTownHall();; };
		break;
	case attackWins:
		cmp = [](const Player& a, const Player& b) {return a.getAttackWins() > b.getAttackWins(); };
		break;
	case defenseWins:
		cmp = [](const Player& a, const Player& b) {return a.getDefenseWins() < b.getDefenseWins(); };
		break;
	case ratioInc:
		cmp = [](const Player& a, const Player& b) {return a.getRatio() > b.getRatio(); };
		break;
	case ratioDec:
		cmp = [](const Player& a, const Player& b) {return a.getRatio() < b.getRatio(); };
		break;
	case warStars:
		cmp = [](const Player& a, const Player& b) {return a.getWarStars() > b.getWarStars(); };
		break;
	case trophies:
		cmp = [](const Player& a, const Player& b) {return a.getTrophies() > b.getTrophies(); };
		break;
	case versusTrophies:
		cmp = [](const Player& a, const Player& b) {return a.getVersusTrophies() > b.getVersusTrophies(); };
		break;
	case legendTrophies:
		cmp = [](const Player& a, const Player& b) {return a.getLegendTrophies() > b.getLegendTrophies(); };
		break;
	case ratioAdj:
		cmp = [](const Player& a, const Player& b) {return a.getRatioAdjusted() > b.getRatioAdjusted(); };
		break;
	case activityMetric:
		cmp = [](const Player& a, const Player& b) {return a.getActivityMetric() > b.getActivityMetric(); };
		break;
	case contribution:
		cmp = [](const Player& a, const Player& b) {return a.getContribution() > b.getContribution(); };
		break;
	}
	std::sort(repo.getAll().begin(), repo.getAll().end(), cmp);
	notifyObservers();
}

void Controller::notifyObservers()
{
	for (Observer* observer : observers) {
		observer->notify();
	}
}

float Controller::computeActivityMetric(Player & p)
{
	float activityMetric;
	//activity metric:
	int cc_size;
	switch (p.getTownHall()) {
	case 1:
		cc_size = 0;
	case 2:
		cc_size = 0;
	case 3:
		cc_size = 10;
	case 4:
		cc_size = 15;
	case 5:
		cc_size = 15;
	case 6:
		cc_size = 20;
	case 7:
		cc_size = 20;
	case 8:
		cc_size = 25;
	case 9:
		cc_size = 30;
	case 10:
		cc_size = 35;
	case 11:
		cc_size = 35;
	case 12:
		cc_size = 40;
	}
	activityMetric = p.getAttackWins() * cc_size + p.getTroopsDonated() + p.getTroopsRequested();
	return activityMetric;
}

float Controller::computeRatioAdj(Player & p)
{
	float ratioAdj;
	if (p.getAttackWins() != 0)
		ratioAdj = p.getTroopsRequested() / p.getAttackWins();
	else
		ratioAdj = p.getTroopsRequested();
	
	ratioAdj /= p.getCcSize();
	
	return ratioAdj;
}

float Controller::computeContribution(Player & p)
{
	float contribution=0;

	contribution += p.getTroopsDonated();
	contribution += p.getGamesScore();
	return contribution;
}

float Controller::computeCcsUsedPerBattle(Player & p)
{
	float ccs;
	if (p.getAttackWins() != 0)
		ccs = p.getTroopsRequested() / p.getAttackWins();
	else
		ccs = p.getTroopsRequested();

	ccs /= p.getCcSize();

	return ccs;
}
