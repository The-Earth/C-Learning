#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
	
	puts("Ranked in decending sort:");	//Ωµ–Ú≈≈¡– 
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

//MODIFY NEEDED!!!!! 
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
		
		strcpy(tmp , wdlst[i]) ; strcpy(wdlst[i] , wdlst[max_index]) ; strcpy(wdlst[max_index] , tmp) ;
	}
	
	puts("Ranked in decending sort:");	//Ωµ–Ú≈≈¡– 
	for(i = 0 ; i < 10 ; ++i)
		printf("%s\t", wdlst[i]);
}

int main()
{
	/*
	//—°‘Ò≈≈–Ú 
	select_sort();
	system("pause");
	
	//strlen()
	char a[100];
	puts("Input a string and I will tell you its length.");
	scanf("%s" , a);
	printf("strlen() = %d." , str_len(a));
	system("pause");
	
	//strcmp()
	char , b[100];
	puts("Input 2 strings and I will compare them.");
	scanf("%s" , a);
	scanf("%s" , b);
	
	printf("strcmp(a,b) = %d" , str_cmp(a , b));
	system(pause);*/
	
	word_sort();
	
	return 0;
}
