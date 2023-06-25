
#include <iostream>
using namespace std;

class Rational
{
private:
    long zaehler, nenner;
    long ggT(long a, long b);

public:
    Rational()
    {
        cout << "Standardkonstruktor" << endl;
        set(0, 1);
    }
    Rational(int i) {
        zaehler = i;
        nenner = 1;
    }
    Rational(long gz) // für Ganzzahlen
    {
        cout << "Konstruktor " << gz << endl;
        set(gz, 1);
    }

    Rational(long z, long n)
    {
        cout << "Konstruktor (" << z << "/" << n << ")" << endl;
        set(z, n);
    }

    Rational(const Rational& r)  // Kopierkonstruktor
    {
        cout << "Kopierkonstruktor ";
        r.ausgabe();
        cout << endl;
        set(r.zaehler, r.nenner);
    }
    /*
      Rational(Rational&& r)  // Movekonstruktor
      {
          cout << "Movekonstruktor ";
          r.ausgabe();
          cout << endl;
          set(r.zaehler, r.nenner);
      }
      */

    void swap(Rational& r)
    {
        std::swap(r.zaehler, zaehler);
        std::swap(r.nenner, nenner);
    }

   //Typumwandlungsoperator
    operator double() {
        return ((double)zaehler / nenner);
    }
    void set(long z, long n);

    friend Rational operator+(const Rational& a, const Rational& b);
    friend Rational operator-(const Rational& a, const Rational& b);
    friend Rational operator*(const Rational& a, const Rational& b);
    friend Rational operator/(const Rational& a, const Rational& b);
    friend bool operator==(const Rational& a, const Rational& b);
    friend bool operator!=(const Rational& a, const Rational& b);
    friend ostream& operator<<(ostream& o, const Rational& rat);
    Rational& operator++() {
       zaehler = zaehler+nenner;
       Rational temp(zaehler, nenner);
       return temp;
     }
    Rational operator++(int i) {
        zaehler = zaehler + nenner * i;
        Rational temp(zaehler, nenner);
        return temp;
     }
    
    void kehrwert()
    {
        long t = zaehler; zaehler = nenner; nenner = t;
    }

    void kuerzen();
    void ausgabe(ostream& o = cout) const
    {
        o << "(" << zaehler << "/" << nenner << ")";
    }

    
};
bool operator==(const Rational& a, const Rational& b) {
    return a.nenner / a.zaehler == b.nenner / b.zaehler;
}

bool operator!=(const Rational& a, const Rational& b) {
    return a.nenner / a.zaehler != b.nenner / b.zaehler;
}

ostream& operator<<(ostream& o, const Rational& rat) {
    return o << "zaehler: " << rat.zaehler << "\n" << "nenner: " << rat.nenner<<endl;
}

//-----------------------------------------------------------------------------------
inline void Rational::set(long z, long n)
{
    if (n)
    {
        zaehler = z;
        nenner = n;
    }
    else
    {
        zaehler = 0;
        nenner = 1;
    }

    kuerzen();
}

//-----------------------------------------------------------------------------------
long Rational::ggT(long x, long y)
{
    while (y)
    {
        long r = x % y;
        x = y;
        y = r;
    }
    return (x);
}

//-----------------------------------------------------------------------------------
void Rational::kuerzen()
{
    int sign = 1;

    if (zaehler < 0)
    {
        sign *= (-1);
        zaehler *= (-1);
    }

    if (nenner < 0)
    {
        sign *= (-1);
        nenner *= (-1);
    }

    long t = ggT(zaehler, nenner);

    if (t)
    {
        zaehler = sign * zaehler / t;
        nenner = nenner / t;
    }
}

//-----------------------------------------------------------------------------------
Rational operator+(const Rational& a, const Rational& b)
{
    Rational temp;
    temp.set(a.zaehler * b.nenner + b.zaehler * a.nenner, a.nenner * b.nenner);
    return temp;
}

//-----------------------------------------------------------------------------------
Rational operator-(const Rational& a, const Rational& b)
{
    return Rational(a.zaehler * b.nenner - b.zaehler * a.nenner, a.nenner * b.nenner);
}

//-----------------------------------------------------------------------------------
Rational operator*(const Rational& a, const Rational& b)
{
    Rational temp;
    temp.set(a.zaehler * b.zaehler, a.nenner * b.nenner);
    return temp;
}

//-----------------------------------------------------------------------------------
Rational operator/(const Rational& a, const Rational& b)
{
    Rational temp;
    temp.set(a.zaehler * b.nenner, a.nenner * b.zaehler);
    return temp;
}

//-----------------------------------------------------------------------------------
int main(void)
{
    Rational  a(3, 4), b;

    b.set(2, 5);
    cout << "b: " << static_cast<double>(b) << endl;

    //   Rational c = a + b;
    Rational c = a+b;
    a.ausgabe(); cout << " + "; b.ausgabe(); cout << " = "; c.ausgabe();
    cout << endl;

    c = (Rational)3 - b;
    cout << "3 - " << b << " = " << c << "(" << static_cast<double>(c) << ")";
    cout << endl;

    c = a*b;
    a.ausgabe(); cout << " * "; b.ausgabe(); cout << " = "; c.ausgabe();
    cout << endl;

    c = a/b;
    a.ausgabe(); cout << " / "; b.ausgabe(); cout << " = "; c.ausgabe();
    cout << endl;

    system("pause");
    return 0;
}
