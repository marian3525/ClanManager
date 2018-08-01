#include "stdafx.h"
#include "Player.h"

Player::Player()
{

}

std::string Player::getTag() const
{
	return tag;
}

std::string Player::getName() const
{
	return name;
}

int Player::getTownHall() const
{
	return townHall;
}

std::string Player::getRole() const
{
	return role;
}

int Player::getRank() const
{
	return rank;
}

int Player::getExperience() const
{
	return experience;
}

std::string Player::getLeague() const
{
	return league;
}

int Player::getTrophies() const
{
	return trophies;
}

int Player::getVersusTrophies() const
{
	return versusTrophies;
}

int Player::getWarStars() const
{
	return warStars;
}

int Player::getLegendTrophies() const
{
	return legendTrophies;
}

int Player::getLastAttackWins() const
{
	return history.getLastAttacks();
}

int Player::getCycleAttackWins(const int cycle) const
{
	/*
		cycle->1...n
	*/
	vector<int> wins = history.getAttacks();
	if (cycle <= wins.size()) {
		return wins[cycle - 1];
	}
	else {
		return -1;
	}
}

int Player::getLastDefenseWins() const
{
	return history.getLastDefenses();
}

int Player::getCycleDefenseWins(const int cycle) const
{
	vector<int> def = history.getDefenses();
	if (cycle <= def.size()) {
		return def[cycle];
	}
	else {
		return -1;
	}
}

int Player::getLastTroopsDonated() const
{
	return history.getLastDonations();
}

int Player::getCycleTroopsDonated(const int cycle) const
{
	vector<int> don = history.getDonations();
	if (cycle <= don.size()) {
		return don[cycle - 1];
	}
	else {
		return -1;
	}
}

int Player::getLastTroopsRequested() const
{
	return history.getLastRequests();
}

int Player::getCycleTroopsRequested(const int cycle) const
{
	vector<int> req = history.getRequests();
	if (cycle <= req.size()) {
		return req[cycle];
	}
	else {
		return -1;
	}
}

float Player::getAvgWarStars() const
{
	float avg=0;
	int counter = 0;
	for (const AttackPair& attack: history.getWarAttacks()) {
		int first = attack.getStars().first;
		int second = attack.getStars().second;
		first != -1 ? avg += first : first=first;
		second != -1 ? avg += second : second = second;
		counter += attack.attacksDone;
	}
	if (counter != 0) {
		return avg / counter;
	}
	else {
		return avg;
	}
}

float Player::getCycleAvgWarStars(const int cycle) const
{
	float avg = 0;
	int counter = 0;
	for (const AttackPair& attack : history.getWarAttacks()) {
		if (attack.getCycle() != cycle)
			continue;
		int first = attack.getStars().first;
		int second = attack.getStars().second;
		first != -1 ? avg += first : first = first;
		second != -1 ? avg += second : second = second;
		counter += attack.attacksDone;
	}
	if (counter != 0) {
		return avg / counter;
	}
	else {
		return avg;
	}
}

float Player::getAvgWarScore() const
{
	float avg = 0;
	int counter = 0;
	for (AttackPair& attack : history.getWarAttacks()) {
		int perf = attack.getPerformance();
		perf != -1 ? avg += perf : perf = perf;
		counter++;
	}
	if (counter != 0) {
		return avg / counter;
	}
	else {
		return avg;
	}
}

float Player::getCycleAvgWarScore(const int cycle) const
{
	float avg = 0;
	int counter = 0;
	for (AttackPair& attack : history.getWarAttacks()) {
		int perf = attack.getPerformance();
		perf != -1 ? avg += perf : perf = perf;
		counter++;
	}
	if (counter != 0) {
		return avg / counter;
	}
	else {
		return avg;
	}
}

float Player::getAvgCgScore() const
{
	float avg = 0;
	int counter = 0;
	for (const ClanGamesScore score : history.getGamesScores()) {
		avg += score.getScore();
		counter++;
	}
	if (counter != 0) {
		return avg / counter;
	}
	else {
		return avg;
	}
}

float Player::getCycleAvgCgScore(const int cycle) const
{
	float avg = 0;
	int counter = 0;
	for (const ClanGamesScore score : history.getGamesScores()) {
		if (score.getCycle() != cycle)
			continue;
		avg += score.getScore();
		counter++;
	}
	if (counter != 0) {
		return avg / counter;
	}
	else {
		return avg;
	}
}

float Player::getLastRatio() const
{
	return history.getLastRatio();
}

float Player::getCycleRatio(const int cycle) const
{
	vector<float> ratio = history.getRatios();
	if (cycle <= ratio.size()) {
		return ratio[cycle - 1];
	}
	else {
		return -1;
	}
}

int Player::getLastActivityMetric() const
{
	return history.getLastActivity();
}

int Player::getCycleActivity(const int cycle) const
{
	vector<int> act = history.getActivity();
	if (cycle <= act.size()) {
		return act[cycle - 1];
	}
	else {
		return -1;
	}
}

int Player::getLastContribution() const
{
	return history.getLastContribution();
}

int Player::getCycleContribution(const int cycle) const
{
	vector<int> cont = history.getContribution();
	if (cycle <= cont.size()) {
		return cont[cycle - 1];
	}
	else {
		return -1;
	}
}

ClanGamesScore Player::getLastGamesScore() const
{
	return history.getLastGamesScore();
}

int Player::getCycleGamesScore(const int cycle) const
{
	int total = 0;
	vector<ClanGamesScore> scores = history.getGamesScores();
	for (const ClanGamesScore& score : scores) {
		if (score.getCycle() != cycle)
			continue;
		total += score.getScore();
	}
	return total;
}

int Player::getCcSize()
{
	switch (getTownHall()) {
	case 1:
		cc_size = 0; break;
	case 2:
		cc_size = 0; break;
	case 3:
		cc_size = 10; break;
	case 4:
		cc_size = 15; break;
	case 5:
		cc_size = 15; break;
	case 6:
		cc_size = 20; break;
	case 7:
		cc_size = 20; break;
	case 8:
		cc_size = 25; break;
	case 9:
		cc_size = 30; break;
	case 10:
		cc_size = 35; break;
	case 11:
		cc_size = 35; break;
	case 12:
		cc_size = 40; break;
	}
	history.setCcSize(cc_size);
	return cc_size;
}

vector<int> Player::getDonationHistory() const
{
	return history.getDonations();
}

vector<int> Player::getRequestHistory() const
{
	return history.getRequests();
}

vector<float> Player::getRatioHistory() const
{
	return history.getRatios();
}

vector<int> Player::getContributionHistory() const
{
	return history.getContribution();
}

vector<ClanGamesScore> Player::getCgScoreHistory() const
{
	return history.getGamesScores();
}

vector<int> Player::getActivityHistory() const
{
	return history.getActivity();
}

string Player::toString() const
{
	/*
		Format: tag,name,th,role,rank,level,league,cups,vscups,warStars,legend,attacks,defenses,donations,requests,ratio,ratio_adj,activity,contribution,
		playerLevel,stars1,stars2,percent1,percent2,enemy1,enemy2,attacks,performance,date...
	*/
	string str;

	str.append("[general]");
	str.append(",");

	str += tag;
	str.append(",");
	str += name;
	str.append(",");
	str += to_string(townHall);
	str.append(",");
	str += role;
	str.append(",");
	str.append(specialRole);
	str.append(",");
	str.append(to_string(comments.size()));
	str.append("&");
	str.append(comments);
	str.append("&");
	str += to_string(rank);
	str.append(",");
	str += to_string(experience);
	str.append(",");
	str += league;
	str.append(",");
	str += to_string(trophies);
	str.append(",");
	str += to_string(versusTrophies);
	str.append(",");
	str += to_string(warStars);
	str.append(",");
	str += to_string(legendTrophies);
	str.append(",");
	str += to_string(history.getLastAttacks());
	str.append(",");
	str += to_string(history.getLastDefenses());
	str.append(",");
	str += to_string(history.getLastDonations());
	str.append(",");
	str += to_string(history.getLastRequests());
	str.append(",");
	str += to_string(history.getLastRatio());
	str.append(",");
	str += to_string(history.getLastAdjustedRatio());
	str.append(",");
	str += to_string(history.getLastActivity());
	str.append(",");
	str += to_string(history.getLastContribution());
	str.append(",");
	str.append("[/general],");

	//add the stats
	string historyString = history.toString();
	str.append(historyString);

	return str;
}

void Player::addWarShow(const AttackPair & warShow)
{
	history.addWarShow(warShow);
	recomputeStats();
}

void Player::addClanGamesScore(const int score, const int cycle)
{
	history.addGamesScore(score, cycle);
	recomputeStats();
}

void Player::setNotes(string text)
{
	this->comments = text;
}

void Player::setSpecialRole(const string newRole)
{
	this->specialRole = newRole;
}

std::vector<AttackPair> Player::getWarAttacks() const
{
	return history.getWarAttacks();
}

void Player::loadFromFile(char * line)
{
	/*
		Read a player from a .stats file, including war attacks
	*/
	char* ptr;
	char* lineCopy = strdup(line);
	int line_len = strlen(line);
	int len = 0;
	/*
		to extract another variable from the file use:
		ptr = strtok(NULL, ",");
		//convert ptr to whatever it is needed

		MAKE SURE THAT THE FORMAT WRITTEN INTO THE FILE IS THE SAME AS THE FORMAT USED TO READ THE FILE: toString and loadFromFile must
		store/load in the same order
	*/

	//read each field and convert to the proper type

	ptr = strtok(line, ",");	
	if (strcmp(ptr, "[general]") != 0)
		throw IOException{ "IOException: Invalid line \"" + string(line) + "\". Expected: \"[general]\"" };

	ptr = strtok(NULL, ",");
	const string tag = string(ptr);
	len += strlen(ptr) + 1;

	ptr = strtok(NULL, ",");
	const string name = string(ptr);
	len += strlen(ptr) + 1;

	ptr = strtok(NULL, ",");
	const int townHall = atoi(ptr);
	len += strlen(ptr) + 1;

	ptr = strtok(NULL, ",");
	const string role = string(ptr);
	len += strlen(ptr) + 1;

	ptr = strtok(NULL, ",");
	const string specialRole = string(ptr);
	len += strlen(ptr) + 1;

	ptr = strtok(NULL, "&");
	int commentsLen;
	commentsLen = stoi(ptr);
	char* comments_ptr = new char[commentsLen+1];
	ptr = strtok(NULL, "&");
	strncpy(comments_ptr, ptr, commentsLen);
	comments_ptr[commentsLen] = 0;
	const string comments = string(comments_ptr);
	delete[] comments_ptr;
	ptr += commentsLen;
	
	ptr = strtok(NULL, ",");
	const int rank = atoi(ptr);
	len += strlen(ptr) + 1;

	ptr = strtok(NULL, ",");
	const int experience = atoi(ptr);
	len += strlen(ptr) + 1;

	ptr = strtok(NULL, ",");
	const string league = string(ptr);
	len += strlen(ptr) + 1;

	ptr = strtok(NULL, ",");
	const int trophies = atoi(ptr);
	len += strlen(ptr) + 1;

	ptr = strtok(NULL, ",");
	const int versusTrophies = atoi(ptr);
	len += strlen(ptr) + 1;

	ptr = strtok(NULL, ",");
	const int warStars = atoi(ptr);
	len += strlen(ptr) + 1;

	ptr = strtok(NULL, ",");
	const int legendThophies = atoi(ptr);
	len += strlen(ptr) + 1;

	this->tag = tag;
	this->name = name;
	this->townHall = townHall;
	this->role = role;
	this->specialRole = specialRole;
	this->rank = rank;
	this->experience = experience;
	this->league = league;
	this->trophies = trophies;
	this->versusTrophies = versusTrophies;
	this->warStars = warStars;
	this->legendTrophies = legendThophies;
	this->comments = comments;

	history.setCcSize(getCcSize());		//set the cc size for the player and its history

	history.readHistoryFromStatsLine(lineCopy);
	free(lineCopy);
}

void Player::loadFromFreshFile(char* line)
{
	/*
		Read a player from a .csv file, downloaded from clashofstats.com
	*/
	char* char_ptr;
	string tag, name, role, league;
	int townHall, rank, experience, trophies, versusTrophies, warStars, legendThophies, attackWins, defenseWins,
		troopsDonated, troopReceived;

	char_ptr = strtok(line, ",");
	if (char_ptr == NULL)
		return;
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

	this->tag = tag;
	this->name = name;
	this->townHall = townHall;
	this->role = role;
	this->rank = rank;
	this->experience = experience;
	this->league = league;
	this->trophies = trophies;
	this->versusTrophies = versusTrophies;
	this->warStars = warStars;
	this->legendTrophies = legendThophies;

	history.addAttacks(attackWins);
	history.addDefenses(defenseWins);
	history.addDonations(troopsDonated);
	history.addRequests(troopReceived);

	getCcSize();
}

void Player::update(const int newAttacks, const int newDefenses, const int newDonations, const int newRequests)
{
	history.addAttacks(newAttacks);
	history.addDefenses(newDefenses);
	history.addDonations(newDonations);
	history.addRequests(newRequests);
	history.computeStats();
}

void Player::computeStats()
{
	history.computeStats();
}

void Player::recomputeStats()
{
	history.recomputeStats();
}

void Player::setCycle(int cycle)
{
	this->cycle = cycle;
	history.setCycle(cycle);
}
