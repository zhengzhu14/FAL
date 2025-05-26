#include <iostream>
#include <vector>

using namespace std;

void resolver() {
	int d;
	int tam;
	cin >> d >> tam;
	std::vector <int> v(tam);
	for (int i = 0; i < tam; ++i) {
		cin >> v[i];
	}

	int max = v[0];
	int aux = v[0];
	int cond = 1;
	int i = 1;
	bool pelos = true;
	while (i < v.size() && pelos) {
		if (v[i] >= max) {
			if (v[i] == max) {
				++cond;
				if (cond > d) pelos = false;
			}
			else {
				if (v[i] - max > 1) pelos = false; 
				else {
					max = v[i];
					cond = 1;
				}
			}
		}
		else pelos = false; 
		if (pelos) ++i;
	}

	if (pelos) cout << "SI\n";
	else cout << "NO\n";
}

int main() {
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; ++i) resolver();
	return 0;
}