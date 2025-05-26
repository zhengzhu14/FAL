#include <iostream>
#include <vector>

using namespace std;

int longitud(std::vector<int> v) {
	int contador = 1;
	int contMax = 0;
	int rest = 1;
	if (v.size() < 3) contMax = v.size();
	else {
		for (int i = 1; i < v.size(); ++i) {
			if (v[i] > v[i - 1]) {
				++rest;
			}
			else rest = 1;
			if (rest >= 3) {
				if (contador > contMax) contMax = contador;
				contador = 2;
				rest = 2;
			}
			else {
				++contador;
				if (contador > contMax) contMax = contador;
			}

		}
	}
	return contMax;
}
void resolver() {
	int tam;
	cin >> tam;
	std::vector <int> v(tam);
	for (int i = 0; i < tam; ++i) {
		cin >> v[i];
	}

	int sol = longitud(v);
	cout << sol << endl;

}

int main() {
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; ++i) resolver();
	return 0;
}