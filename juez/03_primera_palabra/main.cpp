//Nombre: Zhengkai Zhu
//Problema: Primera Palabra
//Cuenta: A70
#include <iostream>
#include <vector>
using namespace std;
std::string primera(const std::vector<std::string> &v) {
	std::string sol = v[0];
	for (int i = 1; i < v.size(); ++i) {
		if (v[i] < sol) {
			sol = v[i];
		}
	}
	return sol;
}
void resolver() {
	int num;
	std::string str;
	cin >> num;
	std::vector<std::string> v;
	for (int i = 0; i < num; ++i) {
		cin >> str;
		v.push_back(str);
	}
	string sol = primera(v);
	cout << sol << endl;
}
int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) resolver();
	return 0;
}