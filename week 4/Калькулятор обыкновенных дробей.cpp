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
        if (denominator == 0) throw invalid_argument("Invalid argument");
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
    return { r1.Numerator() * r2.Denominator() + r2.Numerator() * r1.Denominator(), r1.Denominator() * r2.Denominator() };
}

Rational operator- (const Rational& r1, const Rational& r2) {
    return { r1.Numerator() * r2.Denominator() - r2.Numerator() * r1.Denominator(), r1.Denominator() * r2.Denominator() };
}

Rational operator* (const Rational& r1, const Rational& r2) {
    return { r1.Numerator() * r2.Numerator(), r1.Denominator() * r2.Denominator() };
}

Rational operator/ (const Rational& r1, const Rational& r2) {
    if (r2.Numerator() == 0) throw domain_error("Division by zero");
    return { r1.Numerator() * r2.Denominator(), r1.Denominator() * r2.Numerator() };
}

bool operator< (const Rational& r1, const Rational& r2) {
    if (r1.Denominator() == r2.Denominator()) return r1.Numerator() < r2.Numerator();
    else return (r1.Numerator() * r2.Denominator() < r2.Numerator() * r1.Denominator());
}

istream& operator>> (istream& stream, Rational& r) {
    int num, den;
    char s;
    stream >> num >> s >> den;
    if (stream && s == '/') {
        Rational r1(num, den);
        r = r1;
    }
    return stream;
}

ostream& operator<< (ostream& stream, const Rational& r) {
    stream << r.Numerator();
    stream << "/";
    stream << r.Denominator();
    return stream;
}



int main() {
    Rational r1, r2;
    char s;
    try {
        cin >> r1 >> s >> r2;
        if (s == '+') cout << r1 + r2 << endl;
        else if (s == '-') cout << r1 - r2 << endl;
        else if (s == '*') cout << r1 * r2 << endl;
        else {
            try { cout << r1 / r2 << endl; }
            catch (domain_error& error) {
                cout << error.what() << endl;
            }
        }
    }
    catch (invalid_argument& argument) {
        cout << argument.what() << endl; 
    }
    return 0;
}