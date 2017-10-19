#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void A2Z()
{
	char ser;
	for(ser=65; ser < 91; ++ser)
	{
		printf("%c ",ser);
		if((int) ser % 8 == 0)
		{
			printf("\n");
		}
	}
	printf("\n\n");
}

void modd()
{
	
}

int main()
{
	printf("Homework for 2017/10/19 lecture.\n\n");
	printf("P103 Task 3:\n\n");
	A2Z();
	printf("P103 Task 5:\n\n");
	modd();
	
	return 0;
}
