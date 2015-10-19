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

/* modulo*/
int mod(int i, int j)
{
	return (5 + i % j);
}

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
int const cost(const int *queens, const int range)
{
	int i,j,res;
	int check;
	
	res = 0;
	for (i = 0; i < range -1; ++i)
	{
		for (j = i+1; j < range; j++)
		{
			check = checkCtrs(queens, i, j);
			res += check;
		}
	}

	return res;
}

/* Prints a snapshot */
void printSnapshot(const int * queens, const int range)
{
	int i;
	printf("( ");
	for (i = 0; i < range; i++)
	{
		printf("%d ",queens[i]);
	}
	printf(")\n");
}

/* Simulates the cost for each possible moves */
void simulateCost(int * co, int * queens, const int range)
{
	int i;
	int prev;
	
	for (i = 0; i < range; i++)
	{
		prev = queens[i];
		
		queens[i] = i * 5 +(prev-1) %5;
		co[i*2+1] = cost(queens, range);

		queens[i] = i * 5 +(prev+1) %5;
		co[i*2+2] = cost(queens, range);

		queens[i] = prev;
	}

}

/* Moves one queen depending of the values of co[] */
int move(int * co, int * queens , const int range)
{
	int i;
	int min = co[0];
	int place = 0;
	int p;
	for (int i = 1; i < range*2+1; ++i)
	{
		if (i <= min)
		{
			min = co[i];
			place = i;
		}
	}
	
	if(place != 0)
	{
		p = (place-1)/2;
		if(place % 2 == 0)
		{
			queens[p] = p *5 + (queens[p] -1) % 5;
		}
		else
		{
			queens[p] = p *5 + (queens[p] +1) % 5;
		}
		return 1;
	}
	else
	{
		return 0;
	}	
}

/* Main function */
int main (int argc, char ** argv)
{
	int *queens, *co;
	int i,j;

	queens = (int*) malloc (QUEEN * sizeof(int));
	co = (int*) malloc ((QUEEN*2 +1) * sizeof(int));
	
	/* Initialization */
	for(i = 0; i < QUEEN; ++i)
	{
		queens[i] = rand() % 5 + i * 5;
	}
	for(i = 0; i < QUEEN *2 +1; ++i)
	{
		co[i] = 0;
	}
	
	co[0] = cost(queens,QUEEN);
	printSnapshot(queens, QUEEN);
	printf ("Current cost : %d\n", co[0]);
	
	/*Local search*/
	
	/*while (co[0] > 0)
	{
		simulateCost(co, queens, QUEEN);
		if (!move(co, queens, QUEEN))
		{
			break;
		}
		printSnapshot(queens, QUEEN);
		printf ("Current cost : %d\n", co[0]);
	}*/
	
	printSnapshot(queens, QUEEN);
	printf ("Current cost : %d\n", co[0]);

	/*Free*/
	/*for (i = 0; i < QUEEN; ++i) free(queens+i);
	  for (i = 0; i < QUEEN*2 +1; ++i)free(co+i);*/
	free(queens);
	free(co);

	return 0;
}
