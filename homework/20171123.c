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

void select_sort()
{
	puts("Input an array with length 10 as guided.");
	int i , a[10];
	for(i = 0 ; i < 10 ; ++i)
	{
		printf("Input element with index %d : ", i);
		scanf("%d" , &a[i]);
	}
	
	for(i = 0 ; i < 10 ; ++i)
	{
		int j , tmp , max_index;
		max_index = i;
		for(j = i ; j < 10 ; ++j)
			max_index = a[j] > a[max_index] ? j : max_index ; 
		
		tmp = a[i] ; a[i] = a[max_index] ; a[max_index] = tmp;
	}
	
	puts("Ranked in decending sort:");	//降序排列 
	for(i = 0 ; i < 10 ; ++i)
		printf("%d\t", a[i]);
}

int str_len(const char b[])
{
	int len = 0;
	while(b[len])
		len += 1;
	return len;
}

int str_cmp(const char s1[] , const char s2[])
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

void word_sort()
{
	puts("Sorting 10 words in a decending rank.");
	char wdlst[10][33]; int i;
	
	for(i = 0 ; i < 10 ; ++i)
	{
		printf("Input word with index %d (NO MORE THAN 32 LETTERS !): ", i);
		scanf("%s" , wdlst[i]);
	}
	
	for(i = 0 ; i < 10 ; ++i)
	{
		int j , max_index; char tmp[33];
		max_index = i;
		for(j = i ; j < 10 ; ++j)
			max_index = strcmp(wdlst[max_index] , wdlst[j]) < 0 ? j : max_index ;
		
		strcpy(tmp , wdlst[i]) ;
		strcpy(wdlst[i] , wdlst[max_index]) ;
		strcpy(wdlst[max_index] , tmp) ;
	}
	
	puts("Ranked in decending sort:");	//降序排列 
	for(i = 0 ; i < 10 ; ++i)
		printf("%s\t", wdlst[i]);
}

void letter_stat(const char s[])
{
	int sta[26] = {}, i = 0 , j;
	char tmp[100];
	while(s[i])
	{
		tmp[i] = s[i];
		++i;
	}
	tmp[i] = '\0';
	i = 0;
	
	while(tmp[i])
	{
		if(tmp[i] < 97)
			tmp[i] += 32;	//lowering
		if(tmp[i] >= 97 && tmp[i] <= 122)
			sta[tmp[i]-97] += 1;
		++i;
	}
	
	puts("Here is the static data:");
	for(i = 0 ; i < 26 ; ++i)
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

void saddle_point()
{
	int i , j , k , l=0 , arr[5][5];
	puts("生成的随机数组为：");
	for(i = 0 ; i < 5 ; ++i)	//生成随机数组 
	{
		for(j = 0 ; j < 5 ; ++j)
		{
			arr[i][j] = randf(0.0 , 10.0);
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}
	
	for(i = 0 ; i < 5 ; ++i)
	{
		for(j = 0 ; j < 5 ; ++j)
		{
			int saddle = 1;
			for(k = 0 ; k < 5 ; ++k)
			{
				if(arr[i][j] < arr[i][k])
					saddle = 0;
				if(arr[i][j] > arr[k][j])
					saddle = 0;
			}
			if(saddle == 1)
			{
				printf("第%d行，第%d列的%d是鞍点\n",i+1 ,j+1 , arr[i][j]);
				l = 1;
			}
		}
	}
	if(! l)
		puts("数组中无鞍点");
}

void diag_sum()
{
	int i , j , a[5][5];
	for(i = 0 ; i < 5 ; ++i)
	{
		for(j = 0 ; j < 5 ; ++j)
		{
			printf("请输入第%d行第%d列的元素：",i+1 , j+1);
			scanf("%d",&a[i][j]);
		}
	}
	puts("\n您输入的矩阵为：");
	for(i = 0 ; i < 5 ; ++i)
	{
		for(j = 0 ; j < 5 ; ++j)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	
	int sum1=0 , sum2=0;
	for(i = 0 ; i < 5 ; ++i)
	{
		sum1 += a[i][i];
		sum2 += a[i][4-i];
	}
	printf("\n主对角线之和为%d，副对角线之和为%d", sum1 , sum2);
}

void skim(const char a[])
{
	int ori_len = str_len(a) , skimed_len=0 , i;
	for(i = 0 ; i < ori_len ; ++i)
	{
		if(a[i] == ' ' && a[i+1] == ' ')
		{
			i++;
		}
		skimed_len++ ;
	}
	
	printf("原长度为%d，删去多余空格后长度为%d。", ori_len , skimed_len);
}

int main()
{
	srand((unsigned)time(NULL));

	//selective sort
	select_sort();
	system("pause");
	
	//strlen()
	char a[100];
	puts("Input a string and I will tell you its length.");
	gets(a);
	printf("strlen() = %d." , str_len(a));
	system("pause");
	
	//strcmp()
	char b[100];
	puts("Input 2 strings and I will compare them.");
	gets(a);
	gets(b);
	
	printf("strcmp(a,b) = %d" , str_cmp(a , b));
	system("pause");
	
	//word sort
	word_sort();
	system("pause");
	
	//letter static
	gets(a);
	printf("%s\n",s);
	letter_stat(s);
	system("pause");
	
	//Saddle point
	saddle_point();
	system("pause");
	
	//对角线之和
	diag_sum();
	system("pause")
	
	gets(a);
	skim(a);
	
	return 0;
}
