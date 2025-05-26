#include <iostream>
#include <vector>

using namespace std;
using tPareja = pair <int, int>; //boleano que indica si hay elemento mayoritario luego un entero para indicar
//cual es el elemento mayoritario y luego el numero total. 

tPareja mayoritario(int ini, int fin, std::vector <int> const &v) {
	if (ini > fin) return {-1 ,0};
	else if (ini == fin) return  {v[ini], 1};
	else {
		int mitad = (ini + fin) / 2;
		tPareja m1 = mayoritario(ini, mitad, v);
		tPareja m2 = mayoritario(mitad + 1, fin, v);
		if (!(m1.first > 0) && !(m2.first > 0)) return  { -1,0 };
		else if (m1.first && !m2.first) { //en la primera mitad hay elemento mayoritario
			int j = mitad + 1;
			while (j <= fin) {
				if (v[j] == m1.first) ++m1.second;
				++j;
			}
			if (m1.second <= ((fin - ini + 1) / 2)) m1.first = -1;
			return m1;
		}
		else if (!(m1.first > 0)&& (m2.first > 0)) { //en la segunda mitad hay elemento mayoritario
			int i = mitad;
			while (i >= ini) {
				if (v[i] == m2.first) ++m2.second;
				--i;
			}
			if (m2.second <= ((fin - ini + 1) / 2)) m2.first = -1;
			return m2;
		}
		else {
			tPareja sol;
			if (m1.first == m2.first) {
				sol.first = m1.first;
				sol.second = m1.second + m2.second;
			}
			else {
				sol.first = m1.first;
				sol.second = m1.second;
				int i = mitad + 1;
				while (i <= fin) {
					if (v[i] == sol.first) ++sol.second;
					++i;
				}
				if (sol.second <= ((fin - ini + 1) / 2)) {
					sol.first = m2.first;
					sol.second = m2.second;
					int j = mitad;
					while (j >= ini) {
						if (v[j] == sol.first) ++sol.second;
						--j;
					}
					if (sol.second <= ((fin - ini + 1) / 2)) sol.first = -1;
				}
			}

			return sol;
		}
	}

}

void resolver() {
	std::vector<int> v;
	int aux; 
	cin >> aux;
	while (aux != 0) {
		v.push_back(aux);
		cin >> aux;
	}
	tPareja sol = mayoritario(0, v.size() - 1, v);
	if (sol.first > 0) cout << sol.first << endl;
	else cout << "NO\n";
}

int main() {
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; ++i) resolver();
	return 0;
}