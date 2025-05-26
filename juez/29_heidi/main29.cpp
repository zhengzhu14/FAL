#include <iostream>
#include <vector>

using namespace std;
struct tSolucion {
	int secMax = 0;
	std::vector <int> solv;
};

tSolucion construirHeidi(std::vector <int> const &v, int l) {
	tSolucion sol;
	int j = v.size() - 1;
	int actual = j;
	int contActual = 0;
	int max = v[j];
	while (j >= 0) {
		if (v[j] == v[actual]) {
			++contActual;
			if (v[actual] >= max) {
				if (contActual == l) sol.solv.push_back(actual);
				if (contActual >= l && contActual > sol.secMax) sol.secMax = contActual;
			}
		}
		else {
			contActual = 1;
			actual = j;
			if (v[j] > max) max = v[j];
		}
		--j;
	}

	return sol;
}

bool resolver() {
	int tam;
	int l;
	cin >> tam;
	if (!cin)return false;
	cin >> l;
	std::vector <int> v(tam);
	for (int i = 0; i < tam; ++i) cin >> v[i];

	tSolucion sol = construirHeidi(v, l);
	cout << sol.secMax << ' ' << sol.solv.size() << ' ';
	for (int i = 0; i < sol.solv.size(); ++i) {
		cout << sol.solv[i] << ' ';
	}
	cout << endl;

	return true;
}

int main() {
	while (resolver());
	return 0;
}




