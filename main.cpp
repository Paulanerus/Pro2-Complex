#include <iostream>
#include "Complex.h"
#include "SimpleVektor.h"

std::ostream& operator<<(std::ostream& o, const Complex& c)
{
	o << c.real_part() << " + " << c.imag_part() << 'i';
	return o;
}

std::ostream& operator<<(std::ostream& o, const SimpleVektor& v)
{
	o << "V[" << v.size << "]: ";

	for (int i = 0; i < v.size; i++)
	{
		o << v.data[i] << (i == v.size - 1 ? "." : ", ");
	}

	return o;
}

Complex operator*(int n, const Complex& c)
{
	return { c.real_part() * n, c.imag_part() * 3 };
}

void test1(int len);

void complex_division();

int main()
{
	Complex c1(1, 0);
	Complex c2(0, 1);

	std::cout << "c1 = " << c1 << std::endl;
	std::cout << "c2 = " << c2 << std::endl;

	std::cout << "SUMME: " << c1 + c2 << std::endl;

	std::cout << "PRODUKT: " << c1 * c2 << std::endl;

	std::cout << "PRODUKT: " << 3 * c1 * c2 << std::endl;

	std::cout << "PRODUKT: " << c1 * 3 << std::endl;

	std::cout << "Summe in place: " << (c1 += c2) << std::endl;

	const Complex cc1(2, 0);
	const Complex cc2(0, 2);

	std::cout << "cc1 = " << cc1 << std::endl;

	std::cout << "cc2 = " << cc2 << std::endl;

	std::cout << "const SUMME: " << cc1 + cc2 << std::endl;

	std::cout << "const PRODUKT: " << cc1 * cc2 << std::endl;

	test1(20);

	complex_division();

	return 0;
}

void test1(int len)
{
	SimpleVektor v1(len);
	SimpleVektor v2(len);
	SimpleVektor v3(2 * len);

	std::cout << v1 << std::endl;
	std::cout << v2 << std::endl;
	std::cout << v3 << std::endl;

	v1 <<= 1;
	v2 <<= 2;
	v3 <<= 3;

	std::cout << v1 << std::endl;
	std::cout << v2 << std::endl;
	std::cout << v3 << std::endl;

	if (v1 < v3)
	{
		SimpleVektor v4 = v2;
		v4 += 5;
		std::cout << v4 << std::endl;
	}

	v1 = v2;

	std::cout << v1 << std::endl;
	std::cout << v2 << std::endl;
	std::cout << v3 << std::endl;
}

void complex_division()
{
	Complex c1(12, 45);

	Complex c2(123, 0);

	Complex c3(33, 5);

	std::cout << c1 / c2 << std::endl;
	std::cout << c2 / c3 << std::endl;
}

/*
 * Wann Zuweisungoperator und wann Kopierkonstruktor?
 *
 * Zuweisungoperator: Wird aufgerufen, wenn ein bereits erstelltes Objekt neu zugewiesen wird (v1 = v2).
 *
 * Kopierkonstruktor: Wenn ein neues Objekt erstellt wird und eine Zuweisung eines bereits erstellen Objekts erhält (SimpleVektor v4 = v2).
 */