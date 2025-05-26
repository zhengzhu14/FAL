#include <iostream>
#include <vector>

using namespace std;

void mostrar(std::vector <string> const& sol) {
	for (int i = 0; i < sol.size(); ++i) {
		cout << sol[i] << " ";
	}
	cout << endl;
}
void torre(std::vector <string> const& colores, int n, int k, std::vector<string>& sol) {
	for (int i = 0; i < colores.size(); ++i) {
		sol[k] = colores[i];
		if (k == n - 1) mostrar(sol);
		else torre(colores, n, k + 1, sol);
	}
}

bool resolver() {
	int n;
	cin >> n;
	if (n == 0) return false;
	std::vector <string> sol(n);
	std::vector<string> colores = { "azul", "rojo", "verde" };
	torre(colores, n, 0, sol);
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