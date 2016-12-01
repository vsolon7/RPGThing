#include "Storyline.h"
#include "Text.h"
#include "Player.h"
#include "Races.h"
#include "Classes.h"
#include "Enemy.h"
#include "Items.h"
#include "Battle.h"

#include <vector>
#include <iostream>
#include <sstream>
#include <map>
#include <time.h>
#include <random>

static Text t;
static std::mt19937 randEngine(time(0)); //a mersenne twister - the random engine type.

Storyline::Storyline()
{
	Player p;
	introduction();
}

void Storyline::introduction() //TODO: more story
{
	printCharacterSelection();
	theStoryIntro();
}

void Storyline::printCharacterSelection()
{
	Human h; //check Races.h for these
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
		p.setRace(input);
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
		p.setClass(input + 5);
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
	std::cout << SPACER "\nYou are a(n) " << classNumberToString(p.getClass()) << " " << raceNumberToString(p.getRace()) << "!" BLANK_LINE << SPACER << "\n";

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

		Cinput = t.getStringInput();

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

	classType[6] = "Warrior";
	classType[7] = "Archer";
	classType[8] = "Mage";
	classType[9] = "Rogue";
	classType[10] = "Tank";

	return classType[c]; //returns the string name of the class realitive to their number
}

Storyline::~Storyline()
{
}

void Storyline::theStoryIntro()
{
	int input;
	std::string strInput;

	t.setColor(YELLOW);

	t.printDelayed("You wake up on a beautiful strand (that's a beach shore), dazed and confused.\n", THOUGHT);
	t.printDelayed("You look around a notice an ivory bench with weapons all over the top." BLANK_LINE, THOUGHT);
	t.printDelayed("You shakily stand up, and see the following weapons on the bench: " BLANK_LINE, THOUGHT); t.setColor(WHITE);
	std::cout << "1.) A sword\n2.) A bow\n3.) A wand\n4.) A dagger\n5.) A shield\n6.) A claw" BLANK_LINE;
	t.printDelayed("Which will you choose? (type the number)", NORMAL);

	
	do //make sure they enter a value that is actually a choice
	{
		input = t.getIntInput();
	} while (input > 6 && input < 1);

	switch (input) //this will equip the weapon to the player;
	{
	case 1:
		p.equipWeapon("Shitty", "Sword");
		break;
	case 2:
		p.equipWeapon("Shitty", "Bow");
		break;
	case 3:
		p.equipWeapon("Shitty", "Wand");
		break;
	case 4:
		p.equipWeapon("Shitty", "Dagger");
		break;
	case 5:
		p.equipWeapon("Shitty", "Shield");
		break;
	case 6:
		p.equipWeapon("Shitty", "Claw");
		break;
	}

	t.setColor(YELLOW);
	t.printDelayed("After picking up the weapon, you see a training dummy ahead." BLANK_LINE, THOUGHT); t.setColor(WHITE);
	t.printDelayed("Do you want to ", NORMAL); t.setColor(GREEN); t.printDelayed("attack", SLOW); t.setColor(WHITE);
	t.printDelayed(" the dummy, or ", NORMAL); t.setColor(RED); t.printDelayed("run", SLOW); t.setColor(WHITE);
	t.printDelayed(" away screaming?", NORMAL);

	std::cin.ignore();

	do
	{
		strInput = t.getStringInput();
	} while (strInput != "attack" && strInput != "run" && strInput != "Attack" && strInput != "Run");

	if (strInput == "run" || strInput == "Run")
	{
		t.printDelayed(BLANK_LINE "If you're this scared of a dummy, you're not gonna last much longer.", INTENSE);
		system("PAUSE");
		exit(0);
	} else
	{
		Battle dummyFight;
		Enemy dummy;

		if (dummyFight.doBattle(p, dummy.trainingDummy) == 0)
		{
			t.printDelayed("You win!", INTENSE);
		} else
		{
			t.printDelayed("You lost to an enemy that did 0 damage. You deserve this.", INTENSE);
			system("PAUSE");
			exit(0);
		}
	}
}