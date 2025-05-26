#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


pair <bool, int> interseccion(int ini, int fin, std::vector <int> v1, std::vector<int> v2) {
	if (ini > fin) return { false, fin };
	else {
		int mitad = (fin + ini) / 2;
		if (v1[mitad] == v2[mitad])return { true, mitad };
		else if (v1[mitad] > v2[mitad]) return interseccion(ini, mitad - 1, v1, v2);
		else  return interseccion(mitad + 1, fin, v1, v2);
	}
}

bool resolver() {
	int tam;
	cin >> tam;
	if (tam == 0) return false;
	std::vector<int> v1(tam);
	std::vector <int > v2(tam);
	for (int i = 0; i < tam; ++i) cin >> v1[i];
	for (int i = 0; i < tam; ++i) cin >> v2[i];
	pair <bool, int> sol = interseccion(0, tam - 1, v1, v2);
	if (sol.first) cout << "SI " << sol.second << endl;
	else cout << "NO " << sol.second << ' ' << sol.second + 1 << endl;

	return true;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.in");
	auto cinbuf = cin.rdbuf(in.rdbuf());
#endif
	while (resolver());

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}