#include "IOFuncs.h"

using namespace std;

void pos(int x, int y)
{
	COORD pos;
	HANDLE hOut;
	pos.X = x;
	pos.Y = y;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos);
}

void loadUserDataFromFile(string &theName,string &theScore)
{
	fstream file("userdata");

	string outputString;
	if (file.is_open())
	{
		string name, score;

		getline(file, name); theName = name;
		getline(file, score); theScore = score;

		string nameOutput("玩家名字:"); nameOutput += name;
		string scoreOutput("     最佳分数:"); scoreOutput += score;
		outputString = nameOutput += scoreOutput;

		pos(14, 15);
	}
	else
	{
		pos(20, 15);
		outputString = "历史最高分: 无记录";
	}
	file.close();

	cout << outputString;
	pos(32, 19);
}