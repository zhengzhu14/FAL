#include <iostream>
#include <vector>

using namespace std;



int equilibrio(const std::vector <int> &v) {
	int p = -1;
	int unos = 0;
	int ceros = 0;
	for (int i = 0; i < v.size(); ++i) {
		if (v[i] == 0) ++ceros;
		if (v[i] == 1) ++unos;
		if (unos == ceros) p = i;
	}
	return p;
}

void resolver() {
	int tam;
	cin >> tam;
	std::vector <int> v(tam);

	for (int i = 0; i < tam; ++i) {
		cin >> v[i];
	}
	int sol = equilibrio(v);

	cout << sol << endl;
}

int main() {
	int  casos;
	cin >> casos;
	for (int i = 0; i < casos; ++i)resolver();

	return 0;
}