#include <iostream>
using namespace std;

class Kunde
{
    int m_nummer;
    string m_name;
    static int anzahl;
public:
    Kunde() {
        m_name = "";
        m_nummer = 0;
        anzahl++;
    }
    //mit initialisierungsListe:
    // Kunde(int nummer = 0, const string& name = "") : m_nummer(nummer), m_name(name) {anzahl++};
    Kunde(int nummer = 0, const string& name = "") {
        m_nummer = nummer;
        m_name = name;
        anzahl++;
    }
    ~Kunde() {
        anzahl--;
    }
    int getNummer() const {
        return m_nummer;
    }
    const string& getName() const {
        return m_name;
    }
    void ausgeben()
    {
        cout << m_nummer << ": " << m_name << endl;
    }

    static const int getAnzahl() {
        return anzahl;
    }
};
int Kunde::anzahl = 0;
int main()
{
    cout << "Objekte: " << Kunde::getAnzahl() << endl;
    Kunde k1(1, "Dagobert Duck");
    Kunde k2(2, "Zacharias Zorngiebel");

    cout << "Objekte: " << Kunde::getAnzahl() << endl;
    {
        Kunde k3(3, "Gustav Gans");
        cout << "Objekte: " << Kunde::getAnzahl() << endl;
    }

    cout << "Objekte: " << Kunde::getAnzahl() << endl;

    return 0;
}