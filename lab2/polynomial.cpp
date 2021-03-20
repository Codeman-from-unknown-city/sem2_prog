#include "polynomial.h"

#include <algorithm>

Polynomial::Polynomial(coeffs coefficients): coefficients(std::move(coefficients))
{}

Polynomial::Polynomial() = default;
Polynomial::Polynomial(const Polynomial &other) = default;
Polynomial::~Polynomial() = default;

Polynomial& Polynomial::operator=(const Polynomial& other) {
    if (this != &other)
        coefficients = other.coefficients;
    return *this;
}

bool operator==(const Polynomial& p1, const Polynomial& p2) {
	return p1.coefficients == p2.coefficients;
}

bool operator!=(const Polynomial& p1, const Polynomial& p2) {
	return !(p1 == p2);
}

Polynomial operator-(Polynomial p) {
	for (auto& coefficient: p.coefficients)
        coefficient.second = -coefficient.second;
	return p;
}

void Polynomial::operator+=(const Polynomial& other) {
    for (auto other_coefficient: other.coefficients)
        coefficients[other_coefficient.first] += other_coefficient.second;
}

void Polynomial::operator-=(const Polynomial& other) {
    *this += (-other);
}

Polynomial Polynomial::operator+(const Polynomial& other) {
    Polynomial result(coefficients);
	result += other;
    return result;
}

Polynomial Polynomial::operator-(const Polynomial& other) {
	return *this + (-other);
}

std::istream &operator>>(std::istream &istream, Polynomial &p) {
    unsigned n_of_coefficients;
    istream >> n_of_coefficients;
    std::pair<unsigned, double> coefficient;
    while (n_of_coefficients--) {
        istream >> coefficient.first;
        istream >> coefficient.second;
        p.coefficients.emplace(coefficient);
    }
    return istream;
}

void Polynomial::print_coefficient(std::ostream& ostream, std::pair<unsigned, double> coefficient) {
    if (coefficient.second < 0) {
        ostream << '-';
        coefficient.second = -coefficient.second;
    } else {
        ostream << '+';
    }
    ostream << ' ' << coefficient.second << " * x^" << coefficient.first << ' ';
}

std::ostream &operator<<(std::ostream &ostream, const Polynomial &p) {
    auto iter = p.coefficients.begin();
    std::pair<unsigned, double> first_coefficient = *iter;
    ostream << first_coefficient.second << " * x^" << first_coefficient.first << ' ';
    for (++iter; iter != p.coefficients.end(); ++iter)
        Polynomial::print_coefficient(ostream, *iter);
    return ostream;
}

double Polynomial::operator[](unsigned int index) {
    return coefficients[index];
}

void Polynomial::operator*=(double num) {
    for (auto& coefficient : coefficients)
        coefficient.second *= num;
}

void Polynomial::operator*=(const Polynomial &other) {
    for (auto& coefficient: coefficients)
        for (auto other_coefficient: other.coefficients)
            coefficient.second *= other_coefficient.second;
}

Polynomial Polynomial::operator*(double num) {
    Polynomial p(coefficients);
    p *= num;
    return p;
}

Polynomial Polynomial::operator*(const Polynomial &other) {
    Polynomial p(coefficients);
    p *= other;
    return p;
}

void Polynomial::operator/=(double num) {
    if (num == 0)
        throw std::runtime_error("Dividing a polynomial by zero is prohibited");
    for (auto& coefficient: coefficients)
        coefficient.second /= num;
}

Polynomial Polynomial::operator/(double num) {
    Polynomial p(coefficients);
    p /= num;
    return p;
}
