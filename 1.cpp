#include "stdafx.h"
#include <iostream>
#include <ctime>
using namespace std;

const int sizea = 5, sizeb = 5;
int arr[sizea][sizeb];

void fillrand(int arr[sizea][sizeb]) {
	srand(time(NULL));
	for (int a = 0; a < sizea; a++) 
		for (int b = 0; b < sizeb; b++) {
			arr[a][b] = rand()%100;
		}
}

void print(int arr[sizea][sizeb]) {
	for (int a = 0; a < sizea; a++) {
		for (int b = 0; b < sizeb; b++) {
			cout << arr[a][b] << ' ';
		}
		cout << endl;
	}
}

void nprint(int arr[sizea][sizeb]) {
	for (int a = 0; a < sizea-1; a++) {
		for (int b = 0; b < sizeb-1; b++) {
			cout << arr[a][b] << ' ';
		}
		cout << endl;
	}
}

void erase(int arr[sizea][sizeb]) {
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
	for (int a = x; a < sizea-1; a++) {
		for (int b = 0; b < sizeb; b++) {
			arr[a][b] = arr[a+1][b];
		}
	}
	for (int b = y; b < sizeb-1; b++) {
		for (int a = 0; a < sizea; a++) {
			arr[a][b] = arr[a][b+1];
		}
	}
	for (int a = 0; a < sizea; a++) arr[a][sizeb-1] = '\0';
	for (int b = 0; b < sizeb; b++) arr[sizea-1][b] = '\0';
}

int main()
{
	fillrand(arr);
	print(arr);
	erase(arr);
	cout << endl;
	nprint(arr);
	cout << endl;
    return 0;
}
