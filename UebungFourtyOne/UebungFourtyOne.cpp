#include <iostream>
#include <string>
using namespace std;
class CQueue
{
private:
    string* m_asQueue;  // Array der Queue-Elemente
    int      m_iMax;     // Größe des Array
    int      m_iCount;   // Anzahl der genutzten Elemente im Array
    int      m_iFirst;   // Index des ersten eingefügten Elements,
    // dieses wird als erstes wieder ausgegeben
    int      m_iLast;    // Index des zuletzt eingefügten Elements

public:
    CQueue() : m_asQueue(0), m_iMax(0), m_iCount(0), m_iFirst(0), m_iLast(0) {}
    CQueue(int iMax);
    CQueue(CQueue& cque);
    CQueue(CQueue&& _cque);
    ~CQueue();
    void swap(CQueue& anderer);
    CQueue& operator=(CQueue _cque);
    bool isEmpty() { return m_iCount == 0; } // Queue leer ? 
    bool isFull() { return m_iCount == m_iMax; } // Queue voll ? 
    const string& get();
    bool put(const string& name);
    void contents(); // Auflisten der Queue entspr. der Reihenfolge
    friend CQueue getWinter();
};

CQueue::CQueue(int iMax) : m_iMax(iMax), m_iCount(0), m_iFirst(0), m_iLast(0){
    if (m_iMax <= 0) {
        m_iMax = 0;
        m_asQueue = nullptr;
        return;
    }
    m_asQueue = new string[iMax];
    //Nein, auf dem Heap ist eine dynamische Speicherverwltung notwendig,
    // daher ist es  nicht nötig direkt
    //Werte einzufügen in dieses Array
}
//Kopierkonstruktor
CQueue::CQueue(CQueue& cque) : m_iMax(cque.m_iMax), m_iCount(cque.m_iCount), m_iFirst(cque.m_iFirst), m_iLast(cque.m_iFirst) {
    if (!cque.m_asQueue)
    {
        m_asQueue = nullptr;
        return;
    }
    
    m_asQueue = new string[m_iMax];
    std::copy(cque.m_asQueue, cque.m_asQueue+m_iMax, m_asQueue);
    cerr << "Copy Copy Copy Constructor" << endl;
    //Notwendig um tiefe Kopien anzulegen bei dynamisch angelegten Speicherelementen
    //deren Zeiger, Referenzen etc. deuten sonst auf das Original und haben keien Kopierten Werte
    //Wenn ein älteres Objekt, einen neuen Objekt "zugewiesen" wird, genauer genommen
    // wird das neue Objekt mit Altem Initialisiert, siehe main

    //Aufgerufen wenn neues Objekt mit alten initialsiert wird. Existiert nicht vorher
}

CQueue::~CQueue() {
    if(m_asQueue)
        delete[] m_asQueue;
}

const string& CQueue::get() {
    //Wir können NULL zurückgeben oder einen anderen Wert der ähnliches Aussagt;
    if (!m_asQueue || isEmpty())
        return ""; //oder NULL
    // sonst Zeiger auf Array mit Elementen
    m_iCount--;
    m_iLast %= m_iMax;
    return m_asQueue[m_iLast++];
    
}

void CQueue::swap(CQueue& anderer)
{
    using std::swap;
    swap(*m_asQueue, *anderer.m_asQueue);
    swap(m_iCount, anderer.m_iCount);
    swap(m_iFirst, anderer.m_iFirst);
    swap(m_iLast, anderer.m_iLast);
    swap(m_iMax, anderer.m_iMax);
  
}
//Zuweisungsoperator
CQueue& CQueue::operator=(CQueue _cque)
{ 
    //Wenn Konstanten, Referenzen, dynamisch angaelegter Speicherbereich (In Klasse/Objekt)
    //vorkommen
    //Wenn noch kein bereits evtl. vorhandener Speicherbereich gelöscht werden soll
    cerr << "Zuweisung Zuweisung Zuweisungs Operator" << endl;
    swap(_cque);
    return *this;
    //wird aufgerufen, wenn Objekte bereits existierten
}

CQueue::CQueue(CQueue&& cque) : m_asQueue(m_asQueue), m_iMax(cque.m_iMax), m_iCount(cque.m_iCount), m_iFirst(cque.m_iFirst), m_iLast(cque.m_iFirst) {
    m_iMax = m_iCount = m_iFirst = m_iLast = 0;
    cque.m_asQueue = nullptr;
    cout << "Move Konstruktor" << endl;
//Unterschied zwischen Kopierkonstruktor & Movekonstruktor
    /*KK: Referenz auf L-Werte, Zwischenkopien, Kopiert das Ursprungsobjekt (nutzt neuen Speicherbereich), Keine Kenntnis über Destruktor, für neu erstelle Objekte; MK: Referenz auf R-Werte, keine Zwischenkopien, löst Verbindung des Speichers mit dem Ursprungsprunkt, Kenntnis über Destruktor, für bestehende Objekte */

    //Schritte: Alten Zeiger, dem neuen OBjekt übergeben
                // Alten zeiger auf nullptr setzen (damit Speicherbereich des neuen Obejektes/Zeigers nicht gelöscht wird ) 

  /*  m_iCount = _que.m_iCount;
    _que.m_asQueue = NULL;
    m_iFirst = _que.m_iFirst;
    _que.m_iFirst = NULL;
    m_iLast = _que.m_iLast;
    _que.m_iLast = NULL;
    m_iMax = _que.m_iMax;
    _que.m_iMax = NULL; */
}

CQueue getWinter() {
    //Standardkonstruktor wird aufgerufen, da nur eine normale CQueue erzeugt wird, anschließend werden noch die Werte zugeiwesen
    CQueue a;
    a.m_asQueue = new string[3]{ "Oktober", "November","Dezember" };
    a.m_iCount = 3;
    a.m_iFirst = 0;
    a.m_iLast = 2;
    a.m_iMax = 3;
    return a;
}

void CQueue::contents() {
    string* temp = m_asQueue;
    if (!temp) {
        cout << "Queue ist leer!" << endl;
        return;
    }
    
    int first = 0;
    string s = "Queue: \n";
    while (first < m_iLast) {
        s += to_string(first) + ": " + temp[first] + "\n";
        first++;
    }

    cout << s << endl;
}

bool CQueue::put(const string& name) {
    string* pointer = m_asQueue;
    if (m_iLast < m_iMax)
    {
            m_asQueue[m_iLast] = name;
            m_iLast++;
            return true;

    }
    
    return false;
    
}

int main() {
    //Kopierkonstruktor
    CQueue one;
    CQueue two = one;
    CQueue three(two);
    //Zuweisungsoperator
    CQueue x(5), y(5);
    y = x;
    
    CQueue test = getWinter();
    CQueue test2(4);
    test2.put("Markus");
    test2.put("Markus2");
    test2.put("Markus3");
    test2.put("Markus4");
    test2.contents();
        // test.contents();
        // one.contents();
    return 1;
}