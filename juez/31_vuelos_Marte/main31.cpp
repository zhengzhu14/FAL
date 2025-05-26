#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void intercambiar(pair <string,int> &a, pair<string,int> &b) {
	pair <string,int> aux = a;
	a = b;
	b = aux;
}
void particion(std::vector <pair<string, int>>& v, int altura) {
	int i = 0;
	int j = v.size() - 1;
	while (i <= j) {
		if (v[i].second <= altura) ++i;
		else if (v[j].second > altura) --j;
		else {
			intercambiar(v[i], v[j]);
			++i;
			--j;
		}
	}
}

void mostrar(std::vector <pair<string, int>>const& v, int altura) {
	std::vector <string> bajos;
	std::vector<string> altos;
	int i = 0;
	while (i < v.size() && v[i].second <= altura) {
		bajos.push_back(v[i].first);
		++i;
	}
	for (int j = i; j < v.size(); ++j) {
		altos.push_back(v[j].first);
	}
	sort(bajos.begin(), bajos.end());
	sort(altos.begin(), altos.end());
	cout << "Bajos: ";
	for (int k = 0; k < bajos.size(); ++k) {
		cout << bajos[k] << ' ';
	}
	cout << endl << "Altos: ";
	for (int k = 0; k < altos.size(); ++k) {
		cout << altos[k] << ' ';
	}
	cout << endl;
}

bool resolver() {
	int tam; int altura;
	cin >> tam;
	if (!cin) return false;
	cin >> altura;
	std::vector <pair<string, int>> v(tam);
	for (int i = 0; i < tam; ++i) {
		cin >> v[i].first >> v[i].second;
	}
	particion(v, altura);
	mostrar(v, altura);
	return true;
}

int main() {
	while (resolver());
	return 0;
}