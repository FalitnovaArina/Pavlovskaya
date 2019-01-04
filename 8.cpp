// ConsoleApplication33.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <stdlib.h>        
#include <time.h>			
using namespace std;

void funcStb(int** array, int sStolb, int sStroch){
	int sString = 0;
	for (int i = 0; i < sStolb; i++){
		int a = 0;
		for (int j = 0; j < sStroch; j++){
			if (array[i][j] != 0) a++;
		}
		if (a == sStroch) sString++;
	}
	cout << "Количество строк, не содержащих ни одного нулевого элемента: " << sString << endl;
}

void funcOne(int** array, int sStolb, int sStroch){
	int max = INT_MIN;
	int tArray[sStolb*sStroch];
	int k = 0;
	while (k < sStolb*sStroch){
		for (int i = 0; i < sStolb; i++)
		for (int j = 0; j < sStroch; j++){
			tArray[k] = array[i][j];
			k++;
		}
	}

	for (int i = 0; i < sStolb*sStroch; i++)
	for (int j = i + 1; j < sStolb*sStroch; j++)
	if (tArray[i] == tArray[j] && tArray[i]>max && i != j) max = tArray[i];

	cout << "Максимальное из чисел, встречающихся в заданной матрице более одного раза: " << max << endl;
}

int main(){
	int stolb, stroch;
	const int varRandom = 10;
	srand(time(NULL));
	cout << "Кол - во строк и столбцов: ";
	cin >> stolb >> stroch;

	int** mass = new int*[stolb];
	for (int i = 0; i < stolb; i++){
		mass[i] = new int[stroch];
	}

	for (int i = 0; i < stolb; i++)
	for (int j = 0; j < stroch; j++)
		mass[i][j] = rand() % varRandom;
	for (int i = 0; i < stolb; i++){
		for (int j = 0; j < stroch; j++)
			cout << mass[i][j] << " ";
		cout << endl;
	}

	funcStb(mass, stolb, stroch);
	funcOne(mass, stolb, stroch);
	return 0;
}
