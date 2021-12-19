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
			arr[a][b] = rand() % 100;
		}
}

template <size_t rows, size_t cols>
void print(int(&arr)[rows][cols]) {
	for (int a = 0; a < rows; a++) {
		for (int b = 0; b < cols; b++) {
			cout << arr[a][b] << ' ';
		}
		cout << endl;
	}
}

void erase(int arr[sizea][sizeb], int newarr[sizea - 1][sizeb - 1]) {
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
	for (int a = x; a < sizea - 1; a++) {
		for (int b = 0; b < sizeb; b++) {
			newarr[a][b] = newarr[a + 1][b];
		}
	}
	for (int b = y; b < sizeb - 1; b++) {
		for (int a = 0; a < sizea; a++) {
			newarr[a][b] = newarr[a][b + 1];
		}
	}
}

int main()
{
	fillrand(arr);
	print(arr);
	int newarr[sizea - 1][sizeb - 1];
	erase(arr, newarr);
	delete[] arr;
	cout << endl;
	print(newarr);
	cout << endl;
	return 0;
}