#pragma once
#include <vector>
#include <map>
#include <string>
#include "Text.h"
#include "Items.h"

#define HUMAN 1
#define ELF 2
#define DWARF 3
#define DEMON 4
#define ARCHANGEL 5

#define WARRIOR 6
#define ARCHER 7
#define MAGE 8
#define ROGUE 9
#define TANK 10

struct Player //will hold all player's values such as current HP and attack speed in the future
{
	//lots of variables!

	std::vector<int> pBaseStats = {0, 0, 0};
	int pClass;
	int pRace;
	float critChance; //crit chance
	float evasionChance; //dodge chance agility will increase this
	float critMulti; //multiply our crit damage by what?
	float blockChance; //block chance
	int armor; //players armor, increases phys damage resist
	float physResistance; //phys damage resist. can be increased by items
	float magicResistance; //magic resist, differs by race
	int statGainPerLevel; //stats character gains per level
	int attackSpeed; //will decide how many times per turn you attack. agility will increase this
	int baseDamage; //your starting damage with no weapons
	int addedDamage; //weapons add to this
	float physIncrease; //strength will increase this
	float elfStatMult; //elfs race bonus thing
	float dwarfMeleeIncrease; //his is multiplicative.
	float dwarfArmorIncrease; //only for dwarves
	float magicDamageIncrease; //int will increase this
	float demonMagicIncrease; //demon's magic increase, his is multiplicative
	int lifeRegen; //players life regen!
	float lifeRegenMult; //items can increase this
	int maxHP; //your max HP! strength will increase this
	int maxMana; //your maxInt, int will increase this
	float lifeSteal; //lifesteal!
	float critMultIncrease; //for angels.
	int currentMainWeaponAddedDamage; //for unequpping weapons
	int currentOffWeaponAddedDamage; //for unequipping weapons

	std::vector<bool> isItemEqupped = {0,0,0,0,0,0,0,0};

	Player::Player() 
	{
		critChance = .05f;
		evasionChance = .10f;
		blockChance = .15f;
		critMulti = 2.0f;
		armor = 0;
		magicResistance = 0.0f;
		statGainPerLevel = 2;
		attackSpeed = 1;
		baseDamage = 5;
		addedDamage = 0;
		physIncrease = 1.0f;
		elfStatMult = 1.0f;
		dwarfMeleeIncrease = 1.0f;
		dwarfArmorIncrease = 1.0f;
		magicDamageIncrease = 1.0f;
		demonMagicIncrease = 1.0f;
		maxHP = 15;
		maxMana = 0;
		lifeSteal = 0.0f;
		critMultIncrease = 1.0f;
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

	void Player::setRace(int c)
	{	
		//sets up the races special values!
		pRace = c;

		switch (c)
		{
		case 1:
			//humans get +5% to all percent stats
			magicResistance = .25f;
			magicResistance += .05f; 
			critChance += .05f;
			evasionChance += .05f;
			blockChance += .05f;
			critMulti += .05f;
			statGainPerLevel *= 2;
			physIncrease += .05f;
			magicDamageIncrease += .05f;
			lifeRegenMult += .05f;
			lifeSteal += .05f;
			maxHP += 0;
			break;
		case 2:
			magicResistance = .15f;
			elfStatMult = 1.15f;
			maxHP += 0;
			break;
		case 3:
			magicResistance = .30f;
			dwarfMeleeIncrease += .10f;
			dwarfArmorIncrease += .25f;
			maxHP += 5;
			break;
		case 4:
			demonMagicIncrease += .07f;
			lifeRegenMult += 1.15f;
			maxHP += 3;
			break;
		case 5:
			lifeSteal += .07f;
			critMultIncrease += .4f;
			maxHP += 8;
			break;
		}
	}

	void Player::equipWeapon(std::string pref, std::string type)
	{
		if (!isItemEqupped.at(6))
		{
			Weapon w(pref, type);

			addedDamage += w.damage;
			currentMainWeaponAddedDamage = w.damage;

			isItemEqupped.at(6) = true;

			std::cout << "You equipped the " << pref << " " << type << " to your main hand." BLANK_LINE;
		}
		
		else if (!isItemEqupped.at(7))
		{
			Weapon w(pref, type);

			addedDamage += w.damage;
			currentOffWeaponAddedDamage = w.damage;

			isItemEqupped.at(6) = true;

			std::cout << "You equipped the " << pref << " " << type << " to your off hand." BLANK_LINE;
		}
		
		else
		{
			std::cout << "You have no room for a new weapon." BLANK_LINE;
		}
	}

	void Player::setClass(int c)
	{
		pClass = c;
	}

	int Player::getRace()
	{
		return pRace;
	}

	int Player::getClass()
	{
		return pClass;
	}
};

