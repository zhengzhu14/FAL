//Nombre: Zhengkai Zhu
//Juez: A70
//Problema: Apartamentos con vistas


#include <iostream>
#include <vector>

using namespace std;

struct tEdificio {
	string nombre;
	int altura;
	int piso;

};



std::vector <string> apartamentos(std::vector <tEdificio> const & v) { //He cambiado el nombre de la funcion para que no sea tieneVistas.
	std::vector <string> vistas;
	int max = v[v.size() - 1].altura;
	if (v[v.size() - 1].piso >= 0) {
		vistas.push_back(v[v.size() - 1].nombre);
	}
	for (int i = v.size() - 2; i >= 0; --i) {
		if (v[i].piso >= 0) {
			if (v[i].piso > max) {
				vistas.push_back(v[i].nombre);
			}
		}
		if (v[i].altura > max) max = v[i].altura;
	}

	return vistas;
}

bool  resolver() {
	int tam;
	cin >> tam;
	if (tam == 0) return false;

	std::vector <tEdificio> v(tam);
	for (int i = 0; i < tam; ++i) {
		cin >> v[i].nombre >> v[i].altura >> v[i].piso;
	}

	std::vector <string> vistas = apartamentos(v);
	if (vistas.size() == 0) cout << "Ninguno";
	else {
		cout << vistas.size() << endl;
		for (int i = 0; i < vistas.size(); ++i) {
			cout << vistas[i] << ' ';
		}
	}
	cout << endl;


	return true;
}

int main() {
	while (resolver());

	return 0;
}



/* Tomamos 'n' como el numero de edificios que hay.
En el caso peor:
- El ultimo edificio tiene un piso que se vende, entonces realiza dos operaciones.
- Luego todos los pisos de todos los edificios se venden y cada uno tiene una altura superior al siguiente.
Por ello por cada iteracion del bucle se realizan 6 operaciones (4 comparaciones y 2 asignaciones).
- A todo le sumo la comparacion final para salir del bucle.
Funcion de coste: f(n) = 6(n-1) +3.

*/