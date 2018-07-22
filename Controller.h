#pragma once
#include "Repo.h"
#include <algorithm>
#include <fstream>
#include <string>
#include <iostream>
#include "Observer.h"
#include "ControllerException.h"
#include "AttackPair.h"
using namespace std;

class Controller
{
public:
	Controller();

	void removePlayer(string name);
	void updatePlayer(Player& player);
	void computeMetrics();
	void addWarAttacks(string playerName, AttackPair warShow);

	void importUpdatedData(string path);
	void loadStats();
	void storeStats();
	void importDataFromCopy();

	int getPlayerThLevel(string name);
	int getSize();
	void registerObserver(Observer* observer);
	void onExit();
	vector<Player> getAll();
	string getTime(string format);

	enum SortMode {
		donationInc, donationDec, requestInc, requestDec, xp, townhall, attackWins, defenseWins, ratioInc, ratioDec,
		warStars, trophies, versusTrophies, legendTrophies, ratioAdj, contribution, activityMetric
	};
	void sort(SortMode mode);

private:
	Repo repo{};
	string statsFilename = "playerStats.csv";
	string freshDataFilename = "D:/Projects/C++/ClanManager/ClanManager/#LR0LGRVR - 2018-07-18 16-00-52.csv";		//debug
	string freshCopyFilename = "freshCopy.csv";
	string tableFilename = "table.csv";		//debug

	void notifyObservers();
	float computeActivityMetric(Player& p);
	float computeRatioAdj(Player& p);
	float computeContribution(Player& p);
	float computeCcsUsedPerBattle(Player& p);
	string convertPath(const string& path);
	vector<Observer*> observers;
};

