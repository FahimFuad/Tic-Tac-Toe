#include "TicTacToe.h"
#include <stdlib.h>
#include <chrono>
#include <thread>

char ca[11] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', 'X', 'O' };
bool m_player1turn = true;
bool m_player2turn = false;
bool m_Win1 = false;
bool m_Win2 = false;
 


void TicTacToe::Board()
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

	if (m_Win1)
	{
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "\n\tPlayer1 wins\n\n\n";
		PauseExecution(2);
		system("cls");
		
	}
	if (m_Win2)
	{
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "\n\tPlayer2 wins\n\n\n";
		PauseExecution(2);
		system("cls");
		
	}
}

void TicTacToe::StartGame()
{
	Board();
	Turn(1);
	winCheck(9, 1);
	system("cls");
	Board();
	Turn(2);
	winCheck(10, 2);
	system("cls");
	if (m_gameOver)
		Board();
	
}

void TicTacToe::RollUp()
{
	int decision;
	std::cout << "PLAY---->1" << std::endl;
	std::cout << "EXIT---->2" << std::endl;
	std::cin >> decision;
	if (decision == 1)
	{
		do
		{
			system("cls");
			StartGame();
		} while (!m_gameOver);
	}
	if (decision == 2)
	{
		system("cls");
		std::cout << "\tThanks for Playing TicTacToe\n\n";
		std::cout << "\tGame developed by Fahim Fuad" << std::endl;
		exit(0);
	}
}

void TicTacToe::Play(char ch)
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

void TicTacToe::Turn(int a)
{
	if(m_player1turn && a == 1)
	{
		Play('X');
		m_player1turn = false;
		m_player2turn = true;
	}
	if (m_player2turn && a == 2)
	{
		Play('O');
		m_player1turn = true;
		m_player2turn = false;
	}
}

void TicTacToe::Check(int a)
{
	if (a == 1)
	{
		m_Win1 = true;
		m_Win2 = false;
		m_player1turn = false;
		m_player2turn = false;
		m_gameOver = true;
		std::cout << "\n\n\tPlayer 1 Wins!!!";
	}
	if (a == 2)
	{
		m_Win2 = true;
		m_Win1 = false;
		m_player1turn = false;
		m_player2turn = false;
		m_gameOver = true;
		std::cout << "\n\n\tPlayer 2 Wins!!!";
	}
}

void TicTacToe::winCheck(int ch, int check)
{
	if (ca[0] == ca[ch] && ca[1] == ca[ch] && ca[2] == ca[ch]) Check(check);
	if (ca[3] == ca[ch] && ca[4] == ca[ch] && ca[5] == ca[ch]) Check(check);
	if (ca[6] == ca[ch] && ca[7] == ca[ch] && ca[8] == ca[ch]) Check(check);
	if (ca[0] == ca[ch] && ca[3] == ca[ch] && ca[6] == ca[ch]) Check(check);
	if (ca[1] == ca[ch] && ca[4] == ca[ch] && ca[7] == ca[ch]) Check(check);
	if (ca[2] == ca[ch] && ca[5] == ca[ch] && ca[8] == ca[ch]) Check(check);
	if (ca[2] == ca[ch] && ca[4] == ca[ch] && ca[6] == ca[ch]) Check(check);
	if (ca[0] == ca[ch] && ca[4] == ca[ch] && ca[8] == ca[ch]) Check(check);
}
void TicTacToe::PauseExecution(int sec)
{
	std::chrono::seconds dura(sec);
	std::this_thread::sleep_for(dura);
}
