#include <vector>
#include <iostream>
using namespace std;
enum ErrCode { OK, ADDERR, RMVERR };
//NICHT FERTIG GEMACHT
template <typename T> class Set;
template <typename T> bool operator&    (int, Set<T>&);  // Test auf Mitgliedschaft
template <typename T> bool operator==   (const Set<T>&, const Set<T>&);  // Gleichheit
template <typename T> bool operator!=   (const Set<T>&, const Set<T>&);  // Ungleichheit
template <typename T> Set<T>  operator*   (const Set<T>&, const Set<T>&);  // Schnitt
template <typename T> Set<T>  operator+   (const Set<T>&, const Set<T>&);  // Vereinigung
template <typename T> Set<T>  operator- (const Set<T>&, const Set<T>&);  // Mengenminus
template <typename T> bool operator<=   (const Set<T>&, const Set<T>&);  // Teilmenge
template <typename T> ostream& operator<< (ostream&, const Set<T>&);  // Ausgabe
template <typename T> istream& operator>> (istream&, Set<T>&);        // Eingabe eines Elements
template <typename T> ErrCode   AddElem(const T&);                 // Hinzufügen
template <typename T> ErrCode   RmvElem(const T&);                 // Herausnehmen

template<typename T>
class Set {
private:
	vector<T> elems;     // Elemente der Menge
	int       card;      // aktuelle Kardinalität

public:
	enum ErrCode { OK, ADDERR, RMVERR };
	Set(int size = 50) : card(0), elems<T>(50) {}
	Set(const Set<T>& anotherSet);
	~Set();
	Set<T>& operator=(Set<T> anotherSet);
	friend    bool operator&    <>(int, Set<T>&);  // Test auf Mitgliedschaft
	friend    bool operator==   <>(const Set<T>&, const Set<T>&);  // Gleichheit
	friend    bool operator!=   <>(const Set<T>&, const Set<T>&);  // Ungleichheit
	friend    Set  operator*    <>(const Set<T>&, const Set<T>&);  // Schnitt
	friend    Set  operator+    <>(const Set<T>&, const Set<T>&);  // Vereinigung
	friend    Set  operator-    <>(const Set<T>&, const Set<T>&);  // Mengenminus
	friend    bool operator<=   <>(const Set<T>&, const Set<T>&);  // Teilmenge
	friend    ostream& operator<< <>(ostream&, const Set<T>&);  // Ausgabe
	friend    istream& operator>> <>(istream&, Set<T>&);        // Eingabe eines Elements
	ErrCode   AddElem(const T&);                 // Hinzufügen
	ErrCode   RmvElem(const T&);                 // Herausnehmen
};
template<typename T> Set<T>::Set(const Set<T>& anotherSet) : card(anotherSet.card){
	copy(anotherSet.elems.begin(), anotherSet.elems.end(), back_inserter(elems));
}
template<typename T> Set<T>::~Set() {}


template <typename T> bool operator&    (int aInt, Set<T>& aSet) {
	for
	return true;
	return false;
}
	// Test auf Mitgliedschaft
template <typename T> bool operator==   (const Set<T>&, const Set<T>&);  // Gleichheit
template <typename T> bool operator!=   (const Set<T>&, const Set<T>&);  // Ungleichheit
template <typename T> Set<T>  operator*   (const Set<T>&, const Set<T>&);  // Schnitt
template <typename T> Set<T>  operator+   (const Set<T>&, const Set<T>&);  // Vereinigung
template <typename T> Set<T>  operator- (const Set<T>&, const Set<T>&);  // Mengenminus
template <typename T> bool operator<=   (const Set<T>&, const Set<T>&);  // Teilmenge
template <typename T> ostream& operator<< (ostream&, const Set<T>&);  // Ausgabe
template <typename T> istream& operator>> (istream&, Set<T>&);        // Eingabe eines Elements
template <typename T> ErrCode   AddElem(const T&);                 // Hinzufügen
template <typename T> ErrCode   RmvElem(const T&);                 // Herausnehmen