#include<iostream>
#include<assert.h>

using namespace std;

typedef struct Arithmetic
{
	char name;
	int Max[5];
	int Allocation[5];
	int Need[5];
	int OP;
}ari;
typedef struct In
{
	ari a[5];
	int size;
}in;