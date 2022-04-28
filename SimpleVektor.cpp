#include "SimpleVektor.h"
#include <iostream>

SimpleVektor::SimpleVektor(int nlen)
{
	this->size = nlen;

	this->data = new int[nlen];

	for (int i = 0; i < nlen; i++)
	{
		this->data[i] = 0;
	}
}

SimpleVektor::~SimpleVektor()
{
	delete[] this->data;
}

void SimpleVektor::operator<<=(int nval)
{
	if (this->data == nullptr)
	{
		return;
	}

	for (int i = 0; i < this->size; i++)
	{
		this->data[i] = nval;
	}
}

void SimpleVektor::operator+=(int nval)
{
	if (this->data == nullptr)
	{
		return;
	}

	for (int i = 0; i < this->size; i++)
	{
		this->data[i] += nval;
	}
}

bool SimpleVektor::operator<(const SimpleVektor& v)
{
	return this->size < v.size;
}

SimpleVektor::SimpleVektor(const SimpleVektor& v)
{
	this->size = v.size;

	if (this->data == nullptr)
	{
		this->data = new int[this->size];
	}

	for (int i = 0; i < this->size; i++)
	{
		this->data[i] = v.data[i];
	}
}

SimpleVektor& SimpleVektor::operator=(const SimpleVektor& v)
{
	this->size = v.size;

	if (this->data == nullptr)
	{
		this->data = new int[this->size];
	}

	for (int i = 0; i < this->size; i++)
	{
		this->data[i] = v.data[i];
	}

	return *this;
}
