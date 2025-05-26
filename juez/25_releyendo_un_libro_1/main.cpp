#include <iostream>
#include <vector>

using namespace std;
bool resolver() {
	int tam;
	int intervalo;
	cin >> tam >> intervalo;
	if (tam == 0 && intervalo == 0) return false;
	std::vector<int> v(tam);
	for (int i = 0; i < tam; ++i) cin >> v[i];
	int j = 0;
	int puntActual = 0;
	while (j < intervalo) {
		puntActual += v[j];
		++j;
	}
	int puntMax = puntActual;
	int i = 0;
	int sol = 0;
	for (int j = intervalo; j < v.size(); ++j) {
		puntActual -= v[i];
		puntActual += v[j];
		if (puntActual >= puntMax) {
			puntMax = puntActual;
			sol = i + 1;
		}
		++i;
	}
	cout << sol << endl;
	return true;
}
int main() {
	while (resolver());
	return 0;
}