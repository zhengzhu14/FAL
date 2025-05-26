#include <iostream>
#include <vector>

using namespace std;

bool resolver() {
	int ini; int fin;
	cin >> ini >> fin;
	if (ini == 0 && fin == 0) return false;
	std::vector <int> v(fin - ini + 1);
	std::vector<long long int> sumas(v.size());
	long long int aux = 0;
	for (int i = 0; i <= (fin - ini); ++i) {
		cin >> v[i];
		aux += v[i];
		sumas[i] = aux;
	}

	int casos;
	cin >> casos;
	int p1, p2;
	for (int i = 0; i < casos; ++i) {
		cin >> p1 >> p2;
		if ((p1 - ini) == 0) {
			cout << sumas[p2 - ini];
		}
		else {
			cout << sumas[(p2 - ini)] - sumas[p1 - ini - 1];
		}
		cout << endl;
		
	}
	cout << "---\n";


	return true;
}


int main() {
	while (resolver());
	return 0;
}