#pragma once
#include "AttackPair.h"
#include "IOException.h"
class PlayerHistory
{
public:
	PlayerHistory();
	void setCcSize(int cc);

	std::string toString() const;

	void readHistoryFromStatsLine(char* line);

	void addRatio(const float ratio);
	float getLastRatio() const;
	std::vector<float> getRatioList();

	void addAdjustedRatio(const float adjRatio);
	float getLastAdjustedRatio() const;
	std::vector<float> getAdjustedRatio();

	void addActivity(const int activity);
	int getLastActivity() const;
	std::vector<int> getActivity();

	void addContribution(const int contribution);
	float getLastContribution() const;
	std::vector<int> getContribution();

	void addDonations(const int donations);
	int getLastDonations() const;
	std::vector<int> getDonations();

	void addRequests(const int requests);
	int getLastRequests() const;
	std::vector<int> getRequests();

	void addWarShow(const AttackPair show);
	AttackPair getLastShow() const;
	std::vector<AttackPair> getShows();

	void addAttacks(const int attacks);
	int getLastAttacks() const;
	std::vector<int> getAttacks();

	void addDefenses(const int defenses);
	int getLastDefenses() const;
	std::vector<int> getDefenses();

	void addGamesScore(const int gamesScore);
	int getLastGamesScore() const;
	std::vector<int> getGamesScore() const;

	std::vector<AttackPair> getAttacks() const { return warAttacks; }
	void computeStats();
private:
	std::vector<int> donations;
	std::vector<int> requests;
	std::vector<int> attacks;
	std::vector<int> defenses;
	std::vector<AttackPair> warAttacks;
	std::vector<int> activities;
	std::vector<float> ratios;
	std::vector<float> ratiosAdj;
	std::vector<int> contributions;
	std::vector<int> gamesScores;
	int cc_size;
};

