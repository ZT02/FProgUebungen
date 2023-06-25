#include <iostream>
#define PI 3.14151927
#define pow2(r) (r*r)
#define pow3(r) (r*r*r)
using namespace std;

int main() {
	int a;
	cout << "Radius: ";
	cin >> a;
	double volume = (double)(4 / 3) * PI * pow3(a);
	double surface = 4 * PI * pow2(a);
	cout << "Volumen: " << volume << "\nOberflaeche: " << surface << endl;

	return 0;
}