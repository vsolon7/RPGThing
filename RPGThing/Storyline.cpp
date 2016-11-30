#include "Storyline.h"
#include "Text.h"
#include "Player.h"
#include "Races.h"
#include "Classes.h"

#include <vector>
#include <iostream>
#include <sstream>
#include <map>
#include <time.h>
#include <random>

#define BLANK_LINE "\n\n" //blank line
#define SPACER "==================================================\n" //spacer
#define GAME_NAME "RPGThing" //the name of the game, may change

static Text t;
static std::mt19937 randEngine(time(0));

Storyline::Storyline()
{
	Player p;
	introduction();
}

void Storyline::introduction()
{
	printCharacterSelection();
}

void Storyline::printCharacterSelection()
{
	Human h;
	Elf e;
	Dwarf d;
	Demon de;
	Archangel a;

	std::cout << SPACER << std::endl;
	std::cout << "Welcome to " << GAME_NAME << ". Please pick your race (type the number):" BLANK_LINE;
	std::cout << SPACER << std::endl;

	std::cout << "1.) Human.\n" << "----------\n";
	std::cout << h.abilityOne << h.abilityTwo << BLANK_LINE;

	std::cout << "2.) Elf.\n" << "----------\n";
	std::cout << e.abilityOne << e.abilityTwo << BLANK_LINE;

	std::cout << "3.) Dwarf.\n" << "----------\n";
	std::cout << d.abilityOne << d.abilityTwo << BLANK_LINE;

	std::cout << "4.) Demon.\n" << "----------\n";
	std::cout << de.abilityOne << de.abilityTwo << BLANK_LINE;

	std::cout << "5.) Archangel\n" << "----------\n";
	std::cout << a.abilityOne << a.abilityTwo << BLANK_LINE;

	int input;
	std::cout << ">> ";
	std::cin >> input;

	if (input <= 5 && input >= 1) //basically if they're a nig and type a number thats not a race, reprint it and do nothing.
	{
		p.setRace(raceNumberToString(input));
		printClassSelection();
	}
	else
		printCharacterSelection(); 

}

void Storyline::printClassSelection()
{
	Warrior w;
	Archer a;
	Mage m;
	Rogue r;
	Tank t;

	std::cout << "1.) Warrior.\n";
	std::cout << "------------\n";
	std::cout << w.classDesc << BLANK_LINE;

	std::cout << "2.) Archer.\n";
	std::cout << "-----------\n";
	std::cout << a.classDesc << BLANK_LINE;

	std::cout << "3.) Mage.\n";
	std::cout << "---------\n";
	std::cout << m.classDesc << BLANK_LINE;

	std::cout << "4.) Rogue.\n";
	std::cout << "----------\n";
	std::cout << r.classDesc << BLANK_LINE;

	std::cout << "5.) Tank.\n";
	std::cout << "---------\n";
	std::cout << t.classDesc << BLANK_LINE;

	int input;
	std::cout << ">> ";
	std::cin >> input;

	if (input <= 5 && input >= 1) //basically if they're a nig and type a number thats not a class, reprint it and do nothing.
	{
		p.setClass(classNumberToString(input));
		rollChar(input);
	} else
		printClassSelection();
}

void Storyline::rollChar(int c)
{
	Warrior w;
	Archer a;
	Mage m;
	Rogue r;
	Tank ta;

	system("cls");
	std::cin.ignore();
	std::cout << SPACER "\nYou are a(n) " << p.getClass() << " " << p.getRace() << "!" BLANK_LINE << SPACER << "\n";

	int minStr, minAgi, minInt, priAtt;
	int Str, Agi, Int;
	std::string Cinput = "";

	//gets values for min and max stats based on the values defined in the class.h file
	switch (c)
	{
	case 1:
		minStr = w.minStr;
		minAgi = w.minAgi;
		minInt = w.minInt;
		priAtt = w.primaryStat;
		break;
	case 2:
		minStr = a.minStr;
		minAgi = a.minAgi;
		minInt = a.minInt;
		priAtt = a.primaryStat;
		break;
	case 3:
		minStr = m.minStr;
		minAgi = m.minAgi;
		minInt = m.minInt;
		priAtt = m.primaryStat;
		break;
	case 4:
		minStr = r.minStr;
		minAgi = r.minAgi;
		minInt = r.minInt;
		priAtt = r.primaryStat;
		break;
	case 5:
		minStr = ta.minStr;
		minAgi = ta.minAgi;
		minInt = ta.minInt;
		priAtt = ta.primaryStat;
		break;
	} 

	do
	{
		std::cout << "As a " << p.getClass() << " your minimum required stats are: \n" <<
		minStr << " Strength, " << minAgi << " Agility, and " << minInt << " Intelligence." << BLANK_LINE << 
		"You stats may add up to a max of 21." << BLANK_LINE << SPACER;

		//decides what stat to roll first.
		switch (priAtt)
		{
		case 1:
		{
			std::uniform_int_distribution<int> strRoll(minStr, (20 - (minAgi + minInt)));
			Str = strRoll(randEngine);

			std::uniform_int_distribution<int> agiRoll(minAgi, (20 - Str));
			Agi = agiRoll(randEngine);

			std::uniform_int_distribution<int> intRoll(minInt, (21 - (Str + Agi)));
			Int = intRoll(randEngine);
		}
			break;
		case 2:
		{
			std::uniform_int_distribution<int> agiRoll(minAgi, (20 - (minStr + minInt)));
			Agi = agiRoll(randEngine);

			std::uniform_int_distribution<int> strRoll(minStr, (20 - Agi));
			Str = strRoll(randEngine);

			std::uniform_int_distribution<int> intRoll(minInt, (21 - (Str + Agi)));
			Int = intRoll(randEngine);
		}
			break;
		case 3:
		{
			std::uniform_int_distribution<int> intRoll(minInt, (20 - (minAgi + minStr)));
			Int = intRoll(randEngine);

			std::uniform_int_distribution<int> agiRoll(minAgi, (20 - Int));
			Agi = agiRoll(randEngine);

			std::uniform_int_distribution<int> strRoll(minStr, (21 - (Int + Agi)));
			Str = strRoll(randEngine);
		}
			break;
		}

		std::cout << "You rolled a " << Str << " for STR, " << Agi << " for AGI, and a " << Int << " for INT." BLANK_LINE;
		std::cout << "To roll again, type 'r'. To continue type anything else.";

		Cinput = t.getInput();

		system("cls");
	} while (Cinput == "r" || Cinput == "R");

	p.setBaseStats(Str, Agi, Int);
}

std::string Storyline::raceNumberToString(int c)
{
	std::map<int, std::string> raceType; //map of class' number and their string name

	raceType[1] = "Human";
	raceType[2] = "Elf";
	raceType[3] = "Dwarf";
	raceType[4] = "Demon";
	raceType[5] = "Archangel";

	return raceType[c]; //returns the string name of the class realitive to their number
}

std::string Storyline::classNumberToString(int c)
{
	std::map<int, std::string> classType; //map of class' number and their string name

	classType[1] = "Warrior";
	classType[2] = "Archer";
	classType[3] = "Mage";
	classType[4] = "Rogue";
	classType[5] = "Tank";

	return classType[c]; //returns the string name of the class realitive to their number
}

Storyline::~Storyline()
{
}