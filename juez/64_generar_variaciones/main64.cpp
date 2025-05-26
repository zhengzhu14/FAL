#include <iostream>
#include  <vector>

using namespace std;


void mostrar(std::vector<char> const & v) {
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i];
	}
	cout << endl;
}
void var(int m, int n, int k, std::vector<char>& v) {
	for (char c = 'a'; c < 'a' + m; ++c) {
		v[k] = c; 
		if (k == n - 1) {
			mostrar(v);
		}
		else var(m, n, k + 1, v);
	}
}

bool resolver() {
	int m, n;
	cin >> m >> n;
	if (!cin) return false;
	std::vector <char> v(m);
	var(m, n, 0, v);
	return true;
}

int main() {
	while (resolver());
	return 0;
}