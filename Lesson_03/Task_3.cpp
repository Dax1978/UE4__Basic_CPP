#include <iostream>
#include <string>


int main()
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");

    // std::string s = std::to_string(42);
    int arr[3][3][3];
    int* pArr = nullptr;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                arr[i][j][k] = stoi(std::to_string(i + 1) + std::to_string(j + 1) + std::to_string(k + 1));
            };
        };
    };

    std::cout << "Текущее значение arr[1][1][1] без указателей = " << arr[1][1][1] << std::endl;

    // Считываем адрес на элемент 3d массива [1][1][1]
    pArr = &arr[1][1][1];
    // Выводим значение из полученного адреса на элемент 3d массива [1][1][1], разименовывая указатель
    std::cout << "Текущее значение arr[1][1][1] через указатель = " << *pArr << std::endl;
    // Меняем значение в массиве по указанному адресу
    *pArr = 777;
    // Выводим новое значение из полученного адреса на элемент 3d массива [1][1][1], разименовывая указатель
    std::cout << "Текущее значение arr[1][1][1] через указатель = " << *pArr << std::endl;
    std::cout << "Текущее значение arr[1][1][1] без указателей = " << arr[1][1][1] << std::endl;

    return 0;
}