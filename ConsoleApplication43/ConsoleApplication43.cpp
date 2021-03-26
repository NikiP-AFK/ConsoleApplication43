#include <iostream>
#include <cmath>
using namespace std;
// class for working with rational fractions 
class Rational {
public: // designer
    Rational() :a(0), b(1) {}
    Rational(const long int& number) : a(number), b(1) {}
    Rational(const long int& a, const long int& b)
        : a(a), b(b) {}
    const long int& geta() const { return a; }
    const long int& getB() const { return b; }
    Rational  getRational() const {
        long int gcd = getGCD(geta(), getB());
        long int a = geta() / gcd;
        long int b = getB() / gcd;
        if (b < 0) {
            a = -a;
            b = -b;
        }
        return Rational(a, b);
    }
    static long int getGCD(const long int& a, const long int& b) {
        long int x = abs(a);
        long int y = abs(b);
        while (1) {
            x = x % y;
            if (x == 0) {
                return y;
            }
            y = y % x;
            if (y == 0) {
                return x;
            }
        }
    }
private:
    const long int a;
    const long int b;
};

Rational operator+(const Rational& a, const Rational& b) {
    //operator add

    return Rational(a.geta() * b.getB() +
        b.geta() * a.getB(),
        a.getB() * b.getB());
}

Rational operator-(const Rational& a, const Rational& b) {
    //operator sub
    return Rational(a.geta() * b.getB() -
        b.geta() * a.getB(),
        a.getB() * b.getB());
}

Rational operator-(const Rational& f) {
    return Rational(-f.geta(), f.getB());
}

Rational operator*(const Rational& a, const Rational& b) {
    //operator mul
    return Rational(a.geta() * b.geta(),
        a.getB() * b.getB());
}

Rational operator/(const Rational& a, const Rational& b) {
    //operator div
    return Rational(a.geta() * b.getB(),
        a.getB() * b.geta());
}

ostream& operator<<(ostream& stream, const Rational& fraction) {
    //fraction reduction function reduce
    Rational reduced = fraction.getRational();
    return stream << reduced.geta() << "/" << reduced.getB();
}

long compare(const Rational& a, const Rational& b)
{ //operator comparison
    return a.geta() * b.getB() -
        b.geta() * a.getB();
}

bool operator==(const Rational& a, const Rational& b) {
    return compare(a, b) == 0;
}

bool operator!=(const Rational& a, const Rational& b) {
    return compare(a, b) != 0;
}

bool operator>(const Rational& a, const Rational& b) {
    return compare(a, b) > 0;
}

bool operator<(const Rational& a, const Rational& b) {
    return compare(a, b) < 0;
}

bool operator>=(const Rational& a, const Rational& b) {
    return compare(a, b) >= 0;
}

bool operator<=(const Rational& a, const Rational& b) {
    return compare(a, b) <= 0;
}
//conclusion
int main(int, char**) {
    cout << (Rational(3, 5) + Rational(6, 8)) << endl;
    cout << (Rational(3, 5) - Rational(6, 8)) << endl;
    cout << (Rational(3, 5) * Rational(6, 8)) << endl;
    cout << (Rational(3, 5) / Rational(6, 8)) << endl;
    cout << (Rational(3, 5) > Rational(6, 8)) << endl;
    cout << (Rational(3, 5) < Rational(6, 9)) << endl;
    cout << (Rational(3, 5) == Rational(6, 8)) << endl;
    return 0;
}