#pragma once
#include <vector>
#include "Player.h"
#include <algorithm>

using namespace std;
class Repo
{
public:
	Repo();
	void add(Player p);
	void remove(string name);
	Player getByName(string name);
	Player getById(string id);
	int getSize();
	vector<Player>& getAll();
	~Repo();
private:
	vector<Player> players;
};

