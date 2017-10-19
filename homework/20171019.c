#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void A2Z()
{
	char ser; int i;
	for(ser=65; ser < 91; ++ser)
	{
		printf("%c ",ser);
		if((int) ser % 8 == 0)
		{
			printf("\n");
		}
	}
}

int main()
{
	printf("Homework for 2017/10/19 lecture.\n\n");
	printf("Task 1:\n\n");
	A2Z();
	
	return 0;
}
