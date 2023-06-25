#include <iostream>
using namespace std;

template <typename T>
class Ptr
{
    T* value;
    T dummy;
public:
    Ptr() : value(nullptr) { std::cout << "Ptr::Ptr\n"; }
    Ptr(const T& v) : value(new T(v)) {
        std::cout << "Ptr::Ptr()\n";
    }
    Ptr(const Ptr<T>& p);
    ~Ptr() { std::cout << "Ptr::~Ptr\n"; delete value; }
    Ptr<T>& operator= (Ptr<T> p);
    const T& getValue() const { return value ? *value : nullptr); }
    T* operator->() const;
    T& operator*() const;
    operator bool() const {
        return value != nullptr;
    }

    void swap(Ptr& anderer);
};

template <typename T> Ptr<T>::Ptr(const Ptr<T>& p) {
    Ptr vale = p.getValue();
    *value = vale;
  }

template <typename T> void Ptr<T>::swap(Ptr& anderer) {
    using std::swap;
    swap(value, anderer.value);
}

template <typename T> T* Ptr<T>::operator->() const {
    return *value;
}

template <typename T> T& Ptr<T>::operator*() const {
    return value ? *value : nullptr;
}



template <typename T> Ptr<T>& Ptr<T>::operator=(Ptr<T> p) {
    swap(p);
    return *this;
}
Ptr<int> pglob(42);
int main() {
    Ptr<int> p1(2);        // Konstruktor mit Wert
    Ptr<int> p2 = p1;      // Kopierkonstruktor
    p2 = pglob;            // Copy, Zuwei, Destr
    

  

    return 0;
}