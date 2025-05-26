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
	int sumaActual = 0;
	int max = v[0];
	int maxIndex = 0;
	while (j < intervalo) {
		sumaActual += v[j];
		if (v[j] >= max) {
			max = v[j];
			maxIndex = j;
		}
		++j;
	}
	int i = 0;
	int sol = 0;
	int sumaMax = sumaActual;
	while (j < v.size()) {
		sumaActual -= v[i];
		sumaActual += v[j];
		if (v[j] > max) {
			max = v[j];
			sol = i + 1;
			maxIndex = j;
			sumaMax = sumaActual;
		}
		else if (v[j] < max) {
			if ((j - maxIndex) < intervalo) {
				if (sumaActual >= sumaMax) {
					sumaMax = sumaActual;
					sol = i + 1;
				}
			}
		}
		else { //caso de encontrar con uno que sea igual.
			maxIndex = j;
			if (sumaActual >= sumaMax) {
				sumaMax = sumaActual;
				sol = i + 1;
			}
		}
		++i;
		++j;
	}

	cout << sol << endl;


	
	return true;
}
int main() {
	while (resolver());
	return 0;
}