//Nombre: Zhengkai Zhu
//Problema: 08
//Juez: A70

#include <iostream>
#include <vector>

using namespace std;

struct tPastoso {
	int pos;
	bool existe = false;
};

tPastoso existeIndice(const std::vector<int> & v) {
	tPastoso sol;
	sol.pos = v.size() - 1;
	int suma = 0;
	int i = v.size() - 1;
	while (i >= 0 && v[i] != suma) {
		suma += v[i];
		--i;
	}
	
	if (i >= 0) {
		sol.pos = i;
		sol.existe = true;
	}

	return sol;
}

void resolver() {
	std::vector <int> v;
	int tam;
	int dato;
	cin >> tam;
	for (int i = 0; i < tam; ++i) {
		cin >> dato;
		v.push_back(dato);
	}

	tPastoso sol = existeIndice(v);

	if (sol.existe) {
		cout << "Si " << sol.pos << endl;
	}
	else cout << "No" << endl;


}

int main() {
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; ++i) resolver();
	return 0;
}


/*
El peor caso es el caso en el cual no existe indice pastoso por lo cual se recorre todos los elementos del vector de tamanyo 
'n'. 
Respecto a la funcion de coste para el peor caso:
- Fuera del bucle realizo 3 asignaciones.
- Por cada iteracion del bucle se realiza 2 comparaciones y 2 operaciones (una suma con asignacion y otra resta). Se realizan n
iteraciones pues inicie el contador en v.size() - 1.
- Tras las n iteraciones se realiza una comparacion mas en i>=0 que nos hara salir del bucle.
Entonces f(n) = 4n + 4, siendo 'n' el tamanyo del vector. (En esta funcion no he tenido en cuenta el if despues del bucle.

Comentario: No hemos dado todavia el concepto de invariante de un bucle.
*/