#include "Complex.h"
#include "CException.h"
#include <cassert>
#include <cmath>

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
	//assert(other.real != 0 && other.imag != 0);


	if (other.real == 0 || other.imag == 0)
	{
		throw Complex_ExcDivByZero();
	}

	if ((sqrt(pow(this->real, 2) + pow(this->imag, 2)) / sqrt(pow(other.real, 2) + pow(other.imag, 2))) > 1024)
	{
		throw Complex_ExcDivByNumeric();
	}

	return { (this->real * other.real + this->imag * other.imag) / (other.real * other.real + other.imag * other.imag),
			 (this->imag * other.real - this->real * other.imag) /
			 (other.real * other.real + other.imag * other.imag) };
}

Complex Complex::operator/(const Complex& other) const
{
	//assert(other.real != 0 && other.imag != 0);


	if (other.real == 0 || other.imag == 0)
	{
		throw Complex_ExcDivByZero();
	}

	if ((sqrt(pow(this->real, 2) + pow(this->imag, 2)) / sqrt(pow(other.real, 2) + pow(other.imag, 2))) > 1024)
	{
		throw Complex_ExcDivByNumeric();
	}

	return { (this->real * other.real + this->imag * other.imag) / (other.real * other.real + other.imag * other.imag),
			 (this->imag * other.real - this->real * other.imag) /
			 (other.real * other.real + other.imag * other.imag) };
}

std::ostream& operator<<(std::ostream& o, const Complex& c)
{
	o << c.real_part() << " + " << c.imag_part() << 'i';
	return o;
}
