#pragma once
#include <string>

struct Human
{
	int raceVal = 1;
	std::string raceName = "Human";
	std::string abilityOne = "JACK OF ALL TRADES: \n-Humans get double stats when they level up!\n";
	std::string abilityTwo = "ADAPTABILITY: \n-Humans also gain a flat +5% buff to all stats that involve percents.";
};

struct Elf
{
	int raceVal = 2;
	std::string raceName = "Elf";
	std::string abilityOne = "QUICK THINKING: \n-Elves have a multiplicative 15% increase to agility.\n";
	std::string abilityTwo = "DEATH DODGER: \n-Elves also avoid death when they would normally recieve a fatal blow once per area.";
};

struct Dwarf
{
	int raceVal = 3;
	std::string raceName = "Dwarf";
	std::string abilityOne = "BRED TO FIGHT: \n-Dwarves deal 10% more melee damage.\n";
	std::string abilityTwo = "TOUGH AS NAILS: \n-Dwarves also have 25% increased armor.";
};

struct Demon
{
	int raceVal = 4;
	std::string raceName = "Demon";
	std::string abilityOne = "DEMONIC STRENGTH: \n-Demons deal 7% more magic damage.\n";
	std::string abilityTwo = "DAMNED BLOOD: \n-Demons also have 15% increased life regeneration rate.";
};

struct Archangel
{
	int raceVal = 5;
	std::string raceName = "Archangel";
	std::string abilityOne = "HOLY STRENGTH: \n-Archangels have a multiplicative 40% increased crit multiplier.\n";
	std::string abilityTwo = "PURITY: \n-Archangels also have a base 7% lifesteal.";
};