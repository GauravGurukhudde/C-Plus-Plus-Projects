#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<limits>
#include<string>
#include<unistd.h>
#include"team.h" //<string> <vector> "player.h"

class Game{

public:
	Game();
	int playersPerTeam;
	int maxBalls;
	int totalPlayers;
	std::string players[11];



	bool isFirstInnings;
	Team teamA,teamB;
	Team *battingTeam, *bowlingTeam;
	Player *batsman, *bowler;

	void welcome();
	void showAllPlayers();
	int takeIntegerInput();
	void selectPlayers();
	bool validateSelectedPlayer(int);
	void showTeamPlayers();
	void toss();
	void tossChoice(Team);
	void startFirstInnings();
	void initializePlayers();
	void playInnings();
	void bat();
	bool validateInningsScore();
	void showGameScorecard();
	void startSecondInnings();
	void winner();
	void summary();


};
