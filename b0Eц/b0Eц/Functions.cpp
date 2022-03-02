#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <windows.h>
#include <conio.h>
#include "Header.h"
using namespace std;
#pragma warning(disable : 4996)

int InputInt() {
	int doub;
	while (true) {
		if (scanf_s("%d", &doub) == false || getchar() != '\n') {
			while (getchar() != '\n');
			cout << "Неверный ввод" << endl;
		}
		else {
			return doub;
		}
	}
}


void Introduction() {
	setlocale(LC_ALL, "ru");

	
	cout << endl << "Добро пожаловать в консольную игру 'Боец' " << endl <<
		"Если вы хотите ознакомиться с правилами игры - нажмите 'Пробел' " << endl <<
		"Если желаете сразу начать игру - нажмите любую другую клавишу" << endl;
	char a = getch();
	if (a == 32) {
		string s;
		ifstream f("pravila1.txt");
		while (!f.eof())
		{
			getline(f, s);
			cout << s << endl;
		}
		f.close();
		cout << "Нажмите любую клавишу чтобы продолжить" << endl;
		a = getch();
		system("cls");
	}
	system("cls");
}


int ChoiceMode() {
	cout << endl << "Выберите режим игры: 1 - Один игрок  2 - Два игрока" << endl;
	int mode;
	do {
		mode = getch();
		if (mode != 49 && mode != 50) cout << "Повторите ввод" << endl;
	} while (mode != 49 && mode != 50);
	if (mode == 49)
		return 1;
	else
		return 0;
}


int ChoiceDifficulty(Players& player, Players& bot, Players& player1, Players& player2, int mode) {
	int dificulty, ParamDif;
	if (mode) {
		cout << "Выберете режим игры: 1 - Один уровень (на выбор) 2 - Возрастающая сложность" << endl;

		do {
			dificulty = getch();
			if (dificulty != 49 && dificulty != 50) cout << "Повторите ввод" << endl;
		} while (dificulty != 49 && dificulty != 50);

		switch (dificulty) {
		case 49:
			dificulty = 1;
			break;
		case 50:
			dificulty = 2;
			break;
		}


		switch (dificulty) {

		case 1:
			cout << "Выберете cложность: 1 - Легкая 2 - Средняя 3 - Тяжелая 4 - Hard" << endl;

			do {
				dificulty = getch();
				if (dificulty != 49 && dificulty != 50 && dificulty != 51 && dificulty != 52) cout << "Повторите ввод" << endl;
			} while (dificulty != 49 && dificulty != 50 && dificulty != 51 && dificulty != 52);

			switch (dificulty) {
			case 49:
				dificulty = 1;
				break;
			case 50:
				dificulty = 2;
				break;
			case 51:
				dificulty = 3;
				break;
			case 52:
				dificulty = 4;
				break;
			}

			switch (dificulty) {
			case 1:
				ParamDif = 1;
				CreateBot(bot, ParamDif);
				break;

			case 2:
				ParamDif = 2;
				CreateBot(bot, ParamDif);
				break;

			case 3:
				ParamDif = 3;
				CreateBot(bot, ParamDif);
				break;

			case 4:
				ParamDif = 4;
				CreateBot(bot, ParamDif);
				break;
			}

			break;
		case 2:
			ParamDif = 1;
			CreateBot(bot, ParamDif);
			return 0;
		}
		
	}

	else {
		cout << "Выберете характеристики, которые будут применены к каждому из игроков:" << endl
			<< "1 - У Вас по 15 hp" << endl
			<< "2 - У Вас по 20 hp" << endl
			<< "3 - У Вас по 25 hp и пониженный шанс на промах" << endl <<
			"4 - У вас по 30 hp, пониженный шанс на промах, повышенный шанс на критическое попадание и бесконечная выносливость" << endl;

		do {
			dificulty = getch();
			if (dificulty != 49 && dificulty != 50 && dificulty != 51 && dificulty != 52) cout << "Повторите ввод" << endl;
		} while (dificulty != 49 && dificulty != 50 && dificulty != 51 && dificulty != 52);

		switch (dificulty) {
		case 49:
			dificulty = 1;
			break;
		case 50:
			dificulty = 2;
			break;
		case 51:
			dificulty = 3;
			break;
		case 52:
			dificulty = 4;
			break;
		}

		switch (dificulty) {
		case 1:
			ParamDif = 1;
			CreatePlayers(player1, player2, ParamDif);
			break;

		case 2:
			ParamDif = 2;
			CreatePlayers(player1, player2, ParamDif);
			break;

		case 3:
			ParamDif = 3;
			CreatePlayers(player1, player2, ParamDif);
			break;

		case 4:
			ParamDif = 4;
			CreatePlayers(player1, player2, ParamDif);
			break;
		}


	}

	return dificulty;
}


void CreatePlayer(Players& player) {

	cout << "Введите своё имя ";
	cin >> player.name;
	player.HP = 15;
	player.stamina = 100;
}


void CreateBot(Players& bot, int ParamDif) {

	switch (ParamDif) {
	case 1:
		bot.HP = 10;
		bot.stamina = 100;
		break;
	case 2:
		bot.HP = 20;
		bot.stamina = 100;
		break;
	case 3:
		bot.HP = 25;
		bot.stamina = 100;
		break;
	case 4:
		bot.HP = 30;
		bot.stamina = 10000;
		break;
		
	default:
		cout << "Произошла ошибка" << endl;
	}
}


void CreatePlayers(Players& player1, Players& player2, int ParamDif) {
	cout << "Введите имя первого игрока ";
	cin >> player1.name;
	cout << "Введите имя второго игрока ";
	cin >> player2.name;
	switch (ParamDif) {
	case 1:
		player1.HP = 15;
		player1.stamina = 100;
		player2.HP = 15;
		player2.stamina = 100;
		break;
	case 2:
		player1.HP = 20;
		player1.stamina = 100;
		player2.HP = 20;
		player2.stamina = 100;
		break;
	case 3:
		player1.HP = 25;
		player1.stamina = 100;
		player2.HP = 25;
		player2.stamina = 100;
		break;
	case 4:
		player1.HP = 30;
		player1.stamina = 999999999;
		player2.HP = 30;
		player2.stamina = 999999999;
		break;
	}
}


void Fight() {

	string s;
	ifstream f1("boec2.txt");
	while (!f1.eof())
	{
		getline(f1, s);
		cout << s << endl;
	}
	f1.close();

}


void Win() {

	string s;
	ifstream win("победа.txt");
	while (!win.eof())
	{
		getline(win, s);
		cout << s << endl;
	}
	win.close();

}


void Win2(Players& player1, Players& player2) {
	system("cls");
	if (player1.HP <= 0)
		cout << "Победил игрок под номером 2: " << player2.name << endl;
	else
		cout << "Победил игрок под номером 1: " << player1.name << endl;
	string s;
	ifstream win("победа.txt");
	while (!win.eof())
	{
		getline(win, s);
		cout << s << endl;
	}
	win.close();

}


void Winner() {
	string s;
	ifstream winner("Победитель.txt");
	while (!winner.eof())
	{
		getline(winner, s);
		cout << s << endl;
	}
	winner.close();

}


void Lose() {
	string s;
	ifstream lose("Поражение.txt");
	while (!lose.eof())
	{
		getline(lose, s);
		cout << s << endl;
	}
	lose.close();
}


void Level(int dif) {
	string s;
	if (dif == 1) {
		ifstream dif1("level1.txt");
		while (!dif1.eof())
		{
			getline(dif1, s);
			cout << s << endl;
		}
		dif1.close();
	}
	else if (dif == 2) {
		ifstream dif2("level2.txt");
		while (!dif2.eof())
		{
			getline(dif2, s);
			cout << s << endl;
		}
		dif2.close();
	}
	else if (dif == 3) {
		ifstream dif3("level3.txt");
		while (!dif3.eof())
		{
			getline(dif3, s);
			cout << s << endl;
		}
		dif3.close();
	}
	else if (dif == 4) {
		ifstream dif4("level4.txt");
		while (!dif4.eof())
		{
			getline(dif4, s);
			cout << s << endl;
		}
		dif4.close();
	}
}


int NextLevel(Players& player, Players& bot) {
	if (player.HP <= 0) {
		system("cls");
		Lose();
		return 0;
	}
	else if (bot.HP <= 0) {
		system("cls");
		Win();
		char a = getch();
		system("cls");
	}
	return 1;
}


int NameCheat(Players& player) {
	setlocale(LC_ALL, "ru");
	if (player.name == "Хабиб" || player.name == "хабиб" || player.name == "Федор_Емельяненко" || player.name == "Фёдор_Емельяненко" || player.name == "федор_Емельяненко"
		|| player.name == "Федор_емельяненко" || player.name == "федор_емельяненко") {
		player.HP = 9999999999999;
		return 1;
	}
	else {
		player.HP = 15;
			return 0;
	}
}


int BlockCheat(Players& player) {
	if (player.PartOfBodyAndDamage == 4) {
		player.count++;
		if (player.count == 5) {
				return 1;
		}
	}
	else {
		player.count = 0;	
	}
	return 0;
}


void Controls() {
	cout << "Чтобы ударить противника используйте следующие клавиши:" << endl
		<< "1 - Удар левой рукой " << endl
		<< "2 - Удар правой рукой " << endl
		<< "3 - Удар ногой " << endl
		<< "4 - Поставить блок " << endl;
}


void HodPlayer(Players& player, Players& bot, int cheat) {
	srand(time(NULL));
	
	Controls();

	do {
		player.PartOfBodyAndDamage = getch();
		if (player.PartOfBodyAndDamage != 49 && player.PartOfBodyAndDamage != 50
		&& player.PartOfBodyAndDamage != 51 && player.PartOfBodyAndDamage != 52) cout << "Повторите ввод" << endl;
	} while (player.PartOfBodyAndDamage != 49 && player.PartOfBodyAndDamage != 50
		&& player.PartOfBodyAndDamage != 51 && player.PartOfBodyAndDamage != 52);

	switch (player.PartOfBodyAndDamage) {
		case 49:
			player.PartOfBodyAndDamage = 1;
			break;
		case 50:
			player.PartOfBodyAndDamage = 2;
			break;
		case 51:
			player.PartOfBodyAndDamage = 3;
			break;
		case 52: 
			player.PartOfBodyAndDamage = 4; 
			break;

	}
	
	
	system("cls");

	if (cheat) player.udar = 12;
	else player.udar = rand() % 13;

	cout << endl << endl << endl;
	if ((player.PartOfBodyAndDamage == 1 && player.stamina < 10) || (player.PartOfBodyAndDamage == 2 && player.stamina < 20) || (player.PartOfBodyAndDamage == 3 && player.stamina < 30)) {
		cout << "	У тебя не хватило выносливости на удар и ты поставил блок" << endl;
		player.PartOfBodyAndDamage = 4;
		player.stamina += 50;
	}
	else {
		
			if (player.udar < 5 && player.PartOfBodyAndDamage != 4)
			{
				cout << "	Ты бьёшь опонента, но промахиваешься" << endl;

			}
			else if (player.udar < 5 && player.PartOfBodyAndDamage == 4) {
				cout << "	Ты не смог поставить блок" << endl;
			}
			else if ((player.udar >= 5 && player.udar <= 8) && bot.PartOfBodyAndDamage != 4)
				if (player.PartOfBodyAndDamage == 1 || player.PartOfBodyAndDamage == 2)
				{
					if (player.PartOfBodyAndDamage == 1)
					{
						cout << "	Ты бьёшь опонента левой рукой" << endl;
						bot.HP -= player.PartOfBodyAndDamage;
						player.stamina -= 10;
					}
					else
					{
						cout << "	Ты бьёшь опонента правой рукой" << endl;
						bot.HP -= player.PartOfBodyAndDamage;
						player.stamina -= 20;
					}
					
				}
				else if(player.PartOfBodyAndDamage == 3){
					cout << "	Ты не смог ударить ногой " << endl;
				}
				else {
					cout << "	Ты не смог поставить блок" << endl;
				}
			else if (((player.udar >= 9) && (player.udar <= 11)) && bot.PartOfBodyAndDamage != 4)
			{
				if (player.PartOfBodyAndDamage == 1)
				{
					cout << "	Ты бьёшь опонента левой рукой" << endl;
					bot.HP -= player.PartOfBodyAndDamage;
					player.stamina -= 10;
				}
				else if (player.PartOfBodyAndDamage == 2)
				{
					cout << "	Ты бьёшь опонента правой рукой" << endl;
					bot.HP -= player.PartOfBodyAndDamage;
					player.stamina -= 20;
				}
				else if (player.PartOfBodyAndDamage == 3)
				{
					cout << "	Ты бьёшь опонента ногой" << endl;
					bot.HP -= player.PartOfBodyAndDamage;
					player.stamina -= 30;
				}
				else {
					cout << "	Ты поставил блок" << endl;
					player.stamina += 50;
					if (player.stamina > 100)
						player.stamina = 100;
				}

			}
			else if (player.udar == 12 && bot.PartOfBodyAndDamage != 4)
			{

				if (player.PartOfBodyAndDamage == 1)
				{
					cout << "	У тебя критический удар левой рукой" << endl;
					bot.HP -= player.PartOfBodyAndDamage + 1;
					player.stamina -= 10;
				}
				else if (player.PartOfBodyAndDamage == 2)
				{
					cout << "	У тебя критический удар правой рукой" << endl;
					bot.HP -= player.PartOfBodyAndDamage + 1;
					player.stamina -= 20;
				}
				else if (player.PartOfBodyAndDamage == 3)
				{
					cout << "	У тебя критический удар ногой" << endl;
					bot.HP -= player.PartOfBodyAndDamage + 1;
					player.stamina -= 30;
				}
				else if (player.PartOfBodyAndDamage == 4) {
					cout << "	Ты поставил блок" << endl;
					player.stamina += 50;
					if (player.stamina > 100)
						player.stamina = 100;
				}

				
			}
			else if (player.udar == 12 && bot.PartOfBodyAndDamage == 4 && player.PartOfBodyAndDamage != 4)
			{
				cout << "	Опонент поставил блок, но твой критический удар пробивает его!!" << endl;
				bot.HP -= player.PartOfBodyAndDamage;
				if (player.PartOfBodyAndDamage == 1) {
					bot.HP -= player.PartOfBodyAndDamage;
					player.stamina -= 10;
				}
				else if (player.PartOfBodyAndDamage == 2) {
					bot.HP -= player.PartOfBodyAndDamage;
					player.stamina -= 20;
				}
				else if (player.PartOfBodyAndDamage == 3) {
					bot.HP -= player.PartOfBodyAndDamage;
					player.stamina -= 30;
				}

				
			}
			else if (player.udar == 12  && player.PartOfBodyAndDamage == 4) {
				cout << "	Ты поставил блок" << endl;
				player.stamina += 50;
				if (player.stamina > 100)
					player.stamina = 100;
			}
			else {
				cout << "	Оппонент поставил блок, и ты не смог его пробить" << endl;
			}
	}
	
}


void HodBot(Players& bot, Players& player, int dif)
{
	srand(time(NULL));
	bot.PartOfBodyAndDamage = rand() % 4 + 1;
	if (dif == 1 || dif == 2)
		bot.udar = rand() % 13;
	if (dif == 3)
		bot.udar = (rand() % 10) + 3;
	if (dif == 4)
		bot.udar = (rand() % 12) + 3;

	
	if (bot.udar < 5 && bot.PartOfBodyAndDamage != 4)
	{
		cout << "	Опонент бьёт тебя, но промахивается" << endl;
		
	}
	else if (bot.udar < 5 && bot.PartOfBodyAndDamage == 4) {

		cout << "	Оппонент попытался поставить блок, но не смог" << endl;
		
	}
	else if ((bot.udar >= 5 && bot.udar <= 8) && player.PartOfBodyAndDamage != 4) {
		
		if (bot.PartOfBodyAndDamage == 1)
		{
			cout << "	Опонент бьёт тебя левой рукой" << endl;
			player.HP -= bot.PartOfBodyAndDamage;
			
		}
		else if (bot.PartOfBodyAndDamage == 2)
		{
			cout << "	Опонент бьёт тебя правой рукой" << endl;
			player.HP -= bot.PartOfBodyAndDamage;
			
		}
		
		else if (bot.PartOfBodyAndDamage == 3) {
			cout << "	Опонент не смог ударить ногой" << endl;
			

		}
		else {
			cout << "	Опонент не смог поставить блок" << endl;
			
		}
		
	}
	else if ((bot.udar >= 9 && bot.udar <= 11) && player.PartOfBodyAndDamage != 4)
	{
		if (bot.PartOfBodyAndDamage == 1)
		{
			cout << "	Опонент бьёт тебя левой рукой" << endl;
			player.HP -= bot.PartOfBodyAndDamage;
		}
		else if (bot.PartOfBodyAndDamage == 2)
		{
			cout << "	Опонент бьёт правой рукой" << endl;
			player.HP -= bot.PartOfBodyAndDamage;
		}
		else if (bot.PartOfBodyAndDamage == 3)
		{
			cout << "	Опонент бьёт ногой" << endl;
			player.HP -= bot.PartOfBodyAndDamage;
		}
		else
			cout << "	Опонент поставил блок" << endl;
		
	}
	else if (bot.udar >= 12 && player.PartOfBodyAndDamage != 4 && bot.PartOfBodyAndDamage != 4)
	{
		if (bot.PartOfBodyAndDamage == 1)
		{
			cout << "	У опонента критический удар левой рукой" << endl;
			player.HP -= bot.PartOfBodyAndDamage + 1;
		}
		else if (bot.PartOfBodyAndDamage == 2)
		{
			cout << "	У опонента критический удар правой рукой" << endl;
			player.HP -= bot.PartOfBodyAndDamage + 1;
		}
		else if (bot.PartOfBodyAndDamage == 3)	
		{
			cout << "	У опонента критический удар ногой" << endl;
			player.HP -= bot.PartOfBodyAndDamage + 1;
		}

	}
	else if (bot.udar >= 12 && player.PartOfBodyAndDamage == 4 && bot.PartOfBodyAndDamage != 4)
	{
		cout << "	Ты поставил блок, но критический удар опонента пробивает его!!" << endl;
		player.HP -= bot.PartOfBodyAndDamage;
		
	}
	else {
		cout << "	Ты поставил блок, и оппонент не смог его пробить" << endl;
	}
	cout << "Твои HP: " << player.HP << ", Твоя выносливость: " << player.stamina << ", HP опонента: " << bot.HP << endl;
	Fight();
}


void Hod2Players(Players& player1, Players& player2, int dif) {

	cout << "Ход первого игрока: ";

	do {
		player1.PartOfBodyAndDamage = InputInt();
		if (player1.PartOfBodyAndDamage != 1 && player1.PartOfBodyAndDamage != 2
			&& player1.PartOfBodyAndDamage != 3 && player1.PartOfBodyAndDamage != 4) cout << "Повторите ввод" << endl;
	} while (player1.PartOfBodyAndDamage != 1 && player1.PartOfBodyAndDamage != 2
		&& player1.PartOfBodyAndDamage != 3 && player1.PartOfBodyAndDamage != 4);

	cout<< "Ход второго игрока: ";
	

	do {
		player2.PartOfBodyAndDamage = InputInt();
		if (player2.PartOfBodyAndDamage != 1 && player2.PartOfBodyAndDamage != 2
			&& player2.PartOfBodyAndDamage != 3 && player2.PartOfBodyAndDamage != 4) cout << "Повторите ввод" << endl;
	} while (player2.PartOfBodyAndDamage != 1 && player2.PartOfBodyAndDamage != 2
		&& player2.PartOfBodyAndDamage != 3 && player2.PartOfBodyAndDamage != 4);
	system("cls");
	cout << endl << endl << endl;
	if (dif == 1 || dif == 2) {
		player1.udar = rand() % 13;
		player2.udar = rand() % 13;
	}
	else if (dif == 3) {
		player1.udar = (rand() % 10) + 3;
		player2.udar = (rand() % 10) + 3;
	}
	else if (dif == 4) {
		player1.udar = (rand() % 12) + 3;
		player2.udar = (rand() % 12) + 3;

	}


	
	if ((player1.PartOfBodyAndDamage == 1 && player1.stamina < 10) || (player1.PartOfBodyAndDamage == 2 && player1.stamina < 20) || (player1.PartOfBodyAndDamage == 3 && player1.stamina < 30)) {
		cout << "	У " << player1.name << " не хватило выносливости на удар и он поставил блок" << endl;
		player1.PartOfBodyAndDamage = 4;
		player1.stamina += 50;
	}
	else {

		if (player1.udar < 5 && player1.PartOfBodyAndDamage != 4)
		{
			cout << "	" << player1.name << " бьет, но промахивается" << endl;

		}
		else if (player1.udar < 5 && player1.PartOfBodyAndDamage == 4) {
			cout << "	" << player1.name << " не смог поставить блок" << endl;
	
		}
		else if ((player1.udar >= 5 && player1.udar <= 8) && player2.PartOfBodyAndDamage != 4) {
			if (player1.PartOfBodyAndDamage == 1 || player1.PartOfBodyAndDamage == 2)
			{
				if (player1.PartOfBodyAndDamage == 1)
				{
					cout << "	" << player1.name << " бьёт опонента левой рукой" << endl;
					player2.HP -= player1.PartOfBodyAndDamage;
					player1.stamina -= 10;
				}
				else
				{
					cout << "	" << player1.name << " бьёт опонента правой рукой" << endl;
					player2.HP -= player1.PartOfBodyAndDamage;
					player1.stamina -= 20;
				}

			}
			else if (player1.PartOfBodyAndDamage == 3) {
				cout << "	" << player1.name << " не смог ударить ногой " << endl;
			}
			else {
				cout << "	" << player1.name << " не смог поставить блок" << endl;
			}
		}
		else if (player1.udar >= 9 && player1.udar <= 11 && player2.PartOfBodyAndDamage != 4)
		{
			if (player1.PartOfBodyAndDamage == 1)
			{
				cout << "	" << player1.name << " бьёт опонента левой рукой" << endl;
				player2.HP -= player1.PartOfBodyAndDamage;
				player1.stamina -= 10;
			}
			else if (player1.PartOfBodyAndDamage == 2)
			{
				cout << "	" << player1.name << " бьёт опонента правой рукой" << endl;
				player2.HP -= player1.PartOfBodyAndDamage;
				player1.stamina -= 20;
			}
			else if (player1.PartOfBodyAndDamage == 3)
			{
				cout << "	" << player1.name << " бьёт опонента ногой" << endl;
				player2.HP -= player1.PartOfBodyAndDamage;
				player1.stamina -= 30;
			}
			else {
				cout << "	" << player1.name << " поставил блок" << endl;
				player1.stamina += 50;
				if (player1.stamina > 100)
					player1.stamina = 100;
			}

		}
		else if (player1.udar == 12 && player2.udar != 4)
		{

			if (player1.PartOfBodyAndDamage == 1)
			{
				cout << "	У " << player1.name << " критический удар левой рукой" << endl;
				player2.HP -= player1.PartOfBodyAndDamage + 1;
				player1.stamina -= 10;
			}
			else if (player1.PartOfBodyAndDamage == 2)
			{
				cout << "	У " << player1.name << " критический удар правой рукой" << endl;
				player2.HP -= player1.PartOfBodyAndDamage + 1;
				player1.stamina -= 20;
			}
			else if (player1.PartOfBodyAndDamage == 3)
			{
				cout << "	У " << player1.name << " критический удар ногой" << endl;
				player2.HP -= player1.PartOfBodyAndDamage + 1;
				player1.stamina -= 30;
			}
			else if (player1.PartOfBodyAndDamage == 4) {
				cout << "	" << player1.name << " поставил блок" << endl;
				player1.stamina += 50;
				if (player1.stamina > 100)
					player1.stamina = 100;
			}


		}
		else if (player1.udar == 12 && player2.PartOfBodyAndDamage == 4)
		{
			cout << "	" << player2.name << " поставил блок, но критический удар пробивает его!!" << endl;
			player2.HP -= player1.PartOfBodyAndDamage;
			if (player1.PartOfBodyAndDamage == 1) {
				player2.HP -= player1.PartOfBodyAndDamage;
				player1.stamina -= 10;
			}
			else if (player1.PartOfBodyAndDamage == 2) {
				player2.HP -= player1.PartOfBodyAndDamage;
				player1.stamina -= 20;
			}
			else if (player1.PartOfBodyAndDamage == 3) {
				player2.HP -= player1.PartOfBodyAndDamage;
				player1.stamina -= 30;
			}

		}
		else {
			cout << "	" << player1.name << " поставил блок, и оппонент не смог его пробить" << endl;
		}
	}


	if ((player2.PartOfBodyAndDamage == 1 && player2.stamina < 10) || (player2.PartOfBodyAndDamage == 2 && player2.stamina < 20) || (player2.PartOfBodyAndDamage == 3 && player2.stamina < 30)) {
		cout << "	У " << player2.name << " не хватило выносливости на удар и он поставил блок" << endl;
		player2.PartOfBodyAndDamage = 4;
		player2.stamina += 50;
	}
	else {
		if (player2.udar < 5 && player2.PartOfBodyAndDamage != 4)
		{
			cout << "	" << player2.name << " бьет, но промахивается" << endl;

		}
		else if (player2.udar < 5 && player2.PartOfBodyAndDamage == 4) {
			cout << "	" << player1.name << " не смог поставить блок" << endl;

		}
		else if ((player2.udar >= 5 && player2.udar <= 8)) {
			if (player2.PartOfBodyAndDamage == 1 || player2.PartOfBodyAndDamage == 2)
			{
				if (player2.PartOfBodyAndDamage == 1)
				{
					cout << "	" << player2.name << " бьёт опонента левой рукой" << endl;
					player1.HP -= player2.PartOfBodyAndDamage;
					player2.stamina -= 10;
				}
				else
				{
					cout << "	" << player2.name << " бьёт опонента правой рукой" << endl;
					player1.HP -= player2.PartOfBodyAndDamage;
					player2.stamina -= 20;
				}

			}
			else if (player2.PartOfBodyAndDamage == 3) {
				cout << "	" << player2.name << " не смог ударить ногой " << endl;
			}
			else {
				cout << "	" << player2.name << " не смог поставить блок" << endl;
			}
		}
		else if ((player2.udar >= 9) && (player2.udar <= 11) && player1.PartOfBodyAndDamage != 4)
		{
			if (player2.PartOfBodyAndDamage == 1)
			{
				cout << "	" << player2.name << " бьёт опонента левой рукой" << endl;
				player1.HP -= player2.PartOfBodyAndDamage;
				player2.stamina -= 10;
			}
			else if (player2.PartOfBodyAndDamage == 2)
			{
				cout << "	" << player2.name << " бьёт опонента правой рукой" << endl;
				player1.HP -= player2.PartOfBodyAndDamage;
				player2.stamina -= 20;
			}
			else if (player2.PartOfBodyAndDamage == 3)
			{
				cout << "	" << player2.name << " бьёт опонента ногой" << endl;
				player1.HP -= player2.PartOfBodyAndDamage;
				player2.stamina -= 30;
			}
			else {
				cout << "	" << player2.name << " поставил блок" << endl;
				player2.stamina += 50;
				if (player2.stamina > 100)
					player2.stamina = 100;
			}

		}
		else if (player2.udar == 12 && player1.udar != 4)
		{

			if (player2.PartOfBodyAndDamage == 1)
			{
				cout << "	У " << player2.name << " критический удар левой рукой" << endl;
				player1.HP -= player2.PartOfBodyAndDamage + 1;
				player2.stamina -= 10;
			}
			else if (player2.PartOfBodyAndDamage == 2)
			{
				cout << "	У " << player2.name << " критический удар правой рукой" << endl;
				player1.HP -= player2.PartOfBodyAndDamage + 1;
				player2.stamina -= 20;
			}
			else if (player2.PartOfBodyAndDamage == 3)
			{
				cout << "	У " << player2.name << " критический удар ногой" << endl;
				player1.HP -= player2.PartOfBodyAndDamage + 1;
				player2.stamina -= 30;
			}
			else if (player2.PartOfBodyAndDamage == 4) {
				cout << "	" << player2.name << " поставил блок" << endl;
				player2.stamina += 50;
				if (player2.stamina > 100)
					player2.stamina = 100;
			}


		}
		else if (player2.udar == 12 && player1.PartOfBodyAndDamage == 4)
		{
			cout << "	" << player1.name << " поставил блок, но критический удар пробивает его!!" << endl;
			player1.HP -= player2.PartOfBodyAndDamage;
			if (player2.PartOfBodyAndDamage == 1) {
				player2.stamina -= 10;
			}
			else if (player2.PartOfBodyAndDamage == 2) {
				player2.stamina -= 20;
			}
			else if (player2.PartOfBodyAndDamage == 3) {
				player2.stamina -= 30;
			}

		}
		else {
		cout << "	" << player2.name << " поставил блок, и оппонент не смог его пробить" << endl;
		}
	}
	
	cout << "HP игрока 1: " << player1.HP << ", Его выносливость: " << player1.stamina  <<
		"     HP игрока 2: " << player2.HP << ", Его выносливость: " << player2.stamina << endl;
	Fight();

	cout << "Чтобы ударить противника используйте следующие клавиши:" << endl
		<< "1 - Удар левой рукой " << endl
		<< "2 - Удар правой рукой " << endl
		<< "3 - Удар ногой " << endl
		<< "4 - Поставить блок " << endl;
}
