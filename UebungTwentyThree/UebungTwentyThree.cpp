#include <iostream>
using namespace std;
int main() {

	int a = 10, b, c;
	a *= 5 + 10;    cout << a << endl; //150
	a *= b = c = 20;  cout << a << ", " << b << endl; //3000, 20
	b = b == c;     cout << b << endl; //1
	a >>= b + 2;    cout << a << endl; //375
	a &= 0x3e;    cout << a << endl; //54

	a = 3;
	b = 2;
	a *= b += a <<= a + b;  cout << "a= " << a << ", b= " << b << endl; //a=9408, b=98
	
	return 0;
}