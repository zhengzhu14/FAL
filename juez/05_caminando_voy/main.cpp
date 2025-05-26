//Nombre: Zhengkai Zhu 
//Problema 5: Caminando voy
// Juez: A70


#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

bool apto(const std::vector<int> v, int d) {
	bool apto = true;
	int dif = 0;
	int i = 1;
	while (i < v.size() && apto) {
		if (v[i] > v[i - 1]) {
			dif += (v[i] - v[i - 1]);
		}
		else dif = 0;
		if (dif > d) apto = false;
		++i;
	}

	return apto;
}


bool resolver() {
	int d, tam;
	cin >> d;
	if (!cin) return false;
	std::vector<int> v;
	int cas;
	cin >> tam;
	for (int i = 0; i < tam; ++i) {
		cin >> cas;
		v.push_back(cas);
	}

	if (!apto(v, d)) cout << "NO APTA\n";
	else cout << "APTA\n";


	return true;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("sample-05.1.in");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); 
#endif

	while (resolver());

#ifndef DOMJUDGE 
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}