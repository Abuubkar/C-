#include "numPy512.h"
#include <cmath>
#include <iostream>
using namespace std;



numPy512::numPy512()
{
	this->a = new int*[512];
	for (int i = 0; i < 512; i++)
	{
		this->a[i] = new int[512];
		for (int j = 0; j < 512; j++)
		{
			this->a[i][j] = 0;
		}
	}
}

int** numPy512::unpackbit(long double *p, int dim)
{
	clear();
	if (dim < 0)
		dim = 1;

	this->dim = dim;
	for (int i = 0; i < dim; i++)
	{
		unpack = new int[dim];
		this->unpack = this->binary(p[i]);
		for (int j = 0; j < 512; j++)
		{
			this->a[i][j] = this->unpack[j];
		}
	}

	return a;
}

long double* numPy512::packbit(int ** p, int length, int dim)
{
	clear();
	long double  power;

	b = new long double[dim];
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < length; j++)
		{
			a[i][j] = p[i][j];

		}
	}	
	for (int i = 0; i < dim; i++)
	{
		b[i] = 0; power = 1;

		for (int j = 511; j >= 0; j--)
		{
			b[i] += abs(a[i][j] * power);
			power *= 2;

		}

	}
	return b;
}
int* numPy512::binary(long double num)
{
	int temp[512];
	for (int i = 0; i < 512; i++)
	{
		temp[i] = 0;
	}
	long double rem, quotient = num, binary = 0, i = 1;
	int count = 0;
	while (quotient > 0)
	{

		rem = fmod(quotient, 2);
		quotient = quotient / 2;
		quotient = floor(quotient);
		temp[count] = rem;
		count++;


	}
	count--;
	int temloc = 0; int tem, tempindex = count - 1;;
	while (count > tempindex / 2)
	{
		tem = temp[temloc];
		temp[temloc] = temp[count];
		temp[count] = tem;
		temloc++;
		count--;
	}


	return temp;

}

int numPy512::digitcount(long double x)
{
	int size = 0;
	while (x >= 1)
	{
		x = x / 10;
		size++;
	}
	return size;
}

void numPy512::printunpackbit(int l)
{
	if (l < 0 || l > dim)
		l = 1;

	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < 512; j++)
		{
			cout << this->a[i][j];
		}

		cout << endl;
	}

}

void numPy512::clear()
{
	for (int i = 0; i < 512; i++)
	{
		for (int j = 0; j < 512; j++)
		{
			a[i][j] = 0;
		}
	}
}



numPy512::~numPy512()
{
}
