#include <iostream>
using namespace std;
int main() {
	int n = 3;
	float a = 0, b = 3.2;
	int m;
	char c, e = 1;

	m = (n % 2) ? ( - 1 + n) : n; //2
	cout << m << endl;
	a = (1 / 2) * b; //0
	cout << a << endl;
	c = 4 < (1 << n); //1 = NULL
	cout << (int)c << endl;
	c = ((1 / e) / b) + a; //0 = SOH
	cout << (int)c << endl;
}