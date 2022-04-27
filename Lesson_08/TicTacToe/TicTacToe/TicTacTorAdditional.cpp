#include <iostream>
#include "variable.h"

// ВСПОМАГАТЕЛЬНЫЕ ФУНКЦИИ
/*
Вспомогательные функции всегда желательно писать максимально абстрактно и атомарно(одна функция - одно действие),
чтобы иметь возможность переиспользования их в других проектах, создания библиотек таких функций или вовсе создания
собственного игрового движка. Поэтому мы выделили написание всех вспомогательных функций в отдельную секцию.
С предыдущих занятий у нас было описана пара полезных макросов, вспомним их и применим в соответствующих функциях
получения значения и проверки попадания символа в поле, сразу дополним эти функции установщиком значений и
проверкой на наличие символа в клетке
*/

#define CHK_DOT(x, sz) ((x) >= 0 && (x) < (sz))
#define POINT_ITEM(a, r, c) (*((*(a + r)) + c))

char getval(PLAYER** array, const int row, const int col) {
	return POINT_ITEM(array, row, col);
}
void setval(PLAYER** array, const int row, const int col, PLAYER value) {
	POINT_ITEM(array, row, col) = value;
}
int isvalid(Field& field, int x, int y) {
	return CHK_DOT(x, field.szX) && CHK_DOT(y, field.szY);
}
int isempty(Field& field, int x, int y) {
	return getval(field.map, y, x) == EMPTY;
}

int linechk(Field& field, int y, int x, int vx, int vy, int len, PLAYER c);

// Проверка победы делающего ход
int winchk(Field& field, PLAYER c) {
	for (int y = 0; y < field.szX; y++) {
		for (int x = 0; x < field.szY; x++) {
			if (linechk(field, y, x, 1, 0, field.towin, c)) return 1;
			if (linechk(field, y, x, 1, 1, field.towin, c)) return 1;
			if (linechk(field, y, x, 0, 1, field.towin, c)) return 1;
			if (linechk(field, y, x, 1, -1, field.towin, c)) return 1;
		}
	}
	return 0;
}

// Проверка на ничью
int isdraw(Field& field) {
	for (int y = 0; y < field.szY; y++)
		for (int x = 0; x < field.szX; x++)
			if (isempty(field, x, y))
				return 0;
	return 1;
}

int linechk(Field& field, int y, int x, int vx, int vy, int len, PLAYER c) {
	const int endx = x + (len - 1) * vx;
	const int endy = y + (len - 1) * vy;
	if (!isvalid(field, endx, endy))
		return 0;
	for (int i = 0; i < len; i++)
		if (getval(field.map, (y + i * vy), (x + i * vx)) != c)
			return 0;
	return 1;
}

int gamechk(Field& field, PLAYER dot, const std::string& winString) {
	if (winchk(field, dot)) {
		std::cout << winString << std::endl;
		return 1;
	}
	if (isdraw(field)) {
		std::cout << "draw" << std::endl;
		return 1;
	}
	return 0;
}

int aiwinchk(Field& field) {
	for (int y = 0; y < field.szY; y++) {
		for (int x = 0; x < field.szX; x++) {
			if (isempty(field, x, y)) {
				setval(field.map, y, x, AI);
				if (winchk(field, AI))
					return 1;
				setval(field.map, y, x, EMPTY);
			}
		}
	}
	return 0;
}

int humwinchk(Field& field) {
	for (int y = 0; y < field.szY; y++) {
		for (int x = 0; x < field.szX; x++) {
			if (isempty(field, x, y)) {
				setval(field.map, y, x, HUMAN);
				if (winchk(field, HUMAN)) {
					setval(field.map, y, x, AI);
					return 1;
				}
				setval(field.map, y, x, EMPTY);
			}
		}
	}
	return 0;
}

// проверка ввода целого числа
int enterInt(std::string msg) {
	setlocale(LC_ALL, "Russian");

	int x;
	bool success = false;
	while (!success)
	{
		std::cout << msg;
		std::cin >> x;
		if (std::cin.good()) {
			success = true;
			return x;
		} else {
			std::cout << "Значение введено неверно. Повторите ввод." << std::endl;
			std::cin.clear();
			_flushall();
		}
	}
}