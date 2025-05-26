#include <iostream>

using namespace std;

using tSol = pair <bool, int>;

tSol interesante(int n, int sumD) {
	if (n == 0) return {false , n };
	else if (n < 10) return { sumD % n == 0, n };
	else {
		tSol sol;
		int digito = n % 10;
		sol = interesante(n / 10, sumD + digito);
		sol.first = sol.first && (digito != 0) && ((sol.second % digito) == 0) && sumD % digito == 0;
		sol.second = sol.second + digito;
		return sol;
	}
	
}

void resolver() {
	int n;
	cin >> n;
	tSol sol = interesante(n, 0);
	if (sol.first) cout << "SI" << endl;
	else cout << "NO" << endl;
}

int main() {
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; ++i) resolver();
	return 0;
}