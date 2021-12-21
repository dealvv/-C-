#include <iostream>
#include <cmath>
#include <set>
#include <map>
#include <vector>
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
    return { r1.Numerator() * r2.Numerator(), r1.Denominator() * r2.Denominator() };
}

Rational operator/ (const Rational& r1, const Rational& r2) {
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
    {
        const set<Rational> rs = { {1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2} };
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{ {1, 25}, { 1, 2 }, { 3, 4 }}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}