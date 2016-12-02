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

	t.printDelayed("You wake up."); 

	/*
		Need to think about the lore and decide what time period and where they will wake up.

		I think itll be a little tough to plan out all the lore in advance.
		There may be loopholes in it. Hell, even harry potter had loopholes so i guess no big deal
	*/
}

Town::~Town()
{
}
