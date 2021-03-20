#pragma once

#include <iostream>
#include <unordered_map>

class Polynomial {
    using coeffs = std::unordered_map<unsigned, double>;

  public:
	explicit Polynomial(coeffs coefficients);
	Polynomial();
	Polynomial(const Polynomial& other);
	~Polynomial();

	
	friend bool operator==(const Polynomial& p1, const Polynomial& p2);
	friend bool operator!=(const Polynomial& p1, const Polynomial& p2);
	friend Polynomial operator-(Polynomial p);
    friend std::istream& operator>>(std::istream& istream, Polynomial& p);
    friend std::ostream& operator<<(std::ostream& ostream, const Polynomial& p);
	Polynomial& operator=(const Polynomial& other);
	Polynomial operator+(const Polynomial& other);
	Polynomial operator-(const Polynomial& other);
	Polynomial operator*(double num);
	Polynomial operator*(const Polynomial& other);
	Polynomial operator/(double num);
	void operator*=(double num);
	void operator*=(const Polynomial& other);
	void operator/=(double num);
	void operator+=(const Polynomial& other);
	void operator-=(const Polynomial& other);
	double operator[](unsigned index);

  private:
	coeffs coefficients;
	static void print_coefficient(std::ostream &ostream, std::pair<unsigned, double> coefficient);
};

bool operator==(const Polynomial& p1, const Polynomial& p2);
bool operator!=(const Polynomial& p1, const Polynomial& p2);
Polynomial operator-(Polynomial& p);
std::istream& operator>>(std::istream& istream, Polynomial& p);
std::ostream& operator<<(std::ostream& ostream, const Polynomial& p);
