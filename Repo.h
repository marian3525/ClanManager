#pragma once
#include <vector>
#include "Player.h"
#include <algorithm>

using namespace std;
class Repo
{
public:
	Repo();
	void add(Player& p);
	void remove(string name);
	void updatePlayer(Player& p);
	Player& getByName(string name);
	Player& getById(string id);
	Player& getByIndex(int idx);
	bool existsByName(string name);
	int getSize();
	vector<Player>& getAll();
private:
	vector<Player> players;
};

