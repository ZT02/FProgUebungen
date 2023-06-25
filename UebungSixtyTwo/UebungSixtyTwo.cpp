#include <cmath>
#include <iostream>
using namespace std;
class Figur
{
public:
	virtual double flaeche() const = 0;
	virtual double umfang() const = 0;
	virtual ~Figur() {};
};

class Kreis : public Figur
{
private:
	int radius;
public:
	Kreis(int rad) : radius(rad){}

	double flaeche() const {
		return  radius * radius * 3.14;
	}
	double umfang() const {
		return (radius + radius) * 3.14;
	}
};

class Rechteck : public Figur
{
private:
	int laenge;
	int breite;
public:
	Rechteck(int laenge, int breite) : laenge(laenge), breite(breite) {};
	double flaeche() const {
		return  laenge * breite;
	}
	double umfang() const {
		return 2 * (laenge + breite);
	}
};

class Dreieck : public Figur
{
private:
	int seite1;
	int seite2;
	int hypo;
public:
	Dreieck(int seite1, int seite2, int hyp) : seite1(seite1), seite2(seite2), hypo(hyp) {};
	double flaeche() const {
		double s = double((seite1 + seite2 + hypo)) / 2;
		double area = double(sqrt(s * (s - seite1) * (s - seite2) * (s - hypo)));
		return area;
	}

	double umfang() const {
		return seite1 + seite2 + hypo;
	}
};
ostream& operator<<(ostream& o, const Figur* d) {
	o << d->flaeche() << "\n" << d->umfang();
	return o;
}

void figurDaten(Figur* f)
{
	cout << "Flaeche:" << f->flaeche() << endl;
	cout << "Umfang: " << f->umfang() << endl;
}

/*
a) Der Zeiger auf den Speicherbereich ist als Array von Figur* deklariert. Welche zwei Vorteile ergeben sich dadurch,
dass die Daten nicht direkt im Array, sondern über Zeiger im Array verwaltet werden? Wäre ein Array mit Figur-Objekten überhaupt möglich?

1. Vorteil: Das Array beinhaltet lediglich die Adresse der Objekte und können einfach auf ein neues Objekt ausgerichtet werden. Notwendig um die Array Daten zu manipulieren
2. Vorteil: Es können Objekte mit derselben Basisklasse innerhalb des arrays gespeichert werden, auch wenn die Basisklasse rein virtuell ist oder Objekte keienn spezifischen Konstruktor haben


Ein Array vom Typ Basisklasse mit Element aus der Kindklasse ist nur möglich, wenn die Basisklasse nicht rein virtuell ist und wenn ein passender Konstruktor für die Umwandlung des Types von Kindklasse zu Basisklasse vorhanden ist.
Zeiger von Typ Basisklasse erlauben hingegen das Zeigen auf die Kindklasse, somit muss ein Array also nur Zeiger der Basisklasse enthalten

c) Es soll ein Kopierkonstruktor zur Klasse GeometrieContainer hinzugefügt werden.

i. Wozu dient ein Kopierkonstruktor?
	Ein Kopie Konstruktor dient dazu tiefe Kopien eines Objektes mit dynamsichen Speicher anzuelegen. ist kein Kopierkonstruktor vorhanden, wird bei der Kopie von Zeigern/Referenzen diesselbe Adresse übernommen und somit zeigen diese auf dasselbe Objekt
ii. Wann muss ein Programmierer einen eigenen schreiben?
	Sobald in der eigenen Klasse Zeiger oder Referenzen verwendet werden, dessen Objekte nicht von mehreren OBjekten geteilt werden sollen.
iii. Fügen Sie einen Kopierkonstruktor zur Klasse hinzu.

iv. Wann wird ein Kopierkonstruktor aufgerufen? Geben Sie ein Beispiel an.
	Wenn ein neues Objekt mit einem altem initialisiert wird. D.h. es wird erst ein neues Objekt erzeugt.
	Datum d_alt;
	d_alt.anzeigen();
	Datum d_neu = d_alt;
	// Äquivalent wäre: Datum d_neu(d_alt);



	e) Es sollen nun noch Destruktoren hinzugefügt werden.

i. Warum benötigt die Klasse Figur einen eigenen Destruktor? Geben Sie dessen Deklaration und Implementierung an.
	Beim löschen einer Kindklasse wird bisher nur der Konstruktor der Basisklasse aufgerufen und somit nur die die Speichergröße der Basisklasse freigegeben, auch wenn eine Kindklasse gelöscht werden soll. (kindklasse hat mehr Attribute)
	um dies zu ändern muss eine ein virtuelle Destruktor implementiert werden
	virtual ~Figur() {};
ii. Warum benötigt die Klasse GeometrieContainer einen eigenen Destruktor? Geben Sie dessen Deklaration und Implementierung an.
	Die Klasse beinhaltet einen unique pointer mit einem array mit Zeigern, dieser dynamische Speicher muss wieder freigegeben werden
iii. Welche Auswirkungen hätte es auf die Klasse GeometrieContainer, wenn Figur keinen expliziten Destruktor hätte?
	Der Konstruktor der Figuren-Objekte wird aufgerufen, sobald diese nicht mehr im Scope sind.
	Da ohne Figur-Destruktor nur die Speichergröße der Basisklasse auch bei den kindklassen geöscht werden, würden sich sobald ein Figuren-Objekt out of scope geht/gelöscht wird nur der Teil der Basisklasse gelöscht. und die Komponenten der Kindklassen
	bleiben erhalten. Es entstehen Speicherlecks. (Fehler in der Speicherverwaltung, Arbetisspeicher ist belegt, dieser wird jedoch nicht nutzt und auch nicht freigibt)
*/
class  GeometrieContainer
{
private:
	int anzahl;
	unique_ptr<Figur* []> figuren;

	void swap(GeometrieContainer& anderer);
public:
	GeometrieContainer(int n);

	GeometrieContainer(const GeometrieContainer& temp);

	GeometrieContainer& operator=(GeometrieContainer gc);
	~GeometrieContainer();

};

GeometrieContainer::GeometrieContainer(int n) {
	anzahl = n-1;
	int i = anzahl;
	while (n>0) {
		figuren[i] = new Kreis(2);
		i--;
	}
}

GeometrieContainer::GeometrieContainer(const GeometrieContainer& temp) : anzahl(temp.anzahl) {

	int i = 0;
	while (temp.figuren[i]) {
		*figuren[i] = (*(temp.figuren[i]));
		i++;
	}
}

GeometrieContainer::~GeometrieContainer() {
	int i = 0;
	while (figuren[i]) {
		delete figuren[i];
		i++;
	}
	figuren.reset(nullptr);
}

void GeometrieContainer::swap(GeometrieContainer& anderer) {
	using std::swap;
	swap(anzahl, anderer.anzahl);
	figuren.swap(anderer.figuren);
}

GeometrieContainer& GeometrieContainer::operator=(GeometrieContainer gc) {
	swap(gc);
	return *this;
}

int main() {
	Dreieck* test1 = new Dreieck(1, 2, 3);
	Rechteck* test2 = new Rechteck(1, 2);
	Kreis* test3 = new Kreis(3);
	GeometrieContainer test4(3);
	GeometrieContainer test5 = test4;
	test4 = test5;

	cout << test3 << endl;
}