/*
Задача 1. Вывод массива
Описание
Напишите функцию print, которая принимает на вход массив произвольного размера и выводит его на экран.
В программе создайте несколько массивов разного размера и используйте для вызова вашей функции.

Пример работы программы
1 2 3 4 5 6 7 8 9
6 5 4 8
1 4 3 7 5
*/

#include <iostream>

void print(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;
}

int main(int argc, char** argv)
{
	int array1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	print(array1, 9);
	
	int array2[] = { 6, 5, 4, 8 };
	print(array2, 4);

	int array3[] = { 1, 4, 3, 7, 5 };
	print(array3, 5);

	return EXIT_SUCCESS;
}
