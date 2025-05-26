#include <iostream>
#include <vector>

using namespace std;
using tVector = std::vector<int>;
struct tDatos {
	int m, n;
	tVector d;
};


void comprobar(int k, tDatos const& datos, int & sumaActual, bool &encontrado, std::vector<bool> &sol,
	std::vector <long long int> const& acum) {
	sol[k] = true;
	if (!encontrado && acum[k] + sumaActual >= datos.m && sumaActual - acum[k] <= datos.m) {
		sumaActual += datos.d[k + 1];
		if (k == datos.n - 2) {
			if (sumaActual == datos.m) {
				encontrado = true;
			}
		}
		else {
			comprobar(k + 1, datos, sumaActual, encontrado, sol, acum);
		}
		sumaActual -= datos.d[k + 1];
	}
	
	

	sol[k] = false;
	
	if (!encontrado && acum[k] + sumaActual >= datos.m && sumaActual - acum[k] <= datos.m) {
		sumaActual -= datos.d[k + 1];
		if (k == datos.n - 2) {
			if (sumaActual == datos.m) encontrado = true;
		}
		else {
			comprobar(k + 1, datos, sumaActual, encontrado, sol, acum);
		}
		sumaActual += datos.d[k + 1];
	}
	
}

void resolver() {
	tDatos datos;
	cin >> datos.m >> datos.n;
	if (datos.n > 0) {
		int aux;
		
		for (int i = 0; i < datos.n; ++i) {
			cin >> aux;
			datos.d.push_back(aux);
		}
		if (datos.n == 1) {
			if (datos.d[0] == datos.m) cout << "SI" << endl;
			else cout << "NO" << endl;
		}
		else {
			int sumaActual = datos.d[0];
			bool encontrado = false;
			std::vector<bool> sol(datos.n - 1); //true: suma, false: resta.
			std::vector<long long int> acum(datos.n - 1, 0);
			acum[acum.size() - 1] = datos.d[acum.size()];

			for (int i = acum.size() - 1; i > 0; --i) {
				acum[i - 1] = acum[i] + datos.d[i];
			}

			comprobar(0, datos, sumaActual, encontrado, sol, acum);
			if (encontrado) cout << "SI" << endl;
			else cout << "NO" << endl;
		}
	}
	else {
		if (datos.m == 0) cout << "SI" << endl;
		else cout << "NO" << endl;
	}
	

}
int main() {
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; ++i) resolver();

	return 0;
}