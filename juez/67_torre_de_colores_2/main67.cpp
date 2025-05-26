#include <iostream>
#include <vector>

using namespace std;

void mostrar(std::vector <string> const& sol) {
	for (int i = 0; i < sol.size(); ++i) {
		cout << sol[i] << " ";
	}
	cout << endl;
}
bool esValida(std::vector<string> const& sol, int k) {
	return (sol[k - 1] == "verde" && sol[k] != "verde") || sol[k - 1] != "verde";
}
void torre(std::vector <string> const& colores, int n, int k, std::vector<string>& sol) {
	if (k >= n) mostrar(sol);
	else {
		for (int i = 0; i < colores.size(); ++i) {
			sol[k] = colores[i];
			if (esValida(sol, k)) {
				if (k == n - 1) mostrar(sol);
				else torre(colores, n, k + 1, sol);
			}
		}
	}
}

bool resolver() {
	int n;
	cin >> n;
	if (n == 0) return false;
	std::vector <string> sol(n);
	sol[0] = "rojo";
	std::vector<string> colores = { "azul", "rojo", "verde" };
	torre(colores, n, 1, sol);
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