/*
Задача 2. Одинаковые, но разные функции
Описание
Ваша задача — создать несколько функций с одинаковой сигнатурой, то есть с одинаковым именем,
одинаковыми параметрами и одинаковым типом возвращаемого значения, но с разной реализацией.

Создайте четыре функции int calc(int x, int y), каждая из которых будет реализовывать
одно из четырёх простых арифметических действий: сложение, вычитание, умножение, деление.

В функции main напишите код, который использует каждую из четырёх функций и выводит результат на экран.
В функции передавайте два числа, которые перед этим тоже выведите на экран,
чтобы можно было убедиться в корректности операции.

Пример работы программы
x = 6, y = 9
Сложение: 15
Вычитание: -3
Умножение: 54
Деление: 0
*/

#include <iostream>

namespace Sum
{
	int calc(int x, int y) { return x + y; }
}

namespace Sub
{
	int calc(int x, int y) { return x - y; }
}

namespace Mul
{
	int calc(int x, int y) { return x * y; }
}

namespace Div
{
	int calc(int x, int y) { return x / y; }
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "rus");

	int x{ 6 }, y{ 9 };

	std::cout << "x = " << x << ", y = " << y << std::endl;
	std::cout << "Сложение: " << Sum::calc(x, y) << std::endl;
	std::cout << "Вычитание: " << Sub::calc(x, y) << std::endl;
	std::cout << "Умножение: " << Mul::calc(x, y) << std::endl;
	std::cout << "Деление: " << Div::calc(x, y) << std::endl;
	
	return EXIT_SUCCESS;
}
