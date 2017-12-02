#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double randf(double min, double max)	//随机数生成器 
{
	double r;
	r = rand();
	return (r / RAND_MAX * (max - min) + min);
}

double PI_core(int n) //单次计算pi
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

double SIN_core(int n , double pi)	//单次sin积分运算 
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

double PI_main(double d, int n)	//圆周率运算主程序 
{
	double res = 0 , pi = 1 ;
	while(fabs(res - pi) > d)
	{
		pi = PI_core(n);
		res = 0.5 * (res + pi);
	}
	return res;
}

double SIN_main(double d, int n, double pi)	//sin积分主程序 
{
	double res = 0 , in = 1 ;
	while(fabs(res - in) > d)
	{
		pi = SIN_core(n,pi);
		res = 0.5 * (res + in);
	}
	return res;
}

void yanghui(int n)			//杨辉三角形 
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

int nar(int n)	//判断是否为水仙花数 
{
	return pow(n / 100 , 3) + pow((n - n / 100 * 100) / 10 , 3) + pow(n % 10 , 3) == n ? 1 : 0 ;
}

int greatest_common(int a, int b)	//求最大公约数 
{
	int i, min;
	min = a > b ? b : a;
	for(i = min ; i >= 1 ; --i)
	{
		if(a % i == 0 && b % i == 0)
			return i;
	}
}

int least_common(int a, int b)	//求最小公倍数 
{
	int i, max;
	max = a < b ? b : a;
	for(i = max ; i <= a * b ; ++i)
	{
		if(i % a == 0 && i % b == 0)
			return i;
	}
}

int main()
{
	srand((unsigned)time(NULL));
	//Pi start
	double pi;
	puts("--------Calculating Pi......--------");
	pi = PI_main(0.00001 , pow(10,6));
	printf("pi = %.10f",pi);
	puts("\n--------Calculation ended.--------\n");
	//Pi end
	
	system("pause");
	
	//Sin() start
	puts("--------Integrating Sin(x) from 0 to pi/2");
	printf("The result is %.10f",SIN_main(0.00000001, pow(10,6) , pi));
	puts("\n--------Integration ended.--------\n");
	//Sin() end
	
	system("pause");
	
	
	//杨辉三角 start
	puts("--------杨辉三角 start--------\nHow many layers? ");
	int n;
	scanf("%d",&n); 
	yanghui(n);
	puts("\n--------杨辉三角 end--------\n");
	//杨辉三角 end
	
	system("pause");
	
	//水仙花数 start
	puts("--------水仙花数 start--------\nAll the narcissistic numbers between 100 and 999 are listed as following:\n");
	int i;
	for(i = 100 ; i < 1000 ; ++i)
	{
		if(nar(i))
			printf("%d\t", i);
	}
	puts("\n--------水仙花数 end--------");
	//水仙花数 end
	 
	system("pause");
	
	//D % M start
	int a, b;
	puts("--------Greatest common Divider and Least common Multiple START--------");
	puts("输入两整数，返回它们的最大公约数和最小公倍数，以空格分隔 ： ");
	scanf("%d %d", &a, &b);
	printf("最大公约数：%d\n最小公倍数：%d", greatest_common(a,b), least_common(a,b));
	puts("\n--------Greatest common Divider and Least common Multiple END--------");
	//D % M end
	
	return 0;
}
