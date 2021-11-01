#pragma once

#include <iostream>

class Fraction
{
private:
    int _numer;
    int _denum;

    static int gcd(int a, int b);

public:
    Fraction();
    Fraction(int numer, int denum);

    void operator=(Fraction b)
    {
        _numer = b._numer;
        _denum = b._denum;
    }

    void shorten();

    Fraction operator+(Fraction second);
    Fraction operator-(Fraction second);
    Fraction operator*(Fraction second);
    Fraction operator/(Fraction second);

    Fraction operator+(int second);
    Fraction operator-(int second);
    Fraction operator*(int second);
    Fraction operator/(int second);
    Fraction pow(int pow);

    bool operator<(Fraction second);
    bool operator<=(Fraction second);
    bool operator>(Fraction second);
    bool operator>=(Fraction second);
    bool operator==(Fraction second);
    bool operator!=(Fraction second);

    friend std::ostream &operator<<(std::ostream &stream, Fraction fr);
    // template <typename T>
    // Fraction &operator<<(T &stream)
    // {
    //     stream << this->numer << '/' << this->denum;
    //     return stream;
    // }
};
