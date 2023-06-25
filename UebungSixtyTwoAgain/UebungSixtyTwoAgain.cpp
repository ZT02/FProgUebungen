#include <iostream>

using namespace std;
const double pi = 3.14;
class Figur {

public:
	virtual double flaeche() const = 0;
	virtual double umfang() const = 0;
};

class Kreis : public Figur {
private:
	int radius;

public:
	Kreis(int rad = 0) : radius(rad) {

	}
	double flaeche() const {
		return pow(radius, 2) * pi;
	}
	double umfang() const {
		return 2 * pi * radius;
	}
};

class Rechteck : public Figur {
private:
	int laenge;
	int breite;
public:
	Rechteck(int laenge = 0, int breite = 0) : laenge(laenge), breite(breite){}
	double flaeche() const {
		return laenge * breite;
	}
	double umfang() const {
		return 2 * laenge + 2 * breite;
	}

};

class Dreieck : public Figur {
private:
	int side1;
	int side2;
	int side3;
public:
	Dreieck(int side1 = 0, int side2 = 0, int side3 = 0) : side1(side1), side2(side2), side3(side3){}
	double flaeche() const {
		double s = (double)(side1 + side2 + side3) / 2;
		double area = sqrt(s * (s - side1) * (s - side2) * (s - side3));
		return area;
	}
	double umfang() const {
		return side1 + side2 + side3;
	}
};

void figurDaten(Figur* f)
{
	cout << "Flaeche:" << f->flaeche() << endl;
	cout << "Umfang: " << f->umfang() << endl;
}

int main() {
	Figur* test1 = new Kreis(5);
	Figur* test2 = new Rechteck(4, 3);
	Figur* test3 = new Dreieck(2, 5, 6);

	figurDaten(test1);
	figurDaten(test2);
	figurDaten(test3);
}