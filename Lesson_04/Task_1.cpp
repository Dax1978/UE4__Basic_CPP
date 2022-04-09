#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");

    int iFirst;
    int iSecond;

    std::cout << "Введите первое целое число: ";
    std::cin >> iFirst;
    std::cout << "Введите второе целое число: ";
    std::cin >> iSecond;

    if ((iFirst + iSecond) >= 10 && (iFirst + iSecond) <= 20)
    {
        std::cout << std::boolalpha << true;
    }
    else
    {
        std::cout << std::boolalpha << false;
    };

    return 0;
}