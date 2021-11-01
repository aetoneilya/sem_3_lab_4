#include "Fraction.hpp"
#include "Error.hpp"

Fraction::Fraction()
{
    _numer = 0;
    _denum = 1;
}

Fraction::Fraction(int numer, int denum)
{
    try
    {
        if (denum == 0)
            throw MathException("division by zero", numer, denum, '/');
    }
    catch (MathException &exception)
    {
        std::cerr << "ERROR: (" << exception.what() << ")\n";
        _numer = 0;
        _denum = 1;
        return;
    }

    _numer = numer;
    _denum = denum;

    if (denum < 0)
    {
        _denum = -_denum;
        _numer = -_numer;
    }

    if (numer != 0)
    {
        shorten();
    }
    else
    {
        _denum = 1;
    }
}

void Fraction::shorten()
{
    int divider = gcd(_numer, _denum);
    _numer = _numer / divider;
    _denum = _denum / divider;
}

int Fraction::gcd(int a, int b)
{
    a = abs(a);
    b = abs(b);

    while (a != b)
    {
        if (a > b)
        {
            a -= b;
        }
        else
        {
            b -= a;
        }
    }
    return a;
}

std::ostream &operator<<(std::ostream &stream, Fraction fr)
{
    stream << fr._numer << '/' << fr._denum;
    return stream;
};

Fraction Fraction::operator+(Fraction second)
{
    int resNumer = _numer * second._denum + second._numer * _denum;
    int resDenum = _denum * second._denum;
    Fraction result(resNumer, resDenum);
    return result;
}

Fraction Fraction::operator-(Fraction second)
{
    int resNumer = _numer * second._denum - second._numer * _denum;
    int resDenum = _denum * second._denum;
    Fraction result(resNumer, resDenum);
    return result;
}

Fraction Fraction::operator*(Fraction second)
{
    int resNumer = _numer * second._numer;
    int resDenum = _denum * second._denum;
    Fraction result(resNumer, resDenum);
    return result;
}

Fraction Fraction::operator/(Fraction second)
{
    int resNumer = _numer * second._denum;
    int resDenum = _denum * second._numer;
    Fraction result(resNumer, resDenum);
    return result;
}

Fraction Fraction::operator+(int second)
{
    int resNumer = _numer + second * _denum;
    int resDenum = _denum;
    Fraction result(resNumer, resDenum);
    return result;
}

Fraction Fraction::operator-(int second)
{
    int resNumer = _numer - second * _denum;
    int resDenum = _denum;
    Fraction result(resNumer, resDenum);
    return result;
}

Fraction Fraction::operator*(int second)
{
    int resNumer = _numer * second;
    int resDenum = _denum;
    Fraction result(resNumer, resDenum);
    return result;
}

Fraction Fraction::operator/(int second)
{
    int resNumer = _numer;
    int resDenum = _denum * second;
    Fraction result(resNumer, resDenum);
    return result;
}

Fraction Fraction::pow(int pow)
{
    int resNumer = _numer;
    int resDenum = _denum;

    if (pow > 0)
    {
        for (int i = 0; i < pow; i++)
        {
            resNumer *= resNumer;
            resDenum *= resDenum;
        }
    }
    else if (pow == 0)
    {
        resNumer = 1;
        resDenum = 1;
    }
    else if (pow < 0)
    {
        for (int i = 0; i < pow; i++)
        {
            resNumer *= resNumer;
            resDenum *= resDenum;
        }

        int tmp = resNumer;
        resNumer = resDenum;
        resDenum = tmp;
    }

    Fraction result(resNumer, resDenum);
    return result;
}

bool Fraction::operator<(Fraction second)
{
    int left = _numer * second._denum;
    int right = second._numer * _denum;

    return left < right;
}

bool Fraction::operator<=(Fraction second)
{
    int left = _numer * second._denum;
    int right = second._numer * _denum;

    return left <= right;
}

bool Fraction::operator>(Fraction second)
{
    int left = _numer * second._denum;
    int right = second._numer * _denum;

    return left > right;
}

bool Fraction::operator>=(Fraction second)
{
    int left = _numer * second._denum;
    int right = second._numer * _denum;

    return left >= right;
}

bool Fraction::operator==(Fraction second)
{
    int left = _numer * second._denum;
    int right = second._numer * _denum;

    return left == right;
}

bool Fraction::operator!=(Fraction second)
{
    int left = _numer * second._denum;
    int right = second._numer * _denum;

    return left == right;
}