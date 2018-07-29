#include "stdafx.h"
#include "PlayerHistory.h"


PlayerHistory::PlayerHistory()
{
}

void PlayerHistory::setCcSize(int cc)
{
	cc_size = cc;
}

string PlayerHistory::toString() const
{
	/*
		Create a string with all the history data for the player
	*/
	string str;
	str.append("[history]");
	str.append(",");

	str.append("[donations]");
	str.append(",");
	for (int donation : donations) {
		str.append(to_string(donation));
		str.append(",");
	}
	str.append("[/donations]");
	str.append(",");

	str.append("[requests]");
	str.append(",");
	for (int request : requests) {
		str.append(to_string(request));
		str.append(",");
	}
	str.append("[/requests]");
	str.append(",");

	str.append("[attacks]");
	str.append(",");
	for (int attack : attacks) {
		str.append(to_string(attack));
		str.append(",");
	}
	str.append("[/attacks]");
	str.append(",");

	str.append("[defenses]");
	str.append(",");
	for (int defense : defenses) {
		str.append(to_string(defense));
		str.append(",");
	}
	str.append("[/defenses]");
	str.append(",");

	str.append("[warAttacks]");
	str.append(",");
	for (AttackPair attack : warAttacks) {
		str.append(attack.toString());
		str.append(",");
	}
	str.append("[/warAttacks]");
	str.append(",");

	str.append("[activity]");
	str.append(",");
	for (int activity : activities) {
		str.append(to_string(activity));
		str.append(",");
	}
	str.append("[/activity]");
	str.append(",");

	str.append("[ratio]");
	str.append(",");
	for (float ratio : ratios) {
		str.append(to_string(ratio));
		str.append(",");
	}
	str.append("[/ratio]");
	str.append(",");

	str.append("[ratioAdj]");
	str.append(",");
	for (float ratioAdj : ratiosAdj) {
		str.append(to_string(ratioAdj));
		str.append(",");
	}
	str.append("[/ratioAdj]");
	str.append(",");
	
	str.append("[contributions]");
	str.append(",");
	for (int contribution : contributions) {
		str.append(to_string(contribution));
		str.append(",");
	}
	str.append("[/contributions]");
	str.append(",");

	str.append("[gamesScores]");
	str.append(",");
	for (const ClanGamesScore& score : gamesScores) {
		str.append(to_string(score.getScore()));
		str.append(",");
		str.append(to_string(score.getCycle()));
		str.append(",");
	}
	str.append("[/gamesScores]");
	str.append(",");

	str.append("[/history]");

	return str;
}

void PlayerHistory::readHistoryFromStatsLine(char * line)
{
	/*
		populate the vectors with data from the given line
	*/
	//get a string containing only the history data
	char* history = strstr(line, "[history]");
	char* ptr;
	//read each vector:
	ptr = strtok(history, ",");
	if (strcmp(ptr, "[history]")) {
		throw IOException{ "Unexpected token" };
	}

	ptr = strtok(NULL, ",");
	if (strcmp(ptr, "[donations]")) {
		throw IOException{ "Unexpected token" };
	}
	ptr = strtok(NULL, ",");
	while (strcmp(ptr, "[/donations]")) {
		int donations = stoi(ptr);
		this->donations.push_back(donations);
		ptr = strtok(NULL, ",");
	}

	ptr = strtok(NULL, ",");
	if (strcmp(ptr, "[requests]")) {
		throw IOException{ "Unexpected token" };
	}
	ptr = strtok(NULL, ",");
	while (strcmp(ptr, "[/requests]")) {
		int requests = stoi(ptr);
		this->requests.push_back(requests);
		ptr = strtok(NULL, ",");
	}

	ptr = strtok(NULL, ",");
	if (strcmp(ptr, "[attacks]")) {
		throw IOException{ "Unexpected token" };
	}
	ptr = strtok(NULL, ",");
	while (strcmp(ptr, "[/attacks]")) {
		int attacks = stoi(ptr);
		this->attacks.push_back(attacks);
		ptr = strtok(NULL, ",");
	}

	ptr = strtok(NULL, ",");
	if (strcmp(ptr, "[defenses]")) {
		throw IOException{ "Unexpected token" };
	}
	ptr = strtok(NULL, ",");
	while (strcmp(ptr, "[/defenses]")) {
		int defenses = stoi(ptr);
		this->defenses.push_back(defenses);
		ptr = strtok(NULL, ",");
	}

	ptr = strtok(NULL, ",");
	if (strcmp(ptr, "[warAttacks]")) {
		throw IOException{ "Unexpected token" };
	}
	ptr = strtok(NULL, ",");
	while (strcmp(ptr, "[/warAttacks]")) {
		int thLvl, stars1, stars2, percent1, percent2, enemy1, enemy2, attacksDone, perf, cycle;
		string date;

		thLvl = stoi(ptr);
		ptr = strtok(NULL, ",");
		stars1 = stoi(ptr);
		ptr = strtok(NULL, ",");
		stars2 = stoi(ptr);
		ptr = strtok(NULL, ",");
		percent1 = stoi(ptr);
		ptr = strtok(NULL, ",");
		percent2 = stoi(ptr);
		ptr = strtok(NULL, ",");
		enemy1 = stoi(ptr);
		ptr = strtok(NULL, ",");
		enemy2 = stoi(ptr);
		ptr = strtok(NULL, ",");
		attacksDone = stoi(ptr);
		ptr = strtok(NULL, ",");
		perf = stoi(ptr);
		ptr = strtok(NULL, ",");
		date = string(ptr);
		ptr = strtok(NULL, ",");
		cycle = stoi(ptr);

		AttackPair show{ thLvl, stars1, stars2, percent1, percent2, enemy1, enemy2, attacksDone, perf, date, cycle };
		warAttacks.push_back(show);

		ptr = strtok(NULL, ",");
	}

	ptr = strtok(NULL, ",");
	if (strcmp(ptr, "[activity]")) {
		throw IOException{ "Unexpected token" };
	}
	ptr = strtok(NULL, ",");
	while (strcmp(ptr, "[/activity]")) {
		int activity = stoi(ptr);
		this->activities.push_back(activity);
		ptr = strtok(NULL, ",");
	}

	ptr = strtok(NULL, ",");
	if (strcmp(ptr, "[ratio]")) {
		throw IOException{ "Unexpected token" };
	}
	ptr = strtok(NULL, ",");
	while (strcmp(ptr, "[/ratio]")) {
		int ratio = stoi(ptr);
		this->ratios.push_back(ratio);
		ptr = strtok(NULL, ",");
	}

	ptr = strtok(NULL, ",");
	if (strcmp(ptr, "[ratioAdj]")) {
		throw IOException{ "Unexpected token" };
	}
	ptr = strtok(NULL, ",");
	while (strcmp(ptr, "[/ratioAdj]")) {
		int ratiosAdj = stoi(ptr);
		this->ratiosAdj.push_back(ratiosAdj);
		ptr = strtok(NULL, ",");
	}

	ptr = strtok(NULL, ",");
	if (strcmp(ptr, "[contributions]")) {
		throw IOException{ "Unexpected token" };
	}
	ptr = strtok(NULL, ",");
	while (strcmp(ptr,"[/contributions]")) {
		int contribution = stoi(ptr);
		this->contributions.push_back(contribution);
		ptr = strtok(NULL, ",");
	}

	ptr = strtok(NULL, ",");
	if (strcmp(ptr, "[gamesScores]")) {
		throw IOException{ "Unexpected token" };
	}
	ptr = strtok(NULL, ",");
	while (strcmp(ptr ,"[/gamesScores]")) {
		int scores = stoi(ptr);
		ptr = strtok(NULL, ",");
		int cycle = stoi(ptr);
		ClanGamesScore gamesScore{ scores, cycle };
		this->gamesScores.push_back(gamesScore);
		ptr = strtok(NULL, ",");
	}

	ptr = strtok(NULL, ",");
	if (strcmp(ptr, "[/history]")) {
		throw IOException{ "Unexpected token" };
	}
	recomputeStats();
}

void PlayerHistory::addRatio(const float ratio)
{
	ratios.push_back(ratio);
}

float PlayerHistory::getLastRatio() const
{
	if (ratios.size()==0) {
		return 0;
	}
	else {
		return ratios.back();
	}
}

std::vector<float> PlayerHistory::getRatios() const
{
	return ratios;
}

void PlayerHistory::addAdjustedRatio(const float adjRatio)
{
	ratiosAdj.push_back(adjRatio);
}

float PlayerHistory::getLastAdjustedRatio() const
{
	if (ratiosAdj.size() == 0) {
		return 0;
	}
	else {
		return ratiosAdj.back();
	}
}

std::vector<float> PlayerHistory::getAdjustedRatio()
{
	return ratiosAdj;
}

void PlayerHistory::addActivity(const int activity)
{
	activities.push_back(activity);
}

int PlayerHistory::getLastActivity() const
{
	if (activities.size() == 0) {
		return 0;
	}
	else {
		return activities.back();
	}
}

std::vector<int> PlayerHistory::getActivity() const
{
	return activities;
}

void PlayerHistory::addContribution(const int contribution)
{
	contributions.push_back(contribution);
}

float PlayerHistory::getLastContribution() const
{
	if (contributions.size() == 0) {
		return 0;
	}
	else {
		return contributions.back();
	}
}

std::vector<int> PlayerHistory::getContribution() const
{
	return contributions;
}

void PlayerHistory::addDonations(const int donations)
{
	this->donations.push_back(donations);
}

int PlayerHistory::getLastDonations() const
{
	if (donations.size() == 0) {
		return 0;
	}
	else {
		return donations.back();
	}
}

std::vector<int> PlayerHistory::getDonations() const
{
	return donations;
}

void PlayerHistory::addRequests(const int requests)
{
	this->requests.push_back(requests);
}

int PlayerHistory::getLastRequests() const
{
	if (requests.size() == 0) {
		return 0;
	}
	else {
		return requests.back();
	}
}

std::vector<int> PlayerHistory::getRequests() const
{
	return requests;
}

void PlayerHistory::addWarShow(const AttackPair show)
{
	warAttacks.push_back(show);
}

AttackPair PlayerHistory::getLastShow() const
{
	if (warAttacks.size()==0) {
		return AttackPair();
	}
	else {
		return warAttacks.back();
	}
}

std::vector<AttackPair> PlayerHistory::getShows()
{
	return warAttacks;
}

void PlayerHistory::addAttacks(const int attacks)
{
	this->attacks.push_back(attacks);
}

int PlayerHistory::getLastAttacks() const
{
	if (attacks.size() == 0) {
		return 0;
	}
	else {
		return attacks.back();
	}
}

std::vector<int> PlayerHistory::getAttacks() const
{
	return attacks;
}

void PlayerHistory::addDefenses(const int defenses)
{
	this->defenses.push_back(defenses);
}

int PlayerHistory::getLastDefenses() const
{
	if (defenses.size() == 0) {
		return 0;
	}
	else {
		return defenses.back();
	}
}

std::vector<int> PlayerHistory::getDefenses() const
{
	return defenses;
}

void PlayerHistory::addGamesScore(const int gamesScore, const int cycle)
{
	ClanGamesScore score{ gamesScore, cycle };
	gamesScores.push_back(score);
}

ClanGamesScore PlayerHistory::getLastGamesScore() const
{
	if (gamesScores.size() == 0) {
		return ClanGamesScore();
	}
	else {
		return gamesScores.back();
	}
}

std::vector<ClanGamesScore> PlayerHistory::getGamesScores() const
{
	return gamesScores;
}

int PlayerHistory::getCycleWarScore(int cycle)
{
	/*
		return the sum of the war scores from the wars of the given cycle
	*/
	int sum = 0;
	for(AttackPair& p:warAttacks){
		if (p.getCycle() == cycle) 
			sum += p.getPerformance(); 
	}
	return sum;
}

int PlayerHistory::getCycleGamesScore(int cycle)
{
	/*
		return the sun of the clan games scores from the games in the given cycle
	*/
	int sum = 0;
	for_each(gamesScores.begin(), gamesScores.end(), [&sum, &cycle](const ClanGamesScore& score) {if (score.getCycle() == cycle) sum += score.getScore();});
	return sum;
}

void PlayerHistory::setCycle(int cycle)
{
	this->currentCycle = cycle;
}

void PlayerHistory::recomputeStats()
{
	/*
		called after adding new stats from the new data file every cycle
	*/
	//activity masurement
	float activity = 0;
	activity = getLastRequests() + getLastDonations() + cc_size * getLastAttacks();
	if (activities.size() != 0) {
		activities.pop_back();
	}
	activities.push_back(activity);

	//contributions
	int adj = 5;
	int contribution = adj * getCycleWarScore(currentCycle);
	contribution += getLastDonations() + getCycleGamesScore(currentCycle) + adj * getCycleWarScore(currentCycle);
	contribution *= 3;

	if (contributions.size() != 0) {
		contributions.pop_back();
	}
	contributions.push_back(contribution);

	//ratio adjusted for activity and CG&wars
	float ratio=0;
	if (contribution != 0) {
		if (activity != 0)
			ratio = (float)contribution / activity;
		else
			ratio = 1;
	}
	else {
		ratio = contribution;
	}
	//replace the last recorded ratio
	if (ratios.size() != 0) {
		ratios.pop_back();
	}
	ratios.push_back(ratio);
}

void PlayerHistory::computeStats()
{
	/*
		Update the vectors, don't add new values
	*/
	//activity masurement
	float activity = 0;
	activity = getLastRequests() + getLastDonations() + cc_size * getLastAttacks();
	activities.push_back(activity);

	//contributions
	int adj = 5;
	int contribution = adj * getCycleWarScore(currentCycle);
	contribution += getLastDonations() + getCycleGamesScore(currentCycle) + adj * getCycleWarScore(currentCycle);
	contribution *= 3;
	contributions.push_back(contribution);

	//ratio adjusted for activity and CG&wars
	float ratio = 0;
	if (contribution != 0) {
		if (activity != 0)
			ratio = (float)contribution / activity;
		else
			ratio = 1;
	}
	else {
		ratio = contribution;
	}
	ratios.push_back(ratio);
}
