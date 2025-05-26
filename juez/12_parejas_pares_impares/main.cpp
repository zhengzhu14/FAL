#include <iostream>
#include <vector>


using namespace std;
int parejas(std::vector <int> const & v) {
	int cont = 0; 
	int aux = 0;
	int i = v.size() -  1;
	while (i >= 0) {
		if (v[i] % 2 == 0) {
			++aux;
		}
		else {
			cont += aux;
		}
		--i;
	}
	return cont;

}
void resolver() {
	int tam;
	cin >> tam;
	std::vector <int> v(tam);
	for (int i = 0; i < tam; ++i) {
		cin >> v[i];
	}
	int cantidad = parejas(v);

	cout << cantidad << endl;
}

int main() {
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; ++i) resolver();

	return 0;
}