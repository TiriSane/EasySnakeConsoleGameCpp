#ifndef _IO_FUNCS_H_
#define _IO_FUNCS_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <Windows.h>

void pos(int x, int y);

void loadUserDataFromFile(std::string &theName, std::string &theScore);

#endif // !_IO_FUNCS_H_