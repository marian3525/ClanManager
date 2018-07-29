#pragma once
class ClanGamesScore
{
public:
	ClanGamesScore();
	ClanGamesScore(int score, int cycle) : score{ score }, cycle{ cycle } {};
	int getScore() const { return score; }
	int getCycle() const { return cycle; }
private:
	int score=-1;
	int cycle=-1;
};

