// ConsoleApplication23.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <time.h>

double first(double arr[], int len)
{
	double sum = 0;

	for (int i = 0; i < len; i++)
	if (arr[i] < 0)
		sum += arr[i];

	return sum;
}

double second(double arr[], int len)
{
	int index_min = 0;
	int index_max = 0;
	double mult = 1;

	for (int i = 0; i < len; i++) {
		if (arr[i] < arr[index_min])
			index_min = i;
		if (arr[i] > arr[index_max])
			index_max = i;
	}

	if (index_min > index_max) {
		int temp_index = index_min;
		index_min = index_max;
		index_max = temp_index;
	}

	for (int i = index_min + 1; i < index_max; i++)
		mult *= arr[i];

	return mult;
}

void sort(double arr[], int len)
{
	for (int i = 0; i < len - 1; i++)
	for (int j = i + 1; j < len; j++)
	if (arr[i] > arr[j]) {
		double temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}

	return;
}

int main()
{
	using namespace std;
	setlocale(LC_ALL, "RUSSIAN");
	double arr[10];

	srand(time(0));
	for (int i = 0; i < 10; i++) {
		arr[i] = rand() % 256 - 128;
		cout << arr[i] << ' ' << endl;
	}

	cout << "Сумма отрицательных элементов: " << first(arr, 10) << endl;
	cout << "Произведение между min и max: " << second(arr, 10) << endl;

	sort(arr, 10);

	cout << "Отсортированный массив: ";
	for (int i = 0; i < 10; i++)
		cout << arr[i] << ' ';

	return 0;
}

