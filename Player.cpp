#include "stdafx.h"
#include "Player.h"

void Player::setActivityMetric(float newMetric)
{
	this->activity_metric = newMetric;
}

void Player::setRatioAdjusted(float ratio)
{
	this->ratio_adjusted = ratio;
}

void Player::setRatio(float ratio)
{
	this->ratio = ratio;
}

void Player::setContribution(float contribution)
{
	this->contribution = contribution;
}

void Player::setGamesScore(int score)
{
	this->gamesScore = score;
}

string Player::toString() const
{
	/*
		Format: tag,name,th,role,rank,level,league,cups,vscups,warStars,legend,attacks,defenses,donations,requests,ratio,ratio_adj,activity,contribution,
		playerLevel,stars1,stars2,percent1,percent2,enemy1,enemy2,attacks,performance,date...
	*/
	string str="";

	str += tag;
	str += ",";
	str += name;
	str += ",";
	str += to_string(townHall);
	str += ",";
	str += role;
	str += ",";
	str += to_string(rank);
	str += ",";
	str += to_string(experience);
	str += ",";
	str += league;
	str += ",";
	str += to_string(trophies);
	str += ",";
	str += to_string(versusTrophies);
	str += ",";
	str += to_string(warStars);
	str += ",";
	str += to_string(legendTrophies);
	str += ","; 
	str += to_string(attackWins);
	str += ",";
	str += to_string(defenseWins);
	str += ",";
	str += to_string(troopsDonated);
	str += ",";
	str += to_string(troopsRequested);
	str += ",";
	str += to_string(ratio);
	str += ",";
	str += to_string(ratio_adjusted);
	str += ",";
	str += to_string(activity_metric);
	str += ",";
	str+=to_string(contribution);

	//add the war stats
	for (const AttackPair& attack : warAttacks) {
		str += ",";
		str += attack.toString();
	}
	return str;
}

string Player::toStringDebug()
{
	string str="";
	str += "Tag: " + tag + ", Name: " + name + ", TH Level: " + to_string(townHall) + ", Role: " + role + ", Rank: " + to_string(rank) +
		", Level: " + to_string(experience) + ", League: " + league + ", Trophies: " + to_string(trophies) + ", Versus Trophies: " + to_string(versusTrophies) +
		", War Stars: " + to_string(warStars) + ", Legend Trophies: " + to_string(legendTrophies) + ", Attacks Won: " +
		to_string(attackWins) + ", Defenses Won: " + to_string(defenseWins) + ", Troops Donated: " + to_string(troopsDonated) +
		", Troops Requested: " + to_string(troopsRequested) + ", Ratio: " + to_string(ratio) + ", Adjusted Ratio: " + to_string(ratio_adjusted) + 
		", Activity Metric: " + to_string(activity_metric) + ", Contribution: " + to_string(contribution);
	return str;
}

string Player::toStringTable()
{
	string str;
	str += tag + "," + name + "," + to_string(townHall) + "," + role + "," + to_string(rank) +
		"," + to_string(experience) + "," + league + "," + to_string(trophies) + "," + to_string(versusTrophies) +
		"," + to_string(warStars) + "," + to_string(legendTrophies) + "," +
		to_string(attackWins) + "," + to_string(defenseWins) + "," + to_string(troopsDonated) +
		"," + to_string(troopsRequested) + "," + to_string(ratio) + "," + to_string(ratio_adjusted) +
		"," + to_string(activity_metric) + "," + to_string(contribution);
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

		this->warAttacks.push_back(warShow);
	}
}

void Player::addWarShow(const AttackPair & warShow)
{
	warAttacks.push_back(warShow);
}
