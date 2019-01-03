// ConsoleApplication17.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int x[500];
int y[500];
int x2[500];
int y2[500];

int proverka(int prov, int *xprov, int *yprov, int x, int y)
{
		int c = 0;
	for (int i = 0, j = prov - 1; i < prov; j = i++)
	{
		if ((((yprov[i] <= y) && (y < yprov[j])) || ((yprov[j] <= y) && (y < yprov[i]))) && (x > (xprov[j] - xprov[i]) * (y - yprov[i]) / (yprov[j] - yprov[i]) + xprov[i]))
			c = !c;
	}
	return c;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int c, t, i, f, xp, yp, y2p, x2p, k, p;
	long s1, s2, r1 = 0, r2 = 0, figure№1 = 0, figure№2 = 0;

	cout << "Введите кол - во вершин 1-го многоугольника: " << endl;
	cin >> k;
	cout << "Введите координаты 1-го многоугольника: " << endl;
	for (i = 0; i < k; i++)
	{
		cin >> x[i]; // координата "x" 1-го мног - ка 		
		cin >> y[i]; // координата "y" 1-го мног - ка
	}

	cout << "Введите кол - во вершин 2-го многоугольника:" << endl;
	cin >> p;
	cout << "Введите координаты 2-го многоугольника:" << endl;
	for (i = 0; i < p; i++)
	{
		cin >> x2[i]; // координата "x" 2-го мног - ка
		cin >> y2[i]; // координата "y" 2-го мног - ка
	}

	//Площадь 1-го многоугольника через сумму площадей трапеций
	for (i = 0; i < k; i++)
	{
		if (i == 0)
		{
			s1 = x[i] * (y[k - 1] - y[i + 1]);
			r1 += s1;
		}

		else
		if (i == k - 1)
		{
			s1 = x[i] * (y[i - 1] - y[0]);
			r1 += s1;
		}

		else
		{
			s1 = x[i] * (y[i - 1] - y[i + 1]);
			r1 += s1;
		}
	}

	//Площадь 2-го мног - ка через сумму площадей трапеций
	for (i = 0; i < p; i++)
	{
		if (i == 0)
		{
			s2 = x2[i] * (y2[p - 1] - y2[i + 1]);
			r2 += s2;
		}
		else
		if (i == p - 1)
		{
			s2 = x2[i] * (y2[i - 1] - y2[0]);
			r2 += s2;
		}
		else
		{
			s2 = x2[i] * (y2[i - 1] - y2[i + 1]);
			r2 += s2;
		}
	}

	//Принадлежат ли точки 1-го многоугольника 2-му? Если нет, то 2-му мног - ку присваивается: 0.
	for (i = 0; i < k; i++)
	{
		c = proverka(p, x2, y2, x[i], y[i]);
		if (c % 2 == 0)
		{
			c = 0;
			break;
		}
	}

	//Принадлежат ли точки 2-го многоугольника 1-му? Если нет, то 1-му мног - ку присваивается: 0.
	for (i = 0; i < p; i++)
	{
		t = proverka(k, x, y, x2[i], y2[i]);
		if (t % 2 == 0)
		{
			t = 0;
			break;
		}
	}

	figure№1 = abs(r1 / 2);
	figure№2 = abs(r2 / 2);
	cout << "Площадь 1-го =: " << figure№1 << endl;
	cout << "Площадь 2-го =: " << figure№2 << endl;
	if (c >= 0)
		cout << "1-й мног - к лежит во 2-м" << endl;
	else
	if (t >= 0)
		cout << "2-й мног - к лежит в 1-м" << endl;

		_getch();
	return 0;
}
