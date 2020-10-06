#include <iostream>
#include "numPy256.h"
#include "numPy512.h"
using namespace std;
int main()
{

	numPy256 obj1;	//OBJECT FOR 256 BIT FNCTIONS
	numPy512 obj512; ////OBJECT FOR 512 BIT FNCTIONS

	int num = 1, input[100],**c, digit;


	renum:
	cout << "How many inputs you want to Enter ? :";
	cin >> num;
	if (num < 0)
	 goto renum;
	c = new int *[num];

	renum1:
	cout << "How many digit you want to enter in row " ;
	cin >> digit;
	if (num < 0 && num > 256)
		goto renum1;
	for (int i = 0; i < num; i++)
	{
		c[i] = new int[digit];

	}
	//      ============================== CHECKING PACKBIT ================================
	// Taking value from user ,, or you can also write predefined value like c[0][0]=1,c[0][1]=0,c[0][2]=1
	for (int i = 0; i < num; i++)
		for (int j = 0; j < digit; j++)
		{
			cout << "Enter value for " << i + 1 << " element: ";
			cin >> c[i][j];
		}
	long double xa[100];
	for (int i = 0; i < num; i++) // this loops PACKS and prints all the values  you have entered
	{
		// FOLLOWING FUNCTION PACKS BIT
		long double *ptr = obj1.packbit(c, digit, num); // DIGIT tells how many binary number you have enter ,, NUM TELLS the dimension i.e number of time you gave input 
		cout << "AFTER PACKING BIT" << endl << fixed << ptr[i] << endl; // PRINTING ITS VALUE 
		xa[i] = ptr[i];
	}





	//      ============================== CHECKING UnPACKBIT ================================

	cout << "showing UNPACK" << endl;
	
	// CREATING POINTER TO STORE VALUE IN DECIMAL
	long double *a=new long double [num];
	// CREATING OBJECT TO USE UNPACKBIT FUNCTION 
	numPy256 obj2;
	// TAKING INPUTS
	for(int i = 0 ; i < num ; i ++)
	{
	
		a[i] = xa[i] ;
		
	}

	// Storing answer in POINTER as unpackbit will always return address of unpacked values
	int **b;
	b = obj2.unpackbit(a, num);

	// PRINTING  values for confirmation
	for (int i = 0; i < num; i++)
	{
		for(int j = 0 ; j < 256 ; j++ )
		cout << b[i][j];
		cout << endl;
	}




	// ===================================== 512 BITS =================================



	int num1 = 1, input1[100], **c1, digit1;


renum11:
	cout << "How many inputs you want to Enter ? :";
	cin >> num1;
	if (num1 < 0)
		goto renum11;
	c1 = new int *[num1];

renum111:
	cout << "How many digit you want to enter in row ";
	cin >> digit1;
	if (num < 0 && num > 512)
		goto renum111;
	for (int i = 0; i < num1; i++)
	{
		c1[i] = new int[digit1];

	}
	//      ============================== CHECKING PACKBIT ================================
	// Taking value from user ,, or you can also write predefined value like c[0][0]=1,c[0][1]=0,c[0][2]=1
	for (int i = 0; i < num1; i++)
		for (int j = 0; j < digit1; j++)
		{
			cout << "Enter value for " << i + 1 << " element: ";
			cin >> c1[i][j];
		}
	long double xa1[100];
	for (int i = 0; i < num1; i++) // this loops PACKS and prints all the values  you have entered
	{
		// FOLLOWING FUNCTION PACKS BIT
		long double *ptr1 = obj512.packbit(c, digit, num); // DIGIT tells how many binary number you have enter ,, NUM TELLS the dimension i.e number of time you gave input 
		cout << "AFTER PACKING BIT" << endl << fixed << ptr1[i] << endl; // PRINTING ITS VALUE 
		xa1[i] = ptr1[i];
	}





	//      ============================== CHECKING UnPACKBIT ================================

	cout << " 512 BIT showing UNPACK" << endl;

	// CREATING POINTER TO STORE VALUE IN DECIMAL
	long double *a1 = new long double[num1];
	// CREATING OBJECT TO USE UNPACKBIT FUNCTION 
	numPy512 obj512_1;
	// TAKING INPUTS
	for (int i = 0; i < num1; i++)
	{

		a1[i] = xa1[i];

	}

	// Storing answer in POINTER as unpackbit will always return address of unpacked values
	int **b1;
	b1 = obj512_1.unpackbit(a1, num1);

	// PRINTING  values for confirmation
	for (int i = 0; i < num1; i++)
	{
		for (int j = 0; j < 512; j++)
			cout << b1[i][j];
		cout << endl;
	}









	system("pause");
	return 0;
}