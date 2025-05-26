#include <iostream>
#include <string>
using namespace std;

string converBinario(int n) {
	if (n == 0 || n == 1) {
		return to_string(n);
	}
	else if (n < 4) {
		return to_string(n / 2) + to_string(n % 2);
	}
	else {
		return converBinario(n / 2) + to_string(n % 2);
	}
}

void resolver() {
	int n;
	cin >> n;
	string sol = converBinario(n);
	cout << sol << endl;
}

int main() {
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; ++i) resolver();
	return 0;
}