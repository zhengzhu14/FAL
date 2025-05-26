//Nombre: Zhengkai Zhu
//Juez: A70
//email: zhengzhu@ucm.es

#include <iostream>

using namespace std;


int sumaNoFinal(int n1, int n2) {
	if (n1 == 0 || n2 == 0) {
		return (n1 + n2);
	}
	else {
		int sumaDigito = n1 % 10 + n2 % 10;
		return (sumaDigito) % 10 + (10 * sumaNoFinal(n1 / 10, n2 / 10));
	}
}

int sumaFinal(int n1, int n2, int sol, int pot) { 
	if (n1 == 0 || n2 == 0) {
		return sol + (n1 + n2)*pot;
	}
	else {
		int sumaDigito = n1 % 10 + n2 % 10;
		return sumaFinal(n1 / 10, n2 / 10, (sumaDigito % 10) * pot + sol, pot * 10);
	}
}
void resolver() {
	int n1, n2;
	cin >> n1 >> n2;
	int sol = sumaNoFinal(n1, n2);
	cout << sol << ' ';
	sol = sumaFinal(n1, n2, 0, 1);
	cout << sol << endl;

}

int main() {
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; ++i) resolver();
	return 0;
}


/*
Definicion recursiva:
	n1,n2 € N U {0}
	suma(n1,n2) = {
					n1 + n2											 n1=0 or n2 = 0
					(n1%10 + n2%10)%10 + 10*suma(n1/10, n2/10)		 n1 != 0 and n2 != 0 
	}


Coste: n = minDigitos(n1,n2)
T(n) = {	Co	(Co = 1)			n = 0
			C1 (C1 = 6) + T(n -1)	n > 0
}

T(n) = C1 + T(n -1) = C1 + C1 + T(n-2) = ... = C1*k + T(n - k) = ... = (k = n) C1*n + T(0) = C1*n + Co = 6n + 1.
T € O(n);
*/