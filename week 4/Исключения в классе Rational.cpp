#include <iostream>
#include <cmath>
#include <exception>
using namespace std;

class Rational {
public:
    Rational() {
        num = 0;
        den = 1;
    }

    Rational(const int& numerator, const int& denominator) {
        if (denominator == 0) throw invalid_argument("");
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

Rational operator/ (const Rational& r1, const Rational& r2) {
    if (r2.Numerator() == 0) throw domain_error("");
    return { r1.Numerator() * r2.Denominator(), r1.Denominator() * r2.Numerator() };
}



int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    }
    catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    }
    catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}