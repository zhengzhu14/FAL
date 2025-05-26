#include <iostream>


using namespace std;

int modNoFinal(int n) {
	if (n % 2 == 0) {
		++n;
	}
	else {
		--n;
	}
	if (n < 10) {
		return n;
	}
	else {
		return n % 10 + (10 * modNoFinal(n / 10));
	}
}

int modFinal(int n, int sol, int pot) {
	if (n % 2 == 0) {
		++n;
	}
	else {
		--n;
	}
	if (n < 10) {
		return (n * pot) + sol;
	}
	else {
		return modFinal(n / 10, sol + (n % 10) * pot, pot * 10);
	}
}

void resolver() {
	int n;
	cin >> n;
	int sol;
	sol = modFinal(n, 0, 1);
	cout << sol << endl;
}
int main() {
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; ++i) resolver();
	return 0;
}