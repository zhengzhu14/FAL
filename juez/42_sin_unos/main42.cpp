#include <iostream>

using namespace std;
using lli = long long int;

bool tieneUnos(lli n) {
	if (n == 1) return true;
	else if (n < 10) return false;
	else {
		return tieneUnos(n / 10) || (n % 10 == 1);
	}
}

pair <bool, lli> sinUnos(lli n) {
	if (n == 0) return {false, 1};
	else if (n < 10) {
		if (n == 1) return { true, 1 };
		else return { false, n };
	}
	else {
		pair <bool, lli> sol = sinUnos(n / 10);
		if (sol.first) sol.second = sol.second * 9;
		else {
			if (n % 10 > 1) sol.second =  sol.second * 9 - (9 - n % 10);
			else sol.second = sol.second * 9 - 8;
		}
		sol.first = sol.first || n % 10 == 1;
		return sol;

	}
}

bool resolver() {
	lli n;
	cin >> n;
	if (!cin) return false;
	lli sol = sinUnos(n).second;
	cout << sol << endl;

	return true;
}

int main() {
	while (resolver());
	return 0;
}