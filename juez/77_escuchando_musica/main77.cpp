#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using tSolucion = std::vector <pair<bool, bool>>; 
//vector de pares de booleanos -- first: tomado o no tomado
//							   -- second: ida (true) o vuelta (false) si (first == true)


struct tDatos {
	int ida;
	int vuelta;
	std::vector <pair<int, int>> durSatis; //first: duracion; second: satisfaccion
};

class comparador {
public:
	bool operator ()(std::pair <int, int > p1, std::pair <int, int > p2) { //ordena satisfaccion por duracion
		return (float)p1.second / p1.first > (float)p2.second / p2.first;
	}
};

int estimar(tDatos const & datos, int durIdaActual, int durVueltaActual, int k) {
	int durTotal = datos.ida + datos.vuelta;
	int durActualTotal = durIdaActual + durVueltaActual;
	int i = k + 1; 
	int sumaSatis = 0;
	while (i < datos.durSatis.size() && ((durActualTotal + datos.durSatis[i].first) <= durTotal)) {
		durActualTotal += datos.durSatis[i].first;
		sumaSatis += datos.durSatis[i].second;
		++i;
	}
	if (i < datos.durSatis.size() && durActualTotal < durTotal) {
		sumaSatis += (datos.durSatis[i].second * (durTotal - durActualTotal) / datos.durSatis[i].first + 1);
	}
	return sumaSatis;
}


void escuchar(int k, int& satisActual, int& satisMejor, int & durIdaActual, int& durVueltaActual,
	tDatos const& datos, tSolucion& sol, tSolucion& solMejor) {

	sol[k].first = true; //tomo la cancion
	sol[k].second = true; //lo tomo para la ida.
	durIdaActual += datos.durSatis[k].first;
	satisActual += datos.durSatis[k].second;
	
	if (durIdaActual <= datos.ida) { //comprobamos si es valida
		if (k == (datos.durSatis.size() - 1)) {
			if (durIdaActual == datos.ida && durVueltaActual == datos.vuelta) {
				if (satisActual > satisMejor) {
					solMejor = sol;
					satisMejor = satisActual;
				}
			}
		}
		else {
			escuchar(k + 1, satisActual, satisMejor, durIdaActual, durVueltaActual, datos, sol, solMejor);
		}
	}

	durIdaActual -= datos.durSatis[k].first;

	sol[k].second = false; //lo tomo para la vuelta
	durVueltaActual += datos.durSatis[k].first;

	if (durVueltaActual <= datos.vuelta) {
		if (k == (datos.durSatis.size() - 1)) {
			if (durIdaActual == datos.ida && durVueltaActual == datos.vuelta) {
				if (satisActual > satisMejor) {
					solMejor = sol; 
					satisMejor = satisActual;
				}
			}
		}
		else {
			escuchar(k + 1, satisActual, satisMejor, durIdaActual, durVueltaActual, datos, sol, solMejor);
		}
	}

	satisActual -= datos.durSatis[k].second;
	durVueltaActual -= datos.durSatis[k].first;

	sol[k].first = false;//no lo tomo

	if (k == (datos.durSatis.size() - 1)) {
		if (durIdaActual == datos.ida && durVueltaActual == datos.vuelta) {
			if (satisActual > satisMejor) {
				solMejor = sol;
				satisMejor = satisActual;
			}
		}
	}
	else {
		if ((satisActual + (estimar(datos, durIdaActual, durVueltaActual, k))) > satisMejor) {
			escuchar(k + 1, satisActual, satisMejor, durIdaActual, durVueltaActual, datos, sol, solMejor);
		}
	}



}


bool resolver() {
	int n;
	tDatos datos;
	cin >> n >> datos.ida >> datos.vuelta;
	if (n == 0 && datos.ida == 0 && datos.vuelta == 0) return false;
	std::pair <int, int> aux;
	for (int i = 0; i < n; ++i) {
		cin >> aux.first >> aux.second;
		datos.durSatis.push_back(aux);
	}
	std::sort(datos.durSatis.begin(), datos.durSatis.end(), comparador());
	
	tSolucion sol(n, {false,false});
	tSolucion solMejor(n, {false,false});
	int satisMejor = -1;
	int satisActual = 0;
// Como no es facil encontrar una solucion inicial mejor, lo inicializo al valor mas pequeño posible que es -1

	int durIdaActual = 0;
	int durVueltaActual = 0;

	escuchar(0, satisActual, satisMejor, durIdaActual, durVueltaActual, datos, sol, solMejor);

	if (satisMejor == -1){
		cout << "Imposible" << endl;
	}
	else {
		cout << satisMejor << endl;
	}


	return true;
}

int main() {
	while (resolver());
	return 0;
}




/*
Arbol de exploracion ternario: 
			
			ida                          vuelta                         NoTomado
	ida     vuelta    NoTomado      ida    vuelta    NoTomado        ida vuelta   NoTomado


Cada rama decidimos si la cancion para la ida, vuelta o no lo tomamos (3 ramas)
Los niveles del arbol representan las canciones.

Vector solucion:

Tamanyo: n numero de canciones
Cada elmento es un par de booleanos donde el primero indicamos si lo tomamos para el viaje y en el segundo,
en caso de tomarlo, si para la ida o vuelta





*/