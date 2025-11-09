/*
Задача 2. Угадайка
Описание
Напишите программу, которая просит пользователя угадать слово,
записанное в коде — то есть вводить слова до тех пор, пока одно из них не совпадёт с загаданным словом.

Пример работы программы
Угадайте слово: арбуз
Неправильно
Угадайте слово: клубника
Неправильно
Угадайте слово: малина
Правильно! Вы победили! Загаданное слово — малина
*/

#include <iostream>
#include <string>
#include <Windows.h>


int main(int argc, char** argv)
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	std::string word { "малина" };
	std::string userInput{};

	do {
		std::cout << "Угадайте слово : ";
		std::cin >> userInput;
		if (userInput != word) std::cout << "Неправильно" << std::endl;

	} while (userInput != word);
	std::cout << "Правильно! Вы победили! Загаданное слово — " << word << std::endl;

	return EXIT_SUCCESS;
}