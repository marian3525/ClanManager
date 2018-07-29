#include "stdafx.h"
#include "Repo.h"


Repo::Repo()
{

}

void Repo::add(Player& p)
{	
	players.push_back(p);
}

void Repo::remove(string tag)
{
	auto it = find_if(players.begin(), players.end(), [&tag](Player& p) {return p.getTag() == tag; });
	if(it != players.end())
		players.erase(it);
}

void Repo::updatePlayer(Player& player)
{
	/*
		player will contain vectors of size 1 in history for attacks, defenses, donations and requests
		Add them to p
	*/
	Player& p = getByName(player.getName());
	//add the 4 new values to the vectors
	p.history.addDefenses(player.getLastDefenseWins());
	p.history.addAttacks(player.getLastAttackWins());
	p.history.addDonations(player.getLastTroopsDonated());
	p.history.addRequests(player.getLastTroopsRequested());
	//update stats
	p.computeStats();
}

Player& Repo::getByName(string name)
{
	auto it = find_if(players.begin(), players.end(), [&name](Player& p) {return p.getName() == name; });
	if (it != players.end()) {
		return players[it - players.begin()];
	}
}

Player& Repo::getById(string id)
{
	auto it = find_if(players.begin(), players.end(), [&id](Player& p) {return p.getTag() == id; });
	if (it != players.end()) {
		return players[it - players.begin()];
	}
}

Player& Repo::getByIndex(int idx)
{
	for (int i = 0; i < players.size(); i++)
		if (i == idx)
			return players[i];
}

bool Repo::existsByName(string name)
{
	for (const Player& p : players) {
		if (p.getName() == name)
			return true;
	}
	return false;
}

int Repo::getSize()
{
	return players.size();
}

vector<Player>& Repo::getAll()
{
	return players;
}
