#include "stdafx.h"
#include <iostream>
#include <ctime>
using namespace std;

const int sizea = 2, sizeb = 3, sizec = 4;
int m1[sizea][sizeb];
int m2[sizec][sizea];
int m3[sizec][sizeb] = {0};

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

int main()
{
	srand(time(NULL));
	fillrand(m1);
	fillrand(m2);
	print(m2);
	cout << endl;
	print(m1);
	cout << endl;

	for (int x = 0; x < sizec; x++) {
		for (int y = 0; y < sizeb; y++) {
			for (int a = 0; a < sizea; a++) {
				m3[x][y] += m1[a][y]*m2[x][a];
			}
		}
	}

	print(m3);
	cout << endl;
    return 0;
}
