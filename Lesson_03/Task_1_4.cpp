#include <iostream>

extern const int a;
extern const int b;
extern const int c;
extern const int d;

int main()
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");

    float e = static_cast <float> (a) * ( static_cast <float> (b) + ( static_cast <float> (c) / (float)d ) );
    std::cout << "Полученное значение выражения a * (b + (c / d)) = " << e << "\n";

    return 0;
}