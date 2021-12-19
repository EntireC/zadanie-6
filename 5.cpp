#include "stdafx.h"
#include <iostream>
#include <ctime>
using namespace std;

const int sizea = 10, sizeb = 5;
int arr[sizea][sizeb];

template <size_t rows, size_t cols>
void fillrand(int (&arr)[rows][cols]) {
	for (int a = 0; a < rows; a++) 
		for (int b = 0; b < cols; b++) {
			arr[a][b] = rand()%10;
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
void mintomax (int (&arr)[rows][cols]) {
	int max = arr[0][0], min = arr[0][0], minpoint, maxnew;
	for (int b = 1; b < cols; b++) 
		if (arr[0][b] > max) max = arr[0][b];
	for (int a = 1; a < rows; a++) {
		min = arr[a][0];
		minpoint = 0;
		maxnew = arr[a][0];
		for (int b = 1; b < cols; b++) {
			if (arr[a][b] < min) {
				min = arr[a][b];
				minpoint = b;
			}
			if (arr[a][b] > maxnew) maxnew = arr[a][b];
		}
		arr[a][minpoint] = max;
		max = maxnew;
	}
}



int main()
{
	srand(time(NULL));
	fillrand(arr);
	print(arr);
	cout << endl;
	mintomax(arr);
	print(arr);
	cout << endl;
    return 0;
}
