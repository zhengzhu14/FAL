#include <iostream>

using namespace std;

using lli = long long int;

lli hermite(int y, int n, int i, lli h1, lli h2) { 
	if (n == i) return h2;
	else if (n == (i + 1)) return h1;
	else {
		return hermite(y, n, i + 1, (2 * y) * h1 - (2 * (i + 1) * h2), h1);
	}
}

bool resolver() {
	int n, y;
	cin >> n;
	if (n == -1) return false;
	cin >> y;
	lli sol = hermite(y, n, 0, 2 * y, 1);
	cout << sol << endl;

	return true;

}

int main() {
	while (resolver());

	return 0;
}

/*

Coste de recurrencia: 
  
  T(n) = {	C0					n == 0 or n == 1;
			T(n - 1) + C1 (las operacion para sumar 1 al indice i y para calcular H(i + 2))		 n>1;
  }


Desplegado: sea n > 1;
	
	T(n) = T(n - 1) + C1 = T(n - 2) + C1 + C1 = ... = T(n - k) + C1*k = ... = T(1) + C1*(n - 1) = C1(n - 1) + C0

T € O(n) coste lineal respecto del grado del polinomio


*/

