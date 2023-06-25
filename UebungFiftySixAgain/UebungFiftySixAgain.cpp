#include <iostream>
#include <vector>
using namespace std;

template<typename T>    bool operator&    (int, Set<T>&);  // Test auf Mitgliedschaft
template<typename T>    bool operator==   (const Set<T>&, const Set<T>&);  // Gleichheit
template<typename T>   bool operator!=   (const Set<T>&, const Set<T>&);  // Ungleichheit
template<typename T>   Set<T>  operator*    (const Set<T>&, const Set<T>&);  // Schnitt
template<typename T>  Set<T>  operator+    (const Set<T>&, const Set<T>&);  // Vereinigung
template<typename T>   Set<T>  operator-    (const Set<T>&, const Set<T>&);  // Mengenminus
template<typename T>  bool operator<=   (const Set<T>&, const Set<T>&);  // Teilmenge
template<typename T>   ostream& operator<< (ostream&, const Set<T>&);  // Ausgabe
template<typename T>   istream& operator>> (istream&, Set<T>&);        // Eingabe eines Elements

template<typename T>
class Set {
public:
	vector<T> elems;     // Elemente der Menge
	int       card;      // aktuelle Kardinalität

public:
	enum ErrCode { OK, ADDERR, RMVERR };
	Set(int size = 50) : card(size), elems(vector<T>(size)) {}
	Set(const Set<T>& anotherSet) : card(anotherSet.card){
		elems = vector<T>(card);
		for (auto temp : anotherSet.elems)
			elems.push_back(temp);
	}
	~Set() {}
	Set<T>& operator=(Set<T> anotherSet);
	friend    bool operator&    <>(int, Set<T>&);  // Test auf Mitgliedschaft
	friend    bool operator==   <>(const Set<T>&, const Set<T>&);  // Gleichheit
	friend    bool operator!=  <>(const Set<T>&, const Set<T>&);  // Ungleichheit
	friend    Set  operator*   <>(const Set<T>&, const Set<T>&);  // Schnitt
	friend    Set  operator+    <>(const Set<T>&, const Set<T>&);  // Vereinigung
	friend    Set  operator-    <>(const Set<T>&, const Set<T>&);  // Mengenminus
	friend    bool operator<=   <>(const Set<T>&, const Set<T>&);  // Teilmenge
	friend    ostream& operator<< (ostream&, const Set<T>&);  // Ausgabe
	friend    istream& operator>> (istream&, Set<T>&);        // Eingabe eines Elements
	ErrCode   AddElem(const T&);                 // Hinzufügen
	ErrCode   RmvElem(const T&);                 // Herausnehmen
};

template<typename T>
Set<T>& Set<T>::operator=(Set<T> anotherSet) {
	std::swap(card, anotherSet.card);
	std::swap(elems, anotherSet.elems);
}
template<typename T>// Test auf Mitgliedschaft
bool operator& (T el, Set<T>& a) {
	auto iter = find(a.elems.begin(), a.elems.end(), el);
	return iter != a.elems.end();
}
		
	template<typename T>
    bool operator==   (const Set<T>& a, const Set<T>& b) {
		if (a.card != b.card) {
			return false;
	}

		for (unsigned i = 0; i < card; i++) {
			if (a.elems[i] != b.elems[i])
				return false;
		}
		return true;

	}  // Gleichheit
	template<typename T>
    bool operator!=   (const Set<T>&, const Set<T>&) {
		if (a.card != b.card) {
			return true;
		}

		for (unsigned i = 0; i < card; i++) {
			if (a.elems[i] != b.elems[i])
				return true;
		}
		return false;
	}  // Ungleichheit
	template<typename T>
    Set<T>  operator*    (const Set<T>& a, const Set<T>& b) {
		Set<T> result(a.card > b.card ? a.card : b.card);
		auto iter = a.elems.begin();
		iter = a.elems.begin();
		while (iter != a.elems.end()) {
			if (*iter & b)
				result.elems.push_back(new T(*iter));
			
			iter++;
		}
		return result;
	}  // Schnitt
	template<typename T>
    Set<T>  operator+    (const Set<T>&, const Set<T>&) {}  // Vereinigung
	template<typename T>
    Set<T>  operator-    (const Set<T>&, const Set<T>&) {}  // Mengenminus
	template<typename T>
    bool operator<=   (const Set<T>&, const Set<T>&) {}  // Teilmenge
	template<typename T>
    ostream& operator<< (ostream&, const Set<T>&) {}  // Ausgabe
	template<typename T>
    istream& operator>> (istream&, Set<T>&) {}        // Eingabe eines Elements