#include <iostream>
#include <vector>

using namespace std;


std::vector<int> *fun (vector<int> const &v1, vector <int> const & v2) {
	std::vector<int>sol;
	int i = 0; 
	int j = 0;
	while (i < v1.size() && j < v2.size()) {
		if (v1[i] < v2[j]) {
			sol.push_back(v1[i]);
			++i;
		}
		else if (v1[i] > v2[j]) {
			sol.push_back(v2[j]);
			++j;
		}
		else {
			++i;
			++j;
		}
	}
	while (i < v1.size()) {
		sol.push_back(v1[i]);
		++i;
	}
	while (j < v2.size()) {
		sol.push_back(v2[j]);
		++j;
	}
	return &sol;

}
void resolver() {
	std::vector <int> v1;
	std::vector <int> v2;
	int aux;
	cin >> aux;
	while (aux != 0) {
		v1.push_back(aux);
		cin >> aux;
	}
	cin >> aux;
	while (aux != 0) {
		v2.push_back(aux);
		cin >> aux;
	}
	std::vector <int>* sol = new std::vector<int>;
	sol = fun(v1, v2);
	for (int i = 0; i < sol->size(); ++i) {
		cout << (*sol)[i] << ' ';
	}
	cout << endl;
}
int main() {
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; ++i) resolver();
	return 0;
}