/*
Задача 1. Адреса переменных
Описание
В этом задании вы потренируетесь выводить адреса и размеры переменных. Ваша задача — создать переменные следующих типов:

int;
short;
long;
long long;
float;
double;
long double;
bool.
Для каждой переменной выведите на консоль её адрес и размер.

Пример работы программы
short: 007DF924 2
int: 007DF918 4
long: 007DF90C 4
long long: 007DF8FC 8
float: 007DF8F0 4
double: 007DF8E0 8
long double: 007DF8D0 8
bool: 007DF8C7 1
*/

#include <iostream>
#include <typeinfo>


int main()
{
	short shortVar{};
	int intVar{};
	long longVar{};
	long long long_longVar{};
	float floatVar{};
	double doubleVar{};
	long double long_doubleVar{};
	bool boolVar{};

	std::cout << typeid(shortVar).name() << ": "
		<< &shortVar << " " << sizeof(shortVar) << std::endl;

	std::cout << typeid(intVar).name() << ": "
		<< &intVar << " " << sizeof(intVar) << std::endl;

	std::cout << typeid(longVar).name() << ": "
		<< &longVar << " " << sizeof(longVar) << std::endl;

	std::cout << typeid(long_longVar).name() << ": "
		<< &long_longVar << " " << sizeof(long_longVar) << std::endl;

	std::cout << typeid(floatVar).name() << ": "
		<< &floatVar << " " << sizeof(floatVar) << std::endl;

	std::cout << typeid(doubleVar).name() << ": "
		<< &doubleVar << " " << sizeof(doubleVar) << std::endl;

	std::cout << typeid(long_doubleVar).name() << ": "
		<< &long_doubleVar << " " << sizeof(long_doubleVar) << std::endl;

	std::cout << typeid(boolVar).name()
		<< ": " << &boolVar << " " << sizeof(boolVar) << std::endl;

	return EXIT_SUCCESS;
}
