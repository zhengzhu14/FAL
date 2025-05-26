#include <iostream>
#include <vector>

using namespace std;
using tVector = std::vector <bool>;
using tSolucion = std::pair <bool, pair<int,int>>; //boleano que indica si hay jugador para jugar el partido 
//el primer entero indica la cantidad de partidas y el segundo indica la ronda.

tSolucion partJugadas(int ini, int fin, int ronda, tVector const& v) {
	if (ini >= fin) {
		return { v[ini], {0 , 0} };
	}
	else {
		int mitad = (ini + fin) / 2;
		
		tSolucion m1 = partJugadas(ini, mitad, ronda, v);
		tSolucion m2 = partJugadas(mitad + 1, fin, ronda, v);
		tSolucion sol;
		sol.second.first = m1.second.first + m2.second.first;
		sol.second.second = m1.second.second + 1;
		sol.first = (m1.first || m2.first);
		if (sol.second.second <= ronda) {
			if (m1.first && m2.first) ++sol.second.first;
		}
		return sol;
		
	}
}

int partJugadas(tVector const& v, int ronda) {
	return partJugadas(0, v.size() - 1, ronda, v).second.first;
}

bool resolver() {
	int tam; 
	cin >> tam;
	if (!cin) return false;
	int ronda;
	cin >> ronda;
	tVector v(tam);
	string aux;
	for (int i = 0; i < tam; ++i) {
		cin >> aux; 
		if (aux == "NP") v[i] = false;
		else v[i] = true;
	}
	int sol = partJugadas(v, ronda);
	cout << sol << endl;

	return true;

}

int main() {
	while (resolver());
	return 0;
}