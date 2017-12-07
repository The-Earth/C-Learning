#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define EPS 0.001

double randf(double min , double max)
{
	return (double) rand() / RAND_MAX * (max - min) + min;
}

void _10_1_1()
{
	int a , b[4];
	printf("a�ĵ�ַ��ʮ���ƣ���\t%d\n",&a);
	printf("b�ĵ�ַ��ʮ���ƣ���\t%d\n",b);	//b�ĵ�ַ����b[0]�ĵ�ַ
	printf("b[1]�ĵ�ַ��ʮ���ƣ���\t%d\n",&b[1]);
	printf("a�ĵ�ַ��ʮ�����ƣ���\t%X\n",&a); 
	printf("b�ĵ�ַ��ʮ�����ƣ���\t%X\n",b);
	printf("b�ĵ�ַ��ʮ�����ƣ���\t%X\n",&b[1]);
}

void _10_1_3()
{
	int i , a[] = {1,3,5,7,9} , *p = a;
	for(i = 0 ; i < 5 ; i++)
		printf("a[%d] = %d\t" , i , a[i]);
	printf("\n");
	printf("a = %d\n", p);				//�������a ���׵�ַ
	printf("p + 2 = %d\n" , p+2);		//��� a[2]�ĵ�ַ
	printf("*p+3 = %d\n" , *p + 3);		//���a[0]+3��ֵ
	printf("*(p+3) = %d\n" , *(p+3));	//���a[3]��ֵ
	printf("*p++ = %d\n" , *p++);		//���a[0]��ֵ��ʹpָ��a[1]
	p = a;
	printf("*++p = %d\n" , *++p);		//ʹpָ��a[2]�����a[2]��ֵ
	printf("++*p = %d\n" , ++*p);		//���++a[2]��ֵ 
}

double _10_2_3_fun(double x)
{
	return x*x;
}

double _10_2_3_integral(int a , int b , double (*f)(double))
{
	double sum = 0.0 , x ;
	for(x = a ; x < b ; x = x + EPS)
		sum += EPS * (*f)(x);
	return sum;
}

void _10_2_3()
{
	printf("f(x) = x*x ��[0,1]�ϵĶ����֣�%f\n" , _10_2_3_integral(0 , 1, _10_2_3_fun));
	printf("f(x) = sin(x) ��[0,1]�ϵĶ����֣�%f\n" , _10_2_3_integral(0 , 1, sin));
	printf("f(x) = sqrt(x) ��[0,1]�ϵĶ����֣�%f\n" , _10_2_3_integral(0 , 1, sqrt));
}

void _10_3_2()
{
	int a[5] , i , *p;
	printf("���±���������Ԫ�أ�\n");
	for(i = 0 ; i < 5 ; i++)
		a[i] = (int)randf(1,10);
	for(i = 0 ; i < 5 ; i++)
		printf("%d\t", a[i]);
	printf("\n");
	
	printf("����������������Ԫ�أ�\n");
	for(i = 0 ; i < 5 ; i++)
		*(a+i) = (int)randf(1,10);
	for(i = 0 ; i < 5 ; i++)
		printf("%d\t", a[i]);
	printf("\n");
	
	printf("��ָ����������Ԫ�أ�\n");
	for(p = a ; p < a + 5 ; p++)
		*p = (int)randf(1,10);
	for(i = 0 ; i < 5 ; i++)
		printf("%d\t", a[i]);
	printf("\n");
}

void _10_3_4()
{
	int score[5] = {60 , 80 , 90 , 70 , 50} , i , *p = score;
	printf("Scores:\n");
	for(i = 0 ; i < 5 ; i++)
		printf("%d\t" , *(p+i));	//���ԭ���� 
	printf("\n");
	_10_3_4_list(p,5);				//���õ�����
	for(i = 0 ; i < 5 ; i++)		//������������ 
		printf("%d\t" , *(p+i));
}

void _10_3_4_list(int *a , int n)
{
	int i , t;
	for(i = 0 ; i < n / 2 ; i++)
		t = a[i] , a[i] = a[n-1-i] , a[n-1-i] = t ;
}

void _10_3_8()
{
	char name[][10] = {"zhang san" , "li si" , "wang wu" , "zhao liu"};
	int i , j;
	char t[10];
	printf("����ǰ��\n");
	for(i = 0 ; i < 4 ; i++)
		printf("name[%d] = %s\n" , i , name[i]);
	for(i = 0 ; i < 4 ; i++)
	{
		for(j = 0 ; j < 4 - i - 1 ; j++)
		{
			if(strcmp(name[j] , name[j+1]) > 0)
			{
				strcpy(t , name[j]);
				strcpy(name[j] , name[j+1]);
				strcpy(name[j+1] , t);
			}
		}
		printf("�����\n");
		for(i = 0 ; i < 4 ; i++)
			printf("name[%d] = %s\n",i , name[i]);
	}
}

int main()
{
	srand((unsigned)time(NULL));
	_10_1_1();
	puts("\n");
	_10_1_3();
	puts("\n");
	_10_2_3();
	puts("\n");
	_10_3_2();
	puts("\n");
	_10_3_4();
	puts("\n");
	_10_3_8();
	
	return 0;
}
