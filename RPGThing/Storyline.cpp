#include "Storyline.h"
#include "Text.h"
#include "Player.h"
#include "Races.h"
#include "Classes.h"
#include "Enemy.h"
#include "Items.h"
#include "Battle.h"
#include "Town.h"

#include <vector>
#include <iostream>
#include <sstream>
#include <map>
#include <time.h>
#include <random>

static Text t;
static Town mainTown; //I created the town here to always keep it one town, instead of making lots of new ones.
					  //There is only one town that exists after all.


static std::mt19937 randEngine(time(0)); //a mersenne twister - the random engine type.

Storyline::Storyline()
{
	Player p;
	introduction();
}

void Storyline::introduction() //TODO: more story
{
	p.instance = START;
	printCharacterSelection();
	theStoryIntro();
}

void Storyline::printCharacterSelection()
{
	Improvisation h; //check Races.h for these
	Grace e;
	Battlewise d;
	Shaper de;
	Outlasting a;

	std::cout << SPACER << std::endl;
	std::cout << "Welcome to " << GAME_NAME << ". Please pick your perk (type the number):" BLANK_LINE;
	std::cout << SPACER << std::endl;

	std::cout << "1.) Improvisation.\n" << "----------\n";
	std::cout << h.abilityOne << h.abilityTwo << BLANK_LINE;

	std::cout << "2.) Grace.\n" << "----------\n";
	std::cout << e.abilityOne << e.abilityTwo << BLANK_LINE;

	std::cout << "3.) Battlewise.\n" << "----------\n";
	std::cout << d.abilityOne << d.abilityTwo << BLANK_LINE;

	std::cout << "4.) Shaper.\n" << "----------\n";
	std::cout << de.abilityOne << de.abilityTwo << BLANK_LINE;

	std::cout << "5.) Outlasting\n" << "----------\n";
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

	std::cout << "\n" SPACER << "\n";

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

	clearConsole();
	std::cin.ignore();
	std::cout << SPACER "\nYou are a(n) " << classNumberToString(p.getClass()) << " with the perk " << adaptionNumberToString(p.getRace()) << "!" BLANK_LINE << SPACER << "\n";

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
		std::cout << "As a " << classNumberToString(p.getClass()) << " your minimum required stats are: \n" <<
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

		clearConsole();
	} while (Cinput == "r" || Cinput == "R");

	p.setBaseStats(Str, Agi, Int);
}

std::string Storyline::adaptionNumberToString(int c)
{
	std::map<int, std::string> adaptionType; //map of adaption's number and their string name

	adaptionType[1] = "Improvisation";
	adaptionType[2] = "Grace";
	adaptionType[3] = "Battlewise";
	adaptionType[4] = "Shaper";
	adaptionType[5] = "Outlasting";

	return adaptionType[c]; //returns the string name of the adaption realitive to their number
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

void Storyline::theStoryIntro()
{
	int input;
	std::string strInput;

	t.printDelayed("You wake up on a beautiful strand (that's a beach shore), dazed and confused.\n", THOUGHT);
	t.printDelayed("You look around and notice an ivory bench with weapons all over the top." BLANK_LINE, THOUGHT);
	t.printDelayed("You shakily stand up, and see the following weapons on the bench: " BLANK_LINE, THOUGHT); t.setColor(WHITE);
	std::cout << "1.) A sword\n2.) A bow\n3.) A wand\n4.) A dagger\n5.) A shield\n6.) A claw" BLANK_LINE;
	t.printDelayed("Which will you choose? (type the number)", NORMAL);

	//make sure they enter a value that is actually a choice
	do
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
		pauseConsole();
		exit(0);
	} else
	{
		Battle fight;
		Enemy enemyList;

		std::string fade = "The world fades away . . . . ."; //for later, the switch gave me an error :(

		//fights the training dummy
		switch (fight.doBattle(p, enemyList.trainingDummy))
		{
		case 0:
			t.setColor(GREEN);
			t.printDelayed("You win!" BLANK_LINE, INTENSE);
			t.dotPause(3);

			t.setColor(RED);
			t.printDelayed("Suddenly, from the chest of the dummy, a demon bursts out!" BLANK_LINE, INTENSE);
			t.setColor(RED);
			t.printDelayed("It has the body of a spider, with tentacles for legs and its face is a grotesqe fusion of human faces." BLANK_LINE, INTENSE);
			t.printDelayed("It whispers something with its chilling voice and your body begins to attack it, against your will!\n", INTENSE);
			t.setColor(WHITE);
			pauseConsole();

			//fights the demon from the dummy
			switch (fight.doBattle(p, enemyList.dummyDemon))
			{
			case 1:
				t.setColor(YELLOW);
				t.printDelayed("The demon has defeated you..." BLANK_LINE, SLOW);


				for (unsigned int i = 0; i < fade.length(); i++) //prints this fast at first, then slows down as the message prints. for when you die from the dummy
				{
					std::cout << fade[i];
					Sleep((0.6) * (i * i));
				}

				std::cout << BLANK_LINE;

				break;
			case 0:
				std::cout << "It is impossible to see this message, or you got impossibly lucky with dodge. Either way, game over. Play the lottery." BLANK_LINE;
				pauseConsole();
				exit(0);
				break;
			}

			break;
		case 1:
			t.setColor(RED);
			t.printDelayed("You lost to an enemy that did 0 damage. You deserve this.", INTENSE);
			pauseConsole();
			exit(0);
			break;
		}

		mainTown.townFirstVisit(p); //I just called first visit instead of the normal function to avoid checking the # of town visits EVERY time.

	}
}

Storyline::~Storyline()
{
}
