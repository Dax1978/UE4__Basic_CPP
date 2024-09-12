#include<iostream>
#include<fstream>
#include<iomanip>
#include <cmath>
#include <string>   //для getline()


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Task 1                                                                                                         //
// Выделить в памяти динамический одномерный массив типа int.Размер массива запросить у пользователя.             //
// Инициализировать его числами степенями двойки : 1, 2, 4, 8, 16, 32, 64, 128 … Вывести массив на экран.         //
// Не забыть освободить память. = ) Разбить программу на функции.                                                 //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Функция запроса размера массива
int sizeArr() {
    int n;
    std::cout << "Задание 1\n";
    while (true) // цикл продолжается до тех пор, пока пользователь не введёт корректное значение
    {
        std::cout << "Введите необходимый размер массива: ";
        std::cin >> n;
        if (std::cin.fail()) // если предыдущее извлечение оказалось неудачным,
        {
            std::cout << "Ошибка. Введите пожалуйста целое число!" << std::endl;
            std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
            std::cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
        } else {
            return n;
        }
    }
}

// Функция создания массива
int* createMassiv(size_t n) {
    if (n > 0)
    {
        int* ptrArr = new (std::nothrow) int[n]; // Выделение памяти под одномерный массив
        if (ptrArr != nullptr) // Если память не выделена то указатель будет нулевой
        {
            // Работа с массивом
            for (size_t i = 0; i < n; i++)
                ptrArr[i] = static_cast <int> (pow(2, i));

            return ptrArr;
        } else {
            std::cout << "Ошибка! Невозможно выделить память!";
        }
    }
}

void printMassiv(const int* ptrArr, const int n) {
    std::cout << "Вывод массива:" << std::endl;
    for (size_t i = 0; i < n; i++)
        std::cout << ptrArr[i] << " ";
}

// освобождение памяти
void deleteMassiv(int* ptrArr) {
    delete[] ptrArr;
    ptrArr = nullptr;
    std::cout << "\nМассив удален!" << std::endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Task 2                                                                                                         //
// Динамически выделить матрицу 4х4 типа int. Инициализировать ее псевдослучайными числами через функцию rand.    //
// Вывести на экран.Разбейте вашу программу на функции которые вызываются из main.                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int** createMatrix(const int n = 4, const int m = 4) {
    std::cout << "Задание 2\n";
    int** ptrArr = new int* [n];
    // ptrArr[0] = new int[n * m];
    for (size_t i = 0; i < n; i++) {
        ptrArr[i] = new int[m];
        for (size_t j = 0; j < m; j++) {
            ptrArr[i][j] = rand() % (n * m);
        }
    }
    return ptrArr;
}

void printMatrix(int** ptrArr, const int n = 4, const int m = 4) {
    std::cout << "Вывод матрицы:" << std::endl;
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++)
            std::cout << std::setw(3) << ptrArr[i][j] << " ";
        std::cout << std::endl;
    }
}

void deleteMatrix(int** ptrArr, const int n = 4, const int m = 4) {
    for (size_t i = 0; i < m; i++) {
        delete[] ptrArr[i]; // Освобождаем i-тый одномерный int массив
    }
    delete[] ptrArr;
    ptrArr = nullptr;
    std::cout << "Матрица удалена!" << std::endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Task 3                                                                                                         //
// Написать программу, которая создаст два текстовых файла(*.txt), примерно по 50 - 100 символов в каждом         //
// (особого значения не имеет с каким именно содержимым). Имена файлов запросить у польлзователя.                 //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const int SIZE_TEXT = 6;

std::string soundOfSilenceEng[SIZE_TEXT] = {
    "Hello darkness, my old friend",
    "I've come to talk with you again",
    "Because a vision softly creeping",
    "Left its seeds while I was sleeping",
    "And the vision that was planted in my brain",
    "Still remains within the sound of silence"
};
std::string soundOfSilenceRus[SIZE_TEXT] = {
    "Привет, темнота, мой старый друг,",
    "Я снова пришел поговорить с тобой,",
    "Потому что осторожно подкрадывающееся видение",
    "Бросило свои семена в моем сне,",
    "И видение, взращенное в моем мозгу,",
    "Остается в звуке тишины."
};

void writeFile(std::string file, std::string * text) {
    std::ofstream fout(file);
    for (size_t i = 0; i < SIZE_TEXT; i++) {
        fout << text[i] << std::endl;
    }
    fout.close();
};

void printFile(std::string file) {
    std::ifstream r(file);
    if (r.is_open()) {
        std::cout << "Текст файла " << file << ": " << std::endl;
        std::string line;
        while (!r.eof()) {
            std::getline(r, line);
            std::cout << line << std::endl;
        }
    }
};

struct twoFile {
    std::string file_1;
    std::string file_2;
};

twoFile writeFiles() {
    std::cout << "Задание 3\n";
    twoFile self;
    std::cout << "Укажите наименование 1-ого файла (без расширения): ";
    std::cin >> self.file_1;
    self.file_1 += ".txt";
    writeFile(self.file_1, soundOfSilenceEng);
    std::cout << "Укажите наименование 2-ого файла (без расширения): ";
    std::cin >> self.file_2;
    self.file_2 += ".txt";
    writeFile(self.file_2, soundOfSilenceRus);
    return self;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Task 4                                                                                                         //
// Написать функцию, «склеивающую» эти файлы в третий текстовый файл (имя файлов спросить у пользователя).        //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Чтение 2 файлов построчно и запись в указанный файл
void read2FwriteF3(twoFile files_read, std::string file_write) {
    std::ifstream r(files_read.file_1);
    std::ofstream w(file_write);
    if (r.is_open() && w.is_open()) {
        std::string line;
        while (!r.eof()) {
            std::getline(r, line);
            w << line << std::endl;
            //w << line;
        }
        r.close();
        w.close();
    }
    r.open(files_read.file_2);
    w.open(file_write, std::ios_base::app);
    if (r.is_open() && w.is_open()) {
        std::string line;
        while (!r.eof()) {
            std::getline(r, line);
            w << line << std::endl;
        }
        r.close();
        w.close();
    }
};

std::string task4() {
    std::cout << "Задание 4\n";
    std::string file;
    std::cout << "Укажите наименование файла в котором будет информация с двух файлов (без расширения): ";
    std::cin >> file;
    file += ".txt";
    return file;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Task 5                                                                                                         //
// Написать программу, которая проверяет присутствует ли указанное пользователем при запуске программы слово в    //
// указанном пользователем файле. Используем функцию find которая есть в строках std::string.                     //                                                                    //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

std::string task5file() {
    std::cout << "Задание 5\n";
    std::string file;
    std::cout << "Укажите наименование файла для поиска (без расширения): ";
    std::cin >> file;
    file += ".txt";
    return file;
};

std::string task5str() {
    std::string txt;
    std::cout << "Укажите строку для поиска: ";
    std::cin >> txt;
    return txt;
};

bool findStr(std::string file, std::string txt) {
    std::ifstream r(file);
    if (r.is_open()) {
        std::string line;
        while (!r.eof()) {
            std::getline(r, line);
            if (((int)line.find(txt)) != -1) {
                std::cout << "Строка: " << line << std::endl << "содержит искомую строку в позиции: " << (int)line.find(txt) << std::endl;
                return true;
            }
        }
    }
    std::cout << "В указанном файле нет искомой строки." << std::endl;
    return false;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                   MAIN                                                         //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");

    // Задача 1
    int n = sizeArr();
    int* massiv = createMassiv(n);
    printMassiv(massiv, n);
    deleteMassiv(massiv);
    std::cout << std::endl << std::endl;

    // Задача 2
    int** matrix = createMatrix();
    printMatrix(matrix);
    deleteMatrix(matrix);
    std::cout << std::endl << std::endl;

    // Задача 3
    twoFile nameFiles = writeFiles();
    printFile(nameFiles.file_1);
    printFile(nameFiles.file_2);
    std::cout << std::endl;

    // Задача 4
    std::string file = task4();
    read2FwriteF3(nameFiles, file);
    printFile(file);

    // Задача 5
    file = task5file();
    std::string txt = task5str();
    bool res = findStr(file, txt);;
}