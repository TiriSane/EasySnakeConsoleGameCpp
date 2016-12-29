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

	cout << "╔╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╗" << endl;
	cout << "╠╬╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╬╣" << endl;
	cout << "╠╣                                                    ╠╣" << endl;
	cout << "╠╣         ┏━━━━━━━━━━━━━━━┓         ╠╣" << endl;
	cout << "╠╣         ┃          贪  吃  蛇          ┃         ╠╣" << endl;
	cout << "╠╣         ┗━━━━━━━━━━━━━━━┛         ╠╣" << endl;
	cout << "╠╣                                                    ╠╣" << endl;
	cout << "╠╣                                                    ╠╣" << endl;
	cout << "╠╣                  1. 开 始 游 戏                    ╠╣" << endl;
	cout << "╠╣                                                    ╠╣" << endl;
	cout << "╠╣                  2. 游 戏 设 置                    ╠╣" << endl;
	cout << "╠╣                                                    ╠╣" << endl;
	cout << "╠╣                  3. 退 出 游 戏                    ╠╣" << endl;
	cout << "╠╣                                                    ╠╣" << endl;
	cout << "╠╣                                                    ╠╣" << endl;
	cout << "╠╣                                                    ╠╣" << endl;
	cout << "╠╣                                                    ╠╣" << endl;
	cout << "╠╬╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╬╣" << endl;
	cout << "╚╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╝" << endl;
	cout << "请输入您要进行的操作（1、2、3）：";

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
		cout << "输入错误，请重新选择！" ;
		Sleep(1500);
		return initMenu();
	}
}

void Game::gameSetPage()
{
	system("cls");
	cout << "╔╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╗" << endl;
	cout << "╠╬╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╬╣" << endl;
	cout << "╠╣                                                    ╠╣" << endl;
	cout << "╠╣         ┏━━━━━━━━━━━━━━━┓         ╠╣" << endl;
	cout << "╠╣         ┃         游 戏 设 置          ┃         ╠╣" << endl;
	cout << "╠╣         ┗━━━━━━━━━━━━━━━┛         ╠╣" << endl;
	cout << "╠╣                                                    ╠╣" << endl;
	cout << "╠╣                                                    ╠╣" << endl;
	cout << "╠╣                  1. 修 改 配 色                    ╠╣" << endl;
	cout << "╠╣                                                    ╠╣" << endl;
	cout << "╠╣                  2. 修 改 名 字                    ╠╣" << endl;
	cout << "╠╣                                                    ╠╣" << endl;
	cout << "╠╣                  3. 返 回 主 页                    ╠╣" << endl;
	cout << "╠╣                                                    ╠╣" << endl;
	cout << "╠╣                                                    ╠╣" << endl;
	cout << "╠╣                                                    ╠╣" << endl;
	cout << "╠╣                                                    ╠╣" << endl;
	cout << "╠╬╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╬╣" << endl;
	cout << "╚╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╝" << endl;
	cout << "请输入您要进行的操作（1、2、3）：";

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
		cout << "输入错误，请重新选择！";
		Sleep(1500);
		return gameSetPage();
	}
}

void Game::colorSetPage()
{
	system("cls");
	cout << "╔╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╗" << endl;
	cout << "╠╬╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╬╣" << endl;
	cout << "╠╣                                                    ╠╣" << endl;
	cout << "╠╣         ┏━━━━━━━━━━━━━━━┓         ╠╣" << endl;
	cout << "╠╣         ┃         修 改 配 色          ┃         ╠╣" << endl;
	cout << "╠╣         ┗━━━━━━━━━━━━━━━┛         ╠╣" << endl;
	cout << "╠╣                                                    ╠╣" << endl;
	cout << "╠╣                                                    ╠╣" << endl;
	cout << "╠╣               1.黑白        4.绿黄                 ╠╣" << endl;
	cout << "╠╣                                                    ╠╣" << endl;
	cout << "╠╣               2.白黑        5.红白                 ╠╣" << endl;
	cout << "╠╣                                                    ╠╣" << endl;
	cout << "╠╣               3.深浅蓝      6.紫黄                 ╠╣" << endl;
	cout << "╠╣                                                    ╠╣" << endl;
	cout << "╠╣                                                    ╠╣" << endl;
	cout << "╠╣                                                    ╠╣" << endl;
	cout << "╠╣                                                    ╠╣" << endl;
	cout << "╠╬╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╬╣" << endl;
	cout << "╚╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╝" << endl;
	cout << "请选择你要使用的配色方案(输入其他数字取消颜色设定)：";

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
		printf("将不会更改任何设置。");
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
	cout << "╔╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╗" << endl;
	cout << "╠╬╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╬╣" << endl;
	cout << "╠╣                                                    ╠╣" << endl;
	cout << "╠╣         ┏━━━━━━━━━━━━━━━┓         ╠╣" << endl;
	cout << "╠╣         ┃         修 改 名 字          ┃         ╠╣" << endl;
	cout << "╠╣         ┗━━━━━━━━━━━━━━━┛         ╠╣" << endl;
	cout << "╠╣                                                    ╠╣" << endl;
	cout << "╠╣                                                    ╠╣" << endl;
	cout << "╠╣               当前名字：                           ╠╣" << endl;
	cout << "╠╣                                                    ╠╣" << endl;
	cout << "╠╣                                                    ╠╣" << endl;
	cout << "╠╣                                                    ╠╣" << endl;
	cout << "╠╣          注意：修改名字不会对分数产生影响。        ╠╣" << endl;
	cout << "╠╣              如果不想修改名字请输入0。             ╠╣" << endl;
	cout << "╠╣                                                    ╠╣" << endl;
	cout << "╠╣                                                    ╠╣" << endl;
	cout << "╠╣                                                    ╠╣" << endl;
	cout << "╠╬╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╬╣" << endl;
	cout << "╚╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╝" << endl;
	cout << "请输入需要修改的名字：";
	
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
		cout << "修改完成，即将自动返回设置菜单。" << endl;
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
	cout << "╔╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╗" << endl;
	cout << "╠╬╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╬╬╩╩╩╩╩╩╩╩╩╬╣" << endl;
	pos(0, 17);
	cout << "╠╬╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╬╬╦╦╦╦╦╦╦╦╦╬╣ "<< endl;
	cout << "╚╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╝ "<< endl;
	for (int i = 2; i<17; i++)
	{
		pos(0, i);
		cout << "╠╣";
		pos(34, i);
		cout << "╠╣";
		pos(56, i);
		cout << "╠╣";
	}
	pos(34, 2);
	cout << "╠╣当前分数:         ╠╣";
	pos(34, 6);
	cout << "╠╬╦╦╦╦╦╦╦╦╦╬╣";
	pos(34, 7);
	cout << "╠╬╩╩╩╩╩╩╩╩╩╬╣";
	pos(34, 8);
	cout << "╠╣操作方法：        ╠╣";
	pos(34, 9);
	cout << "╠╣①使用方向键操作  ╠╣";
	pos(34, 10);
	cout << "╠╣       ↑         ╠╣";
	pos(34, 11);
	cout << "╠╣     ←●→       ╠╣";
	pos(34, 12);
	cout << "╠╣       ↓         ╠╣";
	pos(34, 13);
	cout << "╠╣②使用字母键操作  ╠╣";
	pos(34, 14);
	cout << "╠╣       Ｗ         ╠╣";
	pos(34, 15);
	cout << "╠╣     ＡＳＤ       ╠╣";
	pos(34, 16);
	cout << "╠╣③使用esc键结束   ╠╣";
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
	cout << "╔╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╗" << endl;
	cout << "╠╬╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╬╣" << endl;
	cout << "╠╣                                                    ╠╣" << endl;
	cout << "╠╣         ┏━━━━━━━━━━━━━━━┓         ╠╣" << endl;
	cout << "╠╣         ┃         游 戏 结 束          ┃         ╠╣" << endl;
	cout << "╠╣         ┗━━━━━━━━━━━━━━━┛         ╠╣" << endl;
	cout << "╠╣                                                    ╠╣" << endl;
	cout << "╠╣                                                    ╠╣" << endl;
	cout << "╠╣                                                    ╠╣" << endl;
	cout << "╠╣                                                    ╠╣" << endl;
	cout << "╠╣             您本局得分为：                         ╠╣" << endl;
	cout << "╠╣                                                    ╠╣" << endl;
	cout << "╠╣             您最高得分为：                         ╠╣" << endl;
	cout << "╠╣                                                    ╠╣" << endl;
	cout << "╠╣             按任意键返回主菜单。                   ╠╣" << endl;
	cout << "╠╣                                                    ╠╣" << endl;
	cout << "╠╣                                                    ╠╣" << endl;
	cout << "╠╬╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╦╬╣" << endl;
	cout << "╚╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╩╝" << endl;

	pos(17, 8);
	cout << "游戏已经结束";

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