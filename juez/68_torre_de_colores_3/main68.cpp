#include <iostream>
#include <vector>

using namespace std;

void mostrar(std::vector <int> const& sol) {
	for (int i = 0; i < sol.size(); ++i) {
		if (sol[i] == 0) cout << "azul";
		else if (sol[i] == 1) cout << "rojo";
		else cout << "verde";
		cout << " ";
	}
	cout << endl;
}
bool esValida(std::vector<int> const& sol, int k, std::vector<int>const& marcas) {
	return (marcas[0] >= marcas[2]) && ((sol[k - 1] == 2 && sol[k] != 2) || sol[k - 1] != 2);
}
bool esSolucion(std::vector<int> const& marcas) {
	return marcas[1] > (marcas[0] + marcas[2]);
}
void torre(std::vector <int> const& piezas, int n, int k, std::vector<int>& sol, std::vector<int> &marcas, int &contador) {
	for (int i = 0; i < 3; ++i) {
		sol[k] = i;
		if (marcas[i] < piezas[i]) {
			++marcas[i];
			if (esValida(sol, k, marcas)) {
				if (k == n - 1) {
					if (esSolucion(marcas)) { 
						++contador;
						mostrar(sol);
					}
				}
				else torre(piezas, n, k + 1, sol, marcas, contador);
			}
			--marcas[i];
		}

	}
}

bool resolver() {
	int n;
	cin >> n;
	std::vector <int> piezas(3);
	for (int i = 0; i < 3; ++i) cin >> piezas[i];
	if (n == 0 && piezas[1]== 0 && piezas[0]== 0 && piezas[2] == 0) return false;

	std::vector <int> sol(n);
	/*if ((piezas[1] <= n / 2) || ((piezas[0] + piezas[1] + piezas[2]) < n) || (piezas[0] < piezas[2])) {
		cout << "SIN SOLUCION\n";
	}*/
	int contador = 0;
	std::vector <int> marcas = { 0 , 1 , 0 }; //contador de piezas utilizadas 
	sol[0] = 1;
	torre(piezas, n, 1, sol, marcas, contador);
	if (contador == 0) cout << "SIN SOLUCION\n";
	cout << endl;
	return true;
}

int main() {
	while (resolver());
	return 0;
}


/*
Arbol de exploracion:

	Nivel 1:      azul				rojo				verde
	nivel 2:   azul rojo verde    azul rojo verde     azul rojo verde
	...

	nivel n: ....

Vector solucion: sol
	sol.size(): tamanyo de la torre.
	sol[i]: color dispomible para construir la torre
	i < sol.size().

*/