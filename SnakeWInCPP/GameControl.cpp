#include "GameControl.h"

using namespace std;

void Game::initUserData()
{
	string colorConfig;
	fstream file("config");
	if (file.is_open()) { getline(file, colorConfig); system(colorConfig.c_str()); }
	else { system("color 0f"); };
	file.close();

	loadUserDataFromFile(theName,theScore);
}

void Game::initMenu()
{
	system("mode con cols=61 lines=24");
	system("title Snake_Game");
	system("cls");

	cout << "�X�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�[" << endl;
	cout << "�d�p�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�p�g" << endl;
	cout << "�d�g                                                    �d�g" << endl;
	cout << "�d�g         ����������������������������������         �d�g" << endl;
	cout << "�d�g         ��          ̰  ��  ��          ��         �d�g" << endl;
	cout << "�d�g         ����������������������������������         �d�g" << endl;
	cout << "�d�g                                                    �d�g" << endl;
	cout << "�d�g                                                    �d�g" << endl;
	cout << "�d�g                  1. �� ʼ �� Ϸ                    �d�g" << endl;
	cout << "�d�g                                                    �d�g" << endl;
	cout << "�d�g                  2. �� Ϸ �� ��                    �d�g" << endl;
	cout << "�d�g                                                    �d�g" << endl;
	cout << "�d�g                  3. �� �� �� Ϸ                    �d�g" << endl;
	cout << "�d�g                                                    �d�g" << endl;
	cout << "�d�g                                                    �d�g" << endl;
	cout << "�d�g                                                    �d�g" << endl;
	cout << "�d�g                                                    �d�g" << endl;
	cout << "�d�p�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�p�g" << endl;
	cout << "�^�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�a" << endl;
	cout << "��������Ҫ���еĲ�����1��2��3����";

	initUserData();

	int userinput = 0;
	cin >> userinput;

	switch (userinput)
	{
	case 1:
		return gameStart();
		break;

	case 2:
		return gameSetPage();
		break;

	case 3:
		return;
		break;

	default:
		cout << "�������������ѡ��" ;
		Sleep(1500);
		return initMenu();
	}
}

void Game::gameSetPage()
{
	system("cls");
	cout << "�X�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�[" << endl;
	cout << "�d�p�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�p�g" << endl;
	cout << "�d�g                                                    �d�g" << endl;
	cout << "�d�g         ����������������������������������         �d�g" << endl;
	cout << "�d�g         ��         �� Ϸ �� ��          ��         �d�g" << endl;
	cout << "�d�g         ����������������������������������         �d�g" << endl;
	cout << "�d�g                                                    �d�g" << endl;
	cout << "�d�g                                                    �d�g" << endl;
	cout << "�d�g                  1. �� �� �� ɫ                    �d�g" << endl;
	cout << "�d�g                                                    �d�g" << endl;
	cout << "�d�g                  2. �� �� �� ��                    �d�g" << endl;
	cout << "�d�g                                                    �d�g" << endl;
	cout << "�d�g                  3. �� �� �� ҳ                    �d�g" << endl;
	cout << "�d�g                                                    �d�g" << endl;
	cout << "�d�g                                                    �d�g" << endl;
	cout << "�d�g                                                    �d�g" << endl;
	cout << "�d�g                                                    �d�g" << endl;
	cout << "�d�p�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�p�g" << endl;
	cout << "�^�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�a" << endl;
	cout << "��������Ҫ���еĲ�����1��2��3����";

	int userinput = 0;
	cin >> userinput;
	switch (userinput)
	{
	case 1:
		return colorSetPage();
		break;

	case 2:
		return nameSetPage();
		break;

	case 3:
		return initMenu();
		break;

	default:
		cout << "�������������ѡ��";
		Sleep(1500);
		return gameSetPage();
	}
}

void Game::colorSetPage()
{
	system("cls");
	cout << "�X�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�[" << endl;
	cout << "�d�p�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�p�g" << endl;
	cout << "�d�g                                                    �d�g" << endl;
	cout << "�d�g         ����������������������������������         �d�g" << endl;
	cout << "�d�g         ��         �� �� �� ɫ          ��         �d�g" << endl;
	cout << "�d�g         ����������������������������������         �d�g" << endl;
	cout << "�d�g                                                    �d�g" << endl;
	cout << "�d�g                                                    �d�g" << endl;
	cout << "�d�g               1.�ڰ�        4.�̻�                 �d�g" << endl;
	cout << "�d�g                                                    �d�g" << endl;
	cout << "�d�g               2.�׺�        5.���                 �d�g" << endl;
	cout << "�d�g                                                    �d�g" << endl;
	cout << "�d�g               3.��ǳ��      6.�ϻ�                 �d�g" << endl;
	cout << "�d�g                                                    �d�g" << endl;
	cout << "�d�g                                                    �d�g" << endl;
	cout << "�d�g                                                    �d�g" << endl;
	cout << "�d�g                                                    �d�g" << endl;
	cout << "�d�p�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�p�g" << endl;
	cout << "�^�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�a" << endl;
	cout << "��ѡ����Ҫʹ�õ���ɫ����(������������ȡ����ɫ�趨)��";

	int userinput = 0;
	cin >> userinput;
	switch (userinput)
	{
	case 1:
		theColor = "color 0f";
	    break;

	case 2:
		theColor = "color f0";
		break;

	case 3:
		theColor = "color 1b";
		break;

	case 4:
		theColor = "color 2e";
		break;

	case 5:
		theColor = "color 4f";
		break;

	case 6:
		theColor = "color 5e";
		break;

	default:
		printf("����������κ����á�");
		return gameSetPage();
	}
	system(theColor.c_str());

	ofstream ofile("config");
	string of = theColor;
	ofile << of;
	ofile.close();

	return gameSetPage();
}

void Game::nameSetPage()
{
	system("cls");
	cout << "�X�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�[" << endl;
	cout << "�d�p�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�p�g" << endl;
	cout << "�d�g                                                    �d�g" << endl;
	cout << "�d�g         ����������������������������������         �d�g" << endl;
	cout << "�d�g         ��         �� �� �� ��          ��         �d�g" << endl;
	cout << "�d�g         ����������������������������������         �d�g" << endl;
	cout << "�d�g                                                    �d�g" << endl;
	cout << "�d�g                                                    �d�g" << endl;
	cout << "�d�g               ��ǰ���֣�                           �d�g" << endl;
	cout << "�d�g                                                    �d�g" << endl;
	cout << "�d�g                                                    �d�g" << endl;
	cout << "�d�g                                                    �d�g" << endl;
	cout << "�d�g          ע�⣺�޸����ֲ���Է�������Ӱ�졣        �d�g" << endl;
	cout << "�d�g              ��������޸�����������0��             �d�g" << endl;
	cout << "�d�g                                                    �d�g" << endl;
	cout << "�d�g                                                    �d�g" << endl;
	cout << "�d�g                                                    �d�g" << endl;
	cout << "�d�p�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�p�g" << endl;
	cout << "�^�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�a" << endl;
	cout << "��������Ҫ�޸ĵ����֣�";
	
	pos(32, 8);
	cout << theName;
	pos(22, 19);

	cin >> theName;
	if (theName == "0")
	{
		theName = "No Name";
	}
	else
	{
		pos(32,8);
		cout << theName;

		pos(0, 19);
		cout << "�޸���ɣ������Զ��������ò˵���" << endl;
		Sleep(1500);

		ofstream ofile("userdata");
		string of = theName + "\n" + theScore;
		ofile << of;
		ofile.close();
	}
	return gameSetPage();
}

void Game::initUI()
{
	system("cls");
	cout << "�X�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�[" << endl;
	cout << "�d�p�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�p�p�m�m�m�m�m�m�m�m�m�p�g" << endl;
	pos(0, 17);
	cout << "�d�p�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�p�p�j�j�j�j�j�j�j�j�j�p�g "<< endl;
	cout << "�^�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�a "<< endl;
	for (int i = 2; i<17; i++)
	{
		pos(0, i);
		cout << "�d�g";
		pos(34, i);
		cout << "�d�g";
		pos(56, i);
		cout << "�d�g";
	}
	pos(34, 2);
	cout << "�d�g��ǰ����:         �d�g";
	pos(34, 6);
	cout << "�d�p�j�j�j�j�j�j�j�j�j�p�g";
	pos(34, 7);
	cout << "�d�p�m�m�m�m�m�m�m�m�m�p�g";
	pos(34, 8);
	cout << "�d�g����������        �d�g";
	pos(34, 9);
	cout << "�d�g��ʹ�÷��������  �d�g";
	pos(34, 10);
	cout << "�d�g       ��         �d�g";
	pos(34, 11);
	cout << "�d�g     �����       �d�g";
	pos(34, 12);
	cout << "�d�g       ��         �d�g";
	pos(34, 13);
	cout << "�d�g��ʹ����ĸ������  �d�g";
	pos(34, 14);
	cout << "�d�g       ��         �d�g";
	pos(34, 15);
	cout << "�d�g     ���ӣ�       �d�g";
	pos(34, 16);
	cout << "�d�g��ʹ��esc������   �d�g";
}

int Game::mainLoop()
{
	Snake S;
	S.createFood();

	bool isOver = false;
	while (true)
	{
		S.keyBoardControl(isOver);
		S.isHitWall(isOver);
		S.Move();
		pos(38, 4);
		cout << S.score;
		S.isBiteSelf(isOver);
		if (isOver)
		{
			break;
		}
		Sleep(400);
	}

	return S.score;
}

void Game::gameOver(int fs)
{
	system("cls");
	cout << "�X�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�[" << endl;
	cout << "�d�p�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�p�g" << endl;
	cout << "�d�g                                                    �d�g" << endl;
	cout << "�d�g         ����������������������������������         �d�g" << endl;
	cout << "�d�g         ��         �� Ϸ �� ��          ��         �d�g" << endl;
	cout << "�d�g         ����������������������������������         �d�g" << endl;
	cout << "�d�g                                                    �d�g" << endl;
	cout << "�d�g                                                    �d�g" << endl;
	cout << "�d�g                                                    �d�g" << endl;
	cout << "�d�g                                                    �d�g" << endl;
	cout << "�d�g             �����ֵ÷�Ϊ��                         �d�g" << endl;
	cout << "�d�g                                                    �d�g" << endl;
	cout << "�d�g             ����ߵ÷�Ϊ��                         �d�g" << endl;
	cout << "�d�g                                                    �d�g" << endl;
	cout << "�d�g             ��������������˵���                   �d�g" << endl;
	cout << "�d�g                                                    �d�g" << endl;
	cout << "�d�g                                                    �d�g" << endl;
	cout << "�d�p�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�j�p�g" << endl;
	cout << "�^�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�m�a" << endl;

	pos(17, 8);
	cout << "��Ϸ�Ѿ�����";

	stringstream ss; ss << theScore;
	int ds; ss >> ds; ss.clear();
	if (fs >= ds)
	{
		ss << fs;
		ss >> theScore; ss.clear();
	}

	pos(31, 10);
    cout << fs;
	pos(31, 12);
	cout << theScore;

	ofstream ofile("userdata");
	string of = theName + "\n" + theScore;
	ofile << of;
	ofile.close();

	_getch();

	run();
}