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

void yanghui(n)
{
	int arr[n][n] , i , j;
	for(i = 0 ; i < n ; ++i)
	{
		for(j = 0 ; j < n ; ++j)
			{
				if(j == 0 || j == i)
					arr[i][j] = 1;
				else if(j > 0 && j < i)
					arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
				else if(j > i)
					arr[i][j] = 0;
			}
	}
	
	for(i = 0 ; i < n ; ++i)
	{
		for(j = 1 ; j <= n - i ; ++j)
			printf(" ");
		for(j = 0 ; j < n ; ++j)
		{
			if(arr[i][j] != 0)
				printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	srand((unsigned)time(NULL));
	/*//Pi start
	double pi;
	puts("--------Calculating Pi......--------");
	pi = PI(1000000000);
	printf("%.10f",pi);
	puts("\n--------Calculation ended.--------\n");
	//Pi end
	
	system("pause");
	
	//Sin() start
	puts("--------Integrating Sin(x) from 0 to pi/2");
	printf("%.10f",SIN(10000000,pi));
	puts("\n--------Integration ended.--------\n");
	//Sin() end
	
	system("pause");
	*/
	
	//杨辉三角 start
	puts("--------杨辉三角 start--------\nHow many layers? ");
	int n;
	scanf("%d",&n); 
	yanghui(n);
	puts("\n--------杨辉三角 end--------\n");
	//杨辉三角 end
	
	system("pause");
	
	return 0;
}
