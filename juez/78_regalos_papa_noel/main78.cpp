#include <iostream>
#include <vector>
#include <string>

using namespace std;

using tTipos = std::vector <std::pair<int, string>>;
struct tDatos {
	int m, n, satisfaccion;
	std::vector<std::vector<int>> d;
};


std::ostream& operator <<(ostream& salida, std::vector<std::pair<int, int>> const&sol) {
	for (int i = 0; i < sol.size(); ++i) {
		salida << sol[i].first << " " << sol[i].second << " ";
	}
	cout << endl;
	return salida;
}


void regalos(int k, int &cont, std::vector<std::pair<int, int>> sol, tTipos &tipos , tDatos const& datos ) {
	for (int i = 0; i < datos.m - 1; ++i) {
		sol[k].first = i; 
		if (tipos[i].first > 0) {
			--tipos[i].first;
			for (int j = i + 1; j < datos.m; ++j) {
				sol[k].second = j;
				if (tipos[i].second != tipos[j].second && tipos[j].first > 0) {
					--tipos[j].first;
					if (datos.d[k][i] + datos.d[k][j] >= datos.satisfaccion) {
						if (k == datos.n - 1) {
							++cont;
							cout << sol;
						}
						else {
							regalos(k + 1, cont, sol, tipos, datos);
						}
					}

					++tipos[j].first;
				}
			}
			++tipos[i].first;
		}
	}
}


bool resolver() {
	tDatos datos;
	cin >> datos.m >> datos.n >> datos.satisfaccion;
	if (!cin) return false;

	tTipos tipos(datos.m);
	for (int i = 0; i < datos.m; ++i) {
		cin >> tipos[i].first;
	}
	for (int i = 0; i < datos.m; ++i) {
		cin >> tipos[i].second;
	}

	std::vector <int> aux(datos.m);
	for (int i = 0; i < datos.n; ++i) {
		for (int i = 0; i < datos.m; ++i) {
			cin >> aux[i];
		}
		datos.d.push_back(aux);
	}

	int cont = 0;
	std::vector<std::pair<int, int>> sol(datos.n);
	regalos(0, cont, sol, tipos, datos);
	if (cont == 0) {
		cout << "SIN SOLUCION " << endl;
	}
	cout << endl;
	return true;
}

int main() {
	while (resolver());
	return 0;
}