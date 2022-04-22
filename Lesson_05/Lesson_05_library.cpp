#include "pch.h"
#include <iostream>
#include "Lesson_05_library.h"

void printMassiveDouble(int n, double* massive)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << massive[i] << "\t";
    }
}

void printMassiveInt(int n, int* massive)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << massive[i] << "\t";
    }
}

void change1and0massive(int n, int* massive)
{
    for (int i = 0; i < n; i++)
    {
        massive[i] = (massive[i] == 0);
    }
}

void fillMassiveThrough3(int n, int* massive)
{
    for (size_t i = 0, j = 1; i < n; i++, j += 3)
    {
        massive[i] = j;
    }
}

void offsetMassive(int n, int* arr, int offset)
{
    // Проверим смещение, если оно больше длины массива, то удаляем кратное длине массива
    if (abs(offset) >= n) offset = offset - (n * (offset / n));
    // Вводим промежуточный динамический массив
    int* p_arr = new int[n];
    // Смещаем позиции
    for (int i = 0, j = i + offset; i < n; i++, j++)
    {
        if (j < 0)
        {
            p_arr[n + j] = arr[i];
        }
        else if (j > n - 1) {
            p_arr[j - n] = arr[i];
        }
        else {
            p_arr[j] = arr[i];
        }
    }
    // Правим основной массив
    for (int i = 0; i < n; i++) arr[i] = p_arr[i];
    // Удаляем динамический массив
    delete[] p_arr;
}

bool equalMassive(int n, int* arr)
{
    // Посчитаем общую сумму
    int sum = 0;
    int sumL = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    // проверим на четность. Если не четное, то и не будет равенств двух частей.
    // Если четное проверим возможность разделить на 2 равные части.
    if ((sum % 2) == 0)
    {
        for (int i = 0; i < n; i++)
        {
            sumL += arr[i];
            if (sumL == (sum - sumL)) return true;
        }
    }
    else {
        return false;
    }
}

void enterMassive(int n, int* arr)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << "Введите элемент массива #" << i + 1 << ": ";
        std::cin >> arr[i];
    }
}