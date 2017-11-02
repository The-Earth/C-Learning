#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double randf(double min, double max)
{
	double r;
	r = rand();
	return (r / RAND_MAX * (max - min) + min);
}

double PI(int n) //n越大，计算精度越高 
{
	int i, in = 0; double x , y;
	for(i = 1 ; i <= n ; ++i)
	{
		x = randf(-1 , 1) ; y = randf(-1 , 1);
		if(pow(x,2) + pow(y,2) < 1)
			in += 1;
	}
	return (in / (double) n * 4);
}

double SIN(int n , double pi)
{
	int i, in = 0; double x , y;
	for(i = 1 ; i <= n ; ++i)
	{
		x = randf(0 , pi / 2) ; y = randf(0 , 1);
		if(y <= sin(x))
			in += 1;
	}
	return (in / (double) n * pi / 2);
}

int main()
{
	srand((unsigned)time(NULL));
	//Pi start
	double pi;
	puts("--------Calculating Pi......--------");
	pi = PI(1000000000);
	printf("%.10f",pi);
	puts("\n--------Calculation ended.--------\n");
	//Pi end
	
	system("pause");
	
	//Sin() start
	puts("--------Integrating Sin(x) from 0 to pi/2");
	printf("%.10f",SIN(10000000,3.1415926));
	puts("\n--------Integration ended.--------\n");
	//Sin() end
	
	system("pause");
	
	
	
	return 0;
}
