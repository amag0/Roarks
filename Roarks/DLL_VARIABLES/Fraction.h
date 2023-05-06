#pragma once
#include <iostream>


class Fraction {
private:
    int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
    int n, d;

    void simplify(int new_n, int new_d) {
        int common_divisor = gcd(new_n, new_d);
        n = new_n / common_divisor;
        d = new_d / common_divisor;
    }

public:
    Fraction(int n = 0, int d = 1) { simplify(n, d); }
    int num() const { return n; }
    int den() const { return d; }

    Fraction& operator+=(const Fraction& rhs) {
        int new_d = d * rhs.d;
        int new_n = n * rhs.d + d * rhs.n;
        simplify(new_n, new_d);
        return *this;
    }

    Fraction& operator-=(const Fraction& rhs) {
        int new_d = d * rhs.d;
        int new_n = n * rhs.d - d * rhs.n;
        simplify(new_n, new_d);
        return *this;
    }

    Fraction& operator*=(const Fraction& rhs) {
        int new_n = n * rhs.n;
        int new_d = d * rhs.d;
        simplify(new_n, new_d);
        return *this;
    }

    Fraction& operator/=(const Fraction& rhs) {
        int new_n = n * rhs.d;
        int new_d = d * rhs.n;
        simplify(new_n, new_d);
        return *this;
    }
};

// Binary arithmetic operators
Fraction operator+(Fraction lhs, const Fraction& rhs) {
    lhs += rhs;
    return lhs;
}

Fraction operator-(Fraction lhs, const Fraction& rhs) {
    lhs -= rhs;
    return lhs;
}

Fraction operator*(Fraction lhs, const Fraction& rhs) {
    lhs *= rhs;
    return lhs;
}

Fraction operator/(Fraction lhs, const Fraction& rhs) {
    lhs /= rhs;
    return lhs;
}

// Relational operators
bool operator<(const Fraction& lhs, const Fraction& rhs) {
    return lhs.num() * rhs.den() < rhs.num() * lhs.den();
}

bool operator>(const Fraction& lhs, const Fraction& rhs) {
    return rhs < lhs;
}

bool operator<=(const Fraction& lhs, const Fraction& rhs) {
    return !(lhs > rhs);
}

bool operator>=(const Fraction& lhs, const Fraction& rhs) {
    return !(lhs < rhs);
}

bool operator==(const Fraction& lhs, const Fraction& rhs) {
    return lhs.num() == rhs.num() && lhs.den() == rhs.den();
}

bool operator!=(const Fraction& lhs, const Fraction& rhs) {
    return !(lhs == rhs);
}
