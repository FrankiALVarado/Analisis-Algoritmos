#include<iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void insertionSort(int arr[], int & n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void arregloRandom(int arr[], int & n) {
	for (int i = 0; i < 100; i++) {
		arr[i] = (rand() % n) + 1;
	}
}

void arregloCreciente(int arr[],int & n) {

	for (int i = 0; i < n; i++) {
		arr[i] = i + 1;
	}
}

void arregloDecreciente(int arr[], int & n) {

	for (int i = 0; i < n; i++) {
		arr[i] = n - i;
	}
}
int main()
{
	int arr[1000];
	int n = sizeof(arr) / sizeof(arr[0]);
	//arregloRandom(arr);
	arregloCreciente(arr, n);
	auto start = std::chrono::system_clock::now();
	insertionSort(arr, n);
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<float, std::milli> duration = end - start;
	cout << "Insertion en orden creciente" << (duration.count()) << "mili segundos" << "\n";
	//printArray(arr, n);

	arregloDecreciente(arr, n);
	start = std::chrono::system_clock::now();
	insertionSort(arr, n);
	end = std::chrono::system_clock::now();
	duration = end - start;
	cout << "Insertion en orden decreciente" << (duration.count()) << "mili segundos" << "\n";
	//printArray(arr, n);

	arregloRandom(arr, n);
	start = std::chrono::system_clock::now();
	insertionSort(arr, n);
	end = std::chrono::system_clock::now();
	duration = end - start;
	cout << "Insertion en orden decreciente" << (duration.count()) << "mili segundos" << "\n";
	//printArray(arr, n);

	return 0;
}
