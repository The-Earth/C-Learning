#include <stdio.h>
#include <stdlib.h>
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

void input(int *data , int size)
{
	printf("请依次输入%d个数据\n", size);
	for(int i = 0 ; i < size ; ++i)
		scanf("%d" , data + i);
	puts("输入完成"); 
}

void sort(int *data, int size)
{
	for(int i = 0 ; i < size ; ++i)
	{
		for(int j = size-1 ; j > i ; --j)
		{
			if( *(data + j) > *(data + j - 1) )
			{
				int tmp;
				tmp = *(data + j) ; *(data + j) = *(data + j - 1) ; *(data + j - 1) = tmp;
			} 
		}
	}
} 

void output(int *data , int size)
{
	puts("排序结果为：");
	for(int i = 0 ; i < size ; ++i)
		printf("%d\t" , *(data + i));
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
	
	//排序
	int data[6];
	input(data , 6);
	sort(data , 6);
	output(data , 6);
	
	return 0;
}
