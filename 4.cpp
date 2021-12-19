#include "stdafx.h"
#include <iostream>
#include <ctime>
using namespace std;

const int sizem = 5;
int arr[sizem][sizem];

template <size_t rows, size_t cols>
void fillrand(int (&arr)[rows][cols]) {
	for (int a = 0; a < rows; a++) 
		for (int b = 0; b < cols; b++) {
			arr[a][b] = rand()%100;
		}
}

template <size_t rows, size_t cols>
void print(int (&arr)[rows][cols]) {
	for (int a = 0; a < rows; a++) {
		for (int b = 0; b < cols; b++) {
			cout << arr[a][b] << ' ';
		}
		cout << endl;
	}
}

template <size_t rows, size_t cols>
void switcha (int (&arr)[rows][cols], int x, int y) {
	for (int a = 0; a < rows - 1; a++) {
		int t = arr[x][a + (a>=y)];
		arr[x][a + (a >= y)] = arr[a + (a >= x)][y];
		arr[a + (a >= x)][y] = t;
	}
}



int main()
{
	srand(time(NULL));
	fillrand(arr);
	print(arr);
	cout << endl;
	int x = 0, y = 0, min = arr[0][0];
	for (int a = 0; a < sizem; a++) {
		for (int b = 0; b < sizem; b++) {
			if (arr[a][b] < min) {
				min = arr[a][b];
				x = a;
				y = b;
			}
		}
	}
	switcha(arr, x, y);
	print(arr);
	cout << endl;
    return 0;
}
