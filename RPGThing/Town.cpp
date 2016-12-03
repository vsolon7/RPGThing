#include "Town.h"
#include "Text.h"
#include "Storyline.h"
#include "Items.h"

#include <Windows.h>

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
	Text t;
	system("cls");
	std::cout << SPACER;

	t.printDelayed("You wake up.", THOUGHT);
	std::cout << BLANK_LINE;
	t.printDelayed("When you open your eyes, you see multiple empty beds in what seems to be the room of a castle.", THOUGHT);
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

	t.printDelayed("You leave the room, and walk through a hall. It's decorated with angelic symbols.\n", THOUGHT);
		t.dotPause(2);

	t.printDelayed("At the end of the hall there is a door. You open it and find yourself in the square of a town.", THOUGHT);
		t.enterPause();

	t.printDelayed("All around you, people are whispering. You can make out one word, however, as you hear it the most.\n\n It is 'angelic'.", THOUGHT);
		t.enterPause();
}

Town::~Town()
{
}
