// ConsoleApplication31.cpp : Defines the entry point for the console application.
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
	int size;
	cout << "Ñêîëüêî âñåãî ñòóäåíòîâ: ";
	cin >> size;
	cin.get();
	student* array = new student[size];

	for (int i = 0; i < size; i++) {
		cout << "Фамилия и инициалы: ";
		getline(cin, array[i].name);
		cout << "Номер группы: ";
		cin >> array[i].group;
		cout << "Успеваемость (пять элементов): ";
		for (int j = 0; j < 5; j++) {
			cin >> array[i].mark[j];
			array[i].middlemark += array[i].mark[j];
		}

		array[i].middlemark = array[i].middlemark / 5;
		cin.get();
	}

	for (int i = 0; i < size - 1; i++)
	for (int j = 0; j < size - 1 - i; j++)
	if (array[j].group > array[j + 1].group) {
		var = array[j];
		array[j] = array[j + 1];
		array[j + 1] = var;
	}
	
	cout << "Вывод студентов по возрастанию номера группы: " << endl;

	for (int i = 0; i < size; i++) {
		cout << "Фамилия и инициалы: " << array[i].name;
		cout << "Номер группы: " << array[i].group << endl;
		for (int j = 0; j < 5; j++)
		if (array[i].mark[j] > 3) array[i].schet++;
	}


	int j = 0;
	for (int i = 0; i < size; i++) {
		if (array[i].middlemark > 3.9) {
			cout << "Студент, у которого средний балл выше 4.0: " << array[i].name << endl;
			cout << "Номер группы: " << array[i].group << endl;
			j++;
		}
	}

	if (j = 0) cout << "Нет студентов, у которых средний балл выше 4.0" << endl;


	system("PAUSE");
	return 0;
}