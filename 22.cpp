// ConsoleApplication37.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

double mak(double *massive, int n);
double mak1(double *massive, int n);
double mak2(double *massive, int n);

using namespace std;
int main()
{
	int i, n, imax, imin, p_min_max, s_minus, p, S;

	cout << "Введите количество элементов массива: " << endl;
	cin >> n;
	double *massive = new double[n];
	cout << "Введите " << n << " элементов: " << endl;
	for (i = 0; i<n; i++)
		cin >> massive[i];

	cout << "Сумма отрицательных элементов: " << mak(massive, n) << endl;
	cout << "Произведение между минимальным имаксимальным элементами: " << mak1(massive, n) << endl;
	cout << "Отсортированный массив: " << mak2(massive, n) << endl;
	
	delete[] massive;
	return 0;
}
double mak(double *massive, int n)
{
	int S = 0;
	for (int i = 0; i<n; i++)
	{
		if (massive[i]<0) S += massive[i];
	}
	return S;
}
double mak1(double *massive, int n)
{
	int i, imin, imax, p_min_max;
	for (i = imin = imax = 0; i<n; i++)
	{
		if (massive[i]>massive[imax]) imax = i;
		if (massive[i]<massive[imin]) imin = i;
	}
	cout << "min= " << massive[imin] << endl;
	cout << "max= " << massive[imax] << endl;
	p_min_max = 1;
	for (i = imin + 1; i<imax; i++)
	{
		p_min_max *= massive[i];
	}
	return p_min_max;
}
double mak2(double *massive, int n)
{

	int temp;
	for (int i = 0; i < n; i++)
	{
		for (int i = 0; i<n; i++)
		{
			int i_min = i;
			for (int j = i + 1; j<n; j++)
			if (massive[j]<massive[i_min]) i_min = j;
			int tmp = massive[i];
			massive[i] = massive[i_min];
			massive[i_min] = tmp;
		}
	}
	cout << "Отсортированный массив:\n ";
	for (int i = 0; i < n; i++)
	{
		cout << massive[i] << " ";
	}
	system("pause");
}

