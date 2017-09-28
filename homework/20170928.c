#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int triangle()
{
	double a = 0, b = 0, c = 0, area, s; 
	printf("Calculating the area of a given triangle.\nInput length of the three sides (seperated by space):");
	scanf("%lf %lf %lf", &a, &b, &c);
	if (a + b > c && a + c > b && b + c > a)
	{
		s = (a + b + c) / 2;
		area = sqrt(s * (s - a) * (s - b) * (s - c));
		printf("\nThe area of the given triangle is %.2f\n\n",area);
	}
	else
	{
		printf("It is not a triangle.\n\n");
	}
	
	return 0;
}

int ASCII()
{
	getchar();
	 
	char CH;
	printf("Give me an English character and I will tell you its ASCII:");
	scanf("%c",&CH);
	printf("\nIts ASCII number is %d\n\n",CH);
	
	return 0;
}

int change()
{
	getchar();
	
	char or, nw;
	printf("Give me an letter and I will change it in to another form:");
	scanf("%c",&or);
	if (or < 'Z' && or > 'A')
	{
		nw = or + 32;
		printf("The result is %c\n\n",nw);
	}
	else
	{
		if (or > 'a' && or < 'z')
		{
			nw = or - 32;
			printf("The result is \"%c\"\n\n",nw);
		}
		else
			puts("I can not help you!\n\n");
	}
	
	return 0;
}

int d2hob()
{
	int num;
	printf("Give I a decimal int number and I will tell you its hex, oct and bin form:");
	scanf("%d",&num);
	printf("\nHex: %x\nOct: %o\n\n",num,num,num);
	
	return 0;
}

int main()
{
	printf("Task 1:\n");
	triangle();
	printf("Task 2:\n");
	ASCII();
	printf("Task 3:\n");
	change();
	printf("Task 4:\n");
	d2hob();
	
	return 0;
}
