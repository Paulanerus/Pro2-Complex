#ifndef UEBUNG_3_CEXCEPTION_H
#define UEBUNG_3_CEXCEPTION_H

#include <exception>
#include <iostream>
#include "Complex.h"

class CException : public std::exception
{
public:
	virtual void print(const Complex& c1, const Complex& c2) = 0;
};

class Complex_ExcDivByZero : public CException
{

public:
	void print(const Complex& c1, const Complex& c2) override
	{
		std::cout << "Division durch 0 ist verboten! " << c1 << " / " << c2 << std::endl;
	}
};

class Complex_ExcDivByNumeric : public CException
{

public:
	void print(const Complex& c1, const Complex& c2) override
	{
		std::cout << "|" << c1 << "| / |" << c2 << "| > 1024 und dies ist illegal!" << std::endl;
	}
};

#endif
