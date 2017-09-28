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
		printf("\nThe area of the given triangle is %.2f",area);
	}
	else
	{
		printf("It is not a triangle.\n");
	}
	
	return 0;
}

int main()
{
	printf("task1:\n");
	triangle();
	
	return 0;
}
