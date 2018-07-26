#pragma once
#include <algorithm>
#include <fstream>
#include <string>
#include <iostream>
#include "Observer.h"
#include "ControllerException.h"
#include "AttackPair.h"
#include "Player.h"
#include "Repo.h"

class Controller
{
public:
	Controller();

	void removePlayer(std::string name);
	void updatePlayer(Player& player);
	void addWarAttacks(std::string playerName, AttackPair warShow);
	void addClanGamesScore(std::string playerName, int score);

	void importUpdatedData(std::string path);
	void loadStats();
	void storeStats();

	int getPlayerThLevel(std::string name);
	int getSize();
	void registerObserver(Observer* observer);
	void onExit();
	std::vector<Player> getAll();
	std::string getTime(std::string format);
	Player& getPlayer(string name);
	void updateComments(Player& player, string newText);
	string getComments(const Player& p);

	enum SortMode {
		donationInc, donationDec, requestInc, requestDec, xp, townhall, attackWins, defenseWins, ratioInc, ratioDec,
		warStars, trophies, versusTrophies, legendTrophies, ratioAdj, contribution, activityMetric
	};
	void sort(SortMode mode);


private:
	Repo repo{};
	std::string statsFilename = "playerStats.";
	std::string tableFilename = "table.csv";		//debug

	void notifyObservers();
	float computeActivityMetric(Player& p);
	float computeRatioAdj(Player& p);
	float computeContribution(Player& p);
	float computeCcsUsedPerBattle(Player& p);
	std::string convertPath(const std::string& path);
	std::vector<Observer*> observers;
};

