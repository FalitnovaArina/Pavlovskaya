// ConsoleApplication16.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
//#include <cmath> 
//#include <time.h>			
using namespace std;

int main(){
	setlocale(LC_ALL, "Russian");
	const int stolb = 4, stroch = 5;
	srand(time(NULL));				
	int mass[stolb][stroch];
	int sString = 0;
	int max = INT_MIN;

	for (int i = 0; i < stolb; i++)
	for (int j = 0; j < stroch; j++)
		mass[i][j] = rand() % 25;
	for (int i = 0; i < stolb; i++){
		for (int j = 0; j < stroch; j++)
			cout << mass[i][j] << " ";
		cout << endl;
	}
	for (int i = 0; i < stolb; i++){
		int a = 0;
		for (int j = 0; j < stroch; j++){
			if (mass[i][j] ! = 0) a++;
		}
		if (a == stroch) sString++;
	}
	cout << "Количество строк, не содержащих ни одного нулевого элемента: " << sString << endl;

	int mass2[stolb*stroch];
	int k = 0;

	while (k < stolb*stroch){
		for (int i = 0; i < stolb; i++)
		for (int j = 0; j < stroch; j++){
			mass2[k] = mass[i][j];
			k++;
		}
	}

	for (int i = 0; i < stolb*stroch; i++)
	for (int j = i + 1; j < stolb*stroch; j++)
	if (mass2[i] == mass2[j] && mass2[i] > max && i! = j) max = mass2[i];

	cout << "Максимальное из чисел, встречающихся в заданной матрице более одного раза: " << max << endl;

	return 0;
}
