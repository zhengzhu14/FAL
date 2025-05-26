#include <iostream>
#include <vector> 
#include <fstream> 

using namespace std;


bool pesoCorrecto(int dias, int camion, std::vector <int> const& v) {
	int aux = 0;
	int i = 0; 
	while (i < v.size()) {
		aux += v[i];
		if (aux >= camion) {
			if (aux == camion) aux = 0; 
			else {
				aux = v[i];
			}
			--dias;
		}
		++i;
	}
	if (aux > 0 && aux <= camion) --dias;
	return dias >= 0;
}

int pesoCamion(int ini, int fin, int dias, std::vector <int> const &v) {
	if (ini >= fin) return ini;
	else {
		int mitad = (ini + fin - 1) / 2;
		bool peso = pesoCorrecto(dias, mitad, v);
		if (peso) return pesoCamion(ini, mitad, dias, v);
		else return pesoCamion(mitad + 1, fin, dias, v);
	}
}

bool resolver() {
	int tam; int dias;
	cin >> tam >> dias;
	if (tam == 0 && dias == 0) return false;
	std::vector <int> v(tam);
	int suma = 0;
	int max = 0;
	for (int i = 0; i < tam; ++i) {
		cin >> v[i];
		suma += v[i];
		if (v[i] > max) max = v[i];
	}
	int sol = pesoCamion(max, suma, dias, v);
	cout << sol << endl;
	return true;
}


int main() {
	while (resolver());
	return 0;
}