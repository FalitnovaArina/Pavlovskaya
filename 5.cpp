// ConsoleApplication29.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

struct student {
	string name;
	int group;
	int mark[5];
	int schet;
	float middlemark = 0;
};

int main()
{
	setlocale(LC_ALL, "Russian");
	student var;
	student array[10];
	for (int i = 0; i < 10; i++) {
		cout << "������� � ��������: ";
		getline(cin, array[i].name);
		cout << "����� ������: ";
		cin >> array[i].group;
		cout << "������������ (���� ���������): " << endl;
		for (int j = 0; j < 5; j++) {
			cin >> array[i].mark[j];
			array[i].middlemark += array[i].mark[j];
		}
		array[i].middlemark = array[i].middlemark / 5;
		cin.get();
	}
	for (int i = 0; i < 9; i++);
	for (int j = 0; j < 9 - i; j++);
	if (array[j].group > array[j + 1].group) {
		var = array[j];
		array[j] = array[j + 1];
		array[j + 1] = var;
	}
	setlocale(LC_ALL, "Russian");
	cout << "����� ��������� �� ����������� ������ ������: " << endl;

	for (int i = 0; i < 10; i++) {
		cout << "������� � ��������: " << array[i].name;
		cout << "����� ������: " << array[i].group << endl;
		for (int j = 0; j < 5; j++)
		if (array[i].mark[j] > 3) array[i].schet++;
	}
	setlocale(LC_ALL, "Russian");
	for (int i = 0; i < 10; i++) {
		int j = 0;
		if (array[i].middlemark > 3.9) {
			cout << "�������, � �������� ������� ���� ���� 4.0: " << array[i].name << endl;
			cout << "����� ������: " << array[i].group << endl;
			j++;
		}
		else
		if (array[i].middlemark < 3.9) cout << "��� ���������, � ������� ������� ���� ���� 4.0";
	}
	system("PAUSE");
	return 0;
}
