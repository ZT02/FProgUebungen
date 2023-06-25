#pragma once
#include <cmath>
#define PI       3.14159265358979323846

class Figur
{
public:
    virtual double flaeche() const = 0;
    virtual double umfang() const = 0;
    virtual Figur* clone() = 0;
    virtual ~Figur();
};

// ----------------------------------------------------
class Kreis : public Figur
{
private:
    double radius;

public:
    Kreis(double _r) : radius(_r) {}
    Kreis(const Kreis& k) : radius(k.radius) {}

    ~Kreis() {}

    double flaeche() const {
        return radius * radius * PI;
    }

    double umfang() const {
        return 2.0 * radius * PI;
    }

    Figur* clone() {
        Figur* f = new Kreis(*this);
        return f;
    }
};

// ----------------------------------------------------
class Rechteck : public Figur
{
private:
    double b, h;

public:
    Rechteck(double _breite, double _hoehe) :
        b(_breite), h(_hoehe) {}
    Rechteck(const Rechteck& r) : b(r.b), h(r.h) {}
    ~Rechteck() {}

    double flaeche() const {
        return b * h;
    }

    double umfang() const {
        return 2 * (b + h);
    }

    Figur* clone() {
        Figur* f = new Rechteck(*this);
        return f;
    }
};

// ----------------------------------------------------
class Dreieck : public Figur
{
private:
    double a, b, c;

public:
    Dreieck(double _a, double _b, double _c) :
        a(_a), b(_b), c(_c) {}
    Dreieck(const Dreieck& d) : a(d.a), b(d.b), c(d.c) {}
    ~Dreieck() {}

    double flaeche() const {
        double s = umfang() / 2.0;
        return std::sqrt(s * (s - a) * (s - b) * (s - c));
    }

    double umfang() const {
        return (a + b + c);
    }

    Figur* clone() {
        Figur* f = new Dreieck(*this);
        return f;
    }
};

