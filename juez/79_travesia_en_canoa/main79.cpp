#include <iostream>
#include <vector>

using namespace std;

using tVector = std::vector<int>;
struct tDatos {
	int amigos, canoas, peso;
	tVector pesos;
	std::vector<tVector> enemistades;
};


bool marcar(int& canoasActual, int k, tVector &marcaCanoa, int const&pesoCanoa, tDatos const& datos) {
	bool aux;
	int i = 0;
	bool poderSubir = true;
	while (i < 3 && marcaCanoa[i] != -1) {
		if (datos.enemistades[marcaCanoa[i]][k] == 1) poderSubir = false;
		++i;
	}

	if (i < 3 && poderSubir) {
		if (pesoCanoa + datos.pesos[k] <= datos.peso) {
			if (i == 0) ++canoasActual;
			aux = true;
			marcaCanoa[i] = k;
		}
		else aux = false;
	}
	else {
		aux = false;
	}
	return aux;
}

void desmarcar(int& canoasActual, int k, tVector& marcaCanoa) {
	int i = 1; 
	while (i < 3 && marcaCanoa[i] != -1) {
		++i;
	}
	marcaCanoa[i - 1] = -1;
	if (i == 1) --canoasActual;
}

void travesia(int k, tDatos const& datos, tVector& sol, tVector& solMejor,
	int& canoasActual, int &canoasMejor, tVector &lleno, std::vector<tVector> &marcas) {
	for (int i = 0; i < datos.canoas; ++i) {
		sol[k] = i;
		if (marcar(canoasActual, k, marcas[i],lleno[i], datos)) {
			lleno[i] += datos.pesos[k];
			if (k == datos.amigos - 1) {
				if (canoasActual < canoasMejor) {
					canoasMejor = canoasActual;
					solMejor = sol;
				}
			}
			else {
				travesia(k + 1, datos, sol, solMejor, canoasActual, canoasMejor, lleno, marcas);
			}

			lleno[i] -= datos.pesos[k];
			desmarcar(canoasActual, k, marcas[i]);;
		}
	}


}

void resolver() {
	tDatos datos;
	cin >> datos.amigos >> datos.canoas >> datos.peso;
	int dat;
	for (int i = 0; i < datos.amigos; ++i) {
		cin >> dat;
		datos.pesos.push_back(dat);
	}
	tVector aux(datos.amigos);
	for (int i = 0; i < datos.amigos; ++i) {
		for (int j = 0; j < datos.amigos; ++j) {
			cin >> aux[j];
		}
		datos.enemistades.push_back(aux);
	}
	tVector sol(datos.amigos);
	tVector solMejor;
	int canoasActual = 0;
	int canoasMejor = datos.canoas + 1; //lo inicializo a una cantidad maxima

	tVector lleno(datos.canoas, 0);
	std::vector<tVector> marcas(datos.canoas, tVector(3, -1));
	travesia(0, datos, sol, solMejor, canoasActual, canoasMejor, lleno, marcas);
	if (canoasMejor > datos.canoas) {
		cout << "IMPOSIBLE" << endl;
	}
	else cout << canoasMejor << endl;

}

int main() {
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; ++i) resolver();

	return 0;
}