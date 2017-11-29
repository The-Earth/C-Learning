#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int randf(double min, double max)	//随机数生成器 
{
	double r;
	r = rand();
	return (int)(r / RAND_MAX * (max - min) + min);
}

void select_sort()	//选择排序 
{
	puts("按指示输入长度为10的数组");	//数组输入 
	int i , a[10];
	for(i = 0 ; i < 10 ; ++i)
	{
		printf("输入第%d个元素：", i+1);
		scanf("%d" , &a[i]);
	}
	
	for(i = 0 ; i < 10 ; ++i)
	{
		int j , tmp , max_index;
		max_index = i;
		for(j = i ; j < 10 ; ++j)
			max_index = a[j] > a[max_index] ? j : max_index ;	//记录最大索引
		
		tmp = a[i] ; a[i] = a[max_index] ; a[max_index] = tmp;	//交换元素位置 
	}
	
	puts("按降序排列如下");	//按降序输出 
	for(i = 0 ; i < 10 ; ++i)
		printf("%d\t", a[i]);
}

int str_len(const char b[])	//计算字符串长度 
{
	int len = 0;
	while(b[len])
		len += 1;
	return len;
}

int str_cmp(const char s1[] , const char s2[])	//比较字符串（实现strcmp()） 
{
	int i;
	while(s1[i] || s2[i])
	{
		if(s1[i] == s2[i])
			i++ ;
		else
			return s1[i] - s2[i];
	}
}

void word_sort()	//排列单词 
{
	puts("输入十个单词：");
	char wdlst[10][33]; int i;
	for(i = 0 ; i < 10 ; ++i)	//单词输入 
	{
		printf("第%d个单词（不超过32个字母）：", i+1);
		scanf("%s" , wdlst[i]);
	}
	
	for(i = 0 ; i < 10 ; ++i)	//单词排序 
	{
		int j , max_index; char tmp[33];
		max_index = i;
		for(j = i ; j < 10 ; ++j)
			max_index = strcmp(wdlst[max_index] , wdlst[j]) < 0 ? j : max_index ;	//记录最大者的索引 
		
		strcpy(tmp , wdlst[i]) ; strcpy(wdlst[i] , wdlst[max_index]) ; strcpy(wdlst[max_index] , tmp) ; //交换单词顺序 
	}
	
	puts("Ranked in decending sort:");	//按降序输出 
	for(i = 0 ; i < 10 ; ++i)
		printf("%s\t", wdlst[i]);
}

void letter_stat(const char s[])	//字频统计 
{
	int sta[26] = {}, i = 0 , j;	//sta为各字母统计数据 
	char tmp[100];	//最多统计100个字符 
	
	while(s[i])
	{
		tmp[i] = s[i];	//复制传递进来的字符串 
		++i;
	}
	tmp[i] = '\0';
	i = 0;
	
	while(tmp[i])
	{
		if(tmp[i] < 97)
			tmp[i] += 32;	//将字母转为小写 
		if(tmp[i] >= 97 && tmp[i] <= 122)
			sta[tmp[i]-97] += 1;	//记录数据 
		++i;
	}
	
	puts("统计数据如下");
	for(i = 0 ; i < 26 ; ++i)	//输出数据 
	{
		printf("%c : ", 97 + i);
		if(sta[i])
		{
			for(j = 0 ; j < sta[i] ; ++j)
				printf("*");
		}
		printf("\n");
	}
}

void saddle_point()	//鞍点 
{
	int i , j , k , l=0 , arr[5][5];
	puts("生成的随机数组为：");
	for(i = 0 ; i < 5 ; ++i)	//生成5*5随机数组（如果元素太多，很难有鞍点） 
	{
		for(j = 0 ; j < 5 ; ++j)
		{
			arr[i][j] = randf(0.0 , 10.0);
			printf("%d\t", arr[i][j]);	//输出数组
		}
		printf("\n");
	}
	
	for(i = 0 ; i < 5 ; ++i)
	{
		for(j = 0 ; j < 5 ; ++j)	//遍历数组元素 
		{
			int saddle = 1;
			for(k = 0 ; k < 5 ; ++k)	//检测是否为鞍点 
			{
				if(arr[i][j] < arr[i][k])	//满足两个if条件其一，则不是鞍点 
					saddle = 0;
				if(arr[i][j] > arr[k][j])
					saddle = 0;
			}
			if(saddle == 1)
			{
				printf("第%d行，第%d列的%d是鞍点\n",i+1 ,j+1 , arr[i][j]);	//是鞍点则输出结果 
				l = 1;	//标注有鞍点 
			}
		}
	}
	if(! l)
		puts("数组中无鞍点");	//无鞍点提示 
}

void diag_sum()	//矩阵对角线 
{
	int i , j , a[5][5];
	for(i = 0 ; i < 5 ; ++i)	//输入所求矩阵 
	{
		for(j = 0 ; j < 5 ; ++j)
		{
			printf("请输入第%d行第%d列的元素：",i+1 , j+1);
			scanf("%d",&a[i][j]);
		}
	}
	puts("\n您输入的矩阵为：");	//确认输入 
	for(i = 0 ; i < 5 ; ++i)
	{
		for(j = 0 ; j < 5 ; ++j)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	
	int sum1=0 , sum2=0;
	for(i = 0 ; i < 5 ; ++i)	//求和 
	{
		sum1 += a[i][i];
		sum2 += a[i][4-i];
	}
	printf("\n主对角线之和为%d，副对角线之和为%d", sum1 , sum2);
}

void skim(const char a[])	//删除多余空格 
{
	int ori_len = str_len(a) , skimed_len=0 , i;	//str_len()获取长度 
	for(i = 0 ; i < ori_len ; ++i)
	{
		if(a[i] == ' ' && a[i+1] == ' ')	//检测连续空格 
		{
			i++;	//遇到连续空格则跳过一个空格 
		}
		skimed_len++ ;
	}
	
	printf("原长度为%d，删去多余空格后长度为%d。", ori_len , skimed_len);
}

int main()
{
	srand((unsigned)time(NULL));

	//选择排序
	puts("--------选择排序问题--------");
	select_sort();
	puts("\n--------结束--------\n");
	system("pause");
	
	//实现strlen()
	getchar();
	char a[100];
	puts("\n--------实现strlen()--------\n输入一个字符串，返回其strlen()的值（短于100）：");
	gets(a);
	printf("strlen(a) = %d." , str_len(a));
	puts("\n--------结束--------\n");
	system("pause");
	
	//实现strcmp()
	char b[100];
	puts("\n--------实现strcmp()--------\n输入两个字符串，返回strcmp()作用于它们时的返回值：");
	gets(a);
	gets(b);
	
	printf("strcmp(a,b) = %d" , str_cmp(a , b));
	puts("\n--------结束--------\n");
	system("pause");
	
	//单词排序 
	puts("\n--------单词排序问题--------\n");
	word_sort();
	puts("\n--------结束--------\n");
	system("pause");
	
	//字频统计
	getchar();
	puts("\n--------字频统计问题--------\n输入一段文字：");
	gets(a);
	letter_stat(a);
	puts("\n--------结束--------\n");
	system("pause");
	
	//数组鞍点
	puts("\n--------数组鞍点问题（P160 8）--------\n");
	saddle_point();
	puts("\n--------结束--------\n");
	system("pause");
	
	//对角线之和
	puts("\n--------矩阵对角线元素之和问题（P160 9）--------\n");
	diag_sum();
	puts("\n--------结束--------\n");
	system("pause");
	
	//删除多余空格
	getchar();
	puts("\n--------删除多余空格并统计字数问题（P160 12）--------\n输入一段文字：");
	gets(a);
	skim(a);
	puts("\n--------结束--------\n");
	
	return 0;
}
