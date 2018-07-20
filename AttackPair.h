#pragma once
#include "WarException.h"
using namespace std;
class AttackPair
{
public:
	AttackPair(int attackerLevel);
	void addAttack(int stars, int enemyLevel, int percent=-1 );
	pair<int, int> getStars() const { pair<int, int> a(starsFirst, starsSecond); return a; }
	pair<int, int> getPercent() const { pair<int, int> a(percentFirst, percentSecond); return a; }
	pair<int, int> getEnemy() const { pair<int, int> a(enemyFirst, enemySecond); return a; }
	int getPerformance();

	~AttackPair();
private:
	int attackerLevel;
	int starsFirst=-1, starsSecond=-1;
	int percentFirst=-1, percentSecond=-1;
	int enemyFirst=-1, enemySecond=-1;
	int attacksDone=-1;
	int performance=-1;
};

