#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_MAX 33

void word_sort()	//���е��� 
{
	puts("����ʮ�����ʣ�");
	char wdlst[10][WORD_MAX]; int i;
	for(i = 0 ; i < 10 ; ++i)	//�������� 
	{
		printf("��%d�����ʣ�������32����ĸ����", i+1);
		gets(wdlst[i]);
	}
	
	for(i = 0 ; i < 10 ; ++i)
	{
		for(int j = 9 ; j >= i ; --j)
		{
			if(strcmp(wdlst[j] , wdlst[j - 1]) < 0)
			{
				char tmp[WORD_MAX];
				strcpy(tmp , wdlst[j]) ; strcpy(wdlst[j] , wdlst[j - 1]) ; strcpy(wdlst[j - 1] , tmp) ;
			}
		}
	}
	
	puts("�����������£�");	//��������� 
	for(i = 0 ; i < 10 ; ++i)
		printf("%s\t", wdlst[i]);
}

int main()
{
	word_sort(); 
	
	return 0;
}
