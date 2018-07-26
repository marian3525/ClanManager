#include "stdafx.h"
#include "Controller.h"

Controller::Controller()
{

}

void Controller::loadStats()
{
	/*
		Load stats from a file (war performances & long term behaviour)
	*/
	ifstream statsInput(statsFilename);
	char* line = new char[10000];
	char* ptr;
	int line_len;
	int len;

	if (!statsInput.is_open()) {
		throw ControllerException{ "Could not open file: " + statsFilename };
	}
	
	while (!statsInput.eof()) {
		statsInput.getline(line, 10000);
		
		Player player{};
		player.loadFromFile(line);

		repo.add(player);
	}

	statsInput.close();
}

void Controller::storeStats()
{
	/*
		Store stats in a file as persistent storage
	*/
	ofstream stats(statsFilename);
	string outputString;

	if (!stats.is_open())
		throw new ControllerException{ "Cannot open file " + statsFilename };

	for (const Player& player : repo.getAll()) {
		outputString.append(player.toString() + '\n');
	}
	//remove the last \n or it will cause problems when reading back from the file and splitting by fields
	outputString.pop_back();
	stats << outputString;
	stats.close();
}

void Controller::removePlayer(string tag)
{
	repo.remove(tag);
	notifyObservers();
}

void Controller::updatePlayer(Player & player)
{
	/*
		Add the new attacks, defenses, donations and requests to the history vectors
	*/
	repo.updatePlayer(player);

	notifyObservers();
}

void Controller::importUpdatedData(std::string path)
{
	/*
		Load fresh data from the .csv dowloaded from clashofstats
	*/
	ifstream freshFile(path);

	char* line = new char[1300];
	char* char_ptr;				//ptr to the current field in the line

	if (!freshFile.is_open())
		throw ControllerException{ "Could not open file " + path };

	//read the first line with the headers, we don't need it
	freshFile.getline(line, 1298);

	while (!freshFile.eof()) {
		freshFile.getline(line, 1290);

		if (strcmp(line, "")==0)
			//last line
			break;

		Player player{};
		player.loadFromFreshFile(line);

		if (repo.existsByName(player.getName()))
			//if it already exists, load the new stats into the history vectors
			updatePlayer(player);
		else
			repo.add(player);
	}
	delete line;
	freshFile.close();
}

void Controller::addWarAttacks(string playerName, AttackPair warShow)
{
	repo.getByName(playerName).addWarShow(warShow);
}

void Controller::addClanGamesScore(std::string playerName, int score)
{
	repo.getByName(playerName).addClanGamesScore(score);
}

int Controller::getPlayerThLevel(string name)
{
	if (repo.existsByName(name))
		return repo.getByName(name).getTownHall();
	else
		return -1;
}

int Controller::getSize()
{
	return repo.getSize();
}

void Controller::registerObserver(Observer * observer)
{
	/*
		Register the given observer to the notification list
		When a change on the repo data occurs, a call to notify() to all observers will be issued
	*/
	observers.push_back(observer);
}

void Controller::onExit()
{
	/*
		Save all persistent data
	*/
	storeStats();
}

vector<Player> Controller::getAll()
{
	return repo.getAll();
}

string Controller::getTime(string format)
{
	/*
		Format will consist of letters D, M and Y separated by /
		to get 21/7/2018 the format will have to be: D/M/Y
		to get 7/21 the format will have to be: M/D
	*/
	string date;
	time_t currentTime = time(0);
	tm* localTime = localtime(&currentTime);
	int day, month, year;

	for (const char tok : format) {
		switch (tok) {
		case 'D': day = localTime->tm_mday; date += to_string(day); break;
		case 'M': month = localTime->tm_mon + 1; date += to_string(month); break;
		case 'Y': year = localTime->tm_year + 1900; date += to_string(year); break;
		case '/': date += "/"; break;
		}
	}
	return date;
}

Player& Controller::getPlayer(string name)
{
	return repo.getByName(name);
}

void Controller::updateComments(Player & player, string newText)
{
	/*
		remove the '\n' from the text and replace with &&
		set the new description of the player
	*/
	replace(newText.begin(), newText.end(), '\n', '$');
	repo.getByName(player.getName()).setNotes(newText);
}

string Controller::getComments(const Player & p)
{
	//get the notes and replace the $ with endlines
	string notes = repo.getByName(p.getName()).getNotes();
	replace(notes.begin(), notes.end(), '$', '\n');

	return notes;
}

void Controller::sort(SortMode mode)
{
	std::function<bool(const Player& a, const Player& b)> cmp;

	switch (mode) {
	case donationInc:
		cmp = [](const Player& a, const Player& b) {return a.getTroopsDonated() < b.getTroopsDonated(); };
		break;
	case donationDec:
		cmp = [](const Player& a, const Player& b) {return a.getTroopsDonated() > b.getTroopsDonated(); };
		break;
	case requestInc:
		cmp = [](const Player& a, const Player& b) {return a.getTroopsRequested() < b.getTroopsRequested(); };
		break;
	case requestDec:
		cmp = [](const Player& a, const Player& b) {return a.getTroopsRequested() > b.getTroopsRequested(); };
		break;
	case xp:
		cmp = [](const Player& a, const Player& b) {return a.getExperience() > b.getExperience(); };
		break;
	case townhall:
		cmp = [](const Player& a, const Player& b) {return a.getTownHall() > b.getTownHall();; };
		break;
	case attackWins:
		cmp = [](const Player& a, const Player& b) {return a.getAttackWins() > b.getAttackWins(); };
		break;
	case defenseWins:
		cmp = [](const Player& a, const Player& b) {return a.getDefenseWins() > b.getDefenseWins(); };
		break;
	case ratioInc:
		cmp = [](const Player& a, const Player& b) {return a.getRatio() < b.getRatio(); };
		break;
	case ratioDec:
		cmp = [](const Player& a, const Player& b) {return a.getRatio() > b.getRatio(); };
		break;
	case warStars:
		cmp = [](const Player& a, const Player& b) {return a.getWarStars() > b.getWarStars(); };
		break;
	case trophies:
		cmp = [](const Player& a, const Player& b) {return a.getTrophies() > b.getTrophies(); };
		break;
	case versusTrophies:
		cmp = [](const Player& a, const Player& b) {return a.getVersusTrophies() > b.getVersusTrophies(); };
		break;
	case legendTrophies:
		cmp = [](const Player& a, const Player& b) {return a.getLegendTrophies() > b.getLegendTrophies(); };
		break;
	case ratioAdj:
		cmp = [](const Player& a, const Player& b) {return a.getRatioAdjusted() > b.getRatioAdjusted(); };
		break;
	case activityMetric:
		cmp = [](const Player& a, const Player& b) {return a.getActivityMetric() > b.getActivityMetric(); };
		break;
	case contribution:
		cmp = [](const Player& a, const Player& b) {return a.getContribution() > b.getContribution(); };
		break;
	}
	std::sort(repo.getAll().begin(), repo.getAll().end(), cmp);
	notifyObservers();
}


void Controller::notifyObservers()
{
	for (Observer* observer : observers) {
		observer->notify();
	}
}

float Controller::computeActivityMetric(Player & p)
{
	float activityMetric;
	//activity metric:
	int cc_size;
	switch (p.getTownHall()) {
	case 1:
		cc_size = 0;
	case 2:
		cc_size = 0;
	case 3:
		cc_size = 10;
	case 4:
		cc_size = 15;
	case 5:
		cc_size = 15;
	case 6:
		cc_size = 20;
	case 7:
		cc_size = 20;
	case 8:
		cc_size = 25;
	case 9:
		cc_size = 30;
	case 10:
		cc_size = 35;
	case 11:
		cc_size = 35;
	case 12:
		cc_size = 40;
	}
	activityMetric = p.getAttackWins() * cc_size + p.getTroopsDonated() + p.getTroopsRequested();
	return activityMetric;
}

float Controller::computeRatioAdj(Player & p)
{
	float ratioAdj;
	if (p.getAttackWins() != 0)
		ratioAdj = p.getTroopsRequested() / p.getAttackWins();
	else
		ratioAdj = p.getTroopsRequested();
	
	ratioAdj /= p.getCcSize();
	
	return ratioAdj;
}

float Controller::computeContribution(Player & p)
{
	float contribution=0;

	contribution += p.getTroopsDonated();
	contribution += p.getGamesScore();
	return contribution;
}

float Controller::computeCcsUsedPerBattle(Player & p)
{
	float ccs;
	if (p.getAttackWins() != 0)
		ccs = p.getTroopsRequested() / p.getAttackWins();
	else
		ccs = p.getTroopsRequested();

	ccs /= p.getCcSize();

	return ccs;
}

string Controller::convertPath(const string & path)
{
	string _path;

	for (const char c : path) {
		if (c == '\\') {
			//convert the separators from '\' to '\\'
			_path += "\\\\";
		}
		else {
			_path += c;
		}
	}
	return _path;
}
