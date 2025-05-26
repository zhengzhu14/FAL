#include <iostream>
#include <vector>

using namespace std;

int buscarIz(std::vector <int> v, int ini, int fin) {
	if (ini >= fin) return ini;
	else {
		int mitad = (ini + fin) / 2;
		if (v[mitad] <= v[mitad + 1]) return buscarIz(v, ini, mitad);
		else return buscarIz(v, mitad + 1, fin);
	}
}
int buscarDr(std::vector <int> v, int ini, int fin) {
	if (ini >= fin) return ini;
	else {
		int mitad = (ini + fin - 1) / 2;
		if (v[mitad] < v[mitad + 1]) return buscarDr(v, ini, mitad);
		else return buscarDr(v, mitad + 1, fin);
	}
}

int fondoRio(std::vector <int> v, int ini, int fin) {
	return buscarDr(v, ini, fin) - buscarIz(v, ini, fin) + 1;
}

bool resolver() {
	int tam;
	cin >> tam;
	if (tam == -1) return false;
	std::vector <int> v(tam);
	for (int i = 0; i < tam; ++i) cin >> v[i];
	if (tam > 0) {
		int sol = fondoRio(v, 0, v.size() - 1);
		cout << sol << endl;
	}
	else cout << 0 << endl;
	

	return true;
}
int main() {
	while (resolver());
	return 0;
}