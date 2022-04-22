////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Задание 1                                                                                                      //
// Создайте проект из 2х cpp файлов и заголовочного (main.cpp, mylib.cpp, mylib.h) во втором модуле mylib         //
// объявить 3 функции: для инициализации массива(типа float), печати его на экран и подсчета количества           //
// отрицательных и положительных элементов.Вызывайте эти 3 - и функции из main для работы с массивом              //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Task_1_mylib.h"

const int L_ARR = 7;

int main()
{
    setlocale(LC_ALL, "Russian");

    float* arr = makeArr(L_ARR);
    printArr(arr, L_ARR);
    calcPositiveNegative(arr, L_ARR);
    /*std::pair<int, int> result = calcPositiveNegative(arr, L_ARR);
    std::cout << "Положительных элементов = " << result.first << " шт. Отрицательных элементов = " << result.second << " шт." << std::endl;*/
    delete[] arr;
    return 0;
}