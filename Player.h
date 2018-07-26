#pragma once
#include <iomanip>
#include <sstream>
#include "PlayerHistory.h"
#include "IOException.h"
#include "AttackPair.h"

class Player
{
public:
	Player();

	std::string getTag() const { return tag; }
	std::string getName() const { return name; }
	int getTownHall() const { return townHall; }
	std::string getRole() const { return role; }
	int getRank() const { return rank; }
	int getExperience() const { return experience; }
	std::string getLeague() const { return league; }
	int getTrophies() const { return trophies; }
	int getVersusTrophies() const { return versusTrophies; }
	int getWarStars() const { return warStars; }
	int getLegendTrophies()const { return legendTrophies; }
	int getAttackWins() const { return history.getLastAttacks(); }
	int getDefenseWins() const { return history.getLastDefenses(); }
	int getTroopsDonated() const { return history.getLastDonations(); }
	int getTroopsRequested() const { return history.getLastRequests(); }
	std::string getNotes() const { return comments; }
	std::string getSpecialRole() { return specialRole; }
	float getAvgWarStars() const;
	float getAvgWarScore() const;
	float getAvgCgScore() const;
	float getRatio() const { return history.getLastRatio(); }
	std::string getRatioStr() const { std::stringstream ss; ss << std::fixed << std::setprecision(2) << history.getLastRatio(); return ss.str(); };

	float getRatioAdjusted() const { return history.getLastAdjustedRatio(); }
	std::string getRatioAdjustedStr() const { std::stringstream ss; ss << std::fixed << std::setprecision(2) << history.getLastAdjustedRatio(); return ss.str(); }

	float getActivityMetric() const { return history.getLastActivity(); }
	std::string getActivityMetricStr() const { std::stringstream ss; ss << std::fixed << std::setprecision(2) << history.getLastActivity(); return ss.str(); };

	float getContribution() const { return history.getLastContribution(); }
	std::string getContributionStr() const { std::stringstream ss; ss << std::fixed << std::setprecision(2) << history.getLastAdjustedRatio(); return ss.str(); };

	int getGamesScore() const { return history.getLastGamesScore(); }

	int getCcSize();
	
	std::string toString() const;

	void addWarAttacksFromFile(char* line);

	void addWarShow(const AttackPair& warShow);
	void addClanGamesScore(const int score);

	void setNotes(string text);

	std::vector<AttackPair> getWarAttacks() { return history.getShows(); }

	vector<int> getDonationHistory() { return history.getDonations(); }
	vector<int> getRequestHistory() { return history.getRequests(); }
	vector<float> getRatioHistory() { return history.getRatioList(); }
	vector<float> getAdjustedRatioHistory() { return history.getAdjustedRatio(); }
	vector<int> getContributionHistory() { return history.getContribution(); }
	vector<int> getCgScoreHistory() { return history.getGamesScore(); }
	vector<int> getActivityHistory() { return history.getActivity(); }

	void loadFromFile(char* line);
	void loadFromFreshFile(char* line);
	void update(const int newAttacks, const int newDefenses, const int newDonations,
		const int newRequests);
	void computeStats();

private:
	PlayerHistory history;

	std::string tag = "";
	std::string name = "";
	int townHall = 0;
	std::string role = "";
	std::string specialRole = "None";
	std::string comments = "None";
	int rank = 0;
	int experience = 0;
	std::string league = "";
	int trophies = 0;
	int versusTrophies = 0;
	int warStars = 0;
	int legendTrophies = 0;

	int cc_size = 0;
};