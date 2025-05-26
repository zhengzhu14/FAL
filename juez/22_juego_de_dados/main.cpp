#include <iostream>
#include <vector>

using namespace std;

void fun(std::vector<int> const& v, std::vector<int>&sol, int numMax) {
	std::vector<int> contador(numMax);
	int maxRep = 0;
	for (int i = 0; i < v.size(); ++i) {
		contador[v[i] - 1]++;
		if (maxRep < contador[v[i] - 1]) {
			maxRep = contador[v[i] - 1];
		}
	}
	for (int i = contador.size() - 1;  i>= 0; --i) {
		if (contador[i] == maxRep) {
			sol.push_back(i + 1);
		}
	}
}

bool resolver() {
	int tam;
	cin >> tam;
	if (tam == -1) return false;
	int numMax;
	cin >> numMax;
	std::vector <int> v(tam);
	for (int i = 0; i < tam; ++i) {
		cin >> v[i];
	}
	std::vector<int> sol;
	fun(v, sol,numMax);
	for (int i = 0; i < sol.size(); ++i) {
		cout << sol[i] << ' ';
	}
	cout << endl;
	return true;
}

int main() {
	while (resolver());
	return 0;
}