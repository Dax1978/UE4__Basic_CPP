#include <iostream>
// Модуль для работы с типами данных
#include <typeinfo>

// ГЛОБАЛЬНЫЕ ПЕРЕМЕННЫЕ
// Принципиально назвал как локальные, для показа доступа к локальным и глобальным переменным
bool bMyBool = true; // Объявление и инициализация логической переменной
char sMyChar = 'А'; // Объявление и инициализация переменной типа char
short int iMyShortInt1 = -100; // Объявление и инициализация переменной типа short int
unsigned short int iMyShortInt2 = 100; // Объявление и инициализация переменной беззнакового типа short int
int iMyInt1 = -100; // Объявление и инициализация переменной типа int
unsigned int iMyInt2 = 100; // Объявление и инициализация переменной беззнакового типа int
long long lMyLong1 = -100ll; // Объявление и инициализация переменной типа long
unsigned long long lMyLong2 = 100ll; // Объявление и инициализация переменной беззнакового типа long long
float fMyFloat = -100.234f; // Объявление и инициализация переменной типа float
double dMyDouble = 100.234; // Объявление и инициализация переменной типа double

int main()
{
    // Для использования русского языка
    setlocale(LC_ALL, "Russian");
    // Для нормального вывода русских букы в cout
    system("chcp 1251");
    // Проверка вывода русского текста
    std::cout << "Привет мир!\n";

    // ЛОКАЛЬНЫЕ ПЕРЕМЕННЫЕ
    bool bMyBool; // Объявление логической переменной
    bMyBool = false; // Инициализация переменной (присваивание первый раз значения переменной)
    std::cout << "Значение локальной переменной bMyBool: " << std::boolalpha << bMyBool << ". Тип переменной: " << typeid(bMyBool).name() << ". Размер в памяти: " << sizeof(bMyBool) << " байт." << std::endl;
    std::cout << "Значение глобальной переменной bMyBool: " << std::boolalpha << ::bMyBool << ". Тип переменной: " << typeid(::bMyBool).name() << ". Размер в памяти: " << sizeof(::bMyBool) << " байт." << std::endl;
    char sMyChar = 'Б'; // Объявление и инициализация переменной типа char
    std::cout << "Значение локальной переменной sMyChar: " << sMyChar << ". Тип переменной: " << typeid(sMyChar).name() << ". Размер в памяти: " << sizeof(sMyChar) << " байт." << std::endl;
    std::cout << "Значение глобальной переменной sMyChar: " << ::sMyChar << ". Тип переменной: " << typeid(::sMyChar).name() << ". Размер в памяти: " << sizeof(::sMyChar) << " байт." << std::endl;
    short int iMyShortInt1 = -200; // Объявление и инициализация переменной типа short int
    std::cout << "Значение локальной переменной iMyShortInt1: " << iMyShortInt1 << ". Тип переменной: " << typeid(iMyShortInt1).name() << ". Размер в памяти: " << sizeof(iMyShortInt1) << " байт." << std::endl;
    std::cout << "Значение глобальной переменной iMyShortInt1: " << ::iMyShortInt1 << ". Тип переменной: " << typeid(::iMyShortInt1).name() << ". Размер в памяти: " << sizeof(::iMyShortInt1) << " байт." << std::endl;
    unsigned short int iMyShortInt2 = 200; // Объявление и инициализация переменной беззнакового типа short int
    std::cout << "Значение локальной переменной iMyShortInt2: " << iMyShortInt2 << ". Тип переменной: " << typeid(iMyShortInt2).name() << ". Размер в памяти: " << sizeof(iMyShortInt2) << " байт." << std::endl;
    std::cout << "Значение глобальной переменной iMyShortInt2: " << ::iMyShortInt2 << ". Тип переменной: " << typeid(::iMyShortInt2).name() << ". Размер в памяти: " << sizeof(::iMyShortInt2) << " байт." << std::endl;
    int iMyInt1 = -200; // Объявление и инициализация переменной типа int
    std::cout << "Значение локальной переменной iMyInt1: " << iMyInt1 << ". Тип переменной: " << typeid(iMyInt1).name() << ". Размер в памяти: " << sizeof(iMyInt1) << " байт." << std::endl;
    std::cout << "Значение глобальной переменной iMyInt1: " << ::iMyInt1 << ". Тип переменной: " << typeid(::iMyInt1).name() << ". Размер в памяти: " << sizeof(::iMyInt1) << " байт." << std::endl;
    unsigned int iMyInt2 = 200; // Объявление и инициализация переменной беззнакового типа int
    std::cout << "Значение локальной переменной iMyInt2: " << iMyInt2 << ". Тип переменной: " << typeid(iMyInt2).name() << ". Размер в памяти: " << sizeof(iMyInt2) << " байт." << std::endl;
    std::cout << "Значение глобальной переменной iMyInt2: " << ::iMyInt2 << ". Тип переменной: " << typeid(::iMyInt2).name() << ". Размер в памяти: " << sizeof(::iMyInt2) << " байт." << std::endl;
    long long lMyLong1 = -200LL; // Объявление и инициализация переменной типа long
    std::cout << "Значение локальной переменной lMyLong1: " << lMyLong1 << ". Тип переменной: " << typeid(lMyLong1).name() << ". Размер в памяти: " << sizeof(lMyLong1) << " байт." << std::endl;
    std::cout << "Значение глобальной переменной lMyLong1: " << ::lMyLong1 << ". Тип переменной: " << typeid(::lMyLong1).name() << ". Размер в памяти: " << sizeof(::lMyLong1) << " байт." << std::endl;
    unsigned long long lMyLong2 = 200ll; // Объявление и инициализация переменной беззнакового типа long long
    std::cout << "Значение локальной переменной lMyLong2: " << lMyLong2 << ". Тип переменной: " << typeid(lMyLong2).name() << ". Размер в памяти: " << sizeof(lMyLong2) << " байт." << std::endl;
    std::cout << "Значение глобальной переменной lMyLong2: " << ::lMyLong2 << ". Тип переменной: " << typeid(::lMyLong2).name() << ". Размер в памяти: " << sizeof(::lMyLong2) << " байт." << std::endl;
    float fMyFloat = -200.234f; // Объявление и инициализация переменной типа float
    std::cout << "Значение локальной переменной fMyFloat: " << fMyFloat << ". Тип переменной: " << typeid(fMyFloat).name() << ". Размер в памяти: " << sizeof(fMyFloat) << " байт." << std::endl;
    std::cout << "Значение глобальной переменной fMyFloat: " << ::fMyFloat << ". Тип переменной: " << typeid(::fMyFloat).name() << ". Размер в памяти: " << sizeof(::fMyFloat) << " байт." << std::endl;
    double dMyDouble = 200.234; // Объявление и инициализация переменной типа double
    std::cout << "Значение локальной переменной dMyDouble: " << dMyDouble << ". Тип переменной: " << typeid(dMyDouble).name() << ". Размер в памяти: " << sizeof(dMyDouble) << " байт." << std::endl;
    std::cout << "Значение глобальной переменной dMyDouble: " << ::dMyDouble << ". Тип переменной: " << typeid(::dMyDouble).name() << ". Размер в памяти: " << sizeof(::dMyDouble) << " байт." << std::endl;
    auto fMyAouto = -345.456f; // Объявление и инициализация переменной типа auto, по сути float
    std::cout << "Значение локальной переменной fMyAouto: " << fMyAouto << ". Тип переменной: " << typeid(fMyAouto).name() << ". Размер в памяти: " << sizeof(fMyAouto) << " байт." << std::endl;
    
    return 0;
}