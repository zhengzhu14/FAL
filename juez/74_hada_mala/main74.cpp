#include <iostream>
#include <vector>

using namespace std;
using tMatriz = std::vector<std::vector <int>>;

struct tDatos {
	tMatriz d;
	int n, m; //n es el numero de habitantes y m es el numero de invitados
	int hada;
};


void gestionar(int k, tDatos const& datos, std::vector <bool> &marcas, std::vector<int> &sol,
int &supersticion, int &satisActual, int &satisMejor, int &contMejor, std::vector <int> const & acum) {
	for (int i = 0; i < datos.n; ++i) {
		sol[k] = i; 
		if (datos.d[k][i] >= 0 && !marcas[i]) {
			satisActual += datos.d[k][i];
			marcas[i] = true; //marco
			if (k == i) ++supersticion;
			if (supersticion <= (datos.m / 3)) {
				if (k == (datos.m - 1)) {
					if (marcas[datos.hada]) { //Si es solucion valida, es decir el hada esta invitada.
						if (satisActual > satisMejor) {
							satisMejor = satisActual;
							contMejor = 1;
						}
						else if (satisActual == satisMejor) ++contMejor;
					}
				}
				else {//aqui se estima
					if ((acum[k] + satisActual) >= satisMejor)
						gestionar(k + 1, datos, marcas, sol, supersticion, satisActual, satisMejor, contMejor, acum);
				}
			}

			
			satisActual -= datos.d[k][i];
			marcas[i] = false; //desmarco
			if (k == i) --supersticion;
		}
	}

}

bool resolver() {
	tDatos datos;
	cin >> datos.n;
	if (datos.n == 0) return false;
	cin >> datos.m >> datos.hada;
	std::vector <int> entrada(datos.n);
	for (int i = 0; i < datos.m; ++i) {
		for (int j = 0; j < datos.n; ++j) {
			cin >> entrada[j];
		}
		datos.d.push_back(entrada);
	}
	
	int satisMejor = -1; 
	int contMejor = 0;
	int satisActual = 0;

	int supersticion = 0;

	std::vector <int> sol(datos.m); //vector solucion de tamanyo el numero de invitados posibles
	std::vector <bool> marcas(datos.n, false); //vector de marcas del tamanyo


	//Para estimar, creo un vector de acumulados con la mejor valoracion para cada asiento.
	std::vector <int> acum(datos.m);
	for (int i = 0; i < datos.m; ++i) {
		acum[i] = datos.d[i][0];
		for (int j = 1; j < datos.n; ++j) {
			if (datos.d[i][j] > acum[i]) acum[i] = datos.d[i][j];
		}
	}
	for (int i = acum.size() - 1; i > 0; --i) {
		acum[i - 1] += acum[i];
	}


	gestionar(0, datos, marcas, sol, supersticion, satisActual, satisMejor, contMejor, acum);
	if (contMejor > 0) {
		cout << satisMejor << " " << contMejor << endl;
	}
	else cout << "No" << endl;

	return true;
}

int main() {
	while (resolver());
	return 0;
}