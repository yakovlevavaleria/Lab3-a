// ConsoleApplication66.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "stdafx.h"
class Vector // �����- ������
{
	int *p; // ��������� �� ������ (������)
	int n; // ����������� ������� (����� ���������) �������
public:
	Vector(int *p, int n) // ���������� �� ����� ������, �������� ������
	{
		this->n = n; // ������ ����� ���������
		this->p = new int[n]; // �������� ������
		for (int i = 0; i<n; i++) this->p[i] = p[i]; // �������� ���� ������ � ������
	}
	void print() // ������ ������� (�������)
	{
		cout << "\n";
		for (int i = 0; i<n; i++)
			cout << p[i] << " ";
	}
	Vector() { p = 0; n = 0; } // ����������� ��� ����������, ������ "������" ������
	int& operator[](int index) // ��������- ������� (���������� �������� 
								  // ��������� � ��������)
	{
		return p[index];
	}
	Vector & operator =(Vector& v2) // ��������- ������� ����������� ������� 
	{
		n = v2.n;
		p = new int[n];
		for (int i = 0; i<n; i++) p[i] = v2.p[i];
		return *this;
	}
	~Vector() // ����������
	{
		if (n>0) delete[] p; // ����������� ������
	}
	friend Vector & operator *(int x, Vector& v2); // ������������� �������, 
													  // ������������ ��� ������
};
// ��������� ����� �� ������ (������ ������� �� ������ ������, 
// ������� ����������� ������������ ��� ������)
Vector & operator *(int x, Vector& v2) // ��������- ������� ��� ������ 
{
	int *p = new int[v2.n]; // ������� ����� ������
	for (int i = 0; i<v2.n; i++) p[i] = x*v2.p[i]; // ��������� ������
	Vector *pV = new Vector(p, v2.n); // ������� ����� ������ �� ������ �������
	delete[] p; // ����������� ������
	return *pV; // ���������� ������ �� ������
}
int _tmain(int argc, _TCHAR* argv[])
{
	int m1[] = { 5, 20, 8, 7, 13 };
	Vector V1(m1, 5); // ������� ������
	V1.print(); // ������ �������
	cout << "\n";
	for (int i = 0; i<5; i++)
		cout << V1[i] << " "; // ������ ��������� � �������� []
	V1[0] = 10.6; // ������ ��������� � �������� []
	V1.print(); // ������ �������
	Vector V2; // ����� ������ (������� "������")
	V2 = 25 * V1; // ������ ���������� ������������� �������� * 
				   // V2=operator *(100, V1);
	V2.print(); // ������ ����������� �������
	system("pause"); // ������������� ��������� �� ������� ����� �������
	return 0;
}

