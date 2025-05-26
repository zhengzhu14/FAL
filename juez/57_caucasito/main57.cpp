#include <iostream>
#include <vector>

using namespace std;

pair <bool, int> caucasico(int ini, int fin, std::vector <int> const& v) {
	if (ini == fin) {
		if (v[ini] % 2 == 0) return { true, 1 };
		else return { true, 0 };
	}
	else {
		int mitad = (fin + ini) / 2;
		pair <bool, int> m1 = caucasico(ini, mitad, v);
		pair<bool, int> m2 = caucasico(mitad + 1, fin, v);
		pair<bool, int> sol;
		sol.second = m1.second + m2.second;
		sol.first = m1.first && m2.first;
		int dif = abs(m2.second - m1.second);
		sol.first = sol.first && (dif <= 2);
		return sol;
	}
}

bool caucasico(std::vector <int> const& v) {
	return caucasico(0, v.size() - 1, v).first;
}
bool resolver() {
	int tam;
	cin >> tam;
	if (tam == 0) return false;
	std::vector <int> v(tam);
	for (int i = 0; i < tam; ++i) cin >> v[i];

	bool sol = caucasico(v);
	if (sol) cout << "SI\n";
	else cout << "NO\n";

	return true;
}

int main() {
	while (resolver());
	return 0;
}