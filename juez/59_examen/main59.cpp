#include <iostream>
#include <vector>

using namespace std;
using tMatriz = std::vector<std::vector<int>>;
using tPareja = pair <bool, int>;


tPareja equilibrado(int iniC, int finC,int iniF, int finF,tMatriz const& m) {
	if (iniC >= finC && iniF >= finF) {
		if (m[iniF][iniC] == 1) return { true, 1 };
		else return { true, 0 };
	}
	else {
		int mitadF = (iniF + finF) / 2;
		int mitadC = (iniC + finC) / 2;
		tPareja p1 = equilibrado(iniC, mitadC, iniF, mitadF, m);
		tPareja p2 = equilibrado(mitadC + 1, finC, iniF, mitadF, m);
		tPareja p3 = equilibrado(iniC, mitadC, mitadF + 1, finF, m);
		tPareja p4 = equilibrado(mitadC + 1, finC, mitadF + 1, finF, m);
		int parcelas = (finC - iniC + 1) * (finC - iniC + 1);
		int labranzas = p1.second + p2.second + p3.second + p4.second;
		bool eq = p1.first && p2.first && p3.first && p4.first;
		eq = eq && (labranzas >= (parcelas / 4 - 1)) && (labranzas <= ((parcelas * 3) / 4));
		eq = eq && (abs(p1.second - p2.second) <= 2) && (abs(p1.second - p3.second) <= 2) && (abs(p1.second - p4.second) <= 2);
		eq = eq && (abs(p2.second - p3.second) <= 2) && (abs(p2.second - p4.second) <= 2) && (abs(p3.second - p4.second) <= 2);
		return { eq, labranzas };

	}
}

bool equilibrado(tMatriz const& m) {
	return equilibrado(0, m.size() - 1, 0, m.size() - 1, m).first;
}
void resolver() {
	int tam;
	cin >> tam;
	tMatriz m(tam, std::vector <int> (tam));
	for (int i = 0; i < tam; ++i) {
		for (int j = 0; j < tam; ++j) {
			cin >> m[i][j];
		}
	}
	bool sol = equilibrado(m);
	if (sol) cout << "SI\n";
	else cout << "NO\n";
}

int main() {
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; ++i) resolver();
	return 0;
}