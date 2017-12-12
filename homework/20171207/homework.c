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

double arr_average(double *arr , int len)
{
	double sum = 0;
	for(int i = 0 ; i < len ; ++i)
	{
		sum += *(arr + i);
	}
	return sum / len;
}

int main()
{
	//P205 2
	double Rad , C , Area;
	scanf("%lf",&Rad);
	Circle(Rad, &C , &Area);
	printf("\n%f\n%f" , C , Area);
	puts("\n========");
	system("pause");
	
	//P205 4
	char src[32]="abcdefg" , dest[32];
	char *p = dest;
	str_cpy(src , p);
	printf("%s" , dest);
	puts("\n========");
	system("pause");
	
	//P205 5
	double srcarr[5] = {2,4,3,2,1};
	printf("%f",arr_average(srcarr , 5));
	puts("\n========");
	system("pause");
	
	
	return 0;
}
