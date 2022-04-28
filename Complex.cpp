#include "Complex.h"

Complex::Complex(double re, double im)
{
	this->real = re;
	this->imag = im;
}

Complex Complex::operator+(const Complex& other)
{
	return { this->real + other.real, this->imag + other.imag };
}

Complex Complex::operator+(const Complex& other) const
{
	return { this->real + other.real, this->imag + other.imag };
}

Complex Complex::operator*(const Complex& other)
{
	return { this->real * other.real - this->imag * other.imag, this->real * other.imag + this->imag * other.real };
}

Complex Complex::operator*(const Complex& other) const
{
	return { this->real * other.real - this->imag * other.imag, this->real * other.imag + this->imag * other.real };
}

Complex Complex::operator*(int n)
{
	return { this->real * n, this->imag * n };
}

Complex Complex::operator*(int n) const
{
	return { this->real * n, this->imag * n };
}

Complex Complex::operator+=(const Complex& other)
{
	return { this->real + other.real, this->imag + other.imag };
}

Complex Complex::operator+=(const Complex& other) const
{
	return { this->real + other.real, this->imag + other.imag };
}

double Complex::real_part() const
{
	return this->real;
}

double Complex::imag_part() const
{
	return this->imag;
}

Complex Complex::operator/(const Complex& other)
{
	return { 0, 0 };
}

Complex Complex::operator/(const Complex& other) const
{
	return { 0, 0 };
}