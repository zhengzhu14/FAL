#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int, int> particion(std::vector<pair <char, int>> &v) {
	int p = 0;
	int q = v.size();
	int k = 0;
	while (k < q) {
		if (v[k].first == 'v') ++k;
		else if (v[k].first == 'a') {
			std::swap(v[p], v[k]);
			++p; ++k;
		}
		else {
			std::swap(v[q - 1], v[k]);
			--q;
		}
	}
	pair <int, int> sol;
	sol.first = p;
	sol.second = q;
	return sol;
}
void mostrar(std::vector<pair <char, int>> const& v, pair <int, int> sol) {
	std::vector<int> azules;
	std::vector <int> verdes;
	std::vector<int> rojos;
	for (int i = 0; i < sol.first; ++i) {
		azules.push_back(v[i].second);
	}
	for (int i = sol.first; i < sol.second; ++i) {
		verdes.push_back(v[i].second);
	}
	for (int i = sol.second; i < v.size(); ++i) {
		rojos.push_back(v[i].second);
	}
	sort(azules.begin(), azules.end());
	sort(verdes.begin(), verdes.end());
	sort(rojos.begin(), rojos.end());
	cout << "Azules: ";
	for (int i = 0; i < azules.size(); ++i) cout << azules[i] << ' ';
	cout << endl << "Verdes: ";
	for (int i = 0; i < verdes.size(); ++i) cout << verdes[i] << ' ';
	cout << endl << "Rojas: ";
	for (int i = 0; i < rojos.size(); ++i) cout << rojos[i] << ' ';
	cout << endl;

}

bool resolver() {
	int tam;
	cin >> tam;
	if (!cin) return false;
	std::vector<pair <char, int>> v(tam);
	for (int i = 0; i < tam; ++i) {
		cin >> v[i].first >> v[i].second;
	}
	pair <int, int> sol = particion(v);
	mostrar(v, sol);
	return true;
}

int main() {
	while (resolver());
	return 0;
}