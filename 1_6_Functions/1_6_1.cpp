/*
Задача 1. Арифметические функции
Описание
Дана программа:

int main(int argc, char** argv)
{
    int a = 5, b = 10;

    int s = sum(a, b);
    int dif = diff(a, b);
    int mult = multiplication(a, b);
    double div = division(a, b);

    std::cout << a << " + " << b << " = " << s << std::endl;
    std::cout << a << " - " << b << " = " << dif << std::endl;
    std::cout << a << " * " << b << " = " << mult << std::endl;
    std::cout << a << " / " << b << " = " << div << std::endl;

    return 0;
}
В ней используются функции sum, diff, multiplication, division. Ваша задача — написать эти функции,
чтобы результат работы программы выглядел следующим образом:

5 + 10 = 15
5 - 10 = -5
5 * 10 = 50
5 / 10 = 0.5
*/

#include <iostream>

int sum (int var1, int var2)                    // Функция сложения
{
    return var1 + var2;
}

int diff (int var1, int var2)                   // Функция вычитания
{
    return var1 - var2;
}

int multiplication (int var1, int var2)         // Функция умножения
{
    return var1 * var2;
}

double division (int var1, int var2)            // Функция деления
{
    return static_cast<double> (var1) / var2;   // Чтобы деление было нецелочисленным - один из операндов д.б. дробным
}

int main(int argc, char** argv)
{
    int a = 5, b = 10;

    int s = sum(a, b);
    int dif = diff(a, b);
    int mult = multiplication(a, b);
    double div = division(a, b);

    std::cout << a << " + " << b << " = " << s << std::endl;
    std::cout << a << " - " << b << " = " << dif << std::endl;
    std::cout << a << " * " << b << " = " << mult << std::endl;
    std::cout << a << " / " << b << " = " << div << std::endl;

    return 0;
}