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
	//getters
	std::string getTag() const;
	std::string getName() const;
	int getTownHall() const;
	std::string getRole() const;
	int getRank() const;
	int getExperience() const;
	std::string getLeague() const;
	int getTrophies() const;
	int getVersusTrophies() const;
	int getWarStars() const;
	int getLegendTrophies()const;
	int getLastAttackWins() const;
	int getCycleAttackWins(const int cycle) const;
	int getLastDefenseWins() const;
	int getCycleDefenseWins(const int cycle) const;
	int getLastTroopsDonated() const;
	int getCycleTroopsDonated(const int cycle) const;
	int getLastTroopsRequested() const;
	int getCycleTroopsRequested(const int cycle) const;
	std::string getNotes() const { return comments; }
	std::string getSpecialRole() { return specialRole; }
	float getAvgWarStars() const;
	float getCycleAvgWarStars(const int cycle) const;
	float getAvgWarScore() const;
	float getCycleAvgWarScore(const int cycle) const;
	float getAvgCgScore() const;
	float getCycleAvgCgScore(const int cycle) const;
	float getLastRatio() const;
	float getCycleRatio(const int cycle) const;
	int getLastActivityMetric() const;
	int getCycleActivity(const int cycle) const;
	int getLastContribution() const;
	int getCycleContribution(const int cycle) const;
	ClanGamesScore getLastGamesScore() const;
	int getCycleGamesScore(const int cycle) const;
	int getCcSize();

	vector<int> getDonationHistory() const;
	vector<int> getRequestHistory() const;
	vector<float> getRatioHistory() const;
	vector<int> getContributionHistory() const;
	vector<ClanGamesScore> getCgScoreHistory() const;
	vector<int> getActivityHistory() const;

	std::string toString() const;

	void loadFromFile(char* line);
	void loadFromFreshFile(char* line);
	void update(const int newAttacks, const int newDefenses, const int newDonations,
		const int newRequests);

	void addWarShow(const AttackPair& warShow);
	void addClanGamesScore(const int score, const int cycle);
	void setNotes(string text);
	void setSpecialRole(const string newRole);
	std::vector<AttackPair> getWarAttacks() const;

	void computeStats();
	void setCycle(int cycle);

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
	int cycle = -1;
	int cc_size = 0;
	friend class Repo;
};