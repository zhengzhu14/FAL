//Nombre: Zhengkai Zhu
//Esta bien dividido el vector (problema 4)
//Juez: A70

#include <iostream>
#include <vector>
#include <fstream>



using namespace std;

bool division(vector<int> v, int p) {
	//en esta funcion busco el maximo de la primera parte del vector hasta p y el minimo a partir de p
	//luego comparo si el maximo es menor que el minimo, si es cierto entonces esta bien dividido el vector
	int max = v[0];
	int min = v[v.size() - 1];

	for (int i = 0; i <= p; ++i) {
		if (v[i] > max) max = v[i];
	}
	for (int i = v.size() - 1 ; i > p; --i) {
		if (v[i] < min) min = v[i];
	}

	return max < min;
}

void resolver() {
	int tam, p;
	cin >> tam >> p;
	std::vector <int> v;
	int t;
	for (int i = 0; i < tam; ++i) {
		cin >> t;
		v.push_back(t);
	}
	if (p == tam - 1) {
		cout << "SI\n";
	}

	else {
		bool cierto = division(v, p);
		if (cierto) cout << "SI" << endl;
		else cout << "NO" << endl;
	}
	
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("sample-04.3.in");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
	std::ofstream out("datos.out");
	auto coutbuf = std::cout.rdbuf(out.rdbuf());
#endif*/
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		resolver();
	}

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	std::cout.rdbuf(coutbuf);
	system("PAUSE");
#endif

	return 0;
}