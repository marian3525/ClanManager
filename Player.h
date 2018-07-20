#pragma once
#include "AttackPair.h"
using namespace std;

class Player
{
public:
	Player();
	Player(string tag, string name, int townhall, string role, int rank, int experience, string league, int trophies, int versusTrophies,
		int warStars, int legendTrophies, int attackWins, int defenseWins, int troopsDonated, int troopsRequested) : tag{ tag }, name{ name },
		townHall{ townhall }, role{ role }, rank{ rank }, experience{ experience }, league{ league }, trophies{ trophies },
		versusTrophies{ versusTrophies }, warStars{ warStars }, legendTrophies{ legendTrophies }, attackWins{ attackWins }, defenseWins{ defenseWins },
		troopsDonated{ troopsDonated }, troopsRequested{ troopsRequested } {
		switch (getTownHall()) {
		case 1:
			cc_size = 0;
		case 2:
			cc_size = 0;
		case 3:
			cc_size = 10;
		case 4:
			cc_size = 15;
		case 5:
			cc_size = 15;
		case 6:
			cc_size = 20;
		case 7:
			cc_size = 20;
		case 8:
			cc_size = 25;
		case 9:
			cc_size = 30;
		case 10:
			cc_size = 35;
		case 11:
			cc_size = 35;
		case 12:
			cc_size = 40;
		}
	};

	string getTag() const { return tag; }
	string getName() const { return name; }
	int getTownHall() const { return townHall; }
	string getRole() const { return role; }
	int getRank() const { return rank; }
	int getExperience() const { return experience; }
	string getLeague() const { return league; }
	int getTrophies() const { return trophies; }
	int getVersusTrophies() const { return versusTrophies; }
	int getWarStars() const { return warStars; }
	int getLegendTrophies()const { return legendTrophies; }
	int getAttackWins() const { return attackWins; }
	int getDefenseWins() const { return defenseWins; }
	int getTroopsDonated() const { return troopsDonated; }
	int getTroopsRequested() const { return troopsRequested; }

	void setActivityMetric(float newMetric);
	float getActivityMetric() const { return activity_metric; }

	void setRatioAdjusted(float ratio);
	float getRatioAdjusted() const { return ratio_adjusted; }

	void setRatio(float ratio);
	float getRatio() const { return ratio; }

	void setContribution(float contribution);
	float getContribution() const { return contribution; }

	int getGamesScore() const { return gamesScore; }
	void setGamesScore(int score);

	int getCcSize() const { return cc_size; }

	string toString();
	string toStringTable();

	void addWarAttack(int outcome, int enemyThLevel);

private:
	string tag="";
	string name="";
	int townHall=0;
	string role="";
	int rank=0;
	int experience=0;
	string league=0;
	int trophies=0;
	int versusTrophies=0;
	int warStars=0;
	int legendTrophies=0;
	int attackWins=0;
	int defenseWins=0;
	int troopsDonated=0;
	int troopsRequested=0;

	int cc_size=0;

	int gamesScore=0;
	
	vector<AttackPair> warAttacks;

	float activity_metric=0;
	float ratio_adjusted=0;
	float ratio=0;
	float contribution=0;
};

