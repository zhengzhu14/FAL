#include <iostream>
#include <vector> 
#include <fstream> 

using namespace std;

int buscarFaltante(int ini, int fin, std::vector<int> const& v1, std::vector <int> const& v2) {
	//Se asumira que v1 tendra al menos un elemento, si tiene 0 elementos, no tendria sentido que v2 tuviera tamanyo -1.
	if (ini >= fin) return ini;
	else {
		int mitad = (ini + fin) / 2;
		if (v1[mitad] == v2[mitad]) return buscarFaltante(mitad + 1, fin, v1, v2);
		else return buscarFaltante(ini, mitad, v1, v2);
	}
}

void resolver() {
	int tam;
	cin >> tam;
	std::vector <int> v1(tam);
	std::vector <int> v2(tam - 1);
	for (int i = 0; i < tam; ++i) cin >> v1[i];
	for (int i = 0; i < tam - 1; ++i) cin >> v2[i];
	int sol = buscarFaltante(0, tam - 1, v1, v2);
	cout << v1[sol] << endl;


}


int main() {
#ifndef DOMJUDGE 
	std::ifstream in("datos.in");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; ++i) resolver();

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}


/*
Tomo n como el numero de elementos de v1.
Defincion recursiva:


buscarFalt(i, n, v1, v2) { v1[i]           i == n;
						   buscarFalt((i + n - 1)/2 + 1, n, v1, v2)      v1[(i + n - 1)/2] == v2[(i + n - 1)/2];
						   buscarFalt( i, (i + n - 1)/2, v1, v2)         v1[(i + n - 1)/2] == v2[(i + n - 1)/2];
}

Coste:

T(n) {	C0              n == 1;
		T(n/2) + C1     n > 1;
}

Desplegado: 

T(n) = T(n/2) + C1 = T(n / (2^2)) + C1 + C1 = ... = (k llamadas) T(n / 2 ^k) + k*C1 =
= ... = (1 == n/(2^log2(n)) )  T(n /(2^log2(n))) + log2(n)C1 = C0 + log2(n)C1.


T € O(log(n))



*/


