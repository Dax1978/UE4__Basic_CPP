#include <iostream>

#include "variable.h"
#include "TicTacToeLib.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    tictactoe();

    std::cout << "Спасибо за Вашу игру!\n";
    return 0;
}