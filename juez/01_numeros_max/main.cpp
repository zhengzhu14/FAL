
// Nombre y apellidos del alumno
// Usuario del juez de clase


//Nombre: Zhengkai Zhu
// Usuario: A70

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// Funcion que lee de la entrada, resuelve el problema y escribe la salida
void resuelveCaso() {
    int n;
    std::cin >> n;
    // Declaración de variables
    // Codigo del alumno
    int max = n;
    int cont = 0;
    
    while (n != 0) {
        if (n >= max){
            if (max == n) {
                ++cont;
            }
            else {
                max = n;
                cont = 1;
            }
        }

        std::cin >> n;
    }
    
    // Escribir el resultado
    // Codigo del alumno
    cout << max << ' ' << cont << endl;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-01.1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
  
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) resuelveCaso();
    

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    
    return 0;
}
