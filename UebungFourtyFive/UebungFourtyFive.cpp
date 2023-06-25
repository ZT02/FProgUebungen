#include <iostream>
#include <vector>
using namespace std;
class Vereinsmitglied
{
    int m_nummer;
    string m_name;

public:
    Vereinsmitglied(int nummer, const string& name);
    ~Vereinsmitglied() {};
    int getNummer() const;
    const string& getName() const;
    void ausgeben()
    {
        cout << "Mitglied: " << m_name << " ("
            << m_nummer << ")" << endl;
    }
};

Vereinsmitglied::Vereinsmitglied(int nummer, const string& name) : m_nummer(nummer), m_name(name){}
int Vereinsmitglied::getNummer() const {
    return m_nummer;
}

const string& Vereinsmitglied::getName() const {
    return m_name;
}

class Trainer
{
private:
    string name;
    vector<Vereinsmitglied>* Mannschaft;
public:
    Trainer() : name("namenslos"), Mannschaft(new vector<Vereinsmitglied>)  {}

    Trainer(string name) {
        this->name = name;
        Mannschaft = new vector<Vereinsmitglied>;
    }
    //Kopierkonstruktor -> name direkt übernehmen
    Trainer(const Trainer& anderer) : name(anderer.name){
        if (!anderer.Mannschaft)
        {
            Mannschaft = nullptr;
            return;
        }
        //Vektor erst inhaltlich kopieren und zeiger des neuen Objektes zuweisen
        copy(anderer.Mannschaft, anderer.Mannschaft+Mannschaft->size(), Mannschaft);
    }

    ~Trainer() {
        if(!Mannschaft)
            delete Mannschaft;
    }

    void neuesMitglied(const Vereinsmitglied* mitgl);
    Vereinsmitglied* sucheSpieler(int nummer);
};

void Trainer::neuesMitglied(const Vereinsmitglied* mitgl) {
    Trainer::Mannschaft->push_back(*mitgl);

}

Vereinsmitglied* Trainer::sucheSpieler(int nummer) {
    for (int i = 0; i < Mannschaft->size(); i++) {
        if (Mannschaft->at(i).getNummer() == nummer) {
            return &(Mannschaft->at(i));
        }
   }
    //nichts wenn leer
    return nullptr;

}

int main() {
    Trainer a = Trainer();
    Vereinsmitglied *b = new Vereinsmitglied(55,  "Alpha");
    a.neuesMitglied(b);
    a.sucheSpieler(b->getNummer())->ausgeben();
    delete b;
}