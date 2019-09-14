#include <iostream>
#include <chrono>
using std::cin;
using std::cout;


int fib_recursivo(int n) {
	if (n <= 1) {
		return n;
	}
	else {
		return fib_recursivo(n - 1) + fib_recursivo(n - 2);
	}
}

int fib_NoRecursivo(int n) {
	int x = 0;
	int n1 = 0;
	int n2 = 1;
	if (n <= 1){
		return n;
	}
	else {
		int f = 0;
		for (int i = 1; i < n ; i++) {
			f = n1 + n2;
			n1 = n2;
			n2 = f;
			x = x + 1;
		}
		return f;
	}
	
}

int main() {
	int numero = 0;
	
	cout << "Introduce el numero en la secuencia de Fibonacci que quieres calcular: " << "\n";
	cin >> numero;

	cout << "El numero en la secuencia de Fibonacci es: " << numero << "\n";
	auto start = std::chrono::system_clock::now(); 
	cout << "El valor correspondiente con algoritmo de Fibonnaci NO Recursivo es: " << fib_NoRecursivo(numero) << "\n";
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<float, std::milli> duration = end - start;

	cout << "Terminado en: " << (duration.count() / 1000) << " segundos" << "\n";

	start = std::chrono::system_clock::now();
	cout << "El valor correspondiente con algoritmo de Fibonnaci Recursivo es: " << fib_recursivo(numero) << "\n"; 
	end = std::chrono::system_clock::now();
	std::chrono::duration<float, std::milli> duration2 = end - start;

	cout << "Terminado en: " << (duration2.count() / 1000) << " segundos" << "\n";
	

	cin.ignore(2);
	return 0;
}
