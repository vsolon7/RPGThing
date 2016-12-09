#pragma once
#include <map>
#include <vector>
#include <string>

/*
	This will keep track of the many different items and all their values and types

	0 = helm
	1 = chest
	2 = boots
	3 = amulet
	4 = right bracer
	5 = left bracer
	6 = weapon
	7 = shield

	later will add prefixes and stuff to them also. not "magic and rare" items though, just prefixes.

*/

struct Weapon
{
	std::map<std::string, int> prefixM;
	std::vector<std::string> prefixes = { "Shitty", "Retarded", "Bad", "Decent", "Good", "Great", "Dank", "Amazing", "Perfect", "Divine" };

	int damage = 0;
	int type = 6; //weapon type
	float critChanceIncrease = 0.0f;
	float magicDamageIncrease = 0.0f;
	float lifeStealIncrease = 0.0f; //additive
	float blockChanceIncrease = 0.0f;

	Weapon::Weapon(std::string p, std::string type)
	{
		if (type == "Dagger")
		{
			for (unsigned int c = 0; c < prefixes.size(); c++)
			{
				prefixM[prefixes[c]] = ((2 * (c + 1) * (c + 1)) - (c + 1));
			}
			damage = prefixM[p];
			if (damage < 1)
				damage = 1;

			critChanceIncrease = .10f; //additive
			magicDamageIncrease = .05f; //additive
		}

		else if (type == "Claw")
		{
			for (unsigned int c = 0; c < prefixes.size(); c++)
			{
				prefixM[prefixes[c]] = ((((float)5 / 3) * (c + 1) * (c + 1)) - (c + 1));
			}
			damage = prefixM[p];
			if (damage < 1)
				damage = 1;

			critChanceIncrease = 0.05f; //additive
			magicDamageIncrease = 0.05f; //additive
			lifeStealIncrease = 0.10f; //additive
		}

		else if (type == "Wand")
		{
			for (unsigned int c = 0; c < prefixes.size(); c++)
			{
				prefixM[prefixes[c]] = ((((float)5 / 3) * (c + 1) * (c + 1)) - (c + 1));
			}
			damage = prefixM[p];
			if (damage < 1)
				damage = 1;

			critChanceIncrease = 0.05f; //additive
			magicDamageIncrease = 0.15f; //additive
		}

		else if (type == "Bow")
		{
			for (unsigned int c = 0; c < prefixes.size(); c++)
			{
				prefixM[prefixes[c]] = ((((float)5 / 3) * (c + 1) * (c + 1)) - (c + 1));
			}
			damage = prefixM[p];
			if (damage < 1)
				damage = 1;

			critChanceIncrease = .15f; //additive
		}

		else if (type == "Sword")
		{
			for (unsigned int c = 0; c < prefixes.size(); c++)
			{
				prefixM[prefixes[c]] = (2 * (c + 1) * (c + 1));
			}
			damage = prefixM[p];
			if (damage < 1)
				damage = 1;
		}

		else if (type == "Shield")
		{
			damage = 1;

			magicDamageIncrease = .05f; //additive
			blockChanceIncrease = .20f; //additive
			type = 7;
		}
	}
};

struct Amulet
{
	std::map<std::string, float> prefixM;
	std::vector<std::string> prefixes = { "Shitty", "Retarded", "Bad", "Decent", "Good", "Great", "Dank", "Amazing", "Perfect", "Divine" };

	float lifeRegenIncreaseMult = 0.0f;

	//prefix with a capital letter
	Amulet::Amulet(std::string p)
	{
		for (unsigned int i = 0; i < prefixes.size(); i++)
			prefixM[prefixes[i]] = ((((float)i) / 10) + 1); //goes from 1.0 to 2.0. multiplies your life regen based on prefix

		lifeRegenIncreaseMult = prefixM[p];
	}
};