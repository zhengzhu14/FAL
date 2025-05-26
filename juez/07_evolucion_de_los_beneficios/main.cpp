//Nombre: Zhengkai Zhu
//Juez: A70
//Problema: 07 evolucion de los beneficios

#include <iostream>
#include <vector>

using namespace std;

std::vector<int> superarVentas(const std::vector <int> & datos, int ini) {
	std::vector <int> years;
	int max = datos[0];
	++ini;
	for (int i = 1; i < datos.size(); ++i, ++ini) { //en cada iteracion aumentamos tambien el año
		if (datos[i] > max) {
			max = datos[i];
			years.push_back(ini);
		}
	}


	return years;
}

void resolver() {
	std::vector <int> datos;
	int ini, fin;
	cin >> ini >> fin;
	int entrada;
	for (int i = 0; i <= (fin - ini); ++i) {
		cin >> entrada;
		datos.push_back(entrada);
	}

	std::vector <int> years = superarVentas(datos, ini);

	for (int i = 0; i < years.size(); ++i) {
		cout << years[i] << ' ';
	}
	cout << endl;

}

int main() {
	int casos;

	cin >> casos;
	for (int i = 0; i < casos; ++i)  resolver();

	return 0;
}