#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WORD_MAX 33

void word_sort();
struct student;
void mark_sort();
void div_find();
int randf(double min , double max);
int div_find_core(int arr[] , int tar , int len);
struct array;
struct loc;
double dist(struct loc z1 , struct loc z2);

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

struct array
{
	int index;
	int value;
};

void div_find()	//二分法查找 
{ 
	struct array arr[1000] , tmp;
	puts("生成的随机数组为：\n序号\t数值");
	system("pause");
	for(int i = 0 ; i < 1000 ; ++i)
	{
		arr[i].value = randf(0 , 999);
		arr[i].index = i;
		printf("%d\t%d\n" , i , arr[i].value);
	}
	
	for(int i = 0 ; i < 1000 ; ++i)	//排序 
	{
		for(int j = 999 ; j >= i ; --j)
		{
			if(arr[j].value < arr[j - 1].value)
			{
				tmp = arr[j] ; arr[j] = arr[j-1] ; arr[j-1] = tmp ;
			}
		}
	}
	
	int target , arrval[1000];
	puts("输入需要查找的数");
	scanf("%d", &target);
	
	for(int i = 0 ; i < 1000 ; ++i)
	{
		arrval[i] = arr[i].value;
	}
	
	int res = div_find_core(arrval , target , 1000) ;
	if(res >= 0)
		printf("一个目标数的索引为%d", arr[res].index);
	else
		printf("未查找到目标。");
}

int div_find_core(int arr[] , int tar , int len)
{
	int max = len - 1 , min = 0;
	int mid ;
	while(max >= min)
	{
		mid = (max + min) / 2;
		if(arr[mid] == tar)
			return mid;
		if(arr[mid] > tar)
			max = mid - 1;
		else if(arr[mid] < tar)
			min = mid + 1;
	}
	return -1;
}

int randf(double min, double max)	//随机数生成器 
{
	double r;
	r = rand();
	return (int)(r / RAND_MAX * (max - min) + min);
}

struct loc	//坐标
{
	double x;
	double y;
};

double dist(struct loc z1 , struct loc z2)
{
	return (sqrt(pow(z1.x - z2.x, 2) + pow(z1.y - z2.y , 2)));
}

void dist_main()
{
	struct loc z1 , z2 ;
	puts("输入两点坐标，计算距离：\n第一点坐标（X Y 以空格分隔）：");
	scanf("%lf %lf" , &z1.x , &z1.y);
	puts("第二点坐标（X Y 以空格分隔）：");
	scanf("%lf %lf" , &z2.x , &z2.y);
	printf("它们之间的距离为：%.3f" , dist(z1 , z2));
}

int main()
{
	srand((unsigned)time(NULL));
	/*
	//单词冒泡 
	word_sort();
	system("pause");
	
	mark_sort();
	system("pause");
	
	div_find();
	system("pause");
	
	//坐标距离
	dist_main();
	system("pause");*/
	
	return 0;
}
