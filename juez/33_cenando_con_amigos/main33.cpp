#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void cena(std::vector <int> const& v) {
	int j = 0;
	while (j < v.size() && v[j] <= 0)  ++j;
	int comienzo = j;//comienzo de la secuencia más larga.
	int inicio = j;
	int sumaMax = 0;
	int suma = 0;
	int cont = 0;
	int contMin = 1;
	while (j < v.size()) {
		suma += v[j];
		if (suma > 0) {
			cont++;
			if (suma > sumaMax || (suma == sumaMax && cont < contMin)) {
				sumaMax = suma;
				contMin = cont;
				inicio = j - cont + 1;
			}
			/*if (suma >= sumaMax) {
				if (suma == sumaMax) {
					if (cont < contMin) {
						contMin = cont;
						inicio = j - cont + 1;
					}
				}
				else {
					contMin = cont;
					inicio = j - cont + 1;
				}
				sumaMax = suma;
			}*/
		}
		else {
			suma = 0;
			cont = 0;
		}
		++j;
	}

	cout << sumaMax << ' ' << inicio << ' ' << contMin << endl;


	
}

bool resolver() {
	int tam;
	cin >> tam;
	if (!cin) return false;
	std::vector <int> v(tam);
	for (int i = 0; i < tam; ++i) {
		cin >> v[i];
	}
	cena(v);
	return true;

}

int main() {
	while (resolver());
	return 0;
}