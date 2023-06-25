#include <iostream>
using namespace std;


int main()
{




	int a = 2;
	auto lam = [a](int b, int c) {

		return b > c || a == 3;

	};
	cout << lam(1, 2);
}