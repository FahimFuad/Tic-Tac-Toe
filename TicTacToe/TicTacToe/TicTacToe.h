#include <iostream>
#include <string>

#define GAP "\t|"
#define TAB "\t"
#define G "    "
#define LINE "-------|"

class TicTacToe
{
public:
	bool m_gameOver = false;
	void Board();
	void StartGame();
	void RollUp();
private:
	void Play(char ch);
	void Turn(int a);
	void Check(int a);
	void winCheck(int ch, int check);
	void PauseExecution(int sec);
};