#include <iostream>
#include <memory>
#include <cmath>
#include "figur.h"

using namespace std;

Figur::~Figur() {
	cout << "~Figur" << endl;
}

class GeometrieContainer {
private:
	int                     anzahl;
	unique_ptr < Figur* []> figuren;

public:
	GeometrieContainer(int n = 0);
	GeometrieContainer(const GeometrieContainer& gc);
	~GeometrieContainer();

	GeometrieContainer& operator=(GeometrieContainer gc);
	Figur* at(int i) const {
		return figuren[i];
	}

	void set(int i, Figur* f);
};

// ----------------------------------------------------
GeometrieContainer::GeometrieContainer(int n) :
	anzahl(n), figuren(nullptr) {
	if (n <= 0)
		return;

	cout << "Hier Standardkonstruktor (" << n << " Elemente)" << endl;
	figuren = make_unique<Figur* []>(n);
	for (int i = 0; i < n; i++)
		figuren[i] = new Dreieck(1.0 + i, 2.0 + i, 3.0 + i);
}

// ----------------------------------------------------
GeometrieContainer::GeometrieContainer(const GeometrieContainer& gc) :
	anzahl(gc.anzahl) {
	if (anzahl <= 0)
		return;

	cout << "Hier Kopierkonstruktor" << endl;
	figuren = make_unique<Figur* []>(anzahl);  // figuren = new Figur*[anzahl];

	for (int i = 0; i < anzahl; i++)
	{

		/* Alternative mit dynamic_cast

				Kreis* pK = dynamic_cast<Kreis*>(gc.figuren[i]);
				if (pK) {
					figuren[i] = new Kreis(*pK);
					continue;
				}

				Rechteck* pR = dynamic_cast<Rechteck*>(gc.figuren[i]);
				if (pR) {
					figuren[i] = new Rechteck(*pR);
					continue;
				}

				Dreieck* pD = dynamic_cast<Dreieck*>(gc.figuren[i]);
				if (pD) {
					figuren[i] = new Dreieck(*pD);
					continue;
				}

				figuren[i] = nullptr;
		*/

		// Alternative mit clone-Methode
		if (gc.figuren[i])
			figuren[i] = gc.figuren[i]->clone();
		else
			figuren[i] = nullptr;

	}

}

// ----------------------------------------------------
GeometrieContainer& GeometrieContainer::operator=(GeometrieContainer gc)
{
	cout << "Hier Zuweisungsoperator" << endl;
std:swap(anzahl, gc.anzahl);
	std::swap(figuren, gc.figuren);

	return *this;
}

// ----------------------------------------------------
GeometrieContainer::~GeometrieContainer()
{
	if (figuren == nullptr)
		return;

	for (int i = 0; i < anzahl; i++)
		if (figuren[i])
			delete figuren[i];
}

// ----------------------------------------------------
void GeometrieContainer::set(int i, Figur* f)
{
	if (i < 0 || i >= anzahl)
		return;

	/*
	Kreis* pK = dynamic_cast<Kreis*>(f);
	if (pK) {
		if (figuren[i])
			delete figuren[i];
		figuren[i] = new Kreis(*pK);
		return;
	}

	Rechteck* pR = dynamic_cast<Rechteck*>(f);
	if (pR) {
		if (figuren[i])
			delete figuren[i];
		figuren[i] = new Rechteck(*pR);
		return;
	}

	Dreieck* pD = dynamic_cast<Dreieck*>(f);
	if (pD) {
		if (figuren[i])
			delete figuren[i];
		figuren[i] = new Dreieck(*pD);
	}
	*/

	if (figuren[i])
		delete figuren[i];
	figuren[i] = f->clone();
}


// ----------------------------------------------------
void figurDaten(Figur* f)
{
	cout << "Flaeche: " << f->flaeche() << endl;
	cout << "Umfang:  " << f->umfang() << endl;
}

// ----------------------------------------------------
int main()
{
	Kreis     k(5.0);
	Rechteck  r(3.0, 4.0);
	Dreieck   d(5.0, 5.0, 6.0);

	GeometrieContainer  gc(3);

	gc.set(0, &k);
	gc.set(1, &r);
	gc.set(2, &d);

	cout << "Daten zum Kreis: " << endl;
	figurDaten(gc.at(0));

	GeometrieContainer gc2;
	gc2 = gc;
	Kreis k2(10.0);
	gc2.set(0, &k2);

	cout << "Daten zum 2. Kreis: " << endl;
	figurDaten(gc2.at(0));

	cout << endl << "Daten zum Rechteck: " << endl;
	figurDaten(gc.at(1));

	cout << endl << "Daten zum Dreieck: " << endl;
	figurDaten(gc2.at(2));

	return 0;
}