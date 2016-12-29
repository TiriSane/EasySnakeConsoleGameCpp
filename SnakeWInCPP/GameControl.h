#ifndef _GAME_CONTROL_H_
#define _GAME_CONTROL_H_

#include "Snake.h"

class Game
{
public:
	void run() { initMenu(); }

	void initUserData();
	void initMenu();

	void gameSetPage();
	void colorSetPage();
	void nameSetPage();

	void gameStart() { initUI(); int fs=mainLoop(); gameOver(fs); }

	void initUI();
	int mainLoop();

	void gameOver(int fs);

private:
	std::string theName = "No Name";
	std::string theScore = "0";
	std::string theColor = "color 0f";
};

#endif // ! _GAME_CONTROL_H_