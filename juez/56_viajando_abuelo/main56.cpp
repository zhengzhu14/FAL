#include <iostream>
#include <vector>


using namespace std;

bool abueloAguanta(int paradas, int tiempo, std::vector <int> const& v) {
	int aux = 0; 
	int i = 0;
	while (i < v.size()) {
		aux += v[i];
		if (aux > tiempo) {
			aux = v[i];
			--paradas;
		}
		++i;
	}
	return paradas >= 0;
}

int espera(int ini, int fin, int paradas, std::vector <int> const& v) {
	if (ini >= fin) return ini;
	else {
		int mitad = (ini + fin - 1) / 2;
		bool aguantable = abueloAguanta(paradas, mitad, v);
		if (aguantable) return espera(ini, mitad, paradas, v);
		else return espera(mitad + 1, fin, paradas, v);
	}
}

bool resolver() {
	int tam, paradas;
	cin >> tam >> paradas;
	if (tam == 0 && paradas == 0) return false;
	std::vector<int> v(tam);
	int suma = 0;
	int max = 0;
	for (int i = 0; i < tam; ++i) {
		cin >> v[i];
		suma += v[i];
		if (v[i] > max) max = v[i];
	}

	int sol = espera(max, suma, paradas, v);
	cout << sol << endl;

	return true;
}

int main() {
	while (resolver());

	return 0;
}