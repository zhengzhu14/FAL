#include <iostream>


using namespace std;

int sumDigitosNoFinal(int n) {
	if (n < 10) return n;
	else {
		return n % 10 + sumDigitosNoFinal(n / 10);
	}
}

int sumDigitosFinal(int n, int sol) {
	if (n == 0) return sol;
	else {
		return sumDigitosFinal(n / 10, sol + n % 10);
	}
}

void resolver() {
	int cantidad;
	int numero;
	cin >> cantidad >> numero;
	int aux;
	int suma = sumDigitosFinal(numero, 0);
	for (int i = 0; i < cantidad; ++i) {
		cin >> aux;
		if ( suma == sumDigitosFinal(aux, 0)) {
			cout << aux << ' ';
		}
	}
	cout << endl;
}

int main() {
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; ++i) resolver();

	return 0;
}