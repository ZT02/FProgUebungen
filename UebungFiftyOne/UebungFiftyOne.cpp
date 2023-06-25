#include <iostream>
#include <stdlib.h>
#include <set>
using namespace std;
int main() {
	unsigned int zusatzahl;
	unsigned int zufallszahl;
	set<int> lottozahlen;
	set<int>::iterator iter = lottozahlen.begin();

	srand(time(0));
	for (int i = 0; i <= 6; i++) {
		if (i != 6) {
			zufallszahl = rand() % 100;
			iter = find(lottozahlen.begin(), lottozahlen.end(), zufallszahl);
			while (iter != lottozahlen.end()) {
				zufallszahl = rand() % 100;
				iter = find(lottozahlen.begin(), lottozahlen.end(), zufallszahl);
			}
			lottozahlen.insert(zufallszahl);
		}
		else {
			zufallszahl = rand() % 100;
			iter = find(lottozahlen.begin(), lottozahlen.end(), zufallszahl);
			while (iter != lottozahlen.end()) {
				zufallszahl = rand() % 100;
				iter = find(lottozahlen.begin(), lottozahlen.end(), zufallszahl);
			}
			zusatzahl = zufallszahl;
		}

	}
	cout << "Lottozahlen: ";
	for (auto& i : lottozahlen) {
		cout << i << " ";
	}
	cout << "\nZusatzzahl: " << zusatzahl;
	return 1;
}