#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int accidentes(std::vector <int>& v) {
	sort(v.begin(), v.end());
	int max = v[0];
	int longAux = 1;
	int longMax = 1;
	int sol = v[0];
	for (int i = 1; i < v.size(); ++i) {
		if (v[i] == v[i - 1]) {
			++longAux;
			if (longAux > longMax) {
				longMax = longAux;
				sol = v[i];
			}
		}
		else {
			longAux = 1;
		}
	}
	return sol;
}

bool resolver() {
	long long int tam;
	cin >> tam;
	if (tam == -1) return false;
	std::vector <int> v(tam);
	for (int i = 0; i < tam; ++i) {
		cin >> v[i];
	}
	cout << accidentes(v) << endl;
	return true;
}
int main() {
	while (resolver());
	return 0;
}