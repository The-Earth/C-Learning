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
	int i ; double x , y;
	for(i = 0 ; i <= n ; ++i)
	{
		x = randf(-1 , 1) ; y = randf(-1 , 1);
		
	}
}

int main()
{

}
