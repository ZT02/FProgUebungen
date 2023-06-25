#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;
class Rational {
private:
	long zaehler, nenner;

	long ggT(long a, long b) {
		long R;
		while ((a % b) > 0) {
			R = a % b;
			a = b;
			b = R;
		}
		return b;
	}

public:
	Rational() : zaehler(0), nenner(1) {
		cerr << "Standardkonstruktor" << endl;
	}
	Rational(long z, long n) : zaehler(z), nenner(n) {
		cerr << "Allgemeiner Konstruktor" << endl;
		if (n == 0) {
			cerr << "Error: Nenner ist 0" << endl;
			exit(1);
		}
	}
	Rational(long gz) : zaehler(gz), nenner(1) {
		cerr << "Allgemeiner Konstruktor" << endl;
	} // für Ganzzahlen

	Rational(const Rational& r) : zaehler(r.zaehler), nenner(r.nenner) {
		cerr << "Kopierkonstruktor" << endl;
	} // Kopierkonstruktor

	void add(const Rational& a, const Rational& b) {
		set(a.zaehler * b.nenner + b.zaehler * a.nenner,b.nenner * a.nenner);
		kuerzen();
	}
	void sub(const Rational& a, const Rational& b) {
		set(a.zaehler * b.nenner - b.zaehler * a.nenner, b.nenner*a.nenner);
		kuerzen();
	}
	void mult(const Rational& a, const Rational& b) {
		set(a.zaehler * b.zaehler, a.nenner*b.nenner);
		kuerzen();
	}
	void div(const Rational& a, const Rational& b) {
		set(a.zaehler * b.nenner, a.nenner * b.zaehler);
		kuerzen();
	}
	void set(long z, long n) {
		zaehler = z;
		nenner = n;
		kuerzen();
	}
	void kehrwert() {
		long temp = zaehler;
		zaehler = nenner;
		nenner = temp;
	}
	void kuerzen() {
		long ggTValue = ggT(zaehler, nenner);
		zaehler = zaehler / ggTValue;
		nenner = nenner / ggTValue;

	}
	void ausgabe() {
		cout << "Zaehler: " << zaehler << "\n" << "Nenner: " << nenner << endl;
	}
};

int main() {
	Rational a(1, 6);
	Rational b(2, 9);
	Rational c;
	c.add(a, b);
	c.ausgabe();
}