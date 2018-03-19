#include<stdio.h>
#include<time.h>
#include<stdlib.h>


void main()
{   int state;
	srand(time(NULL));
	state=rand() % (3+ 1 - 0) + 0 ;//rand() % (max_number + 1 - minimum_number) + minimum_number
	printf("\nState is %d",state);
}
