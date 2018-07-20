#include "stdafx.h"
#include "AttackPair.h"

AttackPair::AttackPair(int attackerLevel)
{
	this->attackerLevel = attackerLevel;
}

void AttackPair::addAttack(int stars, int enemyLevel, int percent)
{
	switch (attacksDone) {
	case 0:
		starsFirst = stars;
		enemyFirst = enemyLevel;
		attacksDone++;

		break;
	case 1:
		starsSecond = stars;
		enemyFirst = enemyLevel;
		attacksDone++;
		break;
	case 2:
		//both attacks done
		throw new WarException{ "Both attacks already done" };
		break;
	}

}

int AttackPair::getPerformance()
{
	if(performance != -1)		//already computed
		return performance;

		int score;
		int th = attackerLevel;
		int stars;
		int enemy;
		int idx = 0;
		while (idx < 2) {

			if (idx % 2 == 0) {
				stars = starsFirst;
				enemy = enemyFirst;
			}
			else {
				stars = starsSecond;
				enemy = enemySecond;
			}

			idx++;

			if (th == 12) {
				switch (enemyFirst) {
				case 12:
					switch (stars) {
					case 0:score -= 50; break;
					case 1:score -= 30; break;
					case 2:score += 50; break;
					case 3:score += 100; break;
					}
				case 11:
					switch (stars) {
					case 0:score -= 100; break;
					case 1:score -= 50; break;
					case 2:score += 20; break;
					case 3:score += 70; break;
					}
				case 10:
					switch (starsFirst) {
					case 0:score -= 200; break;
					case 1:score -= 150; break;
					case 2:score -= 100; break;
					case 3:score += 50; break;
					}

				case 9:
					switch (starsFirst) {
					case 0:score -= 500; break;
					case 1:score -= 400; break;
					case 2:score -= 350; break;
					case 3:score += 20; break;
					}
				default: {
					switch (starsFirst) {
					case 0:score -= 700; break;
					case 1:score -= 700; break;
					case 2:score -= 700; break;
					case 3:score -= 700; break;
					}
				}
				}
			}
			if (th == 11) {

			}
			if (th == 10) {

			}
			if (th == 9) {

			}
			if (th == 8) {

			}
			if (th == 7) {

			}
			if (th == 6) {

			}
			if (th == 5) {

			}
			if (th == 4) {

			}
			if (th == 3) {

			}
		}
		return score;
	}


AttackPair::~AttackPair()
{
}
