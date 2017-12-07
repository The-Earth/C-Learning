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

int main()
{
	_10_1_1();
	
	return 0;
}
