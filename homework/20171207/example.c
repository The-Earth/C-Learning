#include <stdio.h>
#include <stdlib.h>

void _10_1_1()
{
	int a , b[4];
	printf("a的地址（十进制）：\t%d\n",&a);
	printf("b的地址（十进制）：\t%d\n",b);	//b的地址就是b[0]的地址
	printf("b[1]的地址（十进制）：\t%d\n",&b[1]);
	printf("a的地址（十六进制）：\t%X\n",&a); 
	printf("b的地址（十六进制）：\t%X\n",b);
	printf("b的地址（十六进制）：\t%X\n",&b[1]);
}

void _10_1_3()
{
	int i , a[] = {1,3,5,7,9} , *p = a;
	for(i = 0 ; i < 5 ; i++)
		printf("a[%d] = %d\t" , i , a[i]);
	printf("\n");
	printf("a = %d\n", p);				//输出数组a 的首地址
	printf("p + 2 = %d\n" , p+2);		//输出 a[2]的地址
	printf("*p+3 = %d\n" , *p + 3);		//输出a[0]+3的值
	printf("*(p+3) = %d\n" , *(p+3));	//输出a[3]的值
	printf("*p++ = %d\n" , *p++);		//输出a[0]的值后，使p指向a[1]
	p = a;
	printf("*++p = %d\n" , *++p);		//使p指向a[2]后，输出a[2]的值
	printf("++*p = %d\n" , ++*p);		//输出++a[2]的值 
}

int main()
{
	_10_1_1();
	puts("\n");
	_10_1_3();
	
	return 0;
}
