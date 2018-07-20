#pragma once
#include "Repo.h"
#include <algorithm>
#include "Observer.h"
class Controller
{
public:
	Controller();

	void removePlayer(string name);
	void updatePlayer(const Player& player);
	void computeMetrics();
	void addWarAttacks(string playerName, AttackPair warShow);
	void writeCSV();	//debug
	void importUpdatedData(string path);
	void loadStats();
	void storeStats();

	int getSize();
	void registerObserver(Observer* observer);
	void onExit();
	vector<Player> getAll();

	enum SortMode {
		donationInc, donationDec, requestInc, requestDec, xp, townhall, attackWins, defenseWins, ratioInc, ratioDec,
		warStars, trophies, versusTrophies, legendTrophies, ratioAdj, contribution, activityMetric
	};
	void sort(SortMode mode);

private:
	Repo repo{};
	string statsFilename = "playerStats.csv";
	string freshDataFilename = "#LR0LGRVR - 2018-07-18 16-00-52.csv";
	string tableFilename = "table.csv";

	void notifyObservers();
	float computeActivityMetric(Player& p);
	float computeRatioAdj(Player& p);
	float computeContribution(Player& p);
	float computeCcsUsedPerBattle(Player& p);
	vector<Observer*> observers;
};

