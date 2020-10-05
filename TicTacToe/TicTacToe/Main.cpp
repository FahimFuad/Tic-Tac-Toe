#include <iostream>
#include <string>
#define COUT std::cout
#define GAP "\t|"
#define TAB "\t"
#define G "    "
#define LINE "--------|"
void winCheck();
void Board();
void Game1();
void Game2();
char ca[11] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', 'X', 'O' };
bool gameOver = false;
bool player1turn = true;
bool player2turn = false;
bool Win1 = false;
bool Win2 = false;

int main()
{
	while (!gameOver)
	{
		Board();
		Game1();
		winCheck();
		system("cls");
		Board();
		Game2();
		winCheck();
		system("cls");
	}
	Board();
	system("pause");

}


void Board()
{
	COUT << "      Tic-Tac-Toe\n\n\n\n";

	COUT << GAP << GAP << "\t\n";
	COUT << G << ca[0] << GAP << G << ca[1] << GAP << G << ca[2] << "\t\n";
	COUT << GAP << GAP << "\t\n";

	COUT << "--------|-------|--------\t\n";

	COUT << GAP << GAP << "\t\n";
	COUT << G << ca[3] << GAP << G << ca[4] << GAP << G << ca[5] << "\t\n";
	COUT << GAP << GAP << "\t\n";

	COUT << "--------|-------|--------\t\n";

	COUT << GAP << GAP << "\t\n";
	COUT << G << ca[6] << GAP << G << ca[7] << GAP << G << ca[8] << "\t\n";
	COUT << GAP << GAP << "\t\n";

	if (Win1)
	{
		COUT << "\n\tPlayer1 wins\n\n\n";
	}
	if (Win2)
	{
		COUT << "\n\tPlayer2 wins\n\n\n";
	}
}

void Play(char ch)
{
	switch (ch)
	{
	case 'X': COUT << "\n\nPlayer1's turn-->";
		break;
	case 'O': COUT << "\n\nPlayer2's turn-->";
		break;
	}
	int player_input;
	std::cin >> player_input;

	if (isdigit(ca[player_input - 1]))
		ca[player_input - 1] = ch;


}
void Game1()
{
	if (player1turn)
	{
		Play('X');
		player1turn = false;
		player2turn = true;
	}
}

void Game2()
{
	if (player2turn)
	{
		Play('O');
		player1turn = true;
		player2turn = false;
	}
}

void Check1()
{
	Win1 = true;
	Win2 = false;
	player1turn = false;
	player2turn = false;
	gameOver = true;
	COUT << "\n\n\tPlayer 1 Wins!!!";
}

void Check2()
{
	Win2 = true;
	Win1 = false;
	player1turn = false;
	player2turn = false;
	gameOver = true;
	COUT << "\n\n\tPlayer 2 Wins!!!";
}

void winCheck()
{
	//Horizontal Check 1
	if (ca[0] == ca[9] && ca[1] == ca[9] && ca[2] == ca[9]) Check1();
	if (ca[3] == ca[9] && ca[4] == ca[9] && ca[5] == ca[9]) Check1();
	if (ca[6] == ca[9] && ca[7] == ca[9] && ca[8] == ca[9]) Check1();
	//Vertical Check 1
	if (ca[0] == ca[9] && ca[3] == ca[9] && ca[6] == ca[9]) Check1();
	if (ca[1] == ca[9] && ca[4] == ca[9] && ca[7] == ca[9]) Check1();
	if (ca[2] == ca[9] && ca[5] == ca[9] && ca[8] == ca[9]) Check1();
	//Diagonal Check 1
	if (ca[2] == ca[9] && ca[4] == ca[9] && ca[6] == ca[9]) Check1();
	if (ca[0] == ca[9] && ca[4] == ca[9] && ca[8] == ca[9]) Check1();


	//Horizontal Check 2
	if (ca[0] == ca[10] && ca[1] == ca[10] && ca[2] == ca[10]) Check2();
	if (ca[3] == ca[10] && ca[4] == ca[10] && ca[5] == ca[10]) Check2();
	if (ca[6] == ca[10] && ca[7] == ca[10] && ca[8] == ca[10]) Check2();
	//Vertical Check 2
	if (ca[0] == ca[10] && ca[3] == ca[10] && ca[6] == ca[10]) Check2();
	if (ca[1] == ca[10] && ca[4] == ca[10] && ca[7] == ca[10]) Check2();
	if (ca[2] == ca[10] && ca[5] == ca[10] && ca[8] == ca[10]) Check2();
	//Diagonal Check 1
	if (ca[2] == ca[10] && ca[4] == ca[10] && ca[6] == ca[10]) Check2();
	if (ca[0] == ca[10] && ca[4] == ca[10] && ca[8] == ca[10]) Check2();
}
