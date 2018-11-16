
#include "stdafx.h"
#include "Game.h"
using namespace std;


int main()
{
	cout << "Write \"Start\" if u ready to play!" << endl;
	string readoutter;
	cin >> readoutter;
	system("cls");

	while (readoutter != "End") {// uj jatek kezdese
		if (readoutter != "Start")
			break;

		//jatekmag inicializalasa
		Game newGame = Game();
		//elso leosztas
		newGame.flop();
		//felhasznaloi input
		cout << "Your options: Hit/Stand/Surr" << endl;
		string readinner;
		cin >> readinner;
		system("cls");

		while (readinner != "Surr") {//input feldolgozas

			int points = 0;
			if (readinner == "Hit") {
				points = newGame.hit();
			}
			if (points > 21) {
				cout << "You Lost with Bust" << endl;
				break;
			}
			if (readinner == "Stand" || points == 21) {
				newGame.dealersRound();
				newGame.calculateWinner();
				break;
			}
			//uj input
			cout << "Your options: Hit/Stand/Surr" << endl;
			cin >> readinner;
			system("cls");
		}

		//egy jatekmenet befejezodott
		cout << "Your options: Start/End" << endl;
		cin >> readoutter;
		system("cls");
	}

	return 0;
}

