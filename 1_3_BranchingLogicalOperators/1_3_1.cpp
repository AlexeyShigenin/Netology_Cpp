/*
Задание 1. Таблица истинности
Напишите программу, которая выводит таблицу истинности для логических операторов ||, &&, с применением логических выражений.

Результат работы программы
Оператор: ||
true    true    true
false   true    true
true    false   true
false   false   false

Оператор: &&
true    true    true
false   true    false
true    false   false
false   false   false
*/

#include <iostream>

int main()
{
	setlocale(LC_ALL, "rus");										// Настройка локали для поддержка вывода кирилицы в консоль
	
	bool a{1}, b{1};												// Объявление и инициализация переменных

	std::cout << std::boolalpha;									// Ключ вывода bool в виде true/false, а не 1/0
	
	std::cout << "Оператор: ||" << std::endl;
	std::cout << a << '\t' << b << '\t' << (a || b) << std::endl;	// true || true
	a = false;
	std::cout << a << '\t' << b << '\t' << (a || b) << std::endl;	// false || true
	a = true;
	b = false;
	std::cout << a << '\t' << b << '\t' << (a || b) << std::endl;	// true || false
	a = false;
	std::cout << a << '\t' << b << '\t' << (a || b) << std::endl;	// false || false
		
	std::cout << "\nОператор: &&" << std::endl;
	a = true;
	b = true;
	std::cout << a << '\t' << b << '\t' << (a && b) << std::endl;	// true && true
	a = false;
	std::cout << a << '\t' << b << '\t' << (a && b) << std::endl;	// false && true
	a = true;
	b = false;
	std::cout << a << '\t' << b << '\t' << (a && b) << std::endl;	// true && false
	a = false;
	std::cout << a << '\t' << b << '\t' << (a && b) << std::endl;	// false && false

	return EXIT_SUCCESS;
}
