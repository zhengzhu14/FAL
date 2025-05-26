#include <iostream>
#include <vector>
using namespace std;

void mostrar(std::vector<char> const& v) {
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i];
	}
	cout << endl;
}
void var(int m, int n, int k, std::vector <char>& sol, std::vector<bool>& marcas) {
	for (char c = 'a'; c < 'a' + m; ++c) {
		sol[k] = c;
		if (!marcas[c - 'a']) {
			marcas[c - 'a'] = true;
			if (k == n - 1) mostrar(sol);
			else var(m, n, k + 1,sol, marcas);
			marcas[c - 'a'] = false;

		}
	}
}
bool resolver() {
	int m, n;
	cin >> m >> n;
	if (!cin) return false;
	std::vector <char> sol(n);
	std::vector <bool> marcas(m, false);
	var(m, n, 0, sol, marcas);
	return true;
}
int main() {
	while (resolver());
	return 0;
}