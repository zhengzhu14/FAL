#include <iostream>
#include <vector>
using namespace std;

void segmentoMasCorto(std::vector<bool> const&v, int k) {
	int sol = v.size() + 1;
	int i = 0;
	while (i < v.size() && !v[i]) ++i;
	if (i < v.size()) {
		int cont = 1;
		int aux = 1; //contador para contar hasta k.
		++i;
		while (i < v.size() && aux < k) {
			if (v[i]) {
				++aux;
			}
			++cont;
			++i;
		}
		if (aux == k) {
			sol = cont;
			while (i < v.size()) {
				if (!v[i]) {
					++i;
					++cont;
				}
				else {
					if(v[i - cont + 1]) {
						if (cont < sol) sol = cont;
						++i;
						++cont;
					}
					--cont;
				}
			}
		}
		
	}

	cout << sol << endl;
}

bool resolver() {
	int tam;
	int k;
	cin >> tam;
	if (tam == -1) return false;
	std::vector <bool> v(tam);
	bool aux;
	for (int i = 0; i < tam; ++i) {
		cin >> aux;
		v[i] = aux;
	}
	cin >> k;
	segmentoMasCorto(v, k);
	return true;

}
int main() {
	while (resolver());
	return 0;
}