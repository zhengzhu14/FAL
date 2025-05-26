#include <iostream>

using namespace std;

using lli = long long int;

lli fib(int n, lli n1, lli n2) {
	if (n == 0) return n2;
	else if (n == 1) return n1;
	else {
		return fib(n - 1, n1 + n2, n1);
	}
}
bool resolver() {
	int n;
	cin >> n;
	if (!cin) return false;

	lli sol = fib(n , 1, 0);
	cout << sol << endl;

	return true;
}

int main() {
	while (resolver());

	return 0;
}