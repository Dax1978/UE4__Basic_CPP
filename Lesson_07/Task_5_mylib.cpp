#include <iostream>
#include <cstdlib>
#include <ctime>

namespace MyLib
{
    const float ARR_MIN = -100.0;
    const float ARR_MAX = 101.0;

    // ������� ��������� ������������ ����� � �������� ��������� min : max
    float randFloat(float min, float max) {
        return rand() * (max - min) / RAND_MAX + min;
    }

    // ������� ������ ������������ ����� ������ n
    float* makeArr(const int n) {
        srand(time(0));
        float* arr = new float[n];
        for (rsize_t i = 0; i < n; i++) {
            arr[i] = randFloat(ARR_MIN, ARR_MAX);
        }
        return arr;
    }

    // ������ �������
    void printArr(float* arr, int n) {
        for (rsize_t i = 0; i < n; i++) {
            std::cout << arr[i] << "  ";
        };
        std::cout << "\n";
    }

    // ������ ���������� ������������� � ������������� ���������
    //std::pair<int, int> calcPositiveNegative(float* arr, int n) {
    //    int positive = 0;
    //    int negative = 0;
    //    for (rsize_t i = 0; i < n; i++) arr[i] >= 0 ? positive++ : negative++;
    //    return std::make_pair(positive, negative);
    //}
    void calcPositiveNegative(float* arr, int n) {
        int positive = 0;
        int negative = 0;
        for (rsize_t i = 0; i < n; i++) arr[i] >= 0 ? positive++ : negative++;
        std::cout << "������������� ��������� = " << positive << " ��. ������������� ��������� = " << negative << " ��." << std::endl;
    }
}