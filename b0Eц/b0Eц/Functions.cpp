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
			cout << "�������� ����" << endl;
		}
		else {
			return doub;
		}
	}
}


void Introduction() {
	setlocale(LC_ALL, "ru");

	
	cout << endl << "����� ���������� � ���������� ���� '����' " << endl <<
		"���� �� ������ ������������ � ��������� ���� - ������� '������' " << endl <<
		"���� ������� ����� ������ ���� - ������� ����� ������ �������" << endl;
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
		cout << "������� ����� ������� ����� ����������" << endl;
		a = getch();
		system("cls");
	}
	system("cls");
}


int ChoiceMode() {
	cout << endl << "�������� ����� ����: 1 - ���� �����  2 - ��� ������" << endl;
	int mode;
	do {
		mode = getch();
		if (mode != 49 && mode != 50) cout << "��������� ����" << endl;
	} while (mode != 49 && mode != 50);
	if (mode == 49)
		return 1;
	else
		return 0;
}


int ChoiceDifficulty(Players& player, Players& bot, Players& player1, Players& player2, int mode) {
	int dificulty, ParamDif;
	if (mode) {
		cout << "�������� ����� ����: 1 - ���� ������� (�� �����) 2 - ������������ ���������" << endl;

		do {
			dificulty = getch();
			if (dificulty != 49 && dificulty != 50) cout << "��������� ����" << endl;
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
			cout << "�������� c��������: 1 - ������ 2 - ������� 3 - ������� 4 - Hard" << endl;

			do {
				dificulty = getch();
				if (dificulty != 49 && dificulty != 50 && dificulty != 51 && dificulty != 52) cout << "��������� ����" << endl;
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
		cout << "�������� ��������������, ������� ����� ��������� � ������� �� �������:" << endl
			<< "1 - � ��� �� 15 hp" << endl
			<< "2 - � ��� �� 20 hp" << endl
			<< "3 - � ��� �� 25 hp � ���������� ���� �� ������" << endl <<
			"4 - � ��� �� 30 hp, ���������� ���� �� ������, ���������� ���� �� ����������� ��������� � ����������� ������������" << endl;

		do {
			dificulty = getch();
			if (dificulty != 49 && dificulty != 50 && dificulty != 51 && dificulty != 52) cout << "��������� ����" << endl;
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

	cout << "������� ��� ��� ";
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
		cout << "��������� ������" << endl;
	}
}


void CreatePlayers(Players& player1, Players& player2, int ParamDif) {
	cout << "������� ��� ������� ������ ";
	cin >> player1.name;
	cout << "������� ��� ������� ������ ";
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
	ifstream win("������.txt");
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
		cout << "������� ����� ��� ������� 2: " << player2.name << endl;
	else
		cout << "������� ����� ��� ������� 1: " << player1.name << endl;
	string s;
	ifstream win("������.txt");
	while (!win.eof())
	{
		getline(win, s);
		cout << s << endl;
	}
	win.close();

}


void Winner() {
	string s;
	ifstream winner("����������.txt");
	while (!winner.eof())
	{
		getline(winner, s);
		cout << s << endl;
	}
	winner.close();

}


void Lose() {
	string s;
	ifstream lose("���������.txt");
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
	if (player.name == "�����" || player.name == "�����" || player.name == "�����_�����������" || player.name == "Ը���_�����������" || player.name == "�����_�����������"
		|| player.name == "�����_�����������" || player.name == "�����_�����������") {
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
	cout << "����� ������� ���������� ����������� ��������� �������:" << endl
		<< "1 - ���� ����� ����� " << endl
		<< "2 - ���� ������ ����� " << endl
		<< "3 - ���� ����� " << endl
		<< "4 - ��������� ���� " << endl;
}


void HodPlayer(Players& player, Players& bot, int cheat) {
	srand(time(NULL));
	
	Controls();

	do {
		player.PartOfBodyAndDamage = getch();
		if (player.PartOfBodyAndDamage != 49 && player.PartOfBodyAndDamage != 50
		&& player.PartOfBodyAndDamage != 51 && player.PartOfBodyAndDamage != 52) cout << "��������� ����" << endl;
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
		cout << "	� ���� �� ������� ������������ �� ���� � �� �������� ����" << endl;
		player.PartOfBodyAndDamage = 4;
		player.stamina += 50;
	}
	else {
		
			if (player.udar < 5 && player.PartOfBodyAndDamage != 4)
			{
				cout << "	�� ����� ��������, �� ��������������" << endl;

			}
			else if (player.udar < 5 && player.PartOfBodyAndDamage == 4) {
				cout << "	�� �� ���� ��������� ����" << endl;
			}
			else if ((player.udar >= 5 && player.udar <= 8) && bot.PartOfBodyAndDamage != 4)
				if (player.PartOfBodyAndDamage == 1 || player.PartOfBodyAndDamage == 2)
				{
					if (player.PartOfBodyAndDamage == 1)
					{
						cout << "	�� ����� �������� ����� �����" << endl;
						bot.HP -= player.PartOfBodyAndDamage;
						player.stamina -= 10;
					}
					else
					{
						cout << "	�� ����� �������� ������ �����" << endl;
						bot.HP -= player.PartOfBodyAndDamage;
						player.stamina -= 20;
					}
					
				}
				else if(player.PartOfBodyAndDamage == 3){
					cout << "	�� �� ���� ������� ����� " << endl;
				}
				else {
					cout << "	�� �� ���� ��������� ����" << endl;
				}
			else if (((player.udar >= 9) && (player.udar <= 11)) && bot.PartOfBodyAndDamage != 4)
			{
				if (player.PartOfBodyAndDamage == 1)
				{
					cout << "	�� ����� �������� ����� �����" << endl;
					bot.HP -= player.PartOfBodyAndDamage;
					player.stamina -= 10;
				}
				else if (player.PartOfBodyAndDamage == 2)
				{
					cout << "	�� ����� �������� ������ �����" << endl;
					bot.HP -= player.PartOfBodyAndDamage;
					player.stamina -= 20;
				}
				else if (player.PartOfBodyAndDamage == 3)
				{
					cout << "	�� ����� �������� �����" << endl;
					bot.HP -= player.PartOfBodyAndDamage;
					player.stamina -= 30;
				}
				else {
					cout << "	�� �������� ����" << endl;
					player.stamina += 50;
					if (player.stamina > 100)
						player.stamina = 100;
				}

			}
			else if (player.udar == 12 && bot.PartOfBodyAndDamage != 4)
			{

				if (player.PartOfBodyAndDamage == 1)
				{
					cout << "	� ���� ����������� ���� ����� �����" << endl;
					bot.HP -= player.PartOfBodyAndDamage + 1;
					player.stamina -= 10;
				}
				else if (player.PartOfBodyAndDamage == 2)
				{
					cout << "	� ���� ����������� ���� ������ �����" << endl;
					bot.HP -= player.PartOfBodyAndDamage + 1;
					player.stamina -= 20;
				}
				else if (player.PartOfBodyAndDamage == 3)
				{
					cout << "	� ���� ����������� ���� �����" << endl;
					bot.HP -= player.PartOfBodyAndDamage + 1;
					player.stamina -= 30;
				}
				else if (player.PartOfBodyAndDamage == 4) {
					cout << "	�� �������� ����" << endl;
					player.stamina += 50;
					if (player.stamina > 100)
						player.stamina = 100;
				}

				
			}
			else if (player.udar == 12 && bot.PartOfBodyAndDamage == 4 && player.PartOfBodyAndDamage != 4)
			{
				cout << "	������� �������� ����, �� ���� ����������� ���� ��������� ���!!" << endl;
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
				cout << "	�� �������� ����" << endl;
				player.stamina += 50;
				if (player.stamina > 100)
					player.stamina = 100;
			}
			else {
				cout << "	�������� �������� ����, � �� �� ���� ��� �������" << endl;
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
		cout << "	������� ���� ����, �� �������������" << endl;
		
	}
	else if (bot.udar < 5 && bot.PartOfBodyAndDamage == 4) {

		cout << "	�������� ��������� ��������� ����, �� �� ����" << endl;
		
	}
	else if ((bot.udar >= 5 && bot.udar <= 8) && player.PartOfBodyAndDamage != 4) {
		
		if (bot.PartOfBodyAndDamage == 1)
		{
			cout << "	������� ���� ���� ����� �����" << endl;
			player.HP -= bot.PartOfBodyAndDamage;
			
		}
		else if (bot.PartOfBodyAndDamage == 2)
		{
			cout << "	������� ���� ���� ������ �����" << endl;
			player.HP -= bot.PartOfBodyAndDamage;
			
		}
		
		else if (bot.PartOfBodyAndDamage == 3) {
			cout << "	������� �� ���� ������� �����" << endl;
			

		}
		else {
			cout << "	������� �� ���� ��������� ����" << endl;
			
		}
		
	}
	else if ((bot.udar >= 9 && bot.udar <= 11) && player.PartOfBodyAndDamage != 4)
	{
		if (bot.PartOfBodyAndDamage == 1)
		{
			cout << "	������� ���� ���� ����� �����" << endl;
			player.HP -= bot.PartOfBodyAndDamage;
		}
		else if (bot.PartOfBodyAndDamage == 2)
		{
			cout << "	������� ���� ������ �����" << endl;
			player.HP -= bot.PartOfBodyAndDamage;
		}
		else if (bot.PartOfBodyAndDamage == 3)
		{
			cout << "	������� ���� �����" << endl;
			player.HP -= bot.PartOfBodyAndDamage;
		}
		else
			cout << "	������� �������� ����" << endl;
		
	}
	else if (bot.udar >= 12 && player.PartOfBodyAndDamage != 4 && bot.PartOfBodyAndDamage != 4)
	{
		if (bot.PartOfBodyAndDamage == 1)
		{
			cout << "	� �������� ����������� ���� ����� �����" << endl;
			player.HP -= bot.PartOfBodyAndDamage + 1;
		}
		else if (bot.PartOfBodyAndDamage == 2)
		{
			cout << "	� �������� ����������� ���� ������ �����" << endl;
			player.HP -= bot.PartOfBodyAndDamage + 1;
		}
		else if (bot.PartOfBodyAndDamage == 3)	
		{
			cout << "	� �������� ����������� ���� �����" << endl;
			player.HP -= bot.PartOfBodyAndDamage + 1;
		}

	}
	else if (bot.udar >= 12 && player.PartOfBodyAndDamage == 4 && bot.PartOfBodyAndDamage != 4)
	{
		cout << "	�� �������� ����, �� ����������� ���� �������� ��������� ���!!" << endl;
		player.HP -= bot.PartOfBodyAndDamage;
		
	}
	else {
		cout << "	�� �������� ����, � �������� �� ���� ��� �������" << endl;
	}
	cout << "���� HP: " << player.HP << ", ���� ������������: " << player.stamina << ", HP ��������: " << bot.HP << endl;
	Fight();
}


void Hod2Players(Players& player1, Players& player2, int dif) {

	cout << "��� ������� ������: ";

	do {
		player1.PartOfBodyAndDamage = InputInt();
		if (player1.PartOfBodyAndDamage != 1 && player1.PartOfBodyAndDamage != 2
			&& player1.PartOfBodyAndDamage != 3 && player1.PartOfBodyAndDamage != 4) cout << "��������� ����" << endl;
	} while (player1.PartOfBodyAndDamage != 1 && player1.PartOfBodyAndDamage != 2
		&& player1.PartOfBodyAndDamage != 3 && player1.PartOfBodyAndDamage != 4);

	cout<< "��� ������� ������: ";
	

	do {
		player2.PartOfBodyAndDamage = InputInt();
		if (player2.PartOfBodyAndDamage != 1 && player2.PartOfBodyAndDamage != 2
			&& player2.PartOfBodyAndDamage != 3 && player2.PartOfBodyAndDamage != 4) cout << "��������� ����" << endl;
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
		cout << "	� " << player1.name << " �� ������� ������������ �� ���� � �� �������� ����" << endl;
		player1.PartOfBodyAndDamage = 4;
		player1.stamina += 50;
	}
	else {

		if (player1.udar < 5 && player1.PartOfBodyAndDamage != 4)
		{
			cout << "	" << player1.name << " ����, �� �������������" << endl;

		}
		else if (player1.udar < 5 && player1.PartOfBodyAndDamage == 4) {
			cout << "	" << player1.name << " �� ���� ��������� ����" << endl;
	
		}
		else if ((player1.udar >= 5 && player1.udar <= 8) && player2.PartOfBodyAndDamage != 4) {
			if (player1.PartOfBodyAndDamage == 1 || player1.PartOfBodyAndDamage == 2)
			{
				if (player1.PartOfBodyAndDamage == 1)
				{
					cout << "	" << player1.name << " ���� �������� ����� �����" << endl;
					player2.HP -= player1.PartOfBodyAndDamage;
					player1.stamina -= 10;
				}
				else
				{
					cout << "	" << player1.name << " ���� �������� ������ �����" << endl;
					player2.HP -= player1.PartOfBodyAndDamage;
					player1.stamina -= 20;
				}

			}
			else if (player1.PartOfBodyAndDamage == 3) {
				cout << "	" << player1.name << " �� ���� ������� ����� " << endl;
			}
			else {
				cout << "	" << player1.name << " �� ���� ��������� ����" << endl;
			}
		}
		else if (player1.udar >= 9 && player1.udar <= 11 && player2.PartOfBodyAndDamage != 4)
		{
			if (player1.PartOfBodyAndDamage == 1)
			{
				cout << "	" << player1.name << " ���� �������� ����� �����" << endl;
				player2.HP -= player1.PartOfBodyAndDamage;
				player1.stamina -= 10;
			}
			else if (player1.PartOfBodyAndDamage == 2)
			{
				cout << "	" << player1.name << " ���� �������� ������ �����" << endl;
				player2.HP -= player1.PartOfBodyAndDamage;
				player1.stamina -= 20;
			}
			else if (player1.PartOfBodyAndDamage == 3)
			{
				cout << "	" << player1.name << " ���� �������� �����" << endl;
				player2.HP -= player1.PartOfBodyAndDamage;
				player1.stamina -= 30;
			}
			else {
				cout << "	" << player1.name << " �������� ����" << endl;
				player1.stamina += 50;
				if (player1.stamina > 100)
					player1.stamina = 100;
			}

		}
		else if (player1.udar == 12 && player2.udar != 4)
		{

			if (player1.PartOfBodyAndDamage == 1)
			{
				cout << "	� " << player1.name << " ����������� ���� ����� �����" << endl;
				player2.HP -= player1.PartOfBodyAndDamage + 1;
				player1.stamina -= 10;
			}
			else if (player1.PartOfBodyAndDamage == 2)
			{
				cout << "	� " << player1.name << " ����������� ���� ������ �����" << endl;
				player2.HP -= player1.PartOfBodyAndDamage + 1;
				player1.stamina -= 20;
			}
			else if (player1.PartOfBodyAndDamage == 3)
			{
				cout << "	� " << player1.name << " ����������� ���� �����" << endl;
				player2.HP -= player1.PartOfBodyAndDamage + 1;
				player1.stamina -= 30;
			}
			else if (player1.PartOfBodyAndDamage == 4) {
				cout << "	" << player1.name << " �������� ����" << endl;
				player1.stamina += 50;
				if (player1.stamina > 100)
					player1.stamina = 100;
			}


		}
		else if (player1.udar == 12 && player2.PartOfBodyAndDamage == 4)
		{
			cout << "	" << player2.name << " �������� ����, �� ����������� ���� ��������� ���!!" << endl;
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
			cout << "	" << player1.name << " �������� ����, � �������� �� ���� ��� �������" << endl;
		}
	}


	if ((player2.PartOfBodyAndDamage == 1 && player2.stamina < 10) || (player2.PartOfBodyAndDamage == 2 && player2.stamina < 20) || (player2.PartOfBodyAndDamage == 3 && player2.stamina < 30)) {
		cout << "	� " << player2.name << " �� ������� ������������ �� ���� � �� �������� ����" << endl;
		player2.PartOfBodyAndDamage = 4;
		player2.stamina += 50;
	}
	else {
		if (player2.udar < 5 && player2.PartOfBodyAndDamage != 4)
		{
			cout << "	" << player2.name << " ����, �� �������������" << endl;

		}
		else if (player2.udar < 5 && player2.PartOfBodyAndDamage == 4) {
			cout << "	" << player1.name << " �� ���� ��������� ����" << endl;

		}
		else if ((player2.udar >= 5 && player2.udar <= 8)) {
			if (player2.PartOfBodyAndDamage == 1 || player2.PartOfBodyAndDamage == 2)
			{
				if (player2.PartOfBodyAndDamage == 1)
				{
					cout << "	" << player2.name << " ���� �������� ����� �����" << endl;
					player1.HP -= player2.PartOfBodyAndDamage;
					player2.stamina -= 10;
				}
				else
				{
					cout << "	" << player2.name << " ���� �������� ������ �����" << endl;
					player1.HP -= player2.PartOfBodyAndDamage;
					player2.stamina -= 20;
				}

			}
			else if (player2.PartOfBodyAndDamage == 3) {
				cout << "	" << player2.name << " �� ���� ������� ����� " << endl;
			}
			else {
				cout << "	" << player2.name << " �� ���� ��������� ����" << endl;
			}
		}
		else if ((player2.udar >= 9) && (player2.udar <= 11) && player1.PartOfBodyAndDamage != 4)
		{
			if (player2.PartOfBodyAndDamage == 1)
			{
				cout << "	" << player2.name << " ���� �������� ����� �����" << endl;
				player1.HP -= player2.PartOfBodyAndDamage;
				player2.stamina -= 10;
			}
			else if (player2.PartOfBodyAndDamage == 2)
			{
				cout << "	" << player2.name << " ���� �������� ������ �����" << endl;
				player1.HP -= player2.PartOfBodyAndDamage;
				player2.stamina -= 20;
			}
			else if (player2.PartOfBodyAndDamage == 3)
			{
				cout << "	" << player2.name << " ���� �������� �����" << endl;
				player1.HP -= player2.PartOfBodyAndDamage;
				player2.stamina -= 30;
			}
			else {
				cout << "	" << player2.name << " �������� ����" << endl;
				player2.stamina += 50;
				if (player2.stamina > 100)
					player2.stamina = 100;
			}

		}
		else if (player2.udar == 12 && player1.udar != 4)
		{

			if (player2.PartOfBodyAndDamage == 1)
			{
				cout << "	� " << player2.name << " ����������� ���� ����� �����" << endl;
				player1.HP -= player2.PartOfBodyAndDamage + 1;
				player2.stamina -= 10;
			}
			else if (player2.PartOfBodyAndDamage == 2)
			{
				cout << "	� " << player2.name << " ����������� ���� ������ �����" << endl;
				player1.HP -= player2.PartOfBodyAndDamage + 1;
				player2.stamina -= 20;
			}
			else if (player2.PartOfBodyAndDamage == 3)
			{
				cout << "	� " << player2.name << " ����������� ���� �����" << endl;
				player1.HP -= player2.PartOfBodyAndDamage + 1;
				player2.stamina -= 30;
			}
			else if (player2.PartOfBodyAndDamage == 4) {
				cout << "	" << player2.name << " �������� ����" << endl;
				player2.stamina += 50;
				if (player2.stamina > 100)
					player2.stamina = 100;
			}


		}
		else if (player2.udar == 12 && player1.PartOfBodyAndDamage == 4)
		{
			cout << "	" << player1.name << " �������� ����, �� ����������� ���� ��������� ���!!" << endl;
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
		cout << "	" << player2.name << " �������� ����, � �������� �� ���� ��� �������" << endl;
		}
	}
	
	cout << "HP ������ 1: " << player1.HP << ", ��� ������������: " << player1.stamina  <<
		"     HP ������ 2: " << player2.HP << ", ��� ������������: " << player2.stamina << endl;
	Fight();

	cout << "����� ������� ���������� ����������� ��������� �������:" << endl
		<< "1 - ���� ����� ����� " << endl
		<< "2 - ���� ������ ����� " << endl
		<< "3 - ���� ����� " << endl
		<< "4 - ��������� ���� " << endl;
}
