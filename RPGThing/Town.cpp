#include "Town.h"
#include "Text.h"
#include "Storyline.h"
#include "Items.h"
#include "Caves.h"

#include <string>

#include "portability.h"

Town::Town()
{
	visits = 0;
}

//player is passed by reference just incase you get any items that directly modify your stats.
void Town::visitTown(Player &p)
{

}

/*
	player is passed by reference just incase you get any items that directly modify your stats.

	Also, YAY some decisions will be made that will finally actually permanently change your game
*/
void Town::townFirstVisit(Player &p)
{
	std::string input = "";
	Text t;
  
	clearConsole();
	visits++; //you have now visited the town once
  
	std::cout << SPACER;

	t.setColor(YELLOW);
	t.printDelayed("You wake up.", SLOW); t.setColor(WHITE);
		t.enterPause();
	t.printDelayed("\nWhen you open your eyes, you see multiple empty beds in what seems to be the room of a castle.", THOUGHT);
		t.enterPause(); //press enter to continue! or any key really

	t.printDelayed("You look to your right and notice there is a girl near your bed, staring at you with a look of bewilderment.", THOUGHT);
		t.enterPause();

	t.printDelayed("\n\"Oh, hey,\" you say, \"Uh... why are you staring at me?\"", NORMAL);
		t.enterPause();

   t.setColor(RED);
	t.printDelayed("\n\"I was NOT staring at you!,\"", INTENSE);
   t.setColor(WHITE);
    t.printDelayed(" the girl says, and immediately runs off. She seemed to blush as she said it.", NORMAL);
		t.enterPause();

	t.printDelayed("\n\"Well, that was strange,\" you think, \"I think I will leave this room and see where the hell I am.\"", THOUGHT);
		t.enterPause();
		t.dotPause(2);

	t.printDelayed("You leave the room, and walk through a hall. It's decorated with godly symbols.\n", THOUGHT);
		t.dotPause(2);

	t.printDelayed("At the end of the hall there is a door. You open it and find yourself in the square of a town.", THOUGHT);
		t.enterPause();

	t.printDelayed("All around you, people are whispering. You can make out one word, however, as you hear it the most.\n\n It is 'angelic'.", THOUGHT);
		t.enterPause();

	mapChoice(p); //does the map choice process. You wil either get a map and an acquaintance, or an amulet. Or nothing if you're dumb.

	Caves c;
	c.enterCaves(p);
}

void Town::mapChoice(Player &p)
{
	std::string input = "";
	Text t;
	t.printDelayed("\nOne of them comes up to you.\n", NORMAL);
	t.printDelayed("\"Hello, my name is ", NORMAL);
	t.setColor(GREEN);
	t.printDelayed("Hector", NORMAL); t.setColor(WHITE);
	t.printDelayed(",\" the man says. \n", NORMAL);
	t.printDelayed("He procedes to offer you a map of the surrouding region.\n\n", NORMAL);
	t.printDelayed("Do you ", NORMAL); t.setColor(GREEN);
	t.printDelayed("take", SLOW); t.setColor(WHITE);
	t.printDelayed(" or ", NORMAL); t.setColor(RED);
	t.printDelayed("refuse", SLOW); t.setColor(WHITE);
	t.printDelayed(" the map?", NORMAL);

	do
	{
		input = t.getStringInput();
	} while (input != "take" && input != "Take" && input != "Refuse" && input != "refuse");

	if (input == "take" || input == "Take")
	{
		t.printDelayed("He hands you the map.", NORMAL);
		t.enterPause();
		p.hasMap = true; //you now have a map! nice!

		printMap(); //pls don't even bother looking at this code... its LITERALLY ebola. just know it prints a colored map lol
		t.enterPause();

		t.printDelayed("Hector tells you that based on what he has heard, you probably woke up\n around where the 'O' is in the bottom right corner.", NORMAL);
		t.enterPause();

		t.printDelayed("\n\"Hey seriously, thanks!\" you tell Hector.", NORMAL);
		t.enterPause();

		t.printDelayed("\n\"", NORMAL);
		t.setColor(GREEN);
		t.printDelayed("No problem!", NORMAL); t.setColor(WHITE);
		t.printDelayed("\" Hector says, \"You can visit me anytime! Just type 'visit Hector' when you're in town.\"", NORMAL);
		t.enterPause();

		p.friends["Hector"] = true; //hector is your friend!!! this will make things happen differently later

		t.printDelayed("\"Finally, someone who seems normal.\"", THOUGHT);
		t.printDelayed(" you think.", 31);
		t.enterPause();

		t.printDelayed("\nAfter looking at the map, you decide to head to the caves.", THOUGHT);
	}

	else //it has to be "refuse" || "Refuse". so i can just use else here
	{
		t.printDelayed("\n\"", NORMAL);
		t.setColor(YELLOW);
		t.printDelayed("Oh, well, okay", NORMAL); t.setColor(WHITE);
		t.printDelayed("\". Hector says, and walks off.", NORMAL);
		t.enterPause();

		t.printDelayed("\nAfter he leaves, you see an old woman on the street struggling to pick up boxes.", NORMAL);
		t.enterPause();

		t.printDelayed("Do you want to ", NORMAL); t.setColor(GREEN);
		t.printDelayed("help", SLOW); t.setColor(WHITE);
		t.printDelayed(" or ", NORMAL); t.setColor(RED);
		t.printDelayed("ignore", SLOW); t.setColor(WHITE);
		t.printDelayed(" her?", NORMAL);

		do
		{
			input = t.getStringInput();
		} while (input != "help" && input != "Help" && input != "ignore" && input != "Ignore");

		if (input == "help" || input == "Help")
		{
			t.printDelayed("\nYou help her with the boxes\n", NORMAL);

			t.dotPause(3);
			t.enterPause();

			t.printDelayed("\"", NORMAL); t.setColor(GREEN);
			t.printDelayed("Thank you so much, young man", NORMAL); t.setColor(WHITE);
			t.printDelayed(",\" she says. \"", NORMAL); t.setColor(GREEN);
			t.printDelayed("Here, take this necklace in return", NORMAL); t.setColor(WHITE);
			t.printDelayed(".\"", NORMAL);

			t.enterPause();

			std::cout << std::endl;
			p.equipAmulet("Decent");
			t.enterPause();

			t.printDelayed("\nYou decide to head north of the town and see what you find.\n", THOUGHT);
			t.dotPause(3);
			t.printDelayed("There is a cave system! You begin to explore it." BLANK_LINE, THOUGHT);
		}

		else //must be ignore
		{
			t.printDelayed("\nInstead, you decide to head north of the town and see what you find.\n", THOUGHT);
			t.dotPause(3);
			t.printDelayed("There is a cave system! You begin to explore it." BLANK_LINE, THOUGHT);
		}
	}
}

/*
	I am deeply sorry i made the most unreadable code ever written

	it prints a map that's colored in probably the most retarded way ever.
*/
void Town::printMap()
{
	Text TextT;

	clearConsole();
	TextT.setColor(BLUE);
	std::cout << "################################################################" << std::endl;
	std::cout << "#%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%#" << std::endl;
	std::cout << "#%%%%%%%%%%%%%%%%%%%%%%%%%%"; TextT.setColor(WHITE);std::cout << "^^^^^^^^^^^^"; TextT.setColor(BLUE);
	std::cout << "%%%%%%%%%%%%%%%%%%%%%%%%#" << std::endl;std::cout << "#%%%%%%%%%%%%%%%%%"; TextT.setColor(WHITE);
	std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^"; TextT.setColor(BLUE);std::cout << "%%%%%%%%%%%%%%%%%%%#" << std::endl;std::cout << "#%%%%%%%%%%%"; TextT.setColor(WHITE);
	std::cout << "^^^^^^^^^^^^^^^^";TextT.setColor(GREEN);std::cout << "&&&&&&&&&&"; TextT.setColor(WHITE);std::cout << "^^^^^^^^^^^"; TextT.setColor(BLUE);
	std::cout << "%%%%%%%%%%%%%%#" << std::endl;std::cout << "#%%%%%%%%%%"; TextT.setColor(WHITE);std::cout << "^^^^^^^^^^^^^^^"; TextT.setColor(GREEN);
	std::cout << "&"; TextT.setColor(MAGENTA);std::cout << "***********"; TextT.setColor(GREEN);std::cout << "&"; TextT.setColor(WHITE);
	std::cout << "^^^"; TextT.setColor(GREEN);std::cout << "&&"; TextT.setColor(RED);std::cout << "/////\\"; TextT.setColor(BLUE);
	std::cout << "%%%%%%%%%%%%%#" << std::endl;std::cout << "#%%%%%%%%%%"; TextT.setColor(WHITE);std::cout << "^^^^^"; TextT.setColor(GREEN);
	std::cout << "&&&&&&&&"; TextT.setColor(WHITE);std::cout << "^"; TextT.setColor(GREEN);std::cout << "&"; TextT.setColor(MAGENTA);
	std::cout << "***forest***"; TextT.setColor(GREEN);std::cout << "&"; TextT.setColor(WHITE);std::cout << "^^"; TextT.setColor(GREEN);
	std::cout << "&&"; TextT.setColor(RED);std::cout << "||cave||"; TextT.setColor(GREEN);
	std::cout << "&"; TextT.setColor(BLUE);std::cout << "%%%%%%%%%%%#" << std::endl;
	std::cout << "#%%%%%%%%%"; TextT.setColor(WHITE);std::cout << "^^"; TextT.setColor(GREEN);
	std::cout << "&&&&&&&&&&&&&"; TextT.setColor(WHITE);std::cout << "^"; TextT.setColor(GREEN);
	std::cout << "&"; TextT.setColor(MAGENTA);std::cout << "***********"; TextT.setColor(GREEN);std::cout << "&"; TextT.setColor(WHITE);
	std::cout << "^"; TextT.setColor(GREEN);std::cout << "&&&&&&&&&&&"; TextT.setColor(BLUE);std::cout << "%%%%%%%%%%%%#" << std::endl;
	std::cout << "#%%%%%%%%%"; TextT.setColor(WHITE);std::cout << "^"; TextT.setColor(GREEN);
	std::cout << "&&&&&&&&&&&&&&&"; TextT.setColor(WHITE);std::cout << "^"; TextT.setColor(GREEN);
	std::cout << "&&&&&&&&&&&&"; TextT.setColor(WHITE);std::cout << "^"; TextT.setColor(GREEN);
	std::cout << "&&&&&&&&&&&&"; TextT.setColor(BLUE);std::cout << "%%%%%%%%%%%#" << std::endl;
	std::cout << "#%%%%%%%%"; TextT.setColor(GREEN);std::cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&"; TextT.setColor(WHITE);std::cout << "^"; TextT.setColor(GREEN);
	std::cout << "&"; TextT.setColor(WHITE);std::cout << "|========|"; TextT.setColor(GREEN);std::cout << "&"; TextT.setColor(BLUE);
	std::cout << "%%%%%%%%%%#" << std::endl;std::cout << "#%%%%%%%%"; TextT.setColor(GREEN);std::cout << "&&"; TextT.setColor(WHITE);
	std::cout << "uncharted"; TextT.setColor(GREEN);std::cout << "&&&&&&&&&&&&&&&&&&&&&&"; TextT.setColor(WHITE);std::cout << "|| town ||"; TextT.setColor(GREEN);
	std::cout << "&&"; TextT.setColor(BLUE);std::cout << "%%%%%%%%%#" << std::endl;std::cout << "#%%%%%%%%%"; TextT.setColor(GREEN);
	std::cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&"; TextT.setColor(WHITE);std::cout << "|========|"; TextT.setColor(GREEN);
	std::cout << "&&"; TextT.setColor(BLUE);std::cout << "%%%%%%%%%#" << std::endl;
	std::cout << "#%%%%%%%%%"; TextT.setColor(GREEN);std::cout << "&&&&&&&&&&&&&"; TextT.setColor(BLUE);
	std::cout << "%%%%%%%%%%%%%%"; TextT.setColor(GREEN);std::cout << "&&&&&&&&&&&&&&&"; TextT.setColor(BLUE);
	std::cout << "%%%%%%%%%%%#" << std::endl;std::cout << "#%%%%%%%%%%"; TextT.setColor(GREEN);
	std::cout << "&&&&&&&&"; TextT.setColor(BLUE);std::cout << "%%%%%%%%%%%%%%%%%%%%%%%%"; TextT.setColor(GREEN);std::cout << "&&&&&&&&"; TextT.setColor(BLUE);
	std::cout << "%%%%%%%%%%%%#" << std::endl;std::cout << "#%%%%%%%%%%%"; TextT.setColor(GREEN);std::cout << "&&&&"; TextT.setColor(BLUE);
	std::cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"; TextT.setColor(GREEN);std::cout << "&&"; TextT.setColor(WHITE);std::cout << "O"; TextT.setColor(GREEN);
	std::cout << "&"; TextT.setColor(BLUE);std::cout << "%%%%%%%%%%%%%#" << std::endl;std::cout << "#%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"; TextT.setColor(GREEN);
	std::cout << "&&"; TextT.setColor(BLUE);std::cout << "%%%%%%%%%%%%%%#" << std::endl;
	std::cout << "################################################################" << std::endl; TextT.setColor(WHITE);
}

Town::~Town()
{
}
