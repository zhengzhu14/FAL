#include <iostream>
#include <vector>
using namespace std;

int buscarIz(int ini, int fin, int busc, std::vector <int> const& v) {
	if (ini >= fin) return ini; // vector vacio
	else if (ini + 1 == fin) return ini; // vector 1 elemento
	else { // Vector de dos o mas elementos
		int mitad = (ini + fin - 1) / 2;
		if (v[mitad] < busc) return buscarIz(mitad + 1, fin, busc, v);
		else return buscarIz(ini ,mitad + 1, busc, v );
	}

	/*if (ini > fin) return -1;
	else {
		int mitad = (ini + fin + 1) / 2;
		if (ini == fin && v[mitad] == busc) return mitad;
		if (v[mitad] < busc) return buscarIz(mitad + 1, fin, busc, v);
		else return buscarIz(ini, mitad - 1, busc, v);
	}*/

}

int buscarDr(int ini, int fin, int busc, std::vector <int> const& v) {
	if (ini >= fin) return ini; // vector vacio
	else if (ini + 1 == fin) return ini; // vector un elemento
	else { // vector 2 o mas elementos
		int mitad = (ini + fin) / 2;
		if (busc < v[mitad]) return buscarDr(ini, mitad, busc, v);
		else return buscarDr(mitad, fin, busc, v); // Incluye el elemento mitad
	}
}

bool resolver() {
	int tam, buscado;
	cin >> tam;
	if (!cin) return false;
	cin >> buscado;
	std::vector <int> v(tam);
	for (int i = 0; i < tam; ++i)cin >> v[i];
	int sol1 = buscarIz(0, v.size() - 1, buscado, v);
	if (sol1 == v.size()|| v[sol1] != buscado) cout << "NO EXISTE\n";
	else {
		int sol2 = buscarDr(0, v.size(), buscado, v);
		if (sol1 == sol2) cout << sol1 << endl;
		else cout << sol1 << ' ' << sol2 << endl;
	}

	return true;

}

int main() {
	while (resolver());

	return 0;
}