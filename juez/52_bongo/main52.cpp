#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int bongo(int ini, int fin, int cantado, std::vector <int> const &v) {
	if (ini > fin) return -1;
	else {
		int mitad = (ini + fin) / 2;
		if (v[mitad] == (mitad + cantado)) return mitad;
		else if (v[mitad] < (mitad + cantado)) {
			return bongo(mitad + 1, fin, cantado, v);
		}
		else return bongo(ini, mitad - 1, cantado, v);
	}
}

void resolver() {
	int tam, cantado;
	cin >> tam >> cantado;
	std::vector <int> v(tam);
	for (int i = 0; i < tam; ++i) cin >> v[i];
	int sol = bongo(0, v.size() - 1, cantado, v);
	if (sol == -1) cout << "NO\n";
	else cout << v[sol] << endl;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.in");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());

#endif
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; ++i) resolver();

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}