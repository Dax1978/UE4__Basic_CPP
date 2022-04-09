#include <iostream>
#include <iomanip>

void fillMatrix(int** arr, unsigned int dim, int num)
{
    for (int i = 0; i < dim; i++)
        for (int j = 0; j < dim; j++)
            arr[i][j] = num;
}

void displayMatrix(int **arr, unsigned int dim)
{
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
            std::cout << std::setw(4) << arr[i][j];
        std::cout << std::endl;
    };
    std::cout << std::endl;
};

void fillDiagonalsOne(int** arr, unsigned int dim)
{
    int j = dim - 1;
    for (int i = 0; i < dim; i++)
    {
        arr[i][i] = 1;
        arr[i][j] = 1;
        j--;
    };
};

int main()
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");

    // Размерность квадратной матрицы
    const unsigned int DIM = 7;
    // Квадратная матрица
    int **arr;
    arr = new int* [DIM];
    for (int i = 0; i < DIM; i++)
        arr[i] = new int[DIM];

    fillMatrix(arr, DIM, 0);
    std::cout << "Исходная квадратная матрица, заполненная 0:" << std::endl;
    displayMatrix(arr, DIM);
    fillDiagonalsOne(arr, DIM);
    std::cout << "Главная и побочная диагонали квадратной матрицы, заполненные 1:" << std::endl;
    displayMatrix(arr, DIM);

    for (int i = 0; i < DIM; i++)
        delete []arr[i];
    delete[]arr;

    return 0;
}