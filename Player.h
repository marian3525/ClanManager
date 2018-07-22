#pragma once
#include "AttackPair.h"
#include <iomanip>
#include <sstream>

class Player
{
public:
	Player(string tag, string name, int townhall, string role, int rank, int experience, string league, int trophies, int versusTrophies,
		int warStars, int legendTrophies, int attackWins, int defenseWins, int troopsDonated, int troopsRequested) : tag{ tag },
		name{ name }, townHall{ townhall }, role{ role }, rank{ rank }, experience{ experience }, league{ league }, trophies{ trophies },
		versusTrophies{ versusTrophies }, warStars{ warStars }, legendTrophies{ legendTrophies }, attackWins{ attackWins },
		defenseWins{ defenseWins }, troopsDonated{ troopsDonated }, troopsRequested{ troopsRequested } {
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

	Player(string tag, string name, int townhall, string role, int rank, int experience, string league, int trophies, int versusTrophies,
		int warStars, int legendTrophies, int attackWins, int defenseWins, int troopsDonated, int troopsRequested, float ratio, float ratioAdj,
		float activity, float contribution) : 
		tag{ tag },name{ name }, townHall{ townhall }, role{ role }, rank{ rank }, 
		experience{ experience }, league{ league }, trophies{ trophies },versusTrophies{ versusTrophies }, warStars{ warStars }, 
		legendTrophies{ legendTrophies }, attackWins{ attackWins },defenseWins{ defenseWins }, troopsDonated{ troopsDonated }, 
		troopsRequested{ troopsRequested }, ratio{ ratio }, ratio_adjusted{ ratioAdj },activity_metric{ activity }, 
		contribution{ contribution } {
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

	void setRatio(float ratio);
	float getRatio() const { return ratio; }
	string getRatioStr() const { stringstream ss; ss << std::fixed << std::setprecision(2) << ratio; return ss.str(); };

	void setRatioAdjusted(float ratio);
	float getRatioAdjusted() const { return ratio_adjusted; }
	string getRatioAdjustedStr() const { stringstream ss; ss << std::fixed << std::setprecision(2) << ratio_adjusted; return ss.str(); }

	void setActivityMetric(float newMetric);
	float getActivityMetric() const { return activity_metric; }
	string getActivityMetricStr() const { stringstream ss; ss << std::fixed << std::setprecision(2) << activity_metric; return ss.str(); };

	void setContribution(float contribution);
	float getContribution() const { return contribution; }
	string getContributionStr() const { stringstream ss; ss << std::fixed << std::setprecision(2) << contribution; return ss.str(); };

	int getGamesScore() const { return gamesScore; }
	void setGamesScore(int score);

	int getCcSize() const { return cc_size; }
	
	string toString() const;
	string toStringDebug();
	string toStringTable();

	void addWarAttacksFromFile(char* line);

	void addWarShow(const AttackPair& warShow);
	const vector<AttackPair> getWarAttacks() const { return warAttacks; }

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