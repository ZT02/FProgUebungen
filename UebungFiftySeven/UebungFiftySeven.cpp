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
	Rational() {
		cout << "Standardkonstruktor" << endl;
		set(0, 1);
	}
	// Beispiel mit InitialisierungsListe
	//	Rational(long z, long n) : zaehler(z), nenner(n) {
	//		cerr << "Allgemeiner Konstruktor" << endl;
	//		if (n == 0) {
	//			cerr << "Error: Nenner ist 0" << endl;
	//			exit(1);
	//		}
	//	}

	Rational(long z, long n) {
		cerr << "Allgemeiner Konstruktor" << endl;
		if (n == 0) {
			cerr << "Error: Nenner ist 0" << endl;
			exit(1);
		}
		set(z, n);
	}

	Rational(long gz) {
		cout << "Allgemeiner Konstruktor" << endl;
		set(gz, 1);
	} // für Ganzzahlen

	Rational(const Rational& r) {
		cout << "Kopierkonstruktor" << endl;
		set(r.zaehler, r.nenner);
	} // Kopierkonstruktor
	void swap(Rational& anderer)
	{
		using std::swap;
		swap(zaehler, anderer.zaehler);
		swap(nenner, anderer.nenner);
	}

	//typumwandlungsoperator
	operator double() {
		double d = double(zaehler / nenner);
		return d;
	}

	Rational& operator=(Rational _rat)
	{
		cout << "Ich bin der Zuweisungsoperator :)";
		swap(_rat);
		return *this;
	}

	friend ostream& operator<<(ostream& os, Rational& c) {
		return os << c.zaehler << c.nenner <<endl;
	}

	friend Rational operator+(const Rational& a, const Rational& b) {
		Rational c;
		c.set(a.zaehler * b.nenner + b.zaehler * a.nenner, b.nenner * a.nenner);
		c.kuerzen();
		return c;
	}

	friend Rational operator-(const Rational& a, const Rational& b) {
		Rational c;
		c.set(a.zaehler * b.nenner - b.zaehler * a.nenner, b.nenner * a.nenner);
		c.kuerzen();
		return c;
	}

	friend Rational operator*(const Rational& a, const Rational& b) {
		Rational c;
		c.set(a.zaehler * b.zaehler, a.nenner * b.nenner);
		c.kuerzen();
	}

	friend Rational operator/ (const Rational & a, const Rational & b) {
		Rational c;
		c.set(a.zaehler * b.nenner, a.nenner * b.zaehler);
		c.kuerzen();
		return c;
	}

	friend bool operator== (const Rational& a, const Rational& b) {
		Rational c = a / b;
		if (c.zaehler / c.nenner == 1)
			return true;
		else
			return false;
	}

	friend bool operator!= (const Rational& a, const Rational& b) {
		Rational c = a / b;
		if (c.zaehler / c.nenner != 1)
			return true;
		else
			return false;
	}
	//Prefix
	Rational& operator++ () {
		Rational c(1, 1);
		Rational a(zaehler, nenner);
		Rational b = c + a;
		zaehler = b.zaehler;
		nenner = b.nenner;
		return b;
	}
	//Postfix
	Rational operator++ (int) {
		Rational c = *this;
		Rational a(zaehler, nenner);
		Rational b = c + a;
		zaehler = b.zaehler;
		nenner = b.nenner;
		return b;
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


};



int main() {
	Rational a(1, 6);
	Rational x;
	x.set(5, 9);
	Rational b(2, 9);
	Rational c;
	c = a - b;
	cout << c;
	c = a + b;
	cout << c;
	b = c;
}