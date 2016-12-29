#include "Snake.h"

using namespace std;

uniform_int_distribution<unsigned> uraw(0, 14);
uniform_int_distribution<unsigned> ucol(0, 14);
default_random_engine e;

Snake::Snake()
{
	for (auto &p : snakeBody)
	{
		pos(p.raw, p.column);
		cout << "¡ö";
	}
}

void Snake::createFood()
{
	int x = uraw(e) * 2 + 4;
	int y = ucol(e) + 2;
	Point p(x, y);
	food = p;

	pos(x,y);
	cout << "¡õ";
}

void Snake::keyBoardControl(bool &isOver)
{
	int input, tmpKey;
	if (_kbhit())
	{
		input = _getch();
		if (input == 0xe0)
		{
			tmpKey = _getch();
		}
		else if (input == keyW || input == keyS || input == keyA || input == keyD)
		{
			tmpKey = input;
		}
		else if (input == keyESC)
		{
			isOver = true;
			return;
		}
		switch (tmpKey)
		{
		case keyW:
		case keyUP:
			if (direction != DOWN)
				direction = UP;
			break;
		case keyS:
		case keyDOWN:
			if (direction != UP)
				direction = DOWN;
			break;
		case keyA:
		case keyLEFT:
			if (direction != RIGHT)
				direction = LEFT;
			break;
		case keyD:
		case keyRIGHT:
			if (direction != LEFT)
				direction = RIGHT;
			break;
		}
	}
}

void Snake::isHitWall(bool &isOver)
{
	auto head = snakeBody.begin();
	if ((*head).raw == 2 || (*head).raw == 34 || (*head).column == 1 || (*head).column == 17)
	{
		isOver = true;
	}
}

void Snake::Move()
{
	Point p;
	auto head = snakeBody.begin();
	switch (direction)
	{
	case UP:
		p.raw = head->raw;
		p.column = head->column - 1;
		break;
	case DOWN:
		p.raw = head->raw;
		p.column = head->column + 1;
		break;
	case LEFT:
		p.raw = head->raw - 2;
		p.column = head->column;
		break;
	case RIGHT:
		p.raw = head->raw + 2;
		p.column = head->column;
		break;
	}
	snakeBody.push_front(p);
	head = snakeBody.begin();

	if (head->raw == food.raw && head->column == food.column)
	{
		for (auto &l:snakeBody)
		{
			pos(l.raw, l.column);
			cout << "¡ö";
		}

		++score;
		createFood();
	}
	else
	{
		for (auto &l : snakeBody)
		{
			pos(l.raw, l.column);
			cout << "¡ö";
		}

		auto end = snakeBody.end(); --end;

		pos(end->raw,end->column);
		cout<<"  ";
		snakeBody.pop_back();
	}
}

void Snake::isBiteSelf(bool &isOver)
{
	auto p = snakeBody.begin();
	auto p1 = p; ++p1;
	for (;p1!=snakeBody.end();++p1)
	{
		if (p1->raw==p->raw && p1->column==p->column)
		{
			isOver = true;
		}
	}
}