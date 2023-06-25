#include <iostream>
using namespace std;
template <typename T>
class Ptr
{
    T* value;

public:
    Ptr() : value(nullptr) { std::cout << "Ptr::Ptr\n"; }
    Ptr(const T& v) : value(new T(v)) {
        std::cout << "Ptr::Ptr()\n";
    }
    Ptr(const Ptr<T>& p);
    ~Ptr() { std::cout << "Ptr::~Ptr\n"; delete value; }
    Ptr<T>& operator= (Ptr<T> p);
    const T getValue() const { return *value; }
    T* operator->() const;
    T& operator*() const;
    operator bool() const;
    operator const T* ();
};

template<typename T>
Ptr<T>::operator const T* () {
    return const value;
}

template<typename T>
Ptr<T>::Ptr(const Ptr<T>& p) : value(nullptr){
    if(p)
        value = new T{p->value}
}

template<typename T>
Ptr<T>& Ptr<T>:: operator=(Ptr<T> p) {
    std::swap(value, p.value);
    return *this;
}

template<typename T>
T* Ptr<T>::operator->() const {
    return value;
}
template<typename T>
T& Ptr<T>::operator*() const {

}

template<typename T>
Ptr<T>::operator bool() const {
    return value != nullptr;
}

int main()                 // Konstruktor pglob(42);
{
    Ptr<int> p1(2);        // Konstruktor mit Wert
    Ptr<int> p2 = p1;      // Kopierkonstruktor
    p2 = pglob;            // Copy, Zuwei, Destr
    p1 = myfunc(pglob);    // Zuweisungsoperator

    cout << "p1 nach int: " << *static_cast<int*>(p1) << endl;
    p2++;
    cout << "p2 nach int:" << *p2 << endl;

    return 0;
}