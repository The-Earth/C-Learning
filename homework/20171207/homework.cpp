#include <stdio.h>
#include <math.h>

#define PI 3.1415926

void Circle(double R , double *C , double *Area)
{
	*C = 2 * PI * R;
	*Area = PI * R * R;
}

void strcpy(char src[] , char *dest[])
{
	*dest[] = src[];
}

int main()
{
	//P205 2
	double Rad , C , Area;
	scanf("%lf",&Rad);
	Circle(Rad, &C , &Area);
	printf("\n%f\n%f" , C , Area);
	puts("========");
	
	//P205 4
	char
	
	return 0;
}
