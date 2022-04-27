#include <iostream>
#include <random>

#include "variable.h"
#include "TicTacToeAdditional.h"
#include <windows.h>

void settings(Field &field) {
	std::cout << "���������� ��� � ���� \"�������� - ������!\"!" << std::endl;
	std::cout << "� ������������ �������, �� �������� \"Tic-tac-toe\"." << std::endl;

	// ��������� ������ ����
	int size_field = 0;
	bool success = false;
	while (!success) {
		size_field = enterInt("������� �������� ������ �������� ���� (������ ������ �������� ���� 3): ");
		if (size_field >= 3) {
			success = true;
			field.towin = size_field;
			field.szY = size_field;
			field.szX = size_field;
		} else {
			std::cout << "������! ������� ����� ������ �������� ����." << std::endl;
		}
	}
	
	// ��������� ������� � ��� ����� ��������� ��������� ��� ��������
	size_field = 0;
	success = false;
	while (!success) {
		size_field = enterInt("������� ���������� ��������� ��� ��������: ");
		if (size_field > field.szY) {
			std::cout << "������! ������� ������� ��������. �������� �� ����� ���� ������ ������� �������� ����." << std::endl;
		} else if (size_field < 3) {
			std::cout << "������! ������� ����� ��������. �������� �� ����� ���� ������ 3." << std::endl;
		} else {
			success = true;
			field.towin = size_field;
		}
	}
	
	// ��������� ������ ������������ ���������
	field.bool_ai = false;
	std::string answer;
	std::cout << "�������� ����� ���������� ������ ����������? ������� y/n ��� yes/no: ";
	std::cin >> answer;
	if (answer.find('y') == 0) field.bool_ai = true;
}

// ������ ����� ����
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

// ������� ������� ��������� ����
void print(Field &field) {
	//#include <windows.h>
	std::system("cls");
	std::system("clear");

	// ����� ���������� ����
	std::cout << "���� # " << field.game + 1 << std::endl;
	std::cout << "���������: " << field.wingame << std::endl;
	std::cout << "����������: " << field.losergame << std::endl;
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

// ��� ������
void human(Field &field) {
	int x;
	int y;
	do {
		printf("������� ���������� ���� X � Y (�� 1 �� %d) ����� ������ >>",
			field.szY);
		std::cin >> x >> y;
		// C-style
		// scanf("%d %d", &x, &y);
		// need to check if numbers are entered
		x--; y--;
	} while (!isvalid(field, x, y) || !isempty(field, x, y));
	setval(field.map, y, x, HUMAN);
}
// ��� ����������
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

// ������� ����
void tictactoe() {
	Field field;
	// ��������� �������� ��������� ���
	field.game = 0;
	// ��������� �������� ���������� � ����������� ���
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
		std::cout << "������ ����� (y/n ��� yes/no)? ";
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


