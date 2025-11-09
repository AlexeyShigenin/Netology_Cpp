/*
Первоначальная конфигурация игрового поля в файле "init.txt"
*/

#include <iostream>
#include <fstream>
#include "windows.h"

int** init_game_board(int&, int&);  // Прототип функции первоначальной инициализации игрового поля
int** count_living_neighbors(int**, int, int);  // Прототип функции создания массива, где элементы - количество живых соседей в существующем массиве
int** new_game_board(int**, int**, int, int);   // Прототип функции генерации игрового поля следующего поколения
void copy_game_board(int**, int**, int, int);   // Прототип функции копирования игрового поля
int summ_array(int**, int, int);    // Прототип функции суммирования массива игрового поля для определения отсутствия жизни на поле
bool compare(int**, int**, int, int);   // Прототип функции сравнения игровых полей нового и старого поколений
void print_game_status(int**, int, int, int, int);  // Прототип функции вывода состояния игрового поля в консоль
void delete_two_dim_array(int**, int);  // Прототип функции очищения массива

int main()
{
    setlocale(LC_ALL, "");  // Устанавливаем системную локаль

    int rows{}, columns{};  // Переменные для хранения размера игрового поля
    int step{ 1 };    // Переменная для хранения значения поколения
    bool diff{ 1 };   // Переменная для определения различий между поколениями

    int** gameBoard = init_game_board(rows, columns);   // Создаем игровое поле и инициализируем его данными из файла
    int countLiving = summ_array(gameBoard, rows, columns); // Определяем количество живых клеток на поле
    print_game_status(gameBoard, rows, columns, step, countLiving); // Выводим состояние игры в консоль

    while (diff && countLiving) {  // Пока есть различия между генерациями и количество живых клеток на поле не равно нулю
        Sleep(1000);    // Пауза 1 секунда
        step++; // Инкрементируем переменную поколения
        int** countLivingNeighbors = count_living_neighbors(gameBoard, rows, columns); // Создаем массив, где в элементах - количество живых соседей
        int** newGameBoard = new_game_board(gameBoard, countLivingNeighbors, rows, columns); // Создаем массив нового игрового поля на основе данных о соседях
        delete_two_dim_array(countLivingNeighbors, rows);   // Удаление неиспользуемого массива
        diff = compare(gameBoard, newGameBoard, rows, columns); // Определяем различия между полями разных поколений
        countLiving = summ_array(newGameBoard, rows, columns);  // Определяем сумму массива нового поля для определения наличия живых клеток
        std::system("CLS"); // Очистка экрана
        print_game_status(newGameBoard, rows, columns, step, countLiving);  // Выводим состояние игры в консоль
        copy_game_board(newGameBoard, gameBoard, rows, columns);    // Копирование массива (элементы нового игрового поля становятся "старыми" элементами)
        delete_two_dim_array(newGameBoard, rows);   // Удаление неиспользуемого массива
    }
    delete_two_dim_array(gameBoard, rows);   // Удаление неиспользуемого массива
    std::cout << (diff == 0 ? "Игровое поле стабильно. Конец игры." : "Живые клетки отсутствуют. Конец игры.") << std::endl;

    return EXIT_SUCCESS;
}

int** init_game_board(int& rows, int& columns) { // Реализация функции первоначальной инициализации игрового поля
    std::ifstream file("init.txt"); // Открываем файл первоначальной инициализации игрового поля
    if (file.is_open()) {
        file >> rows >> columns;    // Считываем из файла размеры игрового поля (rows x columns)

        int** array = new int* [rows];  // Создаем двумерный массив игрового поля и инициализируем его нулями
        for (int r = 0; r < rows; r++)
        {
            array[r] = new int[columns]();
        }

        int r{}, c{};   // Переменные для хранения координат клетки
        while (file >> r >> c) {   // Пока не достигли конца файла считываем из файла координаты живых клеток
            array[r][c] = 1;    // Присваиваем "живым" элементам массива единицы
        }
        file.close();   // Закрываем файл
        return array;
    }
    else std::cout << "Ошибка открытия файла" << std::endl;
}

int** count_living_neighbors(int** array, int rows, int columns) { // Реализация функции создания массива,
    // где элементы - количество живых соседей в существующем массиве

    int** newArray = new int* [rows];  //  Создаем новый двумерный массив
    for (int r = 0; r < rows; r++)
    {
        newArray[r] = new int[columns]();
    }

    for (int r = 0; r < rows; r++)  // Заполняем новый двумерный массив значениями из существующего массива
    {
        for (int c = 0; c < columns; c++)   // Заносим в элементы массива количество живых соседей
        {
            if (((r - 1) >= 0) && ((c - 1) >= 0)) newArray[r][c] += array[r - 1][c - 1];
            if ((r - 1) >= 0) newArray[r][c] += array[r - 1][c];
            if (((r - 1) >= 0) && ((c + 1) < columns)) newArray[r][c] += array[r - 1][c + 1];
            if ((c + 1) < columns) newArray[r][c] += array[r][c + 1];
            if (((r + 1) < rows) && ((c + 1) < columns)) newArray[r][c] += array[r + 1][c + 1];
            if ((r + 1) < rows) newArray[r][c] += array[r + 1][c];
            if (((r + 1) < rows) && ((c - 1) >= 0)) newArray[r][c] += array[r + 1][c - 1];
            if ((c - 1) >= 0) newArray[r][c] += array[r][c - 1];
        }
    }
    return newArray;
}

int** new_game_board(int** gameBoard, int** countGameBoard, int rows, int columns) {    // Реализация функции генерации игрового поля следующего поколения

    int** array = new int* [rows];  // Создаем двумерный массив игрового поля и инициализируем его нулями
    for (int r = 0; r < rows; r++)
    {
        array[r] = new int[columns]();
    }

    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < columns; c++)
        {
            array[r][c] = gameBoard[r][c];  // Вносим в элементы нового массива элементы из существующего массива
            if ((gameBoard[r][c] == 0) && (countGameBoard[r][c] == 3)) {    // Условие зарождения жизни в мертвой клетке
                array[r][c] = 1;    // Меняем мертвую клетку на живую
            }
            else if ((countGameBoard[r][c] < 2) || (countGameBoard[r][c] > 3)) {    // Условие умирания живой клетки
                array[r][c] = 0;    // Меняем живую клетку на мертвую
            }
        }
    }
    return array;
}

void copy_game_board(int** newBoard, int** board, int rows, int columns) {   // Реализация функции копирования игрового поля
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < columns; c++)
        {
            board[r][c] = newBoard[r][c];
        }
    }
}

int summ_array(int** array, int rows, int columns) {    // Реализация функции суммы массива игрового поля для определения отсутствия жизни на поле
    int summ{};
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < columns; c++)
        {
            summ += array[r][c];
        }
    }
    return summ;
}

bool compare(int** board1, int** board2, int rows, int columns) {   // Реализация функции сравнения игровых полей нового и старого поколений
    bool diff{};    // Объявляем и инициализируем нулем флаг различий diff
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < columns; c++)
        {
            if (board1[r][c] != board2[r][c]) {
                return diff = 1; // Как появляется первое отличие в элементах массива - сразу возвращыем diff=1
            }
        }
    }
    return diff; // Различий нет, возвращаем diff=0
}

void print_game_status(int** array, int rows, int columns, int step, int countLiving)    // Реализация функции вывода состояния игрового поля в консоль
{
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < columns; c++)
        {
            std::cout << (array[r][c] == 1 ? '*' : '-') << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "Поколение: " << step << ". Живых клеток: " << countLiving << std::endl;
}

void delete_two_dim_array(int** array, int rows)    // Реализация функции очистки двумерного массива
{
    for (int r = 0; r < rows; r++)
    {
        delete[] array[r];  // очищаем каждый подмассив отдельно
    }
    delete[] array; // очищаем верхнеуровневый массив указателей
}

