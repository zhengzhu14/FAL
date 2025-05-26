#include <iostream>
#include <vector>

using namespace std;

int mergeInversiones(int ini, int medio, int fin, std::vector <int>& aux, std::vector <int>& v) {
	int sol = 0;
	int k = ini;
	int i = ini;
	int j = medio + 1;
	while (i <= medio && j <= fin) {
		if (v[i] < v[j]) {
			aux[k] = v[i];
			++k; ++i;
		}
		else {
			sol += (medio - i) + 1;
			aux[k] = v[j];
			++k; ++j;
		}
	}
	while (i <= medio) {
		aux[k] = v[i];
		++k; ++i;
	}
	while (j <= fin) {
		aux[k] = v[j];
		++k; ++j;
	}

	for (int n = ini; n <= fin; ++n) {
		v[n] = aux[n];
	}
	return sol;
}

int inversiones(int ini, int fin, std::vector <int>& aux, std::vector <int>& v) {
	if (ini >= fin) return 0;
	else {
		int sol = 0;
		int mitad = ini + (fin - ini) / 2;
		sol += inversiones(ini, mitad, aux, v);
		sol += inversiones(mitad + 1, fin, aux, v);
		sol += mergeInversiones(ini, mitad, fin, aux, v);
		return sol;
	}
}

int inversiones(std::vector <int> & v) {
	std::vector <int> aux(v.size());
	return inversiones(0, v.size() - 1, aux, v);
}

bool resolver() {
	int tam;
	cin >> tam; 
	if (!cin) return false;
	std::vector <int> v(tam);
	for (int i = 0; i < tam; ++i) cin >> v[i];

	int sol = inversiones(v);
	cout << sol << endl;

	return true;
}
int main() {
	while (resolver());
	return 0;
}