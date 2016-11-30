#pragma once
#include <vector>
#include <string>

struct Player //will hold all player's values such as current HP and attack speed in the future
{

	std::vector<int> pBaseStats = {0, 0, 0};
	std::string pClass;
	std::string pRace;
	float critChance; //crit chance
	float evasionChance; //dodge chance
	int critMulti; //multiply our crit damage by what?
	int blockChance; //block chance
	int armor; //armor 
	float physResistance; //phys damage resist. can be increased by armor or other things
	float magicResistance; //magic resist, differs by race

	Player::Player() 
	{
		critChance = .05;
		evasionChance = .10;
		blockChance = .15;
		critMulti = 2;
		armor = 0;
		magicResistance = 0;
	}

	std::vector<int> Player::getStats()
	{
		return pBaseStats;
	}

	void Player::setBaseStats(int s, int a, int i)
	{
		pBaseStats.at(0) = s;
		pBaseStats.at(1) = a;
		pBaseStats.at(2) = i;
	}

	void Player::setRace(std::string c)
	{
		pRace = c;
	}

	void Player::setClass(std::string c)
	{
		pClass = c;
	}

	std::string Player::getRace()
	{
		return pRace;
	}

	std::string Player::getClass()
	{
		return pClass;
	}
};

