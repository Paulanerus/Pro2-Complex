#ifndef UEBUNG_3_COMPLEX_H
#define UEBUNG_3_COMPLEX_H

class Complex
{
private:
	double real;
	double imag;

public:
	Complex(double real, double imag);

	Complex operator+(const Complex& other);

	Complex operator+(const Complex& other) const;

	Complex operator*(const Complex& other);

	Complex operator*(const Complex& other) const;

	Complex operator*(int n);

	Complex operator*(int n) const;

	Complex operator+=(const Complex& other);

	Complex operator+=(const Complex& other) const;

	Complex operator/(const Complex& other);

	Complex operator/(const Complex& other) const;

	double real_part() const;

	double imag_part() const;
};

#endif
