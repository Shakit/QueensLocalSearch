/*==================================================
 * queens.c
 * authors : Florian Delavernhe, Guillaume Legru
 * date : 5 Oct 2015
 *
 * Compute the solution of the 5 queens problem, using a local search algorithm
 *
 ==================================================*/

#include <stdio.h> /* printf */
#include <stdlib.h> /* malloc, abs */


#define QUEEN 5

/* Check The column constraint : Ri[5] != Rj[5] */
int const checkCtrs(const int * queens, int i, int j)
{
	if ((queens[i] % 5 != queens[j] % 5) &&
		(abs(queens[i] % 5 - queens[j] % 5) != abs(i - j)))
	{
		return 0;
	}
	return 1;
}

/* Returns the cost of a snapshot */
int cost(int *queens, int range)
{
	int i,j,res;
	int check;
	
	res = 0;
	for (i = 0; i < range -1; ++i)
	{
		for (j = i+1; j < range; j++)
		{
			check = checkCtrs(queens, i, j);
			/* if (check) printf("%d and %d\n", i, j); */
			res += check;
			/* printf("res(%d,%d) = %d\n",i,j,res); */
			/* res += checkCtrs(queens, i, j); */
		}
	}
	/* printf("res = %d\n",res); */
	return res;
}

/* Prints a snapshot */
void printSnapshot(int * queens, int range)
{
	int i;
	printf("( ");
	for (i = 0; i < range; i++)
	{
		printf("%d ",queens[i]);
	}
	printf(")\n");
}

/* Main function */
int main (int argc, char ** argv)
{
	int *queens;
	int i;
	int c;

	queens = (int*) malloc (QUEEN);

	/* Initialization of the variables */
	for(i = 0; i < QUEEN; ++i)
	{
		queens[i] = rand() % 5 + i * 5;
	}
	printSnapshot(queens, QUEEN);
	


    /* Value of the current snapshot */
	printf ("%d\n", cost(queens, QUEEN));
	int zbra = (1==1);
	printf ("%d\n",zbra); 
	
	
	return 0;
}
