#pragma once
#include <vector>
#include <map>
#include <string>
#include <random>
#include <ctime>
#include "Player.h"
#include "Items.h"
#include "Text.h"

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

enum GAMESTATE { CAVES, TOWN, START };

struct Player //will hold all player's values such as current HP and attack speed
{
	Text t;
	GAMESTATE instance;
	

	//lots of variables!

	/*
		Actual player stats
	*/
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

	int level;
	int exp;
	std::vector<float> currentMainWeaponStats = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f }; //damage, crit chance, magic increase, lifesteal, block increase
	std::vector<float> currentOffWeaponStats = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f }; //damage, crit chance, magic increase, lifesteal, block increase
	float currentAmmyLRMult; //amulets life regen, for unequipping later

	/*
		friends/non-stats to keep track of
	*/
	bool hasMap;
	std::map<std::string, bool> friends;
	std::vector<bool> isItemEquipped = {0,0,0,0,0,0,0,0};
	/*
		helmet = 0
		amulet = 1

		mainWep = 6
		offwep = 7
	*/

	Player()
	{
		level = 1;
		exp = 0;
		critChance = .05f;
		evasionChance = .10f;
		blockChance = .15f;
		critMulti = 2.0f;
		armor = 0;
		physResistance = 0.0f;
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
		lifeRegenMult = 1.0f;
		maxHP = 15;
		maxMana = 0;
		lifeSteal = 0.0f;
		critMultIncrease = 1.0f;
		hasMap = false;
	}

	std::vector<int> getStats()
	{
		return pBaseStats;
	}

	void setBaseStats(int s, int a, int i)
	{
		pBaseStats.at(0) = s;
		pBaseStats.at(1) = a;
		pBaseStats.at(2) = i;
	}

	void setRace(int c)
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
			lifeRegen = (.01 * maxHP);
			lifeSteal += .05f;
			maxHP += 0;
			break;
		case 2:
			magicResistance = .15f;
			elfStatMult = 1.15f;
			maxHP += 0;
			lifeRegen = (.01 * maxHP);
			break;
		case 3:
			magicResistance = .30f;
			dwarfMeleeIncrease += .10f;
			dwarfArmorIncrease += .25f;
			maxHP += 5;
			lifeRegen = (.02 * maxHP);
			break;
		case 4:
			demonMagicIncrease += .07f;
			lifeRegenMult += 1.15f;
			maxHP += 3;
			lifeRegen = (.02 * maxHP);
			break;
		case 5:
			lifeSteal += .07f;
			critMultIncrease += .4f;
			maxHP += 8;
			lifeRegen = 0;
			break;
		}
	}

	void equipWeapon(std::string pref, std::string type)
	{
		Weapon w(pref, type);

		if (!isItemEquipped.at(6))
		{
			addedDamage += w.damage;
			critChance += w.critChanceIncrease;
			magicDamageIncrease += w.magicDamageIncrease;
			lifeSteal += w.lifeStealIncrease;
			blockChance += w.blockChanceIncrease;

			currentMainWeaponStats.at(0) = w.damage;
			currentMainWeaponStats.at(1) = w.critChanceIncrease;
			currentMainWeaponStats.at(2) = w.magicDamageIncrease;
			currentMainWeaponStats.at(3) = w.lifeStealIncrease;
			currentMainWeaponStats.at(4) = w.blockChanceIncrease;

			isItemEquipped.at(6) = true;

			std::cout << "You equip the ";
			t.setColor(YELLOW);
			std::cout << pref << " " << type; t.setColor(WHITE);
			std::cout << " to your main hand.\n";

			std::cout << "It adds: \n";
			t.setColor(RED);
			std::cout << w.damage; t.setColor(WHITE); std::cout << " damage, \n";
			t.setColor(RED);
			std::cout << (w.critChanceIncrease * 100); t.setColor(WHITE); std::cout << "% crit chance increase, \n";
			t.setColor(RED);
			std::cout << (w.magicDamageIncrease * 100); t.setColor(WHITE); std::cout << "% magic damage increase, \n";
			t.setColor(RED);
			std::cout << (w.lifeStealIncrease * 100); t.setColor(WHITE); std::cout << "% lifesteal increase, and \n";
			t.setColor(RED);
			std::cout << (w.blockChanceIncrease * 100); t.setColor(WHITE); std::cout << "% block chance increase." BLANK_LINE; t.setColor(WHITE);
		}
		
		else if (!isItemEquipped.at(7))
		{
			addedDamage += w.damage;
			critChance += w.critChanceIncrease;
			magicDamageIncrease += w.magicDamageIncrease;
			lifeSteal += w.lifeStealIncrease;
			blockChance += w.blockChanceIncrease;

			currentOffWeaponStats.at(0) = w.damage;
			currentOffWeaponStats.at(1) = w.critChanceIncrease;
			currentOffWeaponStats.at(2) = w.magicDamageIncrease;
			currentOffWeaponStats.at(3) = w.lifeStealIncrease;
			currentOffWeaponStats.at(4) = w.blockChanceIncrease;

			isItemEquipped.at(6) = true;

			std::cout << "You equip the ";
			t.setColor(YELLOW);
			std::cout << pref << " " << type; t.setColor(WHITE);
			std::cout << " to your off hand.\n";

			std::cout << "It adds: \n";
			t.setColor(RED);
			std::cout << w.damage; t.setColor(WHITE); std::cout << " damage, \n";
			t.setColor(RED);
			std::cout << (w.critChanceIncrease * 100); t.setColor(WHITE); std::cout << "% crit chance increase, \n";
			t.setColor(RED);
			std::cout << (w.magicDamageIncrease * 100); t.setColor(WHITE); std::cout << "% magic damage increase, \n";
			t.setColor(RED);
			std::cout << (w.lifeStealIncrease * 100); t.setColor(WHITE); std::cout << "% lifesteal increase, and \n";
			t.setColor(RED);
			std::cout << (w.blockChanceIncrease * 100); t.setColor(WHITE); std::cout << "% block chance increase." BLANK_LINE; t.setColor(WHITE);
		}

		else
		{
			std::string getInput;
			do
			{
				std::cout << "Unequip main hand or off hand? (type 'main' of 'off'): \n";
			} while (getInput != "main" && getInput != "off" && getInput != "Main" && getInput != "Off");
			
			if (getInput == "main" || getInput == "Main")
			{
				unequipWeapon(0); //unequip mainhand weapon to make room for the new weapon

				addedDamage += w.damage;
				critChance += w.critChanceIncrease;
				magicDamageIncrease += w.magicDamageIncrease;
				lifeSteal += w.lifeStealIncrease;
				blockChance += w.blockChanceIncrease;

				currentMainWeaponStats.at(0) = w.damage;
				currentMainWeaponStats.at(1) = w.critChanceIncrease;
				currentMainWeaponStats.at(2) = w.magicDamageIncrease;
				currentMainWeaponStats.at(3) = w.lifeStealIncrease;
				currentMainWeaponStats.at(4) = w.blockChanceIncrease;

				std::cout << "You unequip your main hand to equip the new weapon." BLANK_LINE;

				std::cout << "You equip the ";
				t.setColor(YELLOW);
				std::cout << pref << " " << type; t.setColor(WHITE);
				std::cout << " to your main hand.\n";

				std::cout << "It adds: \n";
				t.setColor(RED);
				std::cout << w.damage; t.setColor(WHITE); std::cout << " damage, \n";
				t.setColor(RED);
				std::cout << (w.critChanceIncrease * 100); t.setColor(WHITE); std::cout << "% crit chance increase, \n";
				t.setColor(RED);
				std::cout << (w.magicDamageIncrease * 100); t.setColor(WHITE); std::cout << "% magic damage increase, \n";
				t.setColor(RED);
				std::cout << (w.lifeStealIncrease * 100); t.setColor(WHITE); std::cout << "% lifesteal increase, and \n";
				t.setColor(RED);
				std::cout << (w.blockChanceIncrease * 100); t.setColor(WHITE); std::cout << "% block chance increase." BLANK_LINE; t.setColor(WHITE);
			}

			else
			{
				unequipWeapon(1);

				addedDamage += w.damage;
				critChance += w.critChanceIncrease;
				magicDamageIncrease += w.magicDamageIncrease;
				lifeSteal += w.lifeStealIncrease;
				blockChance += w.blockChanceIncrease;

				currentOffWeaponStats.at(0) = w.damage;
				currentOffWeaponStats.at(1) = w.critChanceIncrease;
				currentOffWeaponStats.at(2) = w.magicDamageIncrease;
				currentOffWeaponStats.at(3) = w.lifeStealIncrease;
				currentOffWeaponStats.at(4) = w.blockChanceIncrease;

				std::cout << "You unequip your main hand to equip the new weapon." BLANK_LINE;

				std::cout << "You equip the ";
				t.setColor(YELLOW);
				std::cout << pref << " " << type; t.setColor(WHITE);
				std::cout << " to your off hand.\n";

				std::cout << "It adds: \n";
				t.setColor(RED);
				std::cout << w.damage; t.setColor(WHITE); std::cout << " damage, \n";
				t.setColor(RED);
				std::cout << (w.critChanceIncrease * 100); t.setColor(WHITE); std::cout << "% crit chance increase, \n";
				t.setColor(RED);
				std::cout << (w.magicDamageIncrease * 100); t.setColor(WHITE); std::cout << "% magic damage increase, \n";
				t.setColor(RED);
				std::cout << (w.lifeStealIncrease * 100); t.setColor(WHITE); std::cout << "% lifesteal increase, and \n";
				t.setColor(RED);
				std::cout << (w.blockChanceIncrease * 100); t.setColor(WHITE); std::cout << "% block chance increase." BLANK_LINE; t.setColor(WHITE);
			}
		}
	}

	void Player::equipAmulet(std::string pref)
	{
		Amulet a(pref);

		if (!isItemEquipped.at(1))
		{
			lifeRegenMult += a.lifeRegenIncreaseMult;
			currentAmmyLRMult = a.lifeRegenIncreaseMult;

			isItemEquipped.at(1) = true;

			std::cout << "You place the ";
			t.setColor(YELLOW);
			std::cout << pref << " amulet"; t.setColor(WHITE);
			std::cout << " around your neck. It multiplies your life regen by ";
			t.setColor(RED);
			std::cout << a.prefixM[pref]; t.setColor(WHITE);
			std::cout << "." BLANK_LINE;
		}

		else
		{
			lifeRegenMult -= currentAmmyLRMult;
			lifeRegenMult += a.lifeRegenIncreaseMult;
			currentAmmyLRMult = a.lifeRegenIncreaseMult;

			isItemEquipped.at(1) = true;

			std::cout << "You unequip your current amulet." BLANK_LINE;

			std::cout << "You equipped the ";
			t.setColor(YELLOW);
			std::cout << pref << " amulet"; t.setColor(WHITE);
			std::cout << " to your neck. It multiplies your life regen by ";
			t.setColor(RED);
			std::cout << a.prefixM[pref]; t.setColor(WHITE);
			std::cout << "." BLANK_LINE;
		}
	}

	/*
		unequippes the players current weapon, takes a parameter 0 = main hand, 1 = off hand
	*/
	void Player::unequipWeapon(int hand)
	{

		if (hand == 0)
		{
			addedDamage -= currentMainWeaponStats.at(0);
			critChance -= currentMainWeaponStats.at(1);
			magicDamageIncrease -= currentMainWeaponStats.at(2);
			lifeSteal -= currentMainWeaponStats.at(3);
			blockChance -= currentMainWeaponStats.at(4);

			for (unsigned int x = 0; x < currentMainWeaponStats.size(); x++)
				currentMainWeaponStats.at(x) = 0.0f;

			isItemEquipped.at(6) = false;
		}

		else if(hand == 1)
		{
			addedDamage -= currentOffWeaponStats.at(0);
			critChance -= currentOffWeaponStats.at(1);
			magicDamageIncrease -= currentOffWeaponStats.at(2);
			lifeSteal -= currentOffWeaponStats.at(3);
			blockChance -= currentOffWeaponStats.at(4);

			for (unsigned int x = 0; x < currentOffWeaponStats.size(); x++)
				currentMainWeaponStats.at(x) = 0.0f;

			isItemEquipped.at(7) = false;
		}

	}

	void setClass(int c)
	{
		pClass = c;
	}

	int getRace()
	{
		return pRace;
	}

	int getClass()
	{
		return pClass;
	}

	void awardExp(int level)
	{
		std::mt19937 randEngine(time(0));
		std::uniform_int_distribution<int> random( (level / 2), (level * 1.5) );

		int tempExp = random(randEngine);

		if (tempExp < 1)
			tempExp = 1;

		exp += tempExp;
		std::cout << SPACER "You gain " << tempExp << " exp!\n" SPACER;

		if (levelUp())
		{
			std::cout << "\nYou have leveled up! You are now level " << Player::level << "!" BLANK_LINE;
			std::cout << "You gain +" << statGainPerLevel << " to all stats!" BLANK_LINE;

			for (unsigned int i = 0; i < pBaseStats.size(); i++)
				pBaseStats[i] += statGainPerLevel;
			
			std::cout << "Your stats are now:\n";
			std::cout << "Strength: " << pBaseStats.at(0) << "\nAgility: " << pBaseStats.at(1) << "\nIntelligence: " << pBaseStats.at(2) << "\n" SPACER << BLANK_LINE;

		}
	}

	bool levelUp()
	{
		if (exp >= (level * level))
		{
			level += 1;
			exp -= (level * level);

			return true;
		} else
			return false;
	}

	int getLevel()
	{
		return level;
	}

};

