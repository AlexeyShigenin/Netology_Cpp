/*
Задача 1. Приветствие
Описание
Напишите программу, которая спрашивает у пользователя отдельно его имя и фамилию,
а затем приветствует его. Работу необходимо выполнить, используя операции над строками.

Пример работы программы
Введите имя: Егор
Введите фамилию: Летов
Здравствуйте, Егор Летов!
*/

#include <iostream>
#include <cstring>
#include <string>
#include <Windows.h>

void select();
void charFunction();
void stdstringFunction();

int main(int argc, char** argv)
{

	SetConsoleCP(1251);			// Поддержка ввода кирилицы
	SetConsoleOutputCP(1251);	// Поддержка вывода кирилицы

	select();

	return EXIT_SUCCESS;
}

void select()
{
	#define message "Выберите, что использовать для работы со строками:\n1 - char\n2 - std::string\n0 - для выхода"

	int type{};

	do
	{
		std::cout << message << std::endl;

		while (!(std::cin >> type))
		{
			std::cout << message << std::endl;
			std::cin.clear();
			std::cin.ignore(30, '\n');
		}

		switch (type)
		{
		case 1:
			charFunction();		// функция обработки с помощью char
			break;
		case 2:
			stdstringFunction();	// функция обработки с помощью std::string
			break;
		}

	} while (type != 0);
	std::cout << "Вы вышли из программы" << std::endl;
}

void charFunction()
{
	char fullName[30];
	char surName[15];
		
	std::cout << "Введите имя: ";
	std::cin >> fullName;

	std::cout << "Введите фамилию: ";
	std::cin >> surName;

	strcat_s(fullName, " ");
	strcat_s(fullName, surName);

	std::cout << "Здравствуйте, " << fullName << "!\n" << std::endl;

}

void stdstringFunction()
{
	std::string fullName;
	std::string surName;

	std::cout << "Введите имя: ";
	std::cin >> fullName;
	fullName += " ";

	std::cout << "Введите фамилию: ";
	std::cin >> surName;
	fullName += surName;

	std::cout << "Здравствуйте, " << fullName +  "!\n" << std::endl;
}