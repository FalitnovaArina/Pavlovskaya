// ConsoleApplication15.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#include "pch.h"
#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	double dx, xn, xk, x, a, b, c;
	int ac, bc, cc;
	cout << "Введите шаг dx: ";
	cin >> dx;
	cout << "x начальное: ";
	cin >> xn;
	cout << "x конечное: ";
	cin >> xk;
	cout << "Введите а: ";
	cin >> a;
	cout << "Введите b: ";
	cin >> b;
	cout << "Введите c: ";
	cin >> c;
	ac = int(a);
	bc = int(b);
	cc = int(c);

	for (x = xn; x <= xk; x = x + dx) {
		if (x < 0 && b!= 0) {
			cout << "Значение при x = " << x << ": ";
			if (((a || b) && (a || c)) != 0) {
				cout << (a * x * x + b) << endl;
			}
			else {
				cout << int(a * x * x + b) << endl;
			}
		}
		else if (x > 0 && b == 0) {
			cout << "Значение при x = " << x << ": ";
			if (((a || b) && (a || c)) != 0) {
				cout << (x - a) / (x - c) << endl;
			}
			else {
				cout << int((x - a) / (x - c)) << endl;
			}
		}
		else {
			cout << "Значение при x = " << x << ": ";
			if (((a || b) && (a || c)) != 0) {
				cout << x / c << endl;
			}
			else {
				cout << int(x / c) << endl;
			}
		}
	}
	system("pause");
	return 0;
}
