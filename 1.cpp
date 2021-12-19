#include "stdafx.h"
#include <iostream>
#include <ctime>
using namespace std;

const int sizea = 5, sizeb = 5;


void fillrand(int** arr) {
	srand(time(NULL));
	for (int a = 0; a < sizea; a++)
		for (int b = 0; b < sizeb; b++) {
			arr[a][b] = rand() % 100;
		}
}

void print(int** arr, int x, int y) {
	for (int a = 0; a < x; a++) {
		for (int b = 0; b < y; b++) {
			cout << arr[a][b] << ' ';
		}
		cout << endl;
	}
}

void erase(int** arr, int** newarr) {
	int x = 0, y = 0, min = arr[0][0];
	for (int a = 0; a < sizea; a++) {
		for (int b = 0; b < sizeb; b++) {
			if (arr[a][b] < min) {
				min = arr[a][b];
				x = a;
				y = b;
			}
		}
	}
	for (int a = 0; a < sizea - 1; a++) {
		for (int b = 0; b < sizeb - 1; b++) {
			if (a<x && b<y) newarr[a][b] = arr[a][b];
			else if (a>=x && b<y) newarr[a][b] = arr[a+1][b];
			else if (a<x && b>=y) newarr[a][b] = arr[a][b+1];
			else if (a >= x && b >= y) newarr[a][b] = arr[a+1][b + 1];
		}
	}
}

int main()
{
	int **arr;
	arr = new int *[sizea];
	for (int i = 0; i < sizea; i++)
		arr[i] = new int[sizeb];

	int **newarr;
	newarr = new int *[sizea-1];
	for (int i = 0; i < sizea-1; i++)
		newarr[i] = new int[sizeb-1];

	fillrand(arr);
	print(arr, sizea, sizeb);
	erase(arr, newarr);

	for (int i = 0; i < sizea; i++)
		delete[] arr[i];
	delete[] arr;

	cout << endl;
	print(newarr, sizea-1, sizeb-1);
	cout << endl;
	return 0;
}