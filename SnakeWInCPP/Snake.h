#ifndef _SNAKE_H_
#define _SNAKE_H_

#include <list>
#include <random>
#include <conio.h>
#include "IOFuncs.h"

#define keyLEFT 0x4b
#define keyRIGHT 0x4d
#define keyUP 0x48
#define keyDOWN 0x50
#define keyA 0x61
#define keyD 0x64
#define keyW 0x77
#define keyS 0x73
#define keyESC 0x1b

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

struct Point
{
	Point() = default;
	Point(int x, int y) :raw(x), column(y) {}
	int raw = 0;
	int column = 0;
};

class Snake
{
public:
	Snake();
	
	void createFood();
	void keyBoardControl(bool &isOver);
	void isHitWall(bool &isOver);
	void Move();
	void isBiteSelf(bool &isOver);
	
	int score = 0;

private:
	std::list<Point> snakeBody{ { 20,9 },{ 18,9 },{ 16,9 } };

	Point food;
	//UP:1  DOWN:2  LEFT:3  RIGHT:4
	int direction = 4;
};

#endif // !_SNAKE_H_