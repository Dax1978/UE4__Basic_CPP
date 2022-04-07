#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");

    int someInt;
    int result;
    std::cout << "Введите целое число: ";
    std::cin >> someInt;
    result = (someInt <= 21) ? (21 - someInt) : (someInt - 21) * 2;
    std::cout << "Результат: " << result;

    return 0;
}
