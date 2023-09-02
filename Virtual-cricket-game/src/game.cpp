#include"game.h"
using namespace std;

Game::Game(){

	playersPerTeam= 4;
	maxBalls = 6;
	totalPlayers = 11;

	players[0] = "Sahil";
	players[1] = "Vasihnav";
	players[2] = "Amritesh";
	players[3] = "Ashish";
	players[4] = "Harshu ";
	players[5] = "Sumer ";
	players[6] = "Tejas";
	players[7] = "Shantanu";
	players[8] = "Ritesh";
	players[9] = "Aryan";
	players[10] = "Yuvraj";

	isFirstInnings = false;
	teamA.name = "Team~A";
	teamB.name = "Team~B";


}

void Game::welcome() {

	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << ")============== CRIC~IN ==============(" << endl;
    cout << ")                                     (" << endl;
    cout << ")   Welcome to Virtual Cricket Game   (" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    cout << endl << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << ")================== How To Play  ==================(" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << ")                                                  (" << endl;
    cout << ") 1. Create 2 teams.                               (" << endl;
    cout << ")    Each Team will have 4 Players.                (" << endl;
    cout << ")    from a given pool of 11 players.              (" << endl;
    cout << ") 2. Name the Teams (Team-A and Team-B).           (" << endl;
    cout << ") 3. Lead the toss to decide                       (" << endl;
    cout << ")    Batting and Bowling Team.                     (" << endl;
    cout << ") 4. Each innings will consist of 6 balls.         (" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

void Game::showAllPlayers() {

	cout << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << ")========== Pool of Players ==========(" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << endl;

	for (int i = 0; i < totalPlayers; i++) {
        cout << "\t\t[" << i << "] " << players[i] << endl;
    }
}

int Game::takeIntegerInput(){

	int n;


	while(!(cin>>n)){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout<<"Invalid input! Please try again with valid input :";
	}
	return n;
}

void Game::selectPlayers(){

	cout << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << ")========== Create Team-A and Team-B ==========(" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

		for(int i=0; i < playersPerTeam;i++){
			//add Team A
			teamASelection:
			cout<<endl<<"Select Player " <<i+1<< "of Team A -";

			int playerIndexTeamA = takeIntegerInput();

			if(playerIndexTeamA<0 || playerIndexTeamA>10 ){
				cout<<endl<<"Please select from the given players"<<endl;
				goto teamASelection;
			}else if(!(validateSelectedPlayer(playerIndexTeamA))){

				cout<<endl<<"Player has been already selected. Please select other player"<<endl;
				goto teamASelection;
			}
			else{

			Player teamAPlayer;
			teamAPlayer.id = playerIndexTeamA;
			teamAPlayer.name = players[playerIndexTeamA];
			teamA.players.push_back(teamAPlayer);
			}

			//add Team B
			teamBSelection:
			cout<<endl<<"Select Player " <<i+1<<" of Team B -";

			int playerIndexTeamB = takeIntegerInput();

			if(playerIndexTeamB<0 || playerIndexTeamB>10 ){
				cout<<endl<<"Please select from the given players"<<endl;
				goto teamBSelection;
					} else if(!(validateSelectedPlayer(playerIndexTeamB))){

						cout<<endl<<"Player has been already selected. Please select other player"<<endl;
						goto teamBSelection;
					}
			else{
			Player teamBPlayer;

			teamBPlayer.id = playerIndexTeamB;
			teamBPlayer.name = players[playerIndexTeamB];
			teamB.players.push_back(teamBPlayer);
						}
		}


}

bool Game::validateSelectedPlayer(int index){

	int n;
	vector<Player>players;

	players = teamA.players;
	n = players.size();
	for(int i=0; i<n;i++){
		if(players[i].id==index){
			return false;
			}
		}
	players = teamB.players;
	n=players.size();
	for(int i =0;i<n;i++){
		if((players[i].id)==index){
			return false;
			}
		}
	return true;
}

void Game::showTeamPlayers(){

	vector<Player> teamAPlayers = teamA.players;
	vector<Player> teamBPlayers = teamB.players;

	cout << endl << endl;
	    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	    cout << ")=======  Team-A  =======(\t\t)=======  Team-B  =======(" << endl;
	    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	    for(int i=0; i<playersPerTeam;i++){

	    	cout<<")\t"<<teamAPlayers[i].name<<"\t("
	    			<<"\t\t"
					<<")\t"<<teamBPlayers[i].name<<"\t ("<<endl;
	    }
	    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
}

void Game::toss() {

	cout << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << ")========== Let's Toss  ==========(" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;

	cout << "Tossing the coin..." << endl << endl;

	usleep(2000000);

	srand(time(NULL));
	int randomValue = rand() % 2;

    switch(randomValue){
		case 0:
			cout << "Team~A won the toss" << endl << endl;
			tossChoice(teamA);
			break;
		case 1:
			cout << "Team~B won the toss" << endl << endl;
			tossChoice(teamB);
			break;
    }
}

void Game::tossChoice(Team tossWinnerTeam){

	cout << "Enter 1 to bat or 2 to bowl first. " << endl
       		 << "1. Bat" << endl
        	 << "2. Bowl " << endl;

	int tossInput = takeIntegerInput();

	cin.ignore(numeric_limits<streamsize>::max(),'\n');

	switch (tossInput) {
		case 1:
			cout << endl << tossWinnerTeam.name << " won the toss and elected to bat first" << endl << endl;

			if (tossWinnerTeam.name.compare("Team~A") == 0) {	 // if Team-A is the toss winner
				battingTeam = &teamA;
				bowlingTeam = &teamB;
			} else {	// else Team-B is the toss winner
				battingTeam = &teamB;
				bowlingTeam = &teamA;
			}

			break;
		case 2:
			cout << endl << tossWinnerTeam.name << " won the toss and choose to bowl first" << endl << endl;

			if (tossWinnerTeam.name.compare("Team~A") == 0) {	// if Team-A is the toss winner
				bowlingTeam = &teamA;
				battingTeam = &teamB;
			} else {	// else Team-B is the toss winner
				bowlingTeam = &teamB;
				battingTeam = &teamA;
			}

			break;
		default:
			cout << endl << "Invalid input. Please try again:" << endl << endl;
			tossChoice(tossWinnerTeam);
			break;
   	}
}

void Game::startFirstInnings(){

	cout<<"\t\t ))) FIRST INNINGS STARTS ((( "<<endl<<endl;
	isFirstInnings = true;
	initializePlayers();

}

void Game::initializePlayers(){
	//choosing bats man and bowler: initialize *batsman, *bowler
	batsman = &battingTeam->players[0];
	bowler = &bowlingTeam->players[0];

	cout<<battingTeam->name<<" - "<<batsman->name<<" is batting "<<endl;
	cout<<bowlingTeam->name<<" - "<<bowler->name<<" is bowling "<<endl;
}

void Game::playInnings(){

	for(int i =0; i<maxBalls;i++){
		cout<<"Press Enter to bowl..."<<endl;
		cin.get();
		cout<<"Bowling..."<<endl;
		bat();

		if(!validateInningsScore()){
			break;
		}
	}

}
void Game::bat(){
	srand(time(NULL));
	int runsScored= rand() % 7 ;

	//Update Batting score
	batsman->runsScored = batsman->runsScored + runsScored;
	battingTeam-> totalRunsScored = battingTeam->totalRunsScored + runsScored;
	batsman->ballsPlayed = batsman->ballsPlayed +1;

	//Update bowling score
	bowler->ballsBowled = bowler->ballsBowled +1;
	bowlingTeam->totalBallsBowled = bowlingTeam->totalBallsBowled +1;
	bowler->runsGiven = bowler->runsGiven + runsScored;


	if(runsScored != 0){//if runScored = 1 to 6
		cout<<endl<<bowler->name<<" to "<<batsman->name<<" "<<runsScored<<" runs!"<<endl<<endl;
		showGameScorecard();

	}else{//else runsScored =0 and the batsman is 'Out'
		cout<<endl<<bowler->name<<" to "<<batsman->name<<" Out!"<<endl<<endl;

		battingTeam->wicketsLost = battingTeam->wicketsLost + 1;
		bowler->wicketsTaken = bowler->wicketsTaken +1;

		showGameScorecard();

		int nextPlayerIndex = battingTeam->wicketsLost;
		batsman = &battingTeam->players[nextPlayerIndex];
		}
	}

bool Game::validateInningsScore(){

	if(isFirstInnings){

		if(battingTeam->wicketsLost==playersPerTeam||bowlingTeam->totalBallsBowled==maxBalls){
			cout<<"\t\t ))) FIRST INNINGS ENDS ((( "<<endl<<endl;
			cout<<battingTeam->name<<" "<<battingTeam->totalRunsScored<<" - "
					<<battingTeam->wicketsLost<<" {"<<bowlingTeam->totalBallsBowled
					<< "}"<<endl;
			cout<<bowlingTeam->name<<" needs " <<battingTeam->totalRunsScored + 1
					<<" runs to win the match " << endl <<endl;
			//int temp = battingTeam->totalRunsScored +1;
			return false;
		}

	}else{// else 2nd Innings

				if(battingTeam->wicketsLost==playersPerTeam||bowlingTeam->totalBallsBowled==maxBalls||battingTeam->totalRunsScored > bowlingTeam->totalRunsScored)
				{
					cout<<"\t\t ))) SECOND INNINGS ENDS ((( "<<endl<<endl;
								cout<<battingTeam->name<<" "<<battingTeam->totalRunsScored<<" - "
										<<battingTeam->wicketsLost<<" {"<<bowlingTeam->totalBallsBowled
										<< "}"<<endl;
								cout<<bowlingTeam->name<<" "<<bowlingTeam->totalRunsScored<<" - "
										<<bowlingTeam->wicketsLost<<" {"<<battingTeam->totalBallsBowled
										<<"}"<<endl;
								return false;

				}

	}
	return true ;
}

void Game::showGameScorecard() {

    cout << "--------------------------------------------------------------------------" << endl;

    cout << "\t" << battingTeam->name << "  " << battingTeam->totalRunsScored << " - "
      << battingTeam->wicketsLost << " (" << bowlingTeam->totalBallsBowled << ") | " << batsman->name
      << " " << batsman->runsScored << " (" << batsman->ballsPlayed << ") \t" << bowler->name << " "
	  << bowler->ballsBowled << " - " << bowler->runsGiven << " - " << bowler->wicketsTaken << "\t" << endl;

    cout << "--------------------------------------------------------------------------" << endl << endl;
}

void Game::startSecondInnings(){

	Team tmp;
	tmp = *battingTeam;
	*battingTeam = *bowlingTeam;
	*bowlingTeam = tmp;

	cout<<"\t\t ))) SECOND INNINGS STARTS ((( "<<endl<<endl;
	isFirstInnings=false;

	initializePlayers();
	playInnings();
}

void Game::winner()
{
    if(bowlingTeam->totalRunsScored>battingTeam->totalRunsScored)
        cout<<endl<<bowlingTeam->name<<" won the match by "<<playersPerTeam-bowlingTeam->wicketsLost<<" wickets!!"<<endl;
    else if(bowlingTeam->totalRunsScored<battingTeam->totalRunsScored)
        cout<<endl<<battingTeam->name<<" won the match by "<<battingTeam->totalRunsScored-bowlingTeam->totalRunsScored<<" runs!!"<<endl;
    else if(bowlingTeam->totalRunsScored == battingTeam->totalRunsScored)
    	cout<<endl<<"Match Tied Between "<<bowlingTeam->name<<" AND "<<battingTeam->name<<endl;
}

void Game::summary()
{
	usleep(2000000);
	cout<<"\n Displaying Match Summary.... \n\n\n ";

    cout<<endl<<endl<<"\t\t\t     || MATCH ENDS ||"<<endl<<endl;
    cout<<battingTeam->name<<" "<<battingTeam->totalRunsScored<<"-"<<battingTeam->wicketsLost<<" ("<<bowlingTeam->totalBallsBowled<<")"<<endl;
    cout<<"================================================="<<endl;
    cout<<"| PLAYER\t\tBATTING\t\tBOWLING\t|"<<endl;
    for(int i=0;i<playersPerTeam;i++)
    {
    cout<<"|-----------------------------------------------|"<<endl;
    cout<<"| ["<<i<<"] "<<battingTeam->players[i].name<<"\t\t"<<battingTeam->players[i].runsScored<<"("<<battingTeam->players[i].ballsPlayed<<")\t\t"<<battingTeam->players[i].ballsBowled<<"-"<<battingTeam->players[i].runsGiven<<"-"<<battingTeam->players[i].wicketsTaken<<"\t|"<<endl;
    }
    cout<<"================================================="<<endl<<endl;
    cout<<bowlingTeam->name<<" "<<bowlingTeam->totalRunsScored<<"-"<<bowlingTeam->wicketsLost<<" ("<<battingTeam->totalBallsBowled<<")"<<endl;
    cout<<"================================================="<<endl;
    cout<<"| PLAYER\t\tBATTING\t\tBOWLING\t|"<<endl;
    for(int i=0;i<playersPerTeam;i++)
    {
    cout<<"|-----------------------------------------------|"<<endl;
    cout<<"| ["<<i<<"] "<<bowlingTeam->players[i].name<<"\t\t"<<bowlingTeam->players[i].runsScored<<"("<<bowlingTeam->players[i].ballsPlayed<<")\t\t"<<bowlingTeam->players[i].ballsBowled<<"-"<<bowlingTeam->players[i].runsGiven<<"-"<<bowlingTeam->players[i].wicketsTaken<<"\t|"<<endl;
    }
    cout<<"================================================="<<endl;
}




