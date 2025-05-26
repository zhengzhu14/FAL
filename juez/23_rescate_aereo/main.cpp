#include <iostream>
#include <vector>

using namespace std;

struct tInt {
	int i; 
	int j;
};
tInt intervaloMasLargo(std::vector <int> const& v, int altura) {
	tInt sol;
	int max = 0;
	int aux = 0;
	int i = 0;
	for (int j = 0; j < v.size(); ++j) {
		if (v[j] > altura) {
			++aux;
			if (aux > max) {
				max = aux;
				sol.i = i;
				sol.j = j;
			}
		}
		else {
			aux = 0;
			i = j;
			++i;
		}
	}
	return sol;
}
void resolver() {
	int tam; 
	cin >> tam;
	std::vector <int> v(tam);
	int t;
	cin >> t;
	for (int i = 0; i < tam; ++i) {
		cin >> v[i];
	}
	tInt sol = intervaloMasLargo(v, t);
	cout << sol.i << ' ' << sol.j << endl;
}

int main() {
	int casos; 
	cin >> casos;
	for (int i = 0; i < casos; ++i) resolver();
	return 0;
}