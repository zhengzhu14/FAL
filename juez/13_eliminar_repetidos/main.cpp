#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void eliminarRepetidos(std::vector <int>& v) {
	sort(v.begin(), v.end());
	int i = 1;
	int j = 1;
	int aux = v[0];
	while (j < v.size()) {
		if (v[j] != aux) {
			v[i] = v[j];
			aux = v[j];
			++i;
		}
		++j;
	}
	v.resize(i);
}

bool resolver() {
	int tam;
	cin >> tam;
	if (!cin) return false;

	std::vector<int> v(tam);
	for (int i = 0; i < tam; ++i) {
		cin >> v[i];
	}

	eliminarRepetidos(v);

	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << ' ';
	}
	cout << endl;

	return true;

}

int main() {
	while (resolver());
	return 0;
}

