#include <iostream>
#include <vector>

using namespace std;
using tMatriz = std::vector<std::vector<int>>;


int formas(int i, int tam, int valor, std::vector <int> const& v, tMatriz & matriz) {
	if (i >= tam) return 0;
	else if (v[i] == valor) {
		if (matriz[i + 1][valor] == -1) {
			matriz[i + 1][valor] = formas(i + 1, tam, valor, v, matriz);
		}
		return 1 + matriz[i + 1][valor];
	}
	else if (v[i] < valor) {
		if (matriz[i + 1][valor] == - 1) matriz[i + 1][valor] = formas(i + 1, tam, valor, v, matriz);
		if (matriz[i + 1][valor - v[i]] == -1) matriz[i + 1][valor - v[i]] = formas(i + 1, tam, valor - v[i], v, matriz);
		return matriz[i + 1][valor] + matriz[i + 1][valor - v[i]];
	}
	else {
		if (matriz[i + 1][valor] == -1) matriz[i + 1][valor] = formas(i + 1, tam, valor, v, matriz);
		return matriz[i + 1][valor];
	}
	
}

bool resolver() {
	int tam, suma;
	cin >> tam;
	if (!cin) return false;
	cin >> suma;
	std::vector <int> vector(tam);
	for (int i = 0; i < tam; ++i) cin >> vector[i];
	tMatriz matriz(tam + 1, std::vector<int>(suma + 1, -1));
	int sol = formas(0, tam, suma, vector, matriz);

	cout << sol << endl;
	return true;
}

int main() {
	while (resolver());
	return 0;
}