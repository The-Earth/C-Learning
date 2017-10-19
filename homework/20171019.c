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
	printf("\n\n");
}

void fracsum()
{
	int i; double sum = 0.0;
	for(i = 1; i < 201; ++i)
	{
		sum += 1.0 / (double) i;
	}
	printf("The result is %.5f\n\n",sum);
}

void fabonacci()
{
	int a = 1, b = 1, c, n = 2;
	c = a + b;
	printf("%d\t%d\t", a, b);
	while(c <= 10000)
	{
		printf("%d\t",c);
		++ n;
		if(n % 5 == 0)
		{
			printf("\n");
			n = 0;
		}
		a = b; b = c;
		c = a + b;
	}
	printf("\n\n");
}

void sumofnum()
{
	int num, len, a, i, sum=0, temp;
	printf("Give me an integer and I will tell you how long it is and the sum of its numbers.\n:");
	scanf("%d",&num);
	len = log(num) / log(10) + 1;
	temp = num;
	for(i = len - 1; i > -1; --i)
	{
		a = temp / pow(10, i);
		sum += a;
		temp -= a * pow(10, i);
	}
	printf("The length of the number is %d.\nThe sum of its numbers is %d", len, sum);
}

int main()
{
	printf("Homework for 2017/10/19 lecture.\n\n");
	printf("P103 Task 3:\n\n");
	A2Z();
	printf("P103 Task 5:\n\n");
	modd();
	printf("P103 Task 7:\n\n");
	fracsum();
	printf("P103 Task 10:\n\n");
	fabonacci();
	printf("P103 Task 14:\n\n");
	sumofnum();
	
	return 0;
}
