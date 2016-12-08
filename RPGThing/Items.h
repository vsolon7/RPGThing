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
	int lifeStealIncrease = 0.0f; //additive
	int blockChanceIncrease = 0.0f;

	Weapon(std::string p, std::string type)
	{
		if (type == "Dagger")
		{
			for (int c = 0; c < prefixes.size(); c++)
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
			for (int c = 0; c < prefixes.size(); c++)
			{
				prefixM[prefixes[c]] = ((((float)5 / 3) * (c + 1) * (c + 1)) - (c + 1));
			}
			damage = prefixM[p];
			if (damage < 1)
				damage = 1;

			critChanceIncrease = .05f; //additive
			magicDamageIncrease = .05f; //additive
			lifeStealIncrease = .10f; //additive
		}

		else if (type == "Wand")
		{
			for (int c = 0; c < prefixes.size(); c++)
			{
				prefixM[prefixes[c]] = ((((float)5 / 3) * (c + 1) * (c + 1)) - (c + 1));
			}
			damage = prefixM[p];
			if (damage < 1)
				damage = 1;

			float critChanceIncrease = 0.5f; //additive
			float magicDamageIncrease = .15f; //additive
		}

		else if (type == "Bow")
		{
			for (int c = 0; c < prefixes.size(); c++)
			{
				prefixM[prefixes[c]] = ((((float)5 / 3) * (c + 1) * (c + 1)) - (c + 1));
			}
			damage = prefixM[p];
			if (damage < 1)
				damage = 1;

			float critChanceIncrease = .15f; //additive
		}

		else if (type == "Sword")
		{
			for (int c = 0; c < prefixes.size(); c++)
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
