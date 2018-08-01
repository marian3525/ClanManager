#pragma once
#include <vector>
#include <algorithm>
#include "Player.h"
class Repo
{
public:
	Repo();
	void add(Player& p);
	void remove(std::string name);
	void updatePlayer(Player& p, string mode);
	Player& getByName(std::string name);
	Player& getById(std::string id);
	Player& getByIndex(int idx);
	bool existsByName(std::string name);
	int getSize();
	std::vector<Player>& getAll();
private:
	std::vector<Player> players;
};

