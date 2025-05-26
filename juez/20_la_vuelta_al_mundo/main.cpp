#include <iostream>
#include <vector>

using namespace std;

bool resuelveCaso() {
	int tam;
	cin >> tam;
	if (tam == -1) return false;
	std::vector <long long int> v(tam);
	std::vector <int> vAux(tam);
	long long int suma = 0;
	for (int i = 0; i < tam; ++i) {
		cin >> vAux[i];
	}
	for (int i = tam - 1; i >= 0; --i) {
		suma += vAux[i];
		v[i] = suma;
	}
	int aux;
	int dias;
	cin >> dias;
	for (int i = 0; i < dias; ++i) {
		cin >> aux;
		if ((aux - 1) < v.size()) {
			cout << v[aux - 1];
		}
		else cout << 0;
		cout << endl;
	}
	cout << "---" << endl;

	return true;

}
int main() {
	while (resuelveCaso());
	return 0;
}