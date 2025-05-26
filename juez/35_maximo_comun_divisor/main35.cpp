#include <iostream>

using namespace std;

int maxComunDiv(int a, int b) {
	if (b == 0) return a;
	else {
		return maxComunDiv(b, a % b);
	}

}

bool resolver() {
	int a, b;
	cin >> a >> b;
	if (a == 0 && b == 0) return false;

	if (b > a) swap(a, b);
	int sol = maxComunDiv(a, b);

	cout << sol << endl;
	return true;
}
int main() {
	while (resolver());
	return 0;
}