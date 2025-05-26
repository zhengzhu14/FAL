#include <iostream>

using namespace std;

int complementario(int n) {
	if (n < 10) {
		return 9 - n;
	}
	else {
		return (9 - n % 10) + (10 * complementario(n / 10));
	}
}

int invertirCompl(int n, int aux) {
	if (n < 10) {
		return (aux * 10) + 9 - n;
	}
	else {
		return invertirCompl(n / 10, aux * 10 + (9 -(n % 10)));
	}
}

void resolver() {
	int n;
	cin >> n;
	int sol = complementario(n);
	cout << sol << ' ';
	sol = invertirCompl(n, 0);
	cout << sol << endl;
}

int main() {
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; ++i) resolver();
	return 0;
}