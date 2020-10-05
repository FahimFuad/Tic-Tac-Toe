#include "TicTacToe.h"
#include <iostream>
#include <string>
#define GAP "\t|"
#define TAB "\t"
#define G "    "
#define LINE "-------|"

char ca[11] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', 'X', 'O' };
bool gameOver = false;
bool player1turn = true;
bool player2turn = false;
bool Win1 = false;
bool Win2 = false;


int main()
{
	do 
	{
		Logic();

	} while (!gameOver);
	Board();
	system("pause");

}


void Board()
{
	std::cout << "      Tic-Tac-Toe\n\n\n\n";

	std::cout << GAP << GAP << "\t\n";
	std::cout << G << ca[0] << GAP << G << ca[1] << GAP << G << ca[2] << "\t\n";
	std::cout << GAP << GAP << "\t\n";

	std::cout << "--------|-------|--------\t\n";

	std::cout << GAP << GAP << "\t\n";
	std::cout << G << ca[3] << GAP << G << ca[4] << GAP << G << ca[5] << "\t\n";
	std::cout << GAP << GAP << "\t\n";

	std::cout << "--------|-------|--------\t\n";

	std::cout << GAP << GAP << "\t\n";
	std::cout << G << ca[6] << GAP << G << ca[7] << GAP << G << ca[8] << "\t\n";
	std::cout << GAP << GAP << "\t\n";

	if (Win1)
	{
		std::cout << "\n\tPlayer1 wins\n\n\n";
	}
	if (Win2)
	{
		std::cout << "\n\tPlayer2 wins\n\n\n";
	}
}

void Play(char ch)
{
	switch (ch)
	{
	case 'X': std::cout << "\n\nPlayer1's turn-->";
		break;
	case 'O': std::cout << "\n\nPlayer2's turn-->";
		break;
	}
	int player_input;
	std::cin >> player_input;

	if (isdigit(ca[player_input - 1]))
		ca[player_input - 1] = ch;
}

void Game(int a)
{
	if (player1turn && a == 1)
	{
		Play('X');
		player1turn = false;
		player2turn = true;
	}
	if (player2turn && a == 2)
	{
		Play('O');
		player1turn = true;
		player2turn = false;
	}
}



void Check(int a)
{
	if (a == 1)
	{
		Win1 = true;
		Win2 = false;
		player1turn = false;
		player2turn = false;
		gameOver = true;
		std::cout << "\n\n\tPlayer 1 Wins!!!";
	}
	if (a == 2)
	{
		Win2 = true;
		Win1 = false;
		player1turn = false;
		player2turn = false;
		gameOver = true;
		std::cout << "\n\n\tPlayer 2 Wins!!!";
	}
}

void winCheck(int ch, int check)
{
	//Horizontal Check 1
	if (ca[0] == ca[ch] && ca[1] == ca[ch] && ca[2] == ca[ch]) Check(check);
	if (ca[3] == ca[ch] && ca[4] == ca[ch] && ca[5] == ca[ch]) Check(check);
	if (ca[6] == ca[ch] && ca[7] == ca[ch] && ca[8] == ca[ch]) Check(check);
	//Vertical Check 1
	if (ca[0] == ca[ch] && ca[3] == ca[ch] && ca[6] == ca[ch]) Check(check);
	if (ca[1] == ca[ch] && ca[4] == ca[ch] && ca[7] == ca[ch]) Check(check);
	if (ca[2] == ca[ch] && ca[5] == ca[ch] && ca[8] == ca[ch]) Check(check);
	//Diagonal Check 1
	if (ca[2] == ca[ch] && ca[4] == ca[ch] && ca[6] == ca[ch]) Check(check);
	if (ca[0] == ca[ch] && ca[4] == ca[ch] && ca[8] == ca[ch]) Check(check);
}


void Logic()
{
	Board();
	Game(1);
	winCheck(9, 1);
	system("cls");
	Board();
	Game(2);
	winCheck(10, 2);
	system("cls");
}


