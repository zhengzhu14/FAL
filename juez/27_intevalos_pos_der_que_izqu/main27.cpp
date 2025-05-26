#include <iostream>
#include <vector>

using namespace std;

void intervaloMasIzquierda(std::vector <int> const &v, int k) {
	int cont = 0;
	int der = 0;
	int izq = 0;
	int j = 0;
	while (j < k/2) {
		if (v[j] > 0) izq++;
		++j;
	}
	while (j < k) {
		if (v[j] > 0) der++;
		++j;
	}
	if (izq >= der) ++cont;
	while (j < v.size()) {
		if (v[j] > 0) ++der;
		if (v[j - k] > 0) --izq;
		if (v[j - k / 2] > 0) {
			--der;
			++izq;
		}
		if (izq >= der) ++cont;
		++j;
	}
	cout << cont << endl;
}

bool resolver() {
	int tam;
	cin >> tam;
	if (tam == 0) return false;
	int k;
	std::vector <int> v(tam);
	cin >> k;
	for (int i = 0; i < tam; ++i) cin >> v[i];
	intervaloMasIzquierda(v, k);
	return true;
}
int main() {
	while (resolver());
	return 0;
}