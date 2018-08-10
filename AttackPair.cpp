#include "stdafx.h"
#include "AttackPair.h"

AttackPair::AttackPair(){}

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
		enemySecond = enemyLevel;
		attacksDone++;
		getPerformance();
		break;
	case 2:
		//both attacks done
		throw new WarException{ "Both attacks already done" };
		break;
	}
}

pair<int, int> AttackPair::getStars() const
{
	return pair<int, int>(starsFirst, starsSecond);
}

pair<int, int> AttackPair::getPercent() const
{
	return pair<int, int>(percentFirst, percentSecond);
}

pair<int, int> AttackPair::getEnemy() const
{
	return pair<int, int>(enemyFirst, enemySecond);
}

int AttackPair::getCycle() const
{
	return cycle;
}

int AttackPair::getPerformance()
{
	if (performance != -1)		//already computed
		return performance;

	int score=0;
	int th = playerThLevel;
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

		//war performance coefficients:
		if (th == 12) {
			switch (enemy) {
			case 12:
				switch (stars) {
				case 0:score -= 50; break;
				case 1:score -= 30; break;
				case 2:score += 100; break;
				case 3:score += 150; break;
				}
				break;
			case 11:
				switch (stars) {
				case 0:score -= 100; break;
				case 1:score -= 50; break;
				case 2:score += 20; break;
				case 3:score += 70; break;
				}
				break;
			case 10:
				switch (stars) {
				case 0:score -= 200; break;
				case 1:score -= 150; break;
				case 2:score -= 100; break;
				case 3:score += 50; break;
				}
				break;
			case 9:
				switch (stars) {
				case 0:score -= 500; break;
				case 1:score -= 400; break;
				case 2:score -= 350; break;
				case 3:score += 20; break;
				}
				break;
			default: {
				switch (stars) {
				case 0:score -= 700; break;
				case 1:score -= 700; break;
				case 2:score -= 700; break;
				case 3:score += 10; break;
				}
				break;
			}
			}
		}
		if (th == 11) {
			switch (enemy) {
			case 12:
				switch (stars) {
				case 0:score -= 30; break;
				case 1:score -= 10; break;
				case 2:score += 80; break;
				case 3:score += 200; break;
				}
				break;
			case 11:
				switch (stars) {
				case 0:score -= 70; break;
				case 1:score -= 40; break;
				case 2:score += 70; break;
				case 3:score += 150; break;
				}
				break;
			case 10:
				switch (stars) {
				case 0:score -= 150; break;
				case 1:score -= 100; break;
				case 2:score -= 30; break;
				case 3:score += 50; break;
				}
				break;
			case 9:
				switch (stars) {
				case 0:score -= 300; break;
				case 1:score -= 250; break;
				case 2:score -= 100; break;
				case 3:score += 20; break;
				}
				break;
			default: {
				switch (stars) {
				case 0:score -= 700; break;
				case 1:score -= 700; break;
				case 2:score -= 700; break;
				case 3:score += 10; break;
				}
				break;
			}
			}
		}
		if (th == 10) {
			switch (enemy) {
			case 12:
				switch (stars) {
				case 0:score -= 10; break;
				case 1:score -= 5; break;
				case 2:score += 100; break;
				case 3:score += 300; break;
				}
				break;
			case 11:
				switch (stars) {
				case 0:score -= 30; break;
				case 1:score -= 10; break;
				case 2:score += 70; break;
				case 3:score += 200; break;
				}
				break;
			case 10:
				switch (stars) {
				case 0:score -= 100; break;
				case 1:score -= 50; break;
				case 2:score += 10; break;
				case 3:score += 100; break;
				}
				break;
			case 9:
				switch (stars) {
				case 0:score -= 300; break;
				case 1:score -= 200; break;
				case 2:score -= 80; break;
				case 3:score += 50; break;
				}
				break;
			default: {
				switch (stars) {
				case 0:score -= 700; break;
				case 1:score -= 700; break;
				case 2:score -= 700; break;
				case 3:score += 10; break;
				}
				break;
			}
			}
		}
		if (th == 9) {
			switch (enemy) {
			case 12:
				switch (stars) {
				case 0:score -= 5; break;
				case 1:score += 10; break;
				case 2:score += 300; break;
				case 3:score += 500; break;
				}
				break;
			case 11:
				switch (stars) {
				case 0:score -= 10; break;
				case 1:score -= 5; break;
				case 2:score += 200; break;
				case 3:score += 350; break;
				}
				break;
			case 10:
				switch (stars) {
				case 0:score -= 30; break;
				case 1:score -= 10; break;
				case 2:score -= 100; break;
				case 3:score += 250; break;
				}
				break;
			case 9:
				switch (stars) {
				case 0:score -= 200; break;
				case 1:score -= 100; break;
				case 2:score -= 10; break;
				case 3:score += 100; break;
				}
				break;
			default: {
				switch (stars) {
				case 0:score -= 700; break;
				case 1:score -= 700; break;
				case 2:score -= 700; break;
				case 3:score += 10; break;
				}
				break;
			}
			}
		}
		if (th == 8) {
			switch (enemy) {
			case 12:
				switch (stars) {
				case 0:score -= 5; break;
				case 1:score += 50; break;
				case 2:score += 500; break;
				case 3:score += 700; break;
				}
				break;
			case 11:
				switch (stars) {
				case 0:score -= 5; break;
				case 1:score += 50; break;
				case 2:score += 300; break;
				case 3:score += 500; break;
				}
				break;
			case 10:
				switch (stars) {
				case 0:score -= 10; break;
				case 1:score -= 5; break;
				case 2:score += 200; break;
				case 3:score += 300; break;
				}
				break;
			case 9:
				switch (stars) {
				case 0:score -= 50; break;
				case 1:score -= 30; break;
				case 2:score += 50; break;
				case 3:score += 200; break;
				}
				break;
			case 8:
				switch (stars) {
				case 0:score -= 100; break;
				case 1:score -= 50; break;
				case 2:score -= 30; break;
				case 3:score += 100; break;
				}
				break;
			default: {
				switch (stars) {
				case 0:score -= 700; break;
				case 1:score -= 700; break;
				case 2:score -= 700; break;
				case 3:score += 10; break;
				}
				break;
			}
			}
		}
		if (th == 7) {
			switch (enemy) {
			case 12:
				switch (stars) {
				case 0:score -= 5; break;
				case 1:score += 100; break;
				case 2:score += 700; break;
				case 3:score += 900; break;
				}
				break;
			case 11:
				switch (stars) {
				case 0:score -= 5; break;
				case 1:score += 100; break;
				case 2:score += 500; break;
				case 3:score += 700; break;
				}
				break;
			case 10:
				switch (stars) {
				case 0:score -= 10; break;
				case 1:score += 50; break;
				case 2:score += 200; break;
				case 3:score += 300; break;
				}
				break;
			case 9:
				switch (stars) {
				case 0:score -= 10; break;
				case 1:score += 20; break;
				case 2:score += 100; break;
				case 3:score += 300; break;
				}
				break;
			case 8:
				switch (stars) {
				case 0:score -= 10; break;
				case 1:score -= 5; break;
				case 2:score += 50; break;
				case 3:score += 150; break;
				}
				break;
			case 7:
				switch (stars) {
				case 0:score -= 50; break;
				case 1:score -= 30; break;
				case 2:score += 20; break;
				case 3:score += 100; break;
				}
				break;
			default: {
				switch (stars) {
				case 0:score -= 200; break;
				case 1:score -= 200; break;
				case 2:score -= 200; break;
				case 3:score += 10; break;
				}
				break;
			}
			}
		if (th == 6) {
			switch (enemy) {
			case 12:
				switch (stars) {
				case 0:score -= 5; break;
				case 1:score += 100; break;
				case 2:score += 700; break;
				case 3:score += 900; break;
				}
				break;
			case 11:
				switch (stars) {
				case 0:score -= 5; break;
				case 1:score += 100; break;
				case 2:score += 500; break;
				case 3:score += 700; break;
				}
				break;
			case 10:
				switch (stars) {
				case 0:score -= 10; break;
				case 1:score += 90; break;
				case 2:score += 300; break;
				case 3:score += 500; break;
				}
				break;
			case 9:
				switch (stars) {
				case 0:score -= 10; break;
				case 1:score += 50; break;
				case 2:score += 200; break;
				case 3:score += 400; break;
				}
				break;
			case 8:
				switch (stars) {
				case 0:score -= 10; break;
				case 1:score += 30; break;
				case 2:score += 50; break;
				case 3:score += 150; break;
				}
				break;
			case 7:
				switch (stars) {
				case 0:score -= 50; break;
				case 1:score -= 30; break;
				case 2:score += 50; break;
				case 3:score += 200; break;
				}
				break;
			case 6:
				switch (stars) {
				case 0:score -= 10; break;
				case 1:score -= 5; break;
				case 2:score += 50; break;
				case 3:score += 100; break;
				}
				break;
			default: {
				switch (stars) {
				case 0:score -= 100; break;
				case 1:score -= 100; break;
				case 2:score -= 100; break;
				case 3:score += 10; break;
				}
				break;
			}
			}
		}
		}
	}
	performance = score;
	return score;
}

string AttackPair::getDate() const
{
	return date;
}

std::string AttackPair::toString() const
{
	/*
		to .csv format, without the terminating ,
	*/
	std::string str;

	str.append(to_string(playerThLevel));
	str.append(",");
	str.append(to_string(starsFirst));
	str.append(",");
	str.append(to_string(starsSecond));
	str.append(",");
	str.append(to_string(percentFirst));
	str.append(",");
	str.append(to_string(percentSecond));
	str.append(",");
	str.append(to_string(enemyFirst));
	str.append(",");
	str.append(to_string(enemySecond));
	str.append(",");
	str.append(to_string(attacksDone));
	str.append(",");
	str.append(to_string(performance));
	str.append(",");
	str.append(date);
	str.append(",");
	str.append(to_string(cycle));

	return str;
}
