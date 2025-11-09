/*
Задача 2. Снова swap
Описание
Ваша задача — реализовать уже знакомую вам функцию swap (вспомнить можно здесь),
но с помощью указателей, а не ссылок.

Обратите внимание, что в пространстве имён std уже есть функция swap.
Поэтому НЕ используйте в своём решении конструкцию using namespace std;,
так как в этом случае будет вызвана библиотечная функция swap, а не ваша.

Пример работы программы
a = 5, b = 8
a = 8, b = 5
*/

#include <iostream>

void swap(int* var1, int* var2)
{
	int tempVar = *var1;
	*var1 = *var2;
	*var2 = tempVar;
}

int main(int argc, char** argv)
{
	int a = 5, b = 8;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	swap(&a, &b);
	std::cout << "a = " << a << ", b = " << b << std::endl;

	return EXIT_SUCCESS;
}
