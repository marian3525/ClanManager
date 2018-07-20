#pragma once
#include "Repo.h"
#include <algorithm>
#include "Observer.h"
class Controller
{
public:
	Controller();

	void loadStats();
	void removePlayer(string name);
	void importUpdatedData(string path);
	void computeMetrics();
	void writeCSV();
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
	void notifyObservers();
	float computeActivityMetric(Player& p);
	float computeRatioAdj(Player& p);
	float computeContribution(Player& p);
	float computeCcsUsedPerBattle(Player& p);
	vector<Observer*> observers;
};

