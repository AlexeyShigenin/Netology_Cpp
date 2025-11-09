/*
Задача 2. Обмен значениями
Описание
В этом задании вам нужно написать функцию swap, которая будет обменивать значения между двумя переменными.
Посмотрите на эту часть программы:

int main(int argc, char** argv)
{
	int a = 5, b = 8;

	std::cout << "a = " << a << ", b = " << b << std::endl;

	swap(a, b);

	std::cout << "a = " << a << ", b = " << b << std::endl;

	return 0;
}
В этой программе используется функция swap, которую вам и предстоит создать.
При этом вы должны написать её так, чтобы программа работала, как показано ниже.

Пример работы программы
a = 5, b = 8
a = 8, b = 5
*/

#include <iostream>

void swap(int& var1, int& var2)
{
	int tempVar = var1;
	var1 = var2;
	var2 = tempVar;
	return;
}

int main(int argc, char** argv)
{
	int a = 5, b = 8;

	std::cout << "a = " << a << ", b = " << b << std::endl;

	swap(a, b);

	std::cout << "a = " << a << ", b = " << b << std::endl;

	return EXIT_SUCCESS;
}
