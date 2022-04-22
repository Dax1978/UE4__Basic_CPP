////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Задание 4                                                                                                      //
// Объявить структуру Сотрудник с различными полями. Сделайте для нее побайтовое выравнивание с помощью           //
// директивы pragma pack. Выделите динамически переменную этого типа. Инициализируйте ее. Выведите ее на экран и  //
// ее размер с помощью sizeof. Сохраните эту структуру в текстовый файл                                           //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <stdio.h>

#include <iostream>
#include <fstream>

struct EmployeeRaw {
	std::string name; 
	std::string surname;
	bool boss;
	int salary;
	int bonus;
	char access;
};

// Выравнивание полей
#pragma pack(push, 1)
struct Employee {
	std::string name;
	std::string surname;
	bool boss;
	int salary;
	int bonus;
	char access;
};
#pragma pack(pop)

// Вывод данных из струтуры Сотрудник
void printEmployee(Employee emp) {
	std::cout << "Сотрудник: " << emp.surname << " " << emp.name << std::endl;
	if (emp.boss) {
		std::cout << "Занимает руководящую должность" << std::endl;
	} 	else {
		std::cout << "Специалист" << std::endl;
	}
	std::cout << "Оклад: " << emp.salary << " Премия: " << emp.bonus << std::endl;
	std::cout << "Имеет уровень доступа: " << emp.access << std::endl;
	std::cout << "Размер записи о сотруднике: " << sizeof(emp) << " байт" << std::endl;
}


// запись структуры Сотрудник в файл
int saveEmployee(const char* filename, struct Employee* p) {
	// std::cout << std::endl << "Запись" << std::endl;
	// printEmployee(*p);
	std::ofstream f1(filename, std::ios::binary | std::ios::out);
	f1.write((char*)&p, sizeof(p));
	f1.close();
	return 0;
}

// Чтение структуры Сотрудник из файла
Employee readEmployee(const char* filename) {
	Employee *p;
	std::ifstream f2(filename, std::ios::binary | std::ios::in);
	f2.read((char*)&p, sizeof(p));
	f2.close();
	return *p;
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");

	Employee emp;
	emp.name = "Иван";
	emp.surname = "Иванов";
	emp.boss = true;
	emp.salary = 300000;
	emp.bonus = 200000;
	emp.access = 'A';

	// Размер исходной невыровненной структуры
	EmployeeRaw empRaw;
	std::cout << "Размер не выровненной структуры: " << sizeof(empRaw) << " байт" << std::endl << std::endl;

	// Вывод инициализированной структуры
	std::cout << "Вывод инициализированной и выровненной структуры:" << std::endl;
	printEmployee(emp);

	// Запись в файл струтуры
	char filename[] = "Task_4.dat";
	saveEmployee(filename, &emp);
	std::cout << std::endl << "Структура записана в файл: " << filename << std::endl;

	// Чтение структуры
	Employee empRead = readEmployee(filename);
	std::cout << std::endl << "Прочитанные данные из файла:" << std::endl;
	printEmployee(empRead);

	return 0;
}