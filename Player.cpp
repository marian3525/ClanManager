#include "stdafx.h"
#include "Player.h"

Player::Player()
{
}

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

void Player::addWarShow(const AttackPair & warShow)
{
	warAttacks.push_back(warShow);
}
