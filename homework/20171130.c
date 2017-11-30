#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_MAX 33

void word_sort()	//排列单词 
{
	puts("输入十个单词：");
	char wdlst[10][WORD_MAX]; int i;
	for(i = 0 ; i < 10 ; ++i)	//单词输入 
	{
		printf("第%d个单词（不超过32个字母）：", i+1);
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
	
	puts("升序排列如下：");	//按升序输出 
	for(i = 0 ; i < 10 ; ++i)
		printf("%s\t", wdlst[i]);
}

int main()
{
	word_sort(); 
	
	return 0;
}
