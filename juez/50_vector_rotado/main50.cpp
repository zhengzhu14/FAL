#include <iostream>
#include <vector>

using namespace std;

int buscarRotado(std::vector<int> v, int buscado,int ini, int fin) {
	if (ini >= fin) return ini;
	else {
		int mitad = (ini + fin) / 2;
		if (v[mitad] >= v[ini]) {
			if (buscado <= v[mitad] && buscado >= v[ini]) return buscarRotado(v, buscado, ini, mitad);
			else return buscarRotado(v, buscado, mitad + 1, fin);
		}
		else {
			if (buscado >= v[mitad] && buscado <= v[fin]) return buscarRotado(v, buscado, mitad + 1, fin);
			else return buscarRotado(v, buscado, ini, mitad);
		}
	}
}

bool resolver() {
	int tam;
	cin >> tam;
	if (tam == -1) return false;
	int b;
	cin >> b;
	std::vector<int> v(tam);
	for (int i = 0; i < tam; ++i) cin >> v[i];
	int sol = buscarRotado(v, b, 0, v.size() - 1);
	if (sol == v.size() || v[sol] != b) cout << "NO";
	else cout << "SI";
	cout << endl;

	return true;

}

int main() {
	while (resolver());
	return 0;
}