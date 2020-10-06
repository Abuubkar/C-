#include "numPy256.h"
#include <cmath>
#include <iostream>
using namespace std;



numPy256::numPy256()
{
	this->a = new int*[256];
	for (int i = 0; i < 256; i++)
	{
		this->a[i] = new int[256];
		for (int j = 0; j < 256; j++)
		{
			this->a[i][j] = 0;
		}
	}
}

int** numPy256::unpackbit(long double *p,int dim)
{
	clear();
	if (dim < 0)
		dim = 1;

	this->dim = dim;
	for (int i = 0; i < dim; i++)
	{
		unpack = new int [dim];	
		this->unpack = this->binary(p[i]);
		for (int j =0 ; j < 256; j++)
		{
			this->a[i][j] = this->unpack[j];
		}
	}

	return a ;
}

long double* numPy256::packbit(int ** p,int length,int dim)
{
	clear();
	long double  power ;

	b = new long double[dim];
	for (int i = 0; i<dim; i++)
	{
		for (int j = 0; j < length; j++)
		{
			a[i][j] = p[i][j];

		}
	}
	for (int i = 0; i < dim; i++) 
	{
		b[i] = 0; power = 1;
		
		for (int j = 255; j >= 0; j--)
		{
			 b[i] += abs(a[i][j]*power) ;
		     power *= 2;
		
		}

	}
	return b;
}
int* numPy256::binary(long double num)
{
	int temp[256];
	for (int i = 0; i < 256; i++)
	{
		temp[i] = 0;
	}
	long double rem,quotient = num, binary = 0, i = 1;
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
	while (count > tempindex/2 )
	{
    tem = temp[temloc];
	temp[temloc] =	temp[count];
	temp[count] = tem;
	temloc++;
	count--;
	}


	return temp;

}

int numPy256::digitcount(long double x)
{
	int size=0;
	while (x  >= 1)
	{
		x = x / 10;
		size++;
	}
	return size;
}

void numPy256::printunpackbit(int l)
{
	if (l < 0 || l > dim)
	l = 1;
	
		for (int i = 0; i < l; i++)
		{
			for (int j = 0; j < 256; j++)
			{
				cout << this->a[i][j];
			}

			cout << endl;
		}
	
}

void numPy256::clear()
{
	for (int i = 0; i < 256; i++)
	{
		for (int j = 0; j < 256; j++)
		{
			a[i][j] = 0;
		}
	}
}



numPy256::~numPy256()
{
}
