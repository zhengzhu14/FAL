#include <iostream>
#include <vector>

using namespace std;

void resolver() {
	int tam1, tam2;
	cin >> tam1 >> tam2;
	std::vector<int> v1(tam1);
	std::vector <int> v2(tam2);
	for (int i = 0; i < tam1; ++i) cin >> v1[i];
	for (int i = 0; i < tam2; ++i) cin >> v2[i];
	std::vector <int> ordenado;
	int i = 0;
	int j = 0;
	int aux;
	while (i < v1.size() && j < v2.size()) {
		if (v1[i] < v2[j]) {
			aux = v1[i];
			++i;
		}
		else{
			aux = v2[j];
			++j;
		}
		ordenado.push_back(aux);
	}
	while (i < v1.size()) {
		ordenado.push_back(v1[i]);
		++i;
	}
	while (j < v2.size()) {
		ordenado.push_back(v2[j]);
		++j;
	}

	for (int k = 0; k < ordenado.size(); ++k) {
		cout << ordenado[k] << ' ';
	}
	cout << endl;
}

int main() {
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; ++i) resolver();
	return 0;
}