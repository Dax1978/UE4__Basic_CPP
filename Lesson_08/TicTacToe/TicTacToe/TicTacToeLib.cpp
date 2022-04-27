#include <iostream>
#include <random>

#include "variable.h"
#include "TicTacToeAdditional.h"
#include <windows.h>

void settings(Field &field) {
	std::cout << "Приветсвую Вас в игре \"Крестики - Нолики!\"!" << std::endl;
	std::cout << "В англоязычных странах, ее называют \"Tic-tac-toe\"." << std::endl;

	// Определим размер поля
	int size_field = 0;
	bool success = false;
	while (!success) {
		size_field = enterInt("Укажите желаемый размер игрового поля (обычно размер игрового поля 3): ");
		if (size_field >= 3) {
			success = true;
			field.towin = size_field;
			field.szY = size_field;
			field.szX = size_field;
		} else {
			std::cout << "Ошибка! Слишком малый размер игрового поля." << std::endl;
		}
	}
	
	// Определим сколько в ряд нужно поставить элементов для выигрыша
	size_field = 0;
	success = false;
	while (!success) {
		size_field = enterInt("Укажите количество элементов для выигрыша: ");
		if (size_field > field.szY) {
			std::cout << "Ошибка! Слишком большое значение. Значение не может быть больше размера игрового поля." << std::endl;
		} else if (size_field < 3) {
			std::cout << "Ошибка! Слишком малое значение. Значение не может быть меньше 3." << std::endl;
		} else {
			success = true;
			field.towin = size_field;
		}
	}
	
	// Установка режима продвинутого интелекта
	field.bool_ai = false;
	std::string answer;
	std::cout << "Включить режим улучшенной логики компьютера? Укажите y/n или yes/no: ";
	std::cin >> answer;
	if (answer.find('y') == 0) field.bool_ai = true;
}

// Начать новую игру
void init(Field &field) {
	settings(field);
	// field.towin = 3;
	// field.szY = 3;
	// field.szX = 3;
	field.map = (PLAYER**)calloc(sizeof(PLAYER*), field.szY);
	for (int y = 0; y < field.szY; ++y) {
		*(field.map + y) = (PLAYER*)calloc(sizeof(PLAYER), field.szX);
		for (int x = 0; x < field.szX; ++x) {
			setval(field.map, y, x, EMPTY);
		}
	}
}

// Вывести текущее состояние поля
void print(Field &field) {
	//#include <windows.h>
	std::system("cls");
	std::system("clear");

	// Вывод статистики игры
	std::cout << "Игра # " << field.game + 1 << std::endl;
	std::cout << "Выигрышей: " << field.wingame << std::endl;
	std::cout << "Проигрышей: " << field.losergame << std::endl;
	std::cout << std::endl;

	printf("-------\n");
	for (int i = 0; i < field.szY; ++i) {
		std::cout << "|";
		for (int j = 0; j < field.szX; ++j) {
			printf("%c|", getval(field.map, i, j));
		}
		std::cout << std::endl;
	}
}

// Ход игрока
void human(Field &field) {
	int x;
	int y;
	do {
		printf("Введите координаты хода X и Y (от 1 до %d) через пробел >>",
			field.szY);
		std::cin >> x >> y;
		// C-style
		// scanf("%d %d", &x, &y);
		// need to check if numbers are entered
		x--; y--;
	} while (!isvalid(field, x, y) || !isempty(field, x, y));
	setval(field.map, y, x, HUMAN);
}
// Ход компьютера
void ai(Field &field) {
	int x, y;
	//C++11 <random>
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<double> dist(0, 3);
	
	do {
		// C-style
		// x = rand() % field->szX;
		// y = rand() % field->szY;
		x = dist(mt);
		y = dist(mt);
	} while (!isempty(field, x, y));
	setval(field.map, y, x, AI);

	if (field.bool_ai) {
		aiwinchk(field);
		humwinchk(field);
	};
}

// Игровой цикл
void tictactoe() {
	Field field;
	// Установка счетчика сыгранных игр
	field.game = 0;
	// Установка счетчика выигранных и проигранных игр
	field.wingame = 0;
	field.losergame = 0;
	// C-style
	// while (1) {
	while (true) {
		init(field);
		print(field);
		while (true) {
			human(field);
			print(field);
			if (gamechk(field, HUMAN, "Human win!")) {
				field.wingame++;
				break;
			};
			ai(field);
			print(field);
			if (gamechk(field, AI, "AI win!")) {
				field.losergame++;
				break;
			};
		}
		// C-style
		// char answer[1];
		// scanf("%s", answer);
		// if (strcasecmp(answer, "y") != 0)
		// break;
		std::string answer;
		std::cout << "Играем снова (y/n или yes/no)? ";
		// one word to separator
		std::cin >> answer;
		// STL <algorithm>
		transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
		// only "y"
		// if (answer != "y")
		// consider y, yo, ya, yes, yeah, yep, yay, etc
		if (answer.find('y') != 0) break;
		field.game++;
	}
}


