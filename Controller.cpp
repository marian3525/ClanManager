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
		line_len = strlen(line);
		len = 0;
		//read each field and convert it to the proper type
		//Format: tag, name, th, role, rank, level, league, cups, vscups, warStars, legend, attacks, defenses, donations, requests, ratio, ratio_adj, activity, contribution,
		//playerLevel, stars1, stars2, percent1, percent2, enemy1, enemy2, attacks, performance, date...

		ptr = strtok(line, ",");
		const string tag = string(ptr);
		len += strlen(ptr)+1;

		ptr = strtok(NULL, ",");
		const string name = string(ptr);
		len += strlen(ptr)+1;

		ptr = strtok(NULL, ",");
		const int townHall = atoi(ptr);
		len += strlen(ptr)+1;

		ptr = strtok(NULL, ",");
		const string role = string(ptr);
		len += strlen(ptr)+1;

		ptr = strtok(NULL, ",");
		const int rank = atoi(ptr);
		len += strlen(ptr)+1;

		ptr = strtok(NULL, ",");
		const int experience = atoi(ptr);
		len += strlen(ptr)+1;

		ptr = strtok(NULL, ",");
		const string league = string(ptr);
		len += strlen(ptr)+1;

		ptr = strtok(NULL, ",");
		const int trophies = atoi(ptr);
		len += strlen(ptr)+1;

		ptr = strtok(NULL, ",");
		const int versusTrophies = atoi(ptr);
		len += strlen(ptr)+1;

		ptr = strtok(NULL, ",");
		const int warStars = atoi(ptr);
		len += strlen(ptr)+1;

		ptr = strtok(NULL, ",");
		const int legendThophies = atoi(ptr);
		len += strlen(ptr)+1;

		ptr = strtok(NULL, ",");
		const int attackWins = atoi(ptr);
		len += strlen(ptr)+1;

		ptr = strtok(NULL, ",");
		const int defenseWins = atoi(ptr);
		len += strlen(ptr)+1;

		ptr = strtok(NULL, ",");
		const int troopsDonated = atoi(ptr);
		len += strlen(ptr)+1;

		ptr = strtok(NULL, ",");
		const int troopReceived = atoi(ptr);
		len += strlen(ptr)+1;

		ptr = strtok(NULL, ",");
		const float ratio = stof(ptr);
		len += strlen(ptr)+1;

		ptr = strtok(NULL, ",");
		const float ratioAdj = stof(ptr);
		len += strlen(ptr)+1;

		ptr = strtok(NULL, ",");
		const float activity = stof(ptr);
		len += strlen(ptr)+1;

		ptr = strtok(NULL, ",");
		const float contribution = stof(ptr);
		len += strlen(ptr)+1;

		Player p{ tag, name, townHall, role, rank, experience, league, trophies, versusTrophies, warStars, legendThophies,
			attackWins, defenseWins, troopsDonated, troopReceived, ratio, ratioAdj, activity, contribution };

		//checking if the player has war attacks

		if (len < line_len) {
			//"abcd0sawf"
			// 012345678
			// _____^___
			char* warAttacksStart = ptr + strlen(ptr) + 1;
			p.addWarAttacksFromFile(warAttacksStart);
		}

		repo.add(p);
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
		outputString += player.toString() + '\n';
	}
	//remove the last \n or it will cause problems when reading back from the file and splitting by fields
	outputString.pop_back();
	stats << outputString;
	stats.close();
}

void Controller::importDataFromCopy()
{
	importUpdatedData(freshCopyFilename);
}

void Controller::removePlayer(string tag)
{
	repo.remove(tag);
	notifyObservers();
}

void Controller::updatePlayer(Player & player)
{
	repo.updatePlayer(player);

	notifyObservers();
}

void Controller::importUpdatedData(string path)
{
	/*
		Load fresh data from the .csv dowloaded from clashofstats
	*/
	string outputString;	// to the copy file
	ifstream freshFile(path);

	char* line = new char[1300];

	char* char_ptr;				//ptr to the current field in the line

	string tag, name, role, league;
	int townHall, rank, experience, trophies, versusTrophies, warStars, legendThophies, attackWins, defenseWins,
		troopsDonated, troopReceived;

	if (!freshFile.is_open())
		throw ControllerException("Could not open file " + freshDataFilename);

	//read the first line with the headers, we don't need it
	freshFile.getline(line, 1298);

	while (!freshFile.eof()) {
		freshFile.getline(line, 1298);

		//write to the copy:
		outputString += string(line)+'\n';

		//read each field and convert it to the proper type

		char_ptr = strtok(line, ",");
		if (char_ptr==NULL)
			break;
		tag = string(char_ptr + 1, strlen(char_ptr) - 2);		//strip the first and the last chars which are '"' and not needed

		char_ptr = strtok(NULL, ",");
		name = string(char_ptr + 1, strlen(char_ptr) - 2);

		char_ptr = strtok(NULL, ",");
		townHall = atoi(char_ptr);

		char_ptr = strtok(NULL, ",");
		role = string(char_ptr + 1, strlen(char_ptr) - 2);

		char_ptr = strtok(NULL, ",");
		rank = atoi(char_ptr);

		char_ptr = strtok(NULL, ",");
		experience = atoi(char_ptr);

		char_ptr = strtok(NULL, ",");
		league = string(char_ptr + 1, strlen(char_ptr) - 2);

		char_ptr = strtok(NULL, ",");
		trophies = atoi(char_ptr);

		char_ptr = strtok(NULL, ",");
		versusTrophies = atoi(char_ptr);

		char_ptr = strtok(NULL, ",");
		warStars = atoi(char_ptr);

		//0 legend trophies do not exist in the file. No trophies is marked by nothing, so prev_attr,,next_attr
		//if after the prev token there is a , then there are 0 legend trophies. Else, parse as usual
		if (*(char_ptr + strlen(char_ptr) + 1) == ',') {
			legendThophies = 0;
		}
		else {
			char_ptr = strtok(NULL, ",");
			legendThophies = atoi(char_ptr);
		}

		char_ptr = strtok(NULL, ",");
		attackWins = atoi(char_ptr);

		char_ptr = strtok(NULL, ",");
		defenseWins = atoi(char_ptr);

		char_ptr = strtok(NULL, ",");
		troopsDonated = atoi(char_ptr);

		char_ptr = strtok(NULL, ",");
		troopReceived = atoi(char_ptr);

		Player p{ tag, name, townHall, role, rank, experience, league, trophies, versusTrophies, warStars, legendThophies,
			attackWins, defenseWins, troopsDonated, troopReceived };

		if (repo.existsByName(name))
			updatePlayer(p);
		else
			repo.add(p);
	}
	delete line;
	freshFile.close();

	//if the function was called as usual, not as backup because the original was not found
	if (path.find(freshCopyFilename.c_str()) == string::npos) {
		ofstream copyFile(freshCopyFilename);
		if (!copyFile.is_open())
			throw ControllerException("Could not open file " + freshCopyFilename);
		outputString.pop_back();
		copyFile << outputString;
		copyFile.close();
	}
}

void Controller::computeMetrics()
{
	float ratio;
	float ratio_adjusted;
	float activity_metric;
	float contribution;

	
	for (Player& p : repo.getAll()) {
		//the common ratio
		if (p.getTroopsRequested() != 0) {
			ratio = (float) p.getTroopsDonated() / p.getTroopsRequested();
		}
		else {
			ratio = p.getTroopsDonated();
		}
		p.setRatio(ratio);
		
		//adjusted ratio
		float ratioAdj = computeRatioAdj(p);
		p.setRatioAdjusted(ratioAdj);

		//activity masurement
		float activityMetric = computeActivityMetric(p);
		p.setActivityMetric(activityMetric);
	}
}

void Controller::addWarAttacks(string playerName, AttackPair warShow)
{
	Player& player = repo.getByName(playerName);
	player.addWarShow(warShow);
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
		cmp = [](const Player& a, const Player& b) {return a.getRatio() > b.getRatio(); };
		break;
	case ratioDec:
		cmp = [](const Player& a, const Player& b) {return a.getRatio() < b.getRatio(); };
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
