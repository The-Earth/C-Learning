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

int main()
{
	_10_1_1();
	
	return 0;
}
