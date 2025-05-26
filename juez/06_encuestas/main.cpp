//Nombre: Zhengkai Zhu
//Juez. A70
//Problema: no6 encuestas.
#include <iostream>
#include <vector>

using namespace std;
void resolver() {
	int tam;
	cin >> tam;
	std::vector<int> v;
	int dato;
	for (int i = 0; i < tam; ++i) {
		cin >> dato;
		v.push_back(dato);
	}
	long long int suma = 0;
	int cont = 0;
	int igual = 1; //contador del valor minimo en un momento dado, hasta encontrar otro menor
	int min = v[0];
	for (int i = 1; i < tam; ++i) {
		if (v[i] < min) { //el valor que en ’i’ pasa a ser el minimo asi que actualizamos todo.
			suma += igual * min;
			min = v[i];
			cont += igual;
			igual = 1;
		}
		else if (v[i] == min) {
			++igual; //sumo en el contador ’igual’ porque no se si mientras recorro el vector me voy a encontrar un numero menor
		}
		else {
			suma += v[i];
			++cont;
		}
	}

		cout << suma << ' ' << cont << endl;

}
int main() {
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; ++i) resolver();

	return 0;
}
//Caso peor: los valores ordenados de mayor a menor
//Asignaciones fuera del bucle = 4.
//Iteraciones del bucle = n - 1. 

//La 'n' representa el tamanyo del vector.

//En el peor caso siempre se entraria en el primer ’if’ y se realiza las 4 operacions mas la comprobacion de la condicion del bucle
//Funcion de coste: f(n)= 5(n - 1) + 4
// f O(n).