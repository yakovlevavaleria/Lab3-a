// ConsoleApplication66.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "stdafx.h"
class Vector // Класс- вектор
{
	int *p; // Указатель на массив (вектор)
	int n; // Размерность вектора (число элементов) массива
public:
	Vector(int *p, int n) // Коструктор на входе массив, задающий вектор
	{
		this->n = n; // Задаем число элементов
		this->p = new int[n]; // Выделяем память
		for (int i = 0; i<n; i++) this->p[i] = p[i]; // Копируем один массив в другой
	}
	void print() // Печать вектора (массива)
	{
		cout << "\n";
		for (int i = 0; i<n; i++)
			cout << p[i] << " ";
	}
	Vector() { p = 0; n = 0; } // Конструктор без параметров, задает "пустой" объект
	int& operator[](int index) // Оператор- функция (перегрузка операции 
								  // обращения к элементу)
	{
		return p[index];
	}
	Vector & operator =(Vector& v2) // Оператор- функция копирования объекта 
	{
		n = v2.n;
		p = new int[n];
		for (int i = 0; i<n; i++) p[i] = v2.p[i];
		return *this;
	}
	~Vector() // Деструктор
	{
		if (n>0) delete[] p; // Освобождаем память
	}
	friend Vector & operator *(int x, Vector& v2); // Дружественная функция, 
													  // определенная вне класса
};
// Умножение числа на вектор (первый операнд не объект класса, 
// функция обязательно определяется вне класса)
Vector & operator *(int x, Vector& v2) // Оператор- функция вне класса 
{
	int *p = new int[v2.n]; // Создаем новый массив
	for (int i = 0; i<v2.n; i++) p[i] = x*v2.p[i]; // Заполняем массив
	Vector *pV = new Vector(p, v2.n); // Создаем новый объект на основе массива
	delete[] p; // Освобождаем массив
	return *pV; // Возвращаем ссылку на объект
}
int _tmain(int argc, _TCHAR* argv[])
{
	int m1[] = { 5, 20, 8, 7, 13 };
	Vector V1(m1, 5); // Создаем объект
	V1.print(); // Печать объекта
	cout << "\n";
	for (int i = 0; i<5; i++)
		cout << V1[i] << " "; // Пример обращения к операции []
	V1[0] = 10.6; // Пример обращения к операции []
	V1.print(); // Печать объекта
	Vector V2; // Новый объект (вначале "пустой")
	V2 = 25 * V1; // Пример выполнение перегруженной операции * 
				   // V2=operator *(100, V1);
	V2.print(); // Печать полученного объекта
	system("pause"); // Останавливаем программу до нажатия любой клавиши
	return 0;
}

