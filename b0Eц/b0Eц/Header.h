#pragma once
using namespace std;

struct Players {
	string name;
	int HP = 0;
	int PartOfBodyAndDamage = 0;
	int udar = 0;
	int stamina = 0;
	int count = 0;
};						

int InputInt(); 
void Introduction();
int ChoiceMode();
int ChoiceDifficulty(Players& player, Players& bot, Players& player1, Players& player2, int mode);
void CreatePlayer(Players& player);
void CreateBot(Players& bot, int ParamDif);
void CreatePlayers(Players& player1, Players& player2, int ParamDif);
void Fight();
void Win2(Players& player1, Players& player2);
void Winner();
void Lose();
void Level(int dif);
int NextLevel(Players& player, Players& bot);
int NameCheat(Players& player);
int BlockCheat(Players& player);
void Controls();
void HodPlayer(Players& player, Players& bot, int cheat);
void HodBot(Players& bot, Players& player, int dif);
void Hod2Players(Players& player1, Players& player2, int dif);