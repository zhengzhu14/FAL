//Nombre: Zhengkai Zhu
//email:  zhengzhu@ucm.es
//Problema: 28 asalto en el tren.

#include <iostream>
#include <vector>

using namespace std;

struct tRobo {
	int p;
	int ganancia;
};

tRobo roboTren(std::vector <int> const & v, int k) {
	int j = 0;
	int sumaActual = 0;
	int pos = 0;
	while (j < k) {
		sumaActual += v[j];
		++j;
	}
	int sumaMax = sumaActual;
	while (j < v.size()) {
		sumaActual += v[j];
		sumaActual -= v[j - k];
		if (sumaActual >= sumaMax) {
			sumaMax = sumaActual;
			pos = j - k + 1;
		}
		++j;
	}

	tRobo sol;
	sol.p = pos;
	sol.ganancia = sumaMax;
	return sol;
}

void resolver() {
	int tam, k;
	cin >> tam >> k;
	std::vector <int> v(tam);
	for (int i = 0; i < tam; ++i) cin >> v[i];
	tRobo sol = roboTren(v, k);
	cout << sol.p << ' ' << sol.ganancia << endl;
}

int main() {
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; ++i) resolver();
	return 0;
}


/* Coste:
 Sea n el numero de vagones que tiene el tren.
 El caso peor el aquel en el que k = 1 y el vector con las ganancias de cada vagon esta ordenado de menor a mayor.
 Funcion de coste: 
  - Asignaciones fuera de los bucles (sin contar las de la solucion): 4 de coste cte.
  - Coste primer bucle en este caso: 4 (2 comparaciones y dos operaciones aritmeticas)
  - Coste segundo bucle: 
     . Iteraciones: n - 1.
	 . Operaciones por iteracion: 6
	 . +ultima comparacion.
	 : Coste: 6(n - 1) + 1.
  - F(n) = 6(n - 1) + 5.
  F € O(n)


*/