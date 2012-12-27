#include<stdio.h>
#include<stdlib.h>
#include"math.h"

void main(int argc, char *argv[])
{
	float b,i, rem, n=0;
	int a;
	a=atof(argv[1]);
	
	while (a > 0)
	{
		rem = a % 10;
		n = n + rem * pow(2, i);
		++i;
		a = a / 10;
	}
	
	b=(-pow( ( (n/pow(2, 3) ) *(2) -1), 2));
	
	printf("\n%f\n", b);
}

