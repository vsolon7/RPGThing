#include "Battle.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>
#include <random>
#include <time.h>
#include <cmath>
#include <iostream>
#include <Windows.h>

Text t;
std::mt19937 randEngine(time(NULL));

Battle::Battle()
{
}



//will check if player crit based on their crit chance
bool Battle::critRoll(float cChance)
{
	if (cChance < 0.01)
		return false;

	std::uniform_int_distribution<int> rollCrit(0 , 100);

	bool crit = rollCrit(randEngine) < (cChance * 100);

	return crit;
} 

//rolls enemy or player's damage. they can hit from 50% to 150% of their base damage
int Battle::dmgRoll(int avgD)
{
	std::uniform_int_distribution<int> rollDamage((avgD * .50), (avgD * 1.5));

	int dmgBeforeArmor = rollDamage(randEngine); //rolls damage, from 50% of your base damage to 150%

	return dmgBeforeArmor;
}

//will check if player dodged an attack based on their evasion chance
bool Battle::dodgeRoll(float dChance)
{
	if (dChance < 0.01)
		return false;

	std::uniform_int_distribution<int> rollDodge(0, 100);

	bool dodge = rollDodge(randEngine) < (dChance * 100); //if the randEngine rolls less than the dodge chance, you dodged!

	return dodge;
}

/*
	This is the main FRAMEWORK of the battle. The player and enemies attacking get their own functions.
	As of right now, enemies only do phys damage. No magic.
*/
int Battle::doBattle(Player p, std::vector<int> e)
{
	char temp;
	int pHit;
	int eHit;
	int eHP = e.at(3);
	int currPHP = p.maxHP;
	int lifeRegen = (p.lifeRegen * p.lifeRegenMult);
	static bool canDodgeDeath = (p.getRace() == 2); //for the elf. pls don't be too OP. lets him dodge death.

	while (eHP > 0 && currPHP > 0)
	{
		eHit = enemyAttack(p, e); //enemy attacks player! :0
		currPHP -= eHit;

		if (currPHP < p.maxHP) //regens player's life with their HP regen!
			currPHP += lifeRegen;

		//elf's death dodge
		if (currPHP < 0 && canDodgeDeath)
		{
			canDodgeDeath = false; //dodged death, make it false now.
			currPHP = 1;
		} else if (currPHP < 0 && !canDodgeDeath)
		{
			currPHP = 0;
			std::cout << "You now have: "; t.setColor(GREEN);
			std::cout << currPHP << "/" << p.maxHP << " health.\n"; t.setColor(WHITE);

			//tell us enemy HP left
			std::cout << "The enemy now has: "; t.setColor(GREEN);
			std::cout << eHP << "/" << e.at(3) << " health." BLANK_LINE; t.setColor(WHITE);
			std::cout << SPACER;
			system("PAUSE");
			system("cls");
			return 1; //if this wasn't here, they would always get an extra hit. With lifesteal, they will literally never die.
		}

		//tell us player HP left
		std::cout << "You now have: "; t.setColor(GREEN); 
		std::cout << currPHP << "/" << p.maxHP << " health.\n"; t.setColor(WHITE);

		//tell us enemy HP left
		std::cout << "The enemy now has: "; t.setColor(GREEN); 
		std::cout << eHP << "/" << e.at(3) << " health." BLANK_LINE; t.setColor(WHITE);
		std::cout << SPACER;
		system("PAUSE");
		system("cls");


		pHit = playerAttack(p, e); //player attacks! :0
		eHP -= pHit;

		//tell us player HP left
		std::cout << "You now have: "; t.setColor(GREEN); 
		std::cout << currPHP << "/" << p.maxHP << " health." BLANK_LINE; t.setColor(WHITE);

		//tells us enemy HP left
		std::cout << "The enemy now has: "; t.setColor(GREEN);
		std::cout << eHP << "/" << e.at(3) << " health.\n"; t.setColor(WHITE);
		std::cout << SPACER;
		system("PAUSE");
		system("cls");
	}
	if (currPHP > 0) //0 if player lived
		return 0;
	else if (currPHP <= 0) //1 if player died :(
		return 1;
}

int Battle::enemyAttack(Player p, std::vector<int> e)
{
	int totalDamage = 0;
	int enemyAvgD = e.at(0);
	int enemyAS = e.at(2);
	int eHit; //hit before reductions
	int eAHit; //hit after player's phys damage reduction
	float pDodgeChance = p.evasionChance + (((float)sqrt(p.getStats().at(2)) * p.elfStatMult) / 50); //evasion chance is your base dodgechance + sqrt of agility / 50.
	float pPhysReduction = ((1 - ((0.01 * (p.armor * p.dwarfArmorIncrease)) / (1 + (0.01 * abs(p.armor * p.dwarfArmorIncrease))))) + p.physResistance); //phys damage reduction

	int eAttPT = ((int)(sqrt(enemyAS / 3))); //enemy attacks per turn is the sqrt of their attack speed divided by 3
	if (eAttPT < 1) //can't attack less than once per turn
		eAttPT = 1;

	std::cout << SPACER "The enemy attacks you for: \n";
	for (unsigned int c = 0; c < eAttPT; c++)
	{
		if (dodgeRoll(pDodgeChance)) //if player dodges, miss
		{
			t.setColor(YELLOW);
			std::cout << "*miss*";
			t.setColor(WHITE);
			eAHit = 0;
		}
		else //else, hit 
		{
			eHit = dmgRoll(enemyAvgD);
			eAHit = eHit * pPhysReduction; //takes the enemies hit and applies the players phys damage reduction

			t.setColor(RED);
			std::cout << eAHit; t.setColor(WHITE);

		}
		Sleep(50);
		if (c < eAttPT - 1)
			std::cout << " + "; //if its last attack, don't print a plus sign

		totalDamage += eAHit;
	}
		std::cout << " damage. \n"; 
		t.setColor(RED);
		std::cout << "(TOTAL: " << totalDamage << ")\n"; t.setColor(WHITE);
		std::cout << SPACER;

	return totalDamage;
}

int Battle::playerAttack(Player p, std::vector<int> e)
{ 
	system("cls");
	int totalDamage = 0;
	int pAvgD = (((p.baseDamage + p.addedDamage) * p.physIncrease) * p.dwarfMeleeIncrease);
	int pAS = (p.attackSpeed + (sqrt(p.getStats().at(2)) * p.elfStatMult));
	int pHit; //hit before reductions
	int pAHit; //hit after enemies phys damage reduction
	float eDodgeChance = (e.at(4) / 100); //enemy evasion chance, defined in "Enemy.h"
	float ePhysReduction = (1 - ((0.01 * e.at(1) / (1 + (0.01 * abs(e.at(1))))))); //enemy phys damage reduction based on armor defined in "Enemy.h"

	int pAttPT = ((int) (sqrt(pAS / 3))); //player attacks per turn is the sqrt of their attack speed divided by 3
	if (pAttPT < 1) //can't attack less than once per turn
		pAttPT = 1;

	std::cout << SPACER "You attack the enemy for: \n";

	for (unsigned int c = 0; c < pAttPT; c++)
	{
		if (dodgeRoll(eDodgeChance)) //if enemy dodges, miss
		{
			t.setColor(YELLOW);
			std::cout << "*miss*";
			t.setColor(WHITE);
			pAHit = 0;
		}

		else //else, hit
		{
			bool lastHitCrit = false;
			if (critRoll(p.critChance)) //if you crit, multiply your damge by your crit multi!!!
			{
				pHit = (int)(dmgRoll(pAvgD) * (p.critMulti * p.critMultIncrease));
				lastHitCrit = true;
			}
			else
			{
				pHit = dmgRoll(pAvgD);
			}

			pAHit = pHit * ePhysReduction; //takes the players hit and applies the enemies phys damage reduction
			switch (lastHitCrit) //if you crit, it will chance the color to magenta!
			{
			case true:
				t.setColor(MAGENTA);
				lastHitCrit = false;
				break;
			case false:
				t.setColor(RED);
				break;
			}

			std::cout << pAHit; t.setColor(WHITE);
		}

		Sleep(50);
		if (c < pAttPT - 1)
			std::cout << " + "; //if its last attack, don't print a plus sign

		totalDamage += pAHit;
	}

		std::cout << " damage. \n";
		t.setColor(RED);
		std::cout << "(TOTAL: " << totalDamage << ")\n"; t.setColor(WHITE);
		std::cout << SPACER;

	return totalDamage;
}



Battle::~Battle()
{
}
