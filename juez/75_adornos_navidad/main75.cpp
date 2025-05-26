#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class comparador {
public:
	bool operator ()(std::pair <int, int > p1, std::pair <int, int > p2) {
		return (float)p1.second / p1.first > (float)p2.second / p2.first;
	}
};
struct tDatos {
	int n, presupuesto;
	std::vector <std::pair<int, int>> d; //first: coste; second: superficie; 
};


int estimar(tDatos const& datos, int costeActual, int k) {
	int i = k + 1; 
	int sumaCoste = costeActual; 
	int sumaSuperficie = 0;
	while (i < datos.n && (sumaCoste + datos.d[i].first) <= datos.presupuesto) {
		sumaCoste += datos.d[i].first;
		sumaSuperficie += datos.d[i].second;
		++i;
	}

	if (i < datos.n && sumaCoste < datos.presupuesto) {
		int presRestante = datos.presupuesto - sumaCoste;
		sumaSuperficie += (datos.d[i].second * presRestante/ datos.d[i].first) + 1;
	}
	return sumaSuperficie;
}



int inicializarSuperficie(tDatos const& datos) {
	int sumaSuperficie = 0;
	int sumaCoste = 0; 
	int i = 0; 
	while (i < datos.n && (sumaCoste + datos.d[i].first) <= datos.presupuesto) {
		sumaSuperficie += datos.d[i].second;
		sumaCoste += datos.d[i].first; 
		++i;
	}
	return sumaSuperficie;
}

void solucionar(tDatos const& datos, int k, std::vector<bool> &sol, std::vector<bool> &solMejor, int &costeActual,
	int &superficieActual, int &superficieMax) {

	sol[k] = true; // tomo el objecto
	costeActual += datos.d[k].first;
	superficieActual += datos.d[k].second;
	if (costeActual <= datos.presupuesto) {
		if (k == datos.n - 1) { //es solucion
			if (superficieActual > superficieMax) {
				superficieMax = superficieActual;
				solMejor = sol;
			}
		}
		else {
			solucionar(datos, k + 1, sol, solMejor, costeActual, superficieActual, superficieMax);
		}
	}


	costeActual -= datos.d[k].first;
	superficieActual -= datos.d[k].second;
	sol[k] = false;

	if (costeActual <= datos.presupuesto) {
		if (k == datos.n - 1) { //es solucion
			if (superficieActual > superficieMax) {
				superficieMax = superficieActual;
				solMejor = sol;
			}
		}
		else {
			if ((superficieActual + estimar(datos, costeActual, k) > superficieMax))
				solucionar(datos, k + 1, sol, solMejor, costeActual, superficieActual, superficieMax);
		}
	}


}


bool resolver() {
	tDatos datos;
	cin >> datos.n >> datos.presupuesto;
	if (!cin) return false;
	std::pair<int, int> aux;
	for (int i = 0; i < datos.n; ++i) {
		cin >> aux.first >> aux.second;
		datos.d.push_back(aux);
	}
	std::sort(datos.d.begin(), datos.d.end(), comparador());

	int superficieMax = inicializarSuperficie(datos);
	int superficieActual = 0;
	int costeActual = 0;


	std::vector <bool> sol(datos.n, false);
	std::vector <bool> solMejor;

	solucionar(datos, 0, sol, solMejor, costeActual, superficieActual, superficieMax);
	cout << superficieMax << endl;

	return true;

}

int main() {
	while (resolver());
	return 0;
}