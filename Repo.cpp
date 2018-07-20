#include "stdafx.h"
#include "Repo.h"


Repo::Repo()
{

}

void Repo::add(Player p)
{
	players.push_back(p);
}

void Repo::remove(string tag)
{
	auto it = find_if(players.begin(), players.end(), [&tag](Player& p) {return p.getTag() == tag; });
	if(it != players.end())
		players.erase(it);
}

Player Repo::getByName(string name)
{
	auto it = find_if(players.begin(), players.end(), [&name](Player& p) {return p.getName() == name; });
	if (it != players.end()) {
		return players[it - players.begin()];
	}
	return Player{};
}

Player Repo::getById(string id)
{
	auto it = find_if(players.begin(), players.end(), [&id](Player& p) {return p.getTag() == id; });
	if (it != players.end()) {
		return players[it - players.begin()];
	}
	return Player{};
}

int Repo::getSize()
{
	return players.size();
}

vector<Player>& Repo::getAll()
{
	return players;
}


Repo::~Repo()
{
}
