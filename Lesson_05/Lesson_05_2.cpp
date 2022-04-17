// Lesson_05_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Lesson_05_library.h"
#include <cmath>

int main()
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    std::cout << std::endl;

    const int SIZE_ARR_10 = 10;
    const int SIZE_ARR_8 = 8;
    const int SIZE_ARR_7 = 7;
    std::cout << "Практическое задание 5. Все функции перенесены в отдельную динамическую библиотеку Lesson_05_DLL.dll.\n";
    std::cout << std::endl << std::endl << std::endl;

    std::cout << "Задание 1:\n";
    std::cout << "Написать функцию которая выводит массив double чисел на экран. Параметры функции\n";
    std::cout << "это сам массив и его размер. Вызвать эту функцию из main.\n";
    std::cout << "Решение:\n";
    double arr1[SIZE_ARR_10] = { 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0 };
    printMassiveDouble(SIZE_ARR_10, arr1);
    std::cout << std::endl << std::endl << std::endl;


    std::cout << "Задание 2:\n";
    std::cout << "Задать целочисленный массив, состоящий из элементов 0 и 1. Например: [ 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 ].\n";
    std::cout << "Написать функцию, заменяющую в принятом массиве 0 на 1, 1 на 0. Выводить на экран массив до изменений и после.\n";
    std::cout << "(Не используются if..else или case)\n";
    int arr2[SIZE_ARR_10] = { 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 };
    std::cout << "Решение:\n";
    std::cout << "Исходный массив: ";
    printMassiveInt(SIZE_ARR_10, arr2);
    change1and0massive(SIZE_ARR_10, arr2);
    std::cout << "\nРезультат: ";
    printMassiveInt(SIZE_ARR_10, arr2);
    std::cout << std::endl << std::endl << std::endl;

    std::cout << "Задание 3:\n";
    std::cout << "Задать пустой целочисленный массив размером 8. Написать функцию, которая с помощью цикла заполнит его\n";
    std::cout << "значениями 1 4 7 10 13 16 19 22. Вывести массив на экран.\n";
    int arr3[SIZE_ARR_8];
    fillMassiveThrough3(SIZE_ARR_8, arr3);
    std::cout << "\nРезультат: ";
    printMassiveInt(SIZE_ARR_8, arr3);
    std::cout << std::endl << std::endl << std::endl;

    std::cout << "Задание 4:\n";
    std::cout << "Написать функцию, которой на вход подаётся одномерный массив и число n (может быть положительным, или\n";
    std::cout << "отрицательным), при этом метод должен циклически сместить все элементы массива на n позиций.\n";
    int arr4[SIZE_ARR_10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    std::cout << "Решение:\n";
    std::cout << "Исходный массив: ";
    printMassiveInt(SIZE_ARR_10, arr4);    
    std::cout << "\nРезультат смещения вправо на 13: ";
    offsetMassive(SIZE_ARR_10, arr4, 13);
    printMassiveInt(SIZE_ARR_10, arr4);    
    std::cout << "\nРезультат смещения влево на -37: ";
    offsetMassive(SIZE_ARR_10, arr4, -37);
    printMassiveInt(SIZE_ARR_10, arr4);
    std::cout << "\nУкажите свое смещение массива: ";
    int offset;
    std::cin >> offset;
    std::cout << "\nРезультат смещения на " << offset << ": ";
    offsetMassive(SIZE_ARR_10, arr4, offset);
    printMassiveInt(SIZE_ARR_10, arr4);
    std::cout << std::endl << std::endl << std::endl;
    
    std::cout << "Задание 5:\n";
    std::cout << "Написать функцию, которой передается не пустой одномерный целочисленный массив, она должна вернуть \n";
    std::cout << "истину если в массиве есть место, в котором сумма левой и правой части массива равны.\n";
    std::cout << "Примеры:\n";
    std::cout << "         checkBalance([1, 1, 1, || 2, 1]) → true\n";
    std::cout << "         checkBalance([2, 1, 1, 2, 1]) → false\n";
    std::cout << "         checkBalance([10, || 1, 2, 3, 4]) → true\n";
    std::cout << "Абстрактная граница показана символами || , эти символы в массив не входят.\n";
    std::cout << "Решение:\n";
    std::cout << "Для начала заполним 7 элементов массива.\n";
    int arr5[SIZE_ARR_7];
    enterMassive(SIZE_ARR_7, arr5);
    std::cout << "Вы ввели массив: ";
    printMassiveInt(SIZE_ARR_7, arr5);       
    std::cout << "\nВозможность разделить массив: " << std::boolalpha << equalMassive(SIZE_ARR_7, arr5) << std::endl;
    std::cout << std::endl << std::endl << std::endl;
}