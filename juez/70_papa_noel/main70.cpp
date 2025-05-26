#include <iostream>
#include <vector>

using namespace std;

struct tDatos {
	int m, n; //m : numero de juguetes, n: numero de ninyos.
	std::vector <std::vector <int>> j;
};


void regalos(int k, int &satActual, std::vector <bool>& marcas, std::vector<int>& sol, tDatos const& datos, 
	std::vector<int> const & acum , int & satMejor) {
	for (int i = 0; i < datos.m; ++i) {
		sol[k] = i;
		if (!marcas[i]) {
			marcas[i] = true;
			satActual += datos.j[k][i];
			if (k == (datos.n - 1)) {
				if (satActual > satMejor) satMejor = satActual;
			}
			else {
				if ((acum[k + 1] + satActual) > satMejor) {
					regalos(k + 1, satActual, marcas, sol, datos, acum, satMejor);
				}
			}
			satActual -= datos.j[k][i];
			marcas[i] = false;
		}
	}


}

bool resolver() {
	tDatos datos;
	cin >> datos.m >> datos.n;
	if (!cin) return false;

	std::vector <int> auxV(datos.m);
	for (int i = 0; i < datos.n; ++i) {
		for (int j = 0; j < datos.m; ++j) {
			cin >> auxV[j];
		}
		datos.j.push_back(auxV);
	}

	std::vector <int> acum(datos.n, 0);
	int maxFila;
	for (int i = 0; i < datos.n; ++i) {
		maxFila = datos.j[i][0];
		for (int j = 1; j < datos.m; ++j) {
			if (datos.j[i][j] > maxFila) maxFila = datos.j[i][j];
		}
		acum[i] = maxFila;
	}

	for (int i = acum.size() - 1; i > 0; --i) {
		acum[i - 1] += acum[i];
	}

	int satMejor = 0;
	for (int i = 0; i < datos.n; ++i) {
		satMejor += datos.j[i][i];
	} // Inicializo solMejor a una solucion inicial que es válida

	std::vector <bool> marcas(datos.m, false); //vector de marcas de juguetes.
	std::vector <int> sol(datos.n, 0); //vector de ninyos solucion.
	int satActual = 0;

	regalos(0, satActual, marcas, sol, datos, acum, satMejor);
	cout << satMejor << endl;


	return true;
}

int main() {
	while (resolver());
	return 0;
}