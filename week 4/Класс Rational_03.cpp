#include <iostream>
#include <cmath>
using namespace std;

class Rational {
public:
    Rational() {
        num = 0;
        den = 1;
    }

    Rational(const int& numerator, const int& denominator) {
        num = numerator;
        if (num == 0) den = 1;
        else {
            den = denominator;
            int GCD = gcd(abs(num), abs(den));
            if (den < 0) {
                num /= -GCD;
                den /= -GCD;
            }
            else {
                num /= GCD;
                den /= GCD;
            }
        }
    }
    int Numerator() const {
        return num;
    }

    int Denominator() const {
        return den;
    }

private:
    int num, den;
    int gcd(int A, int B) {
        while (A > 0 && B > 0) {
            if (A > B) A %= B;
            else B %= A;
        }
        return A + B;
    }
};

bool operator== (const Rational& r1, const Rational& r2) {
    return (r1.Numerator() == r2.Numerator() && r1.Denominator() == r2.Denominator());
}

Rational operator+ (const Rational& r1, const Rational& r2) {
    return { r1.Numerator() * r2.Denominator() + r2.Numerator() * r1.Denominator(), r1.Denominator()* r2.Denominator() };
}

Rational operator- (const Rational& r1, const Rational& r2) {
    return { r1.Numerator() * r2.Denominator() - r2.Numerator() * r1.Denominator(), r1.Denominator() * r2.Denominator() };
}

Rational operator* (const Rational& r1, const Rational& r2) {
    return { r1.Numerator() * r2.Numerator(), r1.Denominator() * r2.Denominator()};
}

Rational operator/ (const Rational& r1, const Rational& r2) {
    return { r1.Numerator() * r2.Denominator(), r1.Denominator() * r2.Numerator()};
}



int main() {
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}