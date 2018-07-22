#pragma once
#include "WarException.h"
using namespace std;
class AttackPair
{
public:
	AttackPair(int playerThLevel, string date) : playerThLevel{ playerThLevel }, date{ date } {};
	AttackPair(int playerLevel, int star1, int star2, int percent1, int percent2, int enemy1, int enemy2, int attacks, int perf, string date) :
		playerThLevel{ playerLevel }, starsFirst{ star1 }, starsSecond{ star2 }, percentFirst{ percent1 }, percentSecond{ percent2 },
		enemyFirst{ enemy1 }, enemySecond{ enemy2 }, attacksDone{ attacks }, performance{ perf }, date{ date } {};
	void addAttack(int stars, int enemyLevel, int percent=-1 );
	pair<int, int> getStars() const { pair<int, int> a(starsFirst, starsSecond); return a; }
	pair<int, int> getPercent() const { pair<int, int> a(percentFirst, percentSecond); return a; }
	pair<int, int> getEnemy() const { pair<int, int> a(enemyFirst, enemySecond); return a; }
	int getPerformance();
	string toString() const;

private:
	int playerThLevel;
	int starsFirst=-1, starsSecond=-1;
	int percentFirst=-1, percentSecond=-1;
	int enemyFirst=-1, enemySecond=-1;
	int attacksDone=0;
	int performance=-1;
	string date="none";
};

