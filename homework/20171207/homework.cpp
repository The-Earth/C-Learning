#include <stdio.h>
#include <math.h>

#define PI 3.1415926

void Circle(double R , double *C , double *Area)
{
	*C = 2 * PI * R;
	*Area = PI * R * R;
}

void str_cpy(char src[] , char *p)
{
	int i = 0;
	while(src[i])
		*(p+i)= src[i++];
}

int main()
{
	//P205 2
	double Rad , C , Area;
	scanf("%lf",&Rad);
	Circle(Rad, &C , &Area);
	printf("\n%f\n%f" , C , Area);
	puts("\n========");
	
	//P205 4
	char src[32]="abcdefg" , dest[32];
	char *p = dest;
	str_cpy(src , p);
	printf("%s" , dest);
	
	return 0;
}
