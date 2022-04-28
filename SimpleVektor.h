#ifndef UEBUNG_3_SIMPLEVEKTOR_H
#define UEBUNG_3_SIMPLEVEKTOR_H

class SimpleVektor
{
public:
	int size;

	int* data = nullptr;

	SimpleVektor(int nlen = 1);

	SimpleVektor(const SimpleVektor& v);

	~SimpleVektor();

	void operator<<=(int nval);

	void operator+=(int nval);

	bool operator<(const SimpleVektor& v);

	SimpleVektor& operator=(const SimpleVektor& v);
};

#endif
