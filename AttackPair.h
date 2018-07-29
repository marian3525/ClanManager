#pragma once
#include "WarException.h"
using namespace std;
class AttackPair
{
public:
	AttackPair();
	//used when adding from the UI
	AttackPair(int playerThLevel, string date, int cycle) : playerThLevel{ playerThLevel }, date{ date }, cycle{ cycle } {};
	//used when creating while reading from file
	AttackPair(int playerLevel, int star1, int star2, int percent1, int percent2, int enemy1, int enemy2, int attacks, int perf, string date, int cycle) :
		playerThLevel{ playerLevel }, starsFirst{ star1 }, starsSecond{ star2 }, percentFirst{ percent1 }, percentSecond{ percent2 },
		enemyFirst{ enemy1 }, enemySecond{ enemy2 }, attacksDone{ attacks }, performance{ perf }, date{ date }, cycle{ cycle } {};
	void addAttack(int stars, int enemyLevel, int percent=-1 );
	pair<int, int> getStars() const { pair<int, int> a(starsFirst, starsSecond); return a; }
	pair<int, int> getPercent() const { pair<int, int> a(percentFirst, percentSecond); return a; }
	pair<int, int> getEnemy() const { pair<int, int> a(enemyFirst, enemySecond); return a; }
	int getCycle() const { return cycle; }
	int getPerformance();
	string toString() const;
	int attacksDone = 0;		//not -1 or the attacks won't be counter correctly

private:
	int playerThLevel=-1;
	int starsFirst=-1, starsSecond=-1;
	int percentFirst=-1, percentSecond=-1;
	int enemyFirst=-1, enemySecond=-1;
	int performance=-1;
	string date="none";
	int cycle = -1;
};

