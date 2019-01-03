// ConsoleApplication14.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	float a, b, c, x, f, dx, x1, x2;
	cout << "Введите a:"; cin >> a;
	cout << "Введите b:"; cin >> b;
	cout << "Введите c:"; cin >> c;
	cout << "Введите x1:"; cin >> x1;
	cout << "Введите x2:"; cin >> x2;
	cout << "Введите dx:"; cin >> dx;
	for(x = x1; x <x2; x += dx)
	{
		if(c <0 && x != 0)
		{
			f = -a * x - c;
			if ((int(a) || int(b) || int(c)) == 0)
			{
				f = int(f);
			}
			cout << "x =" << x << "f =" << f << endl;
		}
		if(c> 0 && x == 0)
		{
			f = (x - a) / (-c);
			if ((int(a) || int(b) || int(c)) == 0)
			{
				f = int(f);
			}
			cout << "x =" << x << "f =" << f << endl;
		}
		else
		{
			f = (b * x) / (c);
			if ((int(a) || int(b) || int(c)) == 0)
			{
				f = int(f);
			}
			cout << "x =" << x << "f =" << f << endl;
		}
	}
	return 0;
}