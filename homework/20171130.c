#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_MAX 33

void word_sort();
struct student;
void mark_sort();

void word_sort()	//���е��� 
{
	puts("����ʮ�����ʣ�");
	char wdlst[10][WORD_MAX]; int i;
	for(i = 0 ; i < 10 ; ++i)	//�������� 
	{
		printf("��%d�����ʣ�������32����ĸ����", i+1);
		gets(wdlst[i]);
	}
	
	for(i = 0 ; i < 10 ; ++i)	//ð�� 
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

struct student	//ѧ����Ϣ 
{
	char name[WORD_MAX];
	double mark;
};

void mark_sort()
{
	struct student stulist[10] , tmp;
	puts("��10��ѧ���ĳɼ���������");
	for(int i = 0 ; i < 10 ; ++i)	//����ѧ�������ɼ� 
	{
		printf("�����%d��ѧ���������ͳɼ���ֻ����ASCII�ַ������ÿո������",i+1);
		scanf("%s %lf", stulist[i].name , &stulist[i].mark);
	}
	
	for(int i = 0 ; i < 10 ; ++i)	//ð������ 
	{
		for(int j = 9 ; j >= i ; --j)
		{
			if(stulist[j].mark > stulist[j - 1].mark)
			{
				tmp = stulist[j] ; stulist[j] = stulist[i] ; stulist[i] = tmp ;
			}
		}
	}
	puts("���ɼ��Ӹߵ����������£�");
	for(int i = 0 ; i < 10 ; ++i)
		printf("%s\t%.1f\n", stulist[i].name , stulist[i].mark);
}

int main()
{
	/*
	//����ð�� 
	word_sort();
	system("pause");*/
	
	mark_sort();
	
	return 0;
}
