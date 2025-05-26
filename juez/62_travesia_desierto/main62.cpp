#include <iostream>
#include <vector>

using namespace std;

int diaRacion(int ini, int fin, int m, std::vector <int> const & v) {
	if (ini >= fin) {
		if (v[ini] >= m * (int(v.size()) - ini)) return -1;
		else return ini;
	}
	else {
		int mitad = (ini + fin) / 2;
		if (v[mitad] >= m * (int(v.size()) - mitad)) return diaRacion(mitad + 1, fin, m, v);
		else return diaRacion(ini, mitad, m, v);
	}
}

void resolver() {
	int tam, m;
	cin >> tam >> m;
	std::vector <int> v(tam);
	for (int i = 0; i < tam; ++i) cin >> v[i];
	int sol = diaRacion(0, v.size() - 1, m, v);
	if (sol == - 1) cout << "SIN RACIONAMIENTO\n";
	else cout << sol << endl;

}
int main() {
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; ++i) resolver();
	return 0;
}