#include <iostream>
#include <vector>

using namespace std;

int buscarPreso(int ini, int fin, char primero, std::vector<char> const& v) {
	if (ini > fin) return ini;
	else {
		int mitad = (fin + ini) / 2;
		if (mitad < (v[mitad] - primero)) return buscarPreso(ini, mitad - 1, primero, v);
		else return buscarPreso(mitad + 1, fin, primero, v);
	}
}

void resolver() {
	char primero, ultimo;
	cin >> primero >> ultimo;
	std::vector <char> v(ultimo - primero);
	for (int i = 0; i < v.size(); ++i) {
		cin >> v[i];
	}

	char sol = primero + char(buscarPreso(0, v.size() - 1, primero, v));
	cout << sol << endl;



}

int main() {



	int casos;
	cin >> casos;
	for (int i = 0; i < casos; ++i) resolver();
	return 0;
}