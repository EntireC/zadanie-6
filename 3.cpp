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
void reflect(int(&arr)[rows][cols]) {
	for (int a = 0; a < rows; a++) {
		for (int b = 0; b < cols; b++) {
			{
				if (a+b<sizem) {
					int t = arr[a][b];
					arr[a][b] = arr[sizem - 1 - b][sizem - 1 - a];
					arr[sizem - 1 - b][sizem - 1 - a] = t;
				}
			}
		}
	}
}



int main()
{
	srand(time(NULL));
	fillrand(arr);
	print(arr);
	cout << endl;
	reflect(arr);
	print(arr);
	cout << endl;
    return 0;
}
