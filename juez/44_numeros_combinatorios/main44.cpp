#include <iostream>
#include <vector>

using namespace std;

using tMatriz = std::vector <std::vector<int>>;

int combinatorio(int a, int b, tMatriz& matriz) {
	if (b == 0 || a == b) return 1;
	//else if ( == 1 ) return 1;
	else {
		if (matriz[a - 1][b - 1] == -1) {
			matriz[a - 1][b - 1] = combinatorio(a - 1, b - 1, matriz);
		}
		if (matriz[a - 1][b] == -1) {
			matriz[a - 1][b] = combinatorio(a - 1, b, matriz);
		}
		return matriz[a - 1][b - 1] + matriz[a - 1][b];
	}
}

bool resolver() {
	int a, b;
	cin >> a;
	if (!cin) return false;
	cin >> b;
	tMatriz matriz(a + 1, std::vector<int>(b + 1, -1));
	int sol = combinatorio(a, b, matriz);
	cout << sol << endl;
	return true;
}

int main() {
	while (resolver());
	return 0;
}