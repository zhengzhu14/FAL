// Problema: Ultima vez que..

// IMPORTANTE.
// Nombre del alumno: Zhengkai Zhu
// Usuario del juez: A70


#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// función que resuelve el problema
// comentario sobre el coste, O(f(N))
int resolver(std::vector<std::string> const& v, string buscado) {
    int an = 1;
    int i = v.size() - 1 ;
    while (i >= 0 && v[i] != buscado) {
        ++an;
        --i;
    }
    
    if (!(i >= 0)) an = -1;

    return an;

    // Codigo del alumno
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int num;
    std::cin >> num;
    if (num == 0) return false;

    vector<string> a;
    string str;
    string buscado;
    cin >> buscado;

    for (int i = 0; i < num; ++i) {
        cin >> str;
        a.push_back(str);
    }
    // llamar a la funcion que resuelve el problema
    int sol = resolver(a, buscado);


    // Escribir el resultado
    if (sol != -1) cout << sol << endl;
    else cout << "NUNCA\n";


    
    return true;
}

int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("sample-02.1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

    while (resuelveCaso());
    


#ifndef DOMJUDGE // para dejar todo como estaba al principio
        std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
