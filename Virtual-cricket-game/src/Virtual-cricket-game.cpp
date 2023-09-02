
#include"game.h"
using namespace std;

int main() {
	Game game;
	game.welcome();

	cout<<"\nPress Enter to Continue";
	cin.get();

	game.showAllPlayers();

	cout<<"\nPress Enter to Continue";
	cin.get();

	game.selectPlayers();
	game.showTeamPlayers();

	cout<<"\nPress Enter to Toss";
	cin.get();

	cin.ignore(numeric_limits<streamsize>::max(),'\n');

	cout<<endl;
	    cout<<"Starting the toss..."<<endl;

	    usleep(2000000);

	game.toss();

	game.startFirstInnings();

	game.playInnings();

	game.startSecondInnings();

	game.winner();

	game.summary();

	usleep(2000000);
	cout<<"\nPress Enter to Exit";
		cin.get();

	return 0;
}
