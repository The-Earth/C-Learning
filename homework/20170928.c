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
	printf("\nIts ASCII number is %d",CH);
	
	return 0;
}

int main()
{
	printf("task 1:\n");
	triangle();
	printf("task 2:\n");
	ASCII();
	
	return 0;
}
