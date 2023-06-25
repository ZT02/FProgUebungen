#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<typename T>
class CQueue
{
public:
    vector<T>* m_asQueue;  // Array der Queue-Elemente
    int      m_iMax;     // Gr��e des Array
    int      m_iCount;   // Anzahl der genutzten Elemente im Array
    int      m_iFirst;   // Index des ersten eingef�gten Elements,
    // dieses wird als erstes wieder ausgegeben
    int      m_iLast;    // Index des zuletzt eingef�gten Elements

public:
    CQueue() : m_asQueue(nullptr), m_iMax(0), m_iCount(0), m_iFirst(0), m_iLast(0) {}
    CQueue(int iMax);
    CQueue(CQueue<T>& cque);
    CQueue(CQueue<T>&& _cque);
    ~CQueue();
    void swap(CQueue<T>& anderer);
    CQueue<T>& operator=(CQueue<T> _cque);
    bool isEmpty() { return m_iCount == 0; } // Queue leer ? 
    bool isFull() { return m_iCount == m_iMax; } // Queue voll ? 
    const T& get();
    bool put(const T& name);
    void contents(); // Auflisten der Queue entspr. der Reihenfolge
    
};
template<typename T>
CQueue<T>::CQueue(int iMax) : m_iMax(iMax), m_iCount(0), m_iFirst(0), m_iLast(0) {
    if (m_iMax <= 0) {
        m_iMax = 0;
        m_asQueue = nullptr;
        return;
    }
    m_asQueue = new vector<T>;
    //Nein, auf dem Heap ist eine dynamische Speicherverwltung notwendig,
    // daher ist es  nicht n�tig direkt
    //Werte einzuf�gen in dieses Array
}
//Kopierkonstruktor
template<typename T>
CQueue<T>::CQueue(CQueue<T>& cque) : m_asQueue(cque.m_asQueue), m_iMax(cque.m_iMax), m_iCount(cque.m_iCount), m_iFirst(cque.m_iFirst), m_iLast(cque.m_iFirst) {
    if (!cque.m_asQueue)
    {
        m_asQueue = nullptr;
        return;
    }
    cerr << "Copy Copy Copy Constructor" << endl;
    //Notwendig um tiefe Kopien anzulegen bei dynamisch angelegten Speicherelementen
    //deren Zeiger, Referenzen etc. deuten sonst auf das Original und haben keien Kopierten Werte
    //Wenn ein �lteres Objekt, einen neuen Objekt "zugewiesen" wird, genauer genommen
    // wird das neue Objekt mit Altem Initialisiert, siehe main

    //Aufgerufen wenn neues Objekt mit alten initialsiert wird. Existiert nicht vorher
}
template<typename T>
CQueue<T>::~CQueue() {
    if (m_asQueue)
        delete m_asQueue;
}
template<typename T>
const T& CQueue<T>::get() {
    //Wir k�nnen NULL zur�ckgeben oder einen anderen Wert der �hnliches Aussagt;
    if (!m_asQueue || isEmpty())
        return ""; //oder NULL
    // sonst Zeiger auf Array mit Elementen
    m_iCount--;
    m_iLast %= m_iMax;
    return m_asQueue->at(m_iLast++);

}
template<typename T>
void CQueue<T>::swap(CQueue<T>& anderer)
{
    using std::swap;
    swap(*m_asQueue, *anderer.m_asQueue);
    swap(m_iCount, anderer.m_iCount);
    swap(m_iFirst, anderer.m_iFirst);
    swap(m_iLast, anderer.m_iLast);
    swap(m_iMax, anderer.m_iMax);

}
//Zuweisungsoperator
template<typename T>
CQueue<T>& CQueue<T>::operator=(CQueue<T> _cque)
{
    //Wenn Konstanten, Referenzen, dynamisch angaelegter Speicherbereich (In Klasse/Objekt)
    //vorkommen
    //Wenn noch kein bereits evtl. vorhandener Speicherbereich gel�scht werden soll
    cerr << "Zuweisung Zuweisung Zuweisungs Operator" << endl;
    swap(_cque);
    return *this;
    //wird aufgerufen, wenn Objekte bereits existierten
}

template<typename T>
CQueue<T>::CQueue(CQueue<T>&& cque) : m_asQueue(m_asQueue), m_iMax(cque.m_iMax), m_iCount(cque.m_iCount), m_iFirst(cque.m_iFirst), m_iLast(cque.m_iFirst) {
    m_iMax = m_iCount = m_iFirst = m_iLast = 0;
    cque.m_asQueue = nullptr;
    cout << "Move Konstruktor" << endl;
    //Unterschied zwischen Kopierkonstruktor & Movekonstruktor
        /*KK: Referenz auf L-Werte, Zwischenkopien, Kopiert das Ursprungsobjekt (nutzt neuen Speicherbereich), Keine Kenntnis �ber Destruktor, f�r neu erstelle Objekte; MK: Referenz auf R-Werte, keine Zwischenkopien, l�st Verbindung des Speichers mit dem Ursprungsprunkt, Kenntnis �ber Destruktor, f�r bestehende Objekte */

        //Schritte: Alten Zeiger, dem neuen OBjekt �bergeben
                    // Alten zeiger auf nullptr setzen (damit Speicherbereich des neuen Obejektes/Zeigers nicht gel�scht wird ) 

}
template<typename T>
CQueue<T> getWinter() {
    //Standardkonstruktor wird aufgerufen, da nur eine normale CQueue erzeugt wird, anschlie�end werden noch die Werte zugeiwesen
    CQueue<T> a(3);
    vector<T>* temp = new vector<T>;
    a.put("Oktober");
    a.put("November");
    a.put("Dezember");
    /* a.m_iFirst = 0;
    a.m_iLast = 2;
    a.m_iCount = 3;
    a.m_iMax = 3;
    temp->push_back("Oktober");
    temp->push_back("November");
    temp->push_back("Dezember");
    a.m_asQueue = temp; */
    return a;
}
template<typename T>
void CQueue<T>::contents() {
    vector<T>* temp = m_asQueue;
    if (!temp) {
        cout << "Queue ist leer!" << endl;
        return;
    }

    int first = 0;
    string s = "Queue: \n";
    while (first < m_iLast) {
        s += to_string(first) + ": " + temp->at(first) + "\n";
        first++;
    }

    cout << s << endl;
}
template<typename T>
bool CQueue<T>::put(const T& name) {
    if (m_iLast < m_iMax)
    {
        m_asQueue->push_back(name);
        m_iLast++;
        m_iCount++;
        return true;

    }

    return false;

}

int main() {
    //Kopierkonstruktor
    CQueue<string> one;
    CQueue<string> two = one;
    CQueue<string> three(two);
    //Zuweisungsoperator
    CQueue<string> x(5), y(5);
    //y = x;

    CQueue<string> test(3);
        test = getWinter<string>();
    test.contents();
    CQueue<string> test2(4);
    test2.put("Markus0");
    test2.put("Markus1");
    test2.put("Markus2");
    test2.put("Markus3");
    test2.contents();
     test.contents();
     one.contents();
    return 1;
}