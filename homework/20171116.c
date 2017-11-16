#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define pi 3.1415926
#define vol(r , h) (pi * (r) * (r) * (h))	//P140 2
#define MAX(a , b , c) ((a) >= (b) && (a) >= (c) ? (a) : ((b) >= (c) && (b) >= (a) ? (b) : (c)))	//P140 3

void findmin()
{
	int i , a[] = {3,4,2,5,1} , res[2];
	puts("数组为：");
	for(i = 0 ; i < 5 ; ++i)
		printf("%d , ", a[i]);
	printf("\b\b  ");
	
	res[0] = a[0];
	for(i = 0 ; i < 5 ; ++i)
	{
		if(res[0] > a[i])
			res[0] = a[i];
			res[1] = i;
	}
	printf("\n其中最小的数为 %d ,为数组中的第 %d 个，索引号为 %d\n--------", res[0] , res[1] + 1 , res[1]);
}

void sum_ave()
{
	int a[20] = {5,3,6,87,98,6,4,2,3,4,8,9,4,6,8,4,3,65,7,4};
}

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
	printf("The biggest one = %f\n--------\n", MAX(a , b , c));
	//P140 3 end
	
	system("pause");
	
	//P159 1 start
	findmin();
	//P159 1 end
	
	system("pause");
	
	//P159 2 start
	sum_ave();
	//P159 2 end
	return 0;
}
