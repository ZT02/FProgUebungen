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

	Rational(long gz){
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

	Rational& operator=(Rational _rat)
	{
		cout << "Ich bin der Zuweisungsoperator :)";
		swap(_rat);
		return *this;
	}

	friend void add(Rational&, const Rational&, const Rational&);
	friend void sub(Rational&, const Rational&, const Rational&);
	friend void mult(Rational&, const Rational&, const Rational&);
	friend void div(Rational&, const Rational&, const Rational&);

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

void add(Rational& c, const Rational& a, const Rational& b) {
	c.set(a.zaehler * b.nenner + b.zaehler * a.nenner, b.nenner * a.nenner);
	c.kuerzen();
}
void sub(Rational& c, const Rational& a, const Rational& b) {
	c.set(a.zaehler * b.nenner - b.zaehler * a.nenner, b.nenner * a.nenner);
	c.kuerzen();
}
void mult(Rational& c, const Rational& a, const Rational& b) {
	c.set(a.zaehler * b.zaehler, a.nenner *b.nenner);
	c.kuerzen();
}
void div(Rational& c, const Rational& a, const Rational& b) {
	c.set(a.zaehler * b.nenner, a.nenner * b.zaehler);
	c.kuerzen();
}

int main() {
	Rational a(1, 6);
	Rational x;
	x.set(5, 9);
	Rational b(2, 9);
	Rational c;
	sub(x, x, b);
	add(c, a, b);
	c.ausgabe();
	x.ausgabe();
	b = c;
}

//welchen Vorteil bringt diese Änderung?
//Wir können tiefe Kopien der Objekte anlegen
//Zuweisung steuerbar
// Wir können eigene Datentypen Zuweisen, normalerweise geht es nur für eingebaute
//Ermöglicht uns tiefe kopien von Referenzen innerhalb der Klasse (zb. von Referenz Attributen) anzulegen