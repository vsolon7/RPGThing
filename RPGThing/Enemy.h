#pragma once
#include <vector>

struct Enemy
{
	//damage, armor, attack speed, health, dodge chance, level
	std::vector<int> trainingDummy = { 0, 0, 1, 25, 0, 1 };
	std::vector<int> dummyDemon = { 50, 30, 1, 500, 20, 99 };
	std::vector<int> basicCaveEnemy{ 0, 0, 0, 0, 0, 0 }; //The cave enemies' stats will be based off of your level

	std::vector<std::string> prefixes = { "", "Wimpy", "Weak", "Simple", "Dumb", "Easy", "Nonthreatening", //tier 1
		"Decent", "Plain", "Average", "Acceptable", "Fair", "Reasonable", //tier 2
		"Respectable", "Sizable", "Worthy", "Well-Matched", "Trained", "Skilled", //tier 3
		"Hard", "Difficult", "Strong", "Menacing", "Threatening", "Seething", //tier 4
		"Terrifying", "Deadly", "Insane", "Champion", "Mighty", "Intense", //tier 5
		"Impossible", "God-like", "Immortal", "Subjugating", "Unreal", "Legendary" }; //tier 6

	std::vector<std::string> suffixes = { "", " of speed", " of avoidance", " of protection" };

	std::map<int, std::vector<double>> prefixStats;
	std::map<int, std::vector<int>> suffixStats;

	Enemy()
	{
		//tier 1
		prefixStats[0] = { 0, 0, 0, 0, 0, 0 };
		prefixStats[1] = { 0.7, 1, 1, 0.8, 1, 1 };
		prefixStats[2] = { 0.6, 1, 1, 0.9, 1, 1 };
		prefixStats[3] = { 0.8, 1, 1, 0.9, 1, 1 };
		prefixStats[4] = { 0.6, 1, 1, 1.0, 1, 1 };
		prefixStats[5] = { 0.6, 1, 1, 0.8, 1, 1 };
		prefixStats[6] = { 0.7, 1, 1, 0.8, 1, 1 };
		//tier 2
		prefixStats[7] = { 0.9, 1, 1, 1.0, 1, 1 };
		prefixStats[8] = { 1.0, 1, 1, 1.0, 1, 1 };
		prefixStats[9] = { 1.0, 1, 1, 1.0, 1, 1 };
		prefixStats[10] = { 1.1, 1, 1, 1.0, 1, 1 };
		prefixStats[11] = { 1.1, 1, 1, 1.0, 1, 1 };
		prefixStats[12] = { 1.1, 1, 1, 1.0, 1, 1 };
		//tier 3
		prefixStats[13] = { 1.3, 1, 1, 1.5, 1, 1.5 };
		prefixStats[14] = { 1.0, 1, 1, 1.8, 1, 1.5 };
		prefixStats[15] = { 1.4, 1, 1, 1.4, 1, 1.5 };
		prefixStats[16] = { 1.3, 1, 1, 1.5, 1, 1.5 };
		prefixStats[17] = { 1.1, 1, 1, 1.1, 1, 1.5 };
		prefixStats[18] = { 1.7, 1, 1, 1.0, 1, 1.5 };
		//tier 4
		prefixStats[19] = { 2.0, 1, 1, 3.0, 1, 2.5 };
		prefixStats[20] = { 1.9, 1, 1, 2.5, 1, 2.5 };
		prefixStats[21] = { 2.5, 1, 1, 2.2, 1, 2.5 };
		prefixStats[22] = { 2.3, 1, 1, 2.2, 1, 2.5 };
		prefixStats[23] = { 2.3, 1, 1, 2.2, 1, 2.5 };
		prefixStats[24] = { 3.1, 1, 1, 1.8, 1, 2.5 };
		//tier 5
		prefixStats[25] = { 3.0, 1, 1, 5.0, 1, 4 };
		prefixStats[26] = { 4.0, 1, 1, 3.5, 1, 4 };
		prefixStats[27] = { 3.5, 1, 1, 3.8, 1, 4 };
		prefixStats[28] = { 3.5, 1, 1, 5.0, 1, 4 };
		prefixStats[29] = { 4.5, 1, 1, 3.0, 1, 4 };
		prefixStats[30] = { 3.1, 1, 1, 4.0, 1, 4 };
		//tier 6
		prefixStats[31] = { 5.0, 1, 1, 9.0, 1, 5 };
		prefixStats[32] = { 6.0, 1, 1, 10.0, 1, 5 };
		prefixStats[33] = { 3.5, 1, 1, 12.0, 1, 5 };
		prefixStats[34] = { 7.0, 1, 1, 2.0, 1, 5 };
		prefixStats[35] = { 4.5, 1, 1, 7.0, 1, 5 };
		prefixStats[36] = { 6.0, 1, 1, 6.0, 1, 5 };
		//suffix stats
		suffixStats[1] = { 1, 1, 0, 1, 4, 0 };
		suffixStats[2] = { 1, 1, 30, 1, 1, 0 };
		suffixStats[3] = { 1, 1, 1, 5, 1, 0 };
	}

	std::string getPrefix(int r)
	{
		return prefixes.at(r);
	}
};