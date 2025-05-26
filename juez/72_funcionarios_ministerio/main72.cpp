#include <iostream>
#include <vector>

using namespace std;

using tMatriz = std::vector <std::vector<int>>;

void asignacion(int k, int& sumaActual, int& sumaMinima, tMatriz const& datos, std::vector <int> const& acum,
				std::vector<int> &sol, std::vector<bool> &marcas) {

	for (int i = 0; i < datos.size() ; ++i) {
		sol[k] = i;
		if (!marcas[i]) {
			marcas[i] = true;
			sumaActual += datos[k][i];
			if (k == (datos.size() - 1)) {
				if (sumaActual < sumaMinima) sumaMinima = sumaActual;
			}
			else {
				if ((acum[k + 1] + sumaActual) < sumaMinima) {
					asignacion(k + 1, sumaActual, sumaMinima, datos, acum, sol, marcas);
				}
			}
			sumaActual -= datos[k][i];
			marcas[i] = false;
		}

	}
}

bool resolver() {
	int n;
	cin >> n;
	if (n == 0) return false;
	tMatriz datos(n, std::vector<int>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> datos[i][j];
		}
	}
	std::vector <int> acum(n);
	int minFil = 0;
	for (int i = 0; i < n; ++i) {
		minFil = datos[i][0];
		for (int j = 1; j < n; ++j) {
			if (minFil > datos[i][j]) minFil = datos[i][j];
		}
		acum[i] = minFil;
	}
	for (int i = (n - 1); i > 0; --i) {
		acum[i - 1] += acum[i];
	}

	int sumaMinima = 0;
	for (int i = 0; i < n; ++i) {
		sumaMinima += datos[i][i];
	}
	int sumaActual = 0;
	std::vector <int> sol(n);
	std::vector<bool> marcas(n, false);


	asignacion(0, sumaActual, sumaMinima, datos, acum, sol, marcas);
	cout << sumaMinima << endl;


	return true;
}

int main() {
	while (resolver());

	return 0;
}