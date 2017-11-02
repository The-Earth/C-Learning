#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double randf(double min, double max)
{
	double r;
	r = rand();
	return (r / RAND_MAX * (max - min) + min);
}

double PI(int n)
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

int main()
{
	srand((unsigned)time(NULL));
	//Pi start
	puts("--------Calculating Pi......--------");
	printf("%.10f",PI(100000000));
	puts("\n--------Calculation ended.--------\n");
	//Pi end
	
	system("pause");
}
