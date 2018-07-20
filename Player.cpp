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

string Player::toString()
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

void Player::addWarAttack(int outcome, int enemyThLevel)
{
}
