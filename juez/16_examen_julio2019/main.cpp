#include <iostream>
#include <vector>
using namespace std;
 
int kemparejados(std::vector<int> const &v, int k) {
	int res = 0;
	int i = 0; 
	int j = 0;
	while (j < v.size() && i <= j) {
		if (v[j] - v[i] < k) ++j;
		else if (v[j] - v[i] == k) {
			++res;
			++j;
		}
		else {
			++i;
		}
	}

	return res;
}

bool resolver() {
	int n; 
	cin >> n;
	if (n == -1) return false;
	int k;
	cin >> k;
	std::vector <int> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];

	int res = kemparejados(v, k);
	cout << res << endl;

	return true;
}

int main() {
	while (resolver());
	return 0;
}