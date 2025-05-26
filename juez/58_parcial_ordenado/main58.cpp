#include <iostream>
#include <vector>

using namespace std;

using tSolucion = pair <bool, pair<int, int>>;
//primer entero es el minimo y el segundo es el maximo

tSolucion parcOrden(int ini, int fin, std::vector <int> const& v) {
	if (ini == fin) {
		return { true, {v[ini], v[ini]}};
	}
	else {
		int mitad = (ini + fin) / 2;
		tSolucion iz = parcOrden(ini, mitad, v);
		tSolucion der = parcOrden(mitad + 1, fin, v);
		tSolucion sol;
		if (iz.second.second < der.second.second) sol.second.second = iz.second.second;
		else sol.second.second = der.second.second;
		if (iz.second.first < der.second.first) sol.second.first = der.second.first;
		else sol.second.first = iz.second.first;

		sol.first = iz.first && der.first;
		sol.first = sol.first && (der.second.second >= iz.second.second) && (iz.second.first <= der.second.first);
		return sol;
	}
}

bool parcOrden(std::vector <int> const& v) {
	return parcOrden(0, v.size() - 1, v).first;
}

bool resolver() {
	std::vector<int> v;
	int aux;
	cin >> aux;
	if (aux == 0) return false;
	while (aux != 0) {
		v.push_back(aux);
		cin >> aux;
	}

	bool sol = parcOrden(v);
	if (sol) cout << "SI\n";
	else cout << "NO\n";
	return true;
}

int main() {
	while (resolver());
	return 0;
}