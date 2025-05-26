#include <iostream>
#include <vector>

using namespace std;

void modificar(std::vector<long long int>& v, int erase) {
	int p = 0;
	for (int i = 0; i < v.size(); ++i) {
		if (p == i) {
			if (v[p] != erase) {
				++p;
			}
		}
		else {
			if (v[i] != erase) {
				v[p] = v[i];
				++p;
			}
		}
	}
	v.resize(p);
}

void resolver() {
	int tam;
	int erase;
	cin >> tam >> erase;
	std::vector <long long int> v(tam);
	for (int i = 0; i < tam; ++i) cin >> v[i];

	modificar(v, erase);
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); ++i) cout << v[i] << ' ';
	cout << endl;
}

int main() {
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; ++i) resolver();
	return 0;
}