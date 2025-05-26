#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using tVector = std::vector <int>;

bool esValido(tVector const& sol, int k) {
	bool aux = true;
	if (k >= 2 && sol[k - 2] == sol[k - 1]) {
		aux = aux && sol[k] != sol[k - 1];
	}
	return aux;
}


void mostrar(tVector const& sol) {
	for (int i = 0; i < sol.size(); ++i) cout << sol[i] << " ";
	cout << endl;
}

void tiras(int tam, int k, int max, tVector & marcas, tVector& sol, tVector const& energias, int & acum, int& cont) {
	for (int i = 0; i < energias.size(); ++i) {
		sol[k] = i;
		++marcas[i];
		if ((marcas[i] - (k + 1 - marcas[i])) <= 1) {
			if (esValido(sol, k)) {
				acum += energias[i];
				if (k == tam - 1) {
					if (acum <= max) ++cont;
				}
				else tiras(tam, k + 1, max, marcas, sol, energias, acum, cont);
				acum -= energias[i];
			}
		}
		--marcas[i];
	}
}
bool resolver() {
	int tam;
	cin >> tam;
	if (tam == 0) return false;

	int cant, max;
	cin >> cant >> max;
	tVector sol(tam);
	tVector energias(cant);
	tVector marcas(cant, 0);
	for (int i = 0; i < cant; ++i) {
		cin >> energias[i];
	}
	int cont = 0;
	int acum = 0;
	tiras(tam, 0, max, marcas, sol, energias, acum, cont);
	cout << cont << endl;
	return true;
}

int main() {
	while (resolver());
	return 0;
}