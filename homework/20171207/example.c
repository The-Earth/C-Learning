#include <stdio.h>
#include <stdlib.h>

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

int main()
{
	_10_1_1();
	puts("\n");
	_10_1_3();
	
	return 0;
}
