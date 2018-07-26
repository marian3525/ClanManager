#include "stdafx.h"
#include "Player.h"

Player::Player()
{

}

float Player::getAvgWarStars() const
{
	float avg=0;
	int counter = 0;
	for (const AttackPair& attack: history.getAttacks()) {
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

float Player::getAvgWarScore() const
{
	float avg = 0;
	int counter = 0;
	for (AttackPair& attack : history.getAttacks()) {
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
	for (const int score : history.getGamesScore()) {
		avg += score;
		counter++;
	}
	if (counter != 0) {
		return avg / counter;
	}
	else {
		return avg;
	}
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
void Player::addWarAttacksFromFile(char* line)
{
	/*
		line-pointer to a line terminated by \n where war attacks are stored in the format provided by AttackPair::toString()
		will not free the char pointer
		Add the war attacks found in the line to the player
		format for each AttackPair: playerLevel,starsFirst,starsSecond,percentFirst,percentSecond,enemyFirst,enemySecond,attackDone,performance,date
	*/
	char* ptr;
	const char* separators=",\n";
	const int len = strlen(line);
	//or just ,?

	ptr = strtok(line, separators);

	while (ptr != NULL) {
		const int playerThLevel = atoi(ptr);

		ptr = strtok(NULL, separators);
		const int starsFirst = atoi(ptr);
		
		ptr = strtok(NULL, separators);
		const int starsSecond = atoi(ptr);

		ptr = strtok(NULL, separators);
		const int percentFirst = atoi(ptr);

		ptr = strtok(NULL, separators);
		const int percentSecond = atoi(ptr);

		ptr = strtok(NULL, separators);
		const int enemyFirst = atoi(ptr);

		ptr = strtok(NULL, separators);
		const int enemySecond = atoi(ptr);

		ptr = strtok(NULL, separators);
		const int attacksDone = atoi(ptr);

		ptr = strtok(NULL, separators);
		const int performance = atoi(ptr);

		ptr = strtok(NULL, separators);
		const string date = string(ptr);

		ptr = strtok(NULL, separators);

		AttackPair warShow{ playerThLevel, starsFirst, starsSecond, percentFirst, percentSecond, enemyFirst, enemySecond, 
			attacksDone, performance, date };

		//this->warAttacks.push_back(warShow);
	}
}

void Player::addWarShow(const AttackPair & warShow)
{
	history.addWarShow(warShow);
}

void Player::addClanGamesScore(const int score)
{
	history.addGamesScore(score);
}

void Player::setNotes(string text)
{
	this->comments = text;
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
