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

		string nameOutput("�������:"); nameOutput += name;
		string scoreOutput("     ��ѷ���:"); scoreOutput += score;
		outputString = nameOutput += scoreOutput;

		pos(14, 15);
	}
	else
	{
		pos(20, 15);
		outputString = "��ʷ��߷�: �޼�¼";
	}
	file.close();

	cout << outputString;
	pos(32, 19);
}