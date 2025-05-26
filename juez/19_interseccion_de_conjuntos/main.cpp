#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void resolver() {
	int aux;
	std::vector <int> v1;
	std::vector<int> v2;
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
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	int i = 0;
	int j = 0;
	while (i < v1.size() && j < v2.size()) {
		if (v1[i] < v2[j]) {
			++i;
		}
		else if (v1[i] > v2[j]) {
			++j;
		}
		else {
			cout << v1[i] << ' ';
			++i;
			++j;
		}
	}
	cout << endl;


}

int main() {
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; ++i) resolver();

	return 0;
}