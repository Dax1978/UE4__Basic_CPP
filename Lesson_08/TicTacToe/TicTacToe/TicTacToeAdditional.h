#pragma once
#include "variable.h"

char getval(PLAYER** array, const int row, const int col);
void setval(PLAYER** array, const int row, const int col, PLAYER value);
int isvalid(Field& field, int x, int y);
int isempty(Field& field, int x, int y);
int gamechk(Field& field, PLAYER dot, const std::string& winString);
int aiwinchk(Field& field);
int humwinchk(Field& field);

// проверка ввода целого числа
int enterInt(std::string msg);