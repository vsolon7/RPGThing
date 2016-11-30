#pragma once
#include <vector>
#include <string>

struct Player
{

	std::vector<int> pStats = {0, 0, 0};
	std::string pClass;
	std::string pRace;

	Player::Player() 
	{
	}

	std::vector<int> Player::getStats()
	{
		return pStats;
	}

	void Player::setBaseStats(int s, int a, int i)
	{
		pStats.at(0) = s;
		pStats.at(1) = a;
		pStats.at(2) = i;
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

