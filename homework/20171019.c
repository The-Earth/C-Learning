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
	int i, n = 0;
	for(i = 1; i < 1001; ++i)
	{
		if(i % 3 == 2 && i % 5 == 3 && i % 7 == 2)
		{
			printf("%d\t",i);
			++ n;
			if(n % 5 == 0)
			{
				printf("\n");
				n = 0;
			}
		}
	}
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
