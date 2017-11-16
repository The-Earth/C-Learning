#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define pi 3.1415926
#define vol(r , h) (pi * (r) * (r) * (h))	//P140 2
#define MAX(a , b , c) ((a) >= (b) && (a) >= (c) ? (a) : ((b) >= (c) && (b) >= (a) ? (b) : (c)))	//P140 3

int main()
{
	//P140 2 start
	double r, h;
	puts("Calculating volume of a sylinder.\nr & h = ?(Seperated by space) : ");
	scanf("%lf %lf", &r, &h);
	printf("The result is %f\n--------\n", vol(r,h));
	//P140 2 end
	
	system("pause");
	
	//P140 3 start
	double a, b, c;
	puts("--------\nI'll tell you the biggest number amount the given three : (Seperated by space)");
	scanf("%lf %lf %lf", &a, &b, &c);
	printf("The biggest one = %f", MAX(a , b , c));
	//P140 3 end
	
	return 0;
}
