#include <iostream>
// Для использования setw - для установки ширины вывода
#include <iomanip>
#include <string>

class TicTacToe {
private:
    // Перечисление вариантов символов в игре
    enum ticTacToe { n = ' ', x = 'X', o = 'O' };
    // Массив для хранения результатов игроков
    int aResult[2] = { 0, 0 };
    // Свойство для определения номера активного игрока
    int numPlayer = 1;
    // Свойство для сохранения количества сделанных за 1 игру ходов
    int numMove = 0;
    // Флаг окончания игры
    bool endGame = false;
    // Исходный массив    
    char aGame[3][3] = {
        { ticTacToe::n, ticTacToe::n, ticTacToe::n },
        { ticTacToe::n, ticTacToe::n, ticTacToe::n },
        { ticTacToe::n, ticTacToe::n, ticTacToe::n }
    };


    // Очистка игрпового поля
    void clearGame()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                aGame[i][j] = ticTacToe::n;
            };
        };
    };
    // Вывод текущего состояния игры на экран
    void printGameField()
    {
        std::cout << std::setw(4) << "    " << " 1  " << " 2  " << " 3" << std::endl;
        std::cout << std::endl;
        std::cout << " A  " << std::setw(2) << std::setfill(' ') << aGame[0][0] << " |" << std::setw(2) << aGame[0][1] << " |" << std::setw(2) << aGame[0][2] << std::endl;
        std::cout << std::setw(4) << "    " << std::setw(3) << "---" << " " << std::setw(3) << "---" << " " << std::setw(3) << "---" << std::endl;
        std::cout << " B  " << std::setw(2) << std::setfill(' ') << aGame[1][0] << " |" << std::setw(2) << aGame[1][1] << " |" << std::setw(2) << aGame[1][2] << std::endl;
        std::cout << std::setw(4) << "    " << std::setw(3) << "---" << " " << std::setw(3) << "---" << " " << std::setw(3) << "---" << std::endl;
        std::cout << " C  " << std::setw(2) << std::setfill(' ') << aGame[2][0] << " |" << std::setw(2) << aGame[2][1] << " |" << std::setw(2) << aGame[2][2] << std::endl;
    };
    // Проверка условий выигрыша
    int endingGame()
    {
        // Выигрыши игрока 1
        if (aGame[0][0] == ticTacToe::o and aGame[0][1] == ticTacToe::o and aGame[0][2] == ticTacToe::o) { return 0; };
        if (aGame[1][0] == ticTacToe::o and aGame[1][1] == ticTacToe::o and aGame[1][2] == ticTacToe::o) { return 0; };
        if (aGame[2][0] == ticTacToe::o and aGame[2][1] == ticTacToe::o and aGame[2][2] == ticTacToe::o) { return 0; };
        if (aGame[0][0] == ticTacToe::o and aGame[1][0] == ticTacToe::o and aGame[2][0] == ticTacToe::o) { return 0; };
        if (aGame[0][1] == ticTacToe::o and aGame[1][1] == ticTacToe::o and aGame[2][1] == ticTacToe::o) { return 0; };
        if (aGame[0][2] == ticTacToe::o and aGame[1][2] == ticTacToe::o and aGame[2][2] == ticTacToe::o) { return 0; };
        if (aGame[0][0] == ticTacToe::o and aGame[1][1] == ticTacToe::o and aGame[2][2] == ticTacToe::o) { return 0; };
        if (aGame[0][2] == ticTacToe::o and aGame[1][1] == ticTacToe::o and aGame[2][0] == ticTacToe::o) { return 0; };

        // Выигрышы игрока 2
        if (aGame[0][0] == ticTacToe::x and aGame[0][1] == ticTacToe::x and aGame[0][2] == ticTacToe::x) { return 1; };
        if (aGame[1][0] == ticTacToe::x and aGame[1][1] == ticTacToe::x and aGame[1][2] == ticTacToe::x) { return 1; };
        if (aGame[2][0] == ticTacToe::x and aGame[2][1] == ticTacToe::x and aGame[2][2] == ticTacToe::x) { return 1; };
        if (aGame[0][0] == ticTacToe::x and aGame[1][0] == ticTacToe::x and aGame[2][0] == ticTacToe::x) { return 1; };
        if (aGame[0][1] == ticTacToe::x and aGame[1][1] == ticTacToe::x and aGame[2][1] == ticTacToe::x) { return 1; };
        if (aGame[0][2] == ticTacToe::x and aGame[1][2] == ticTacToe::x and aGame[2][2] == ticTacToe::x) { return 1; };
        if (aGame[0][0] == ticTacToe::x and aGame[1][1] == ticTacToe::x and aGame[2][2] == ticTacToe::x) { return 1; };
        if (aGame[0][2] == ticTacToe::x and aGame[1][1] == ticTacToe::x and aGame[2][0] == ticTacToe::x) { return 1; }; 

        if (numMove == 9) { return 7; };
        
        // В противном случае возвращаем 100
        return 100;
    };
    // Метод для хода игрока
    void makeMove()
    {
        int row = 0;
        int col = 0;
        std::string movePlayer;
        std::cout << std::endl;
        std::cout << "Игрок " << numPlayer << " делайте свой ход!  ";
        std::cin >> movePlayer;
        
        if (movePlayer[0] == 'Q' or movePlayer[0] == 'q')
        {
            endGame = true;
        }
        else
        {   
            if (movePlayer[0] == 'A' or movePlayer[0] == 'a') { row = 0; };
            if (movePlayer[0] == 'B' or movePlayer[0] == 'b') { row = 1; };
            if (movePlayer[0] == 'C' or movePlayer[0] == 'c') { row = 2; };
            if (movePlayer[1] == '1') { col = 0; };
            if (movePlayer[1] == '2') { col = 1; };
            if (movePlayer[1] == '3') { col = 2; };

            if (aGame[row][col] == ticTacToe::n)
            {
                if (numPlayer == 1)
                {
                    aGame[row][col] = ticTacToe::o;
                    numPlayer = 2;
                }
                else
                {
                    aGame[row][col] = ticTacToe::x;
                    numPlayer = 1;
                }
                numMove++;
            }
            else
            {
                std::cout << "В указанном Вами поле уже имеется значение! Укажите другое поле.\n";
            };
        }
    };
    // 1 отдельная игра
    void playGame()
    {
        while (!endGame)
        {
            printGameField();
            // Делаем ход
            makeMove();
            if (!endGame)
            {
                // Записываем 
                int endG = endingGame();
                if (endG != 100)
                {
                    if (endG == 0)
                    {
                        std::cout << "Игрок 1 (O) выиграл!!!\n";
                        aResult[endG]++;
                        printGameField();
                        std::cout << std::endl << std::endl;
                        clearGame();
                        numMove = 0;
                        break;
                    }
                    if (endG == 1)
                    {
                        std::cout << "Игрок 2 (X) выиграл!!!\n";
                        aResult[endG]++;
                        printGameField();
                        std::cout << std::endl << std::endl;
                        clearGame();
                        numMove = 0;
                        break;
                    }
                    if (endG == 7)
                    {
                        std::cout << "Ну чтож, ничья!\n";
                        printGameField();
                        clearGame();
                        numMove = 0;
                        break;
                    };
                };
            }
            else
            {                
                break;
            }
        };
    }
    // Цикл игр
    void playGames()
    {
        std::cout << std::endl;
        std::cout << "Добро пожаловать в игру Крестики - Нолики!\n";
        std::cout << "Игрок 1 играет ноликами (O)\n";
        std::cout << "Игрок 2 играет крестиками (X)\n";
        std::cout << "Для хода укажите номер строки и колонки. Пример: A1 или a1.\n";
        std::cout << "Для выхода введите Q или q\n";
        while (!endGame)
        {
            playGame();
        };
        std::cout << std::endl << std::endl;
        std::cout << "Игрок 1 выиграл " << aResult[0] << " раз.\n";
        std::cout << "Игрок 2 выиграл " << aResult[1] << " раз.\n";
        std::cout << "Спасибо за то, что сыграли в игру!!!\n";
    }

public:
    // Конструктор в котором запускается цикл игр
    TicTacToe()
    {
        playGames();
    }

    

};

int main()
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");    

    // Создаем объект нашей игры
    TicTacToe tttGame;

    return 0;
}
