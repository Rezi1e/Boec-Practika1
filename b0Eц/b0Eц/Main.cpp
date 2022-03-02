#include <iostream>
#include <ctime>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include "Header.h"
using namespace std;
#pragma warning(disable : 4996)


int main() {
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); 
	int game = 1, dif, k = 0, cheat = 0, mode, end;
	Players player, bot, player1, player2;
	Introduction();
	do {
		mode = ChoiceMode();

		if (mode) {

			dif = ChoiceDifficulty(player, bot, player1, player2, mode);
			CreatePlayer(player);
			if (NameCheat(player)) player.HP = 99999999;
			system("cls");
			if (!dif) {
				dif++;
				while (game) {
					Level(dif);
					char a = getch();
					system("cls");
					cout << endl << endl << endl << endl;
					Fight();

					while (game) {
						HodPlayer(player, bot, cheat);
						if (k < 1) {
							if (BlockCheat(player)) {
								cheat = 1;
								k++;
							}
						}
						HodBot(bot, player, dif);
						if (player.HP <= 0 || bot.HP <= 0) break;
					}

					if (dif == 4) {
						system("cls");
						if (player.HP) Winner();
						else Lose();
						break;
					}

					if (!NextLevel(player, bot))
						break;

					if (dif >= 1) {
						dif++;
						if (NameCheat(player)) player.HP = 99999999;
						player.stamina = 100;
						CreateBot(bot, dif);

					}
				}
			}
			else {
				Level(dif);
				char a = getch();
				system("cls");
				cout << endl << endl << endl << endl;
				Fight();

				while (game) {
					HodPlayer(player, bot, cheat);
					if (k < 1) {
						if (BlockCheat(player)) {
							cheat = 1;
							k++;
						}
					}
					HodBot(bot, player, dif);
					if (player.HP <= 0 || bot.HP <= 0) break;
				}
				NextLevel(player, bot);

			}
		}
		else {
			dif = ChoiceDifficulty(player, bot, player1, player2, mode);
			system("cls");

			cout << endl;
			Controls();
			while (game) {
				Hod2Players(player1, player2, dif);
				if (player1.HP <= 0 || player2.HP <= 0) break;
			}
			Win2(player1, player2);
		}


		cout << "Если вы желаете начать игру заново - Нажмите любую клавишу" << endl <<
			"Если желаете закрыть программу - Нажмите '0'" << endl;
		end = getch();
		system("cls");
	} while (end != 48);
	return 1;
}