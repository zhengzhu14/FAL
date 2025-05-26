#include <iostream>
#include <vector>

using namespace std;

int concavidad(std::vector<int> v, int ini, int fin) {
	if (ini >= fin) return v[ini];
	else {
		int medio = (ini + fin) / 2;
		if (v[medio] < v[medio + 1]) return concavidad(v, ini, medio);
		else return concavidad(v, medio + 1, fin);
	}
}

bool resolver() {
	int tam;
	cin >> tam;
	if (!cin) return false;
	std::vector <int> v(tam);
	for (int i = 0; i < tam; ++i) cin >> v[i];
	int sol = concavidad(v, 0, v.size() - 1);
	cout << sol << endl;
	return true;

}

int main() {
	while (resolver());
	return 0;
}