#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_MAX 33

void word_sort();
struct student;
void mark_sort();

void word_sort()	//排列单词 
{
	puts("输入十个单词：");
	char wdlst[10][WORD_MAX]; int i;
	for(i = 0 ; i < 10 ; ++i)	//单词输入 
	{
		printf("第%d个单词（不超过32个字母）：", i+1);
		gets(wdlst[i]);
	}
	
	for(i = 0 ; i < 10 ; ++i)	//冒泡 
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

struct student	//学生信息 
{
	char name[WORD_MAX];
	double mark;
};

void mark_sort()
{
	struct student stulist[10] , tmp;
	puts("对10名学生的成绩进行排序");
	for(int i = 0 ; i < 10 ; ++i)	//接收学生姓名成绩 
	{
		printf("输入第%d个学生的姓名和成绩（只接受ASCII字符），用空格隔开：",i+1);
		scanf("%s %lf", stulist[i].name , &stulist[i].mark);
	}
	
	for(int i = 0 ; i < 10 ; ++i)	//冒泡排序 
	{
		for(int j = 9 ; j >= i ; --j)
		{
			if(stulist[j].mark > stulist[j - 1].mark)
			{
				tmp = stulist[j] ; stulist[j] = stulist[i] ; stulist[i] = tmp ;
			}
		}
	}
	puts("按成绩从高到低排列如下：");
	for(int i = 0 ; i < 10 ; ++i)
		printf("%s\t%.1f\n", stulist[i].name , stulist[i].mark);
}

int main()
{
	/*
	//单词冒泡 
	word_sort();
	system("pause");*/
	
	mark_sort();
	
	return 0;
}
