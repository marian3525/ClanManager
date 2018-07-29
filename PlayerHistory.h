#pragma once
#include "AttackPair.h"
#include "IOException.h"
#include "ClanGamesScore.h"
class PlayerHistory
{
public:
	PlayerHistory();
	void setCcSize(int cc);

	std::string toString() const;

	void readHistoryFromStatsLine(char* line);

	void addRatio(const float ratio);
	float getLastRatio() const;
	std::vector<float> getRatios() const;

	void addAdjustedRatio(const float adjRatio);
	float getLastAdjustedRatio() const;
	std::vector<float> getAdjustedRatio();

	void addActivity(const int activity);
	int getLastActivity() const;
	std::vector<int> getActivity() const;

	void addContribution(const int contribution);
	float getLastContribution() const;
	std::vector<int> getContribution() const;

	void addDonations(const int donations);
	int getLastDonations() const;
	std::vector<int> getDonations() const;

	void addRequests(const int requests);
	int getLastRequests() const;
	std::vector<int> getRequests() const;

	void addWarShow(const AttackPair show);
	AttackPair getLastShow() const;
	std::vector<AttackPair> getShows();

	void addAttacks(const int attacks);
	int getLastAttacks() const;
	std::vector<int> getAttacks() const;

	void addDefenses(const int defenses);
	int getLastDefenses() const;
	std::vector<int> getDefenses() const;

	void addGamesScore(const int gamesScore, const int cycle);
	ClanGamesScore getLastGamesScore() const;
	std::vector<ClanGamesScore> getGamesScores() const;

	std::vector<AttackPair> getWarAttacks() const { return warAttacks; }

	int getCycleWarScore(int cycle);
	int getCycleGamesScore(int cycle);
	void setCycle(int cycle);
	void computeStats();
	void recomputeStats();
private:
	//all the stats have one entry per cycle, except warAttacks and gamesScores
	//AttackPair and ClanGamesScore both have a cycle field for each object
	std::vector<int> donations;
	std::vector<int> requests;
	std::vector<int> attacks;
	std::vector<int> defenses;
	std::vector<AttackPair> warAttacks;
	std::vector<int> activities;
	std::vector<float> ratios;
	std::vector<float> ratiosAdj;
	std::vector<int> contributions;
	std::vector<ClanGamesScore> gamesScores;

	int cc_size=-1;
	int currentCycle=0;
};

