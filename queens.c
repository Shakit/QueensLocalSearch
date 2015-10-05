/*==================================================
 * queens.c
 * authors : Florian Delavernhe, Guillaume Legru
 * date : 5 Oct 2015
 *
 * Compute the solution of the 5 queens problem, using a local search algorithm
 *
  ==================================================*/

#include <stdlib.h>

#define QUEEN 5

/* Check The column constraint : Ri[5] != Rj[5] */
int checkCtrs(int Ri, int Rj)
{
	return ((Ri % 5 != Rj % 5) && /*TODO*/)
}


int main (int argc, char ** argv)
{
	int *queens;
	int i;

	queens = (int*) malloc (QUEEN);

	/* Initialization of the variables */
	for(i = 0; i < QUEEN; ++i)
	{
		queens[i] = rand() % 5 + i * 5;
	}

	
	
	return 0;
}
