
class numPy512
{
	int** a;
	long double *b;
	int dim;
	int *unpack;
public:
	numPy512();
	long double* packbit(int **p, int length, int dim);
	int** unpackbit(long double *p, int dim);
	int * binary(long double num);
	int digitcount(long double x);
	void printunpackbit(int l);
	void clear();
	~numPy512();
};

