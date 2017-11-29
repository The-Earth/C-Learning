#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int randf(double min, double max)	//����������� 
{
	double r;
	r = rand();
	return (int)(r / RAND_MAX * (max - min) + min);
}

void select_sort()	//ѡ������ 
{
	puts("��ָʾ���볤��Ϊ10������");	//�������� 
	int i , a[10];
	for(i = 0 ; i < 10 ; ++i)
	{
		printf("�����%d��Ԫ�أ�", i+1);
		scanf("%d" , &a[i]);
	}
	
	for(i = 0 ; i < 10 ; ++i)
	{
		int j , tmp , max_index;
		max_index = i;
		for(j = i ; j < 10 ; ++j)
			max_index = a[j] > a[max_index] ? j : max_index ;	//��¼�������
		
		tmp = a[i] ; a[i] = a[max_index] ; a[max_index] = tmp;	//����Ԫ��λ�� 
	}
	
	puts("��������������");	//��������� 
	for(i = 0 ; i < 10 ; ++i)
		printf("%d\t", a[i]);
}

int str_len(const char b[])	//�����ַ������� 
{
	int len = 0;
	while(b[len])
		len += 1;
	return len;
}

int str_cmp(const char s1[] , const char s2[])	//�Ƚ��ַ�����ʵ��strcmp()�� 
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

void word_sort()	//���е��� 
{
	puts("����ʮ�����ʣ�");
	char wdlst[10][33]; int i;
	for(i = 0 ; i < 10 ; ++i)	//�������� 
	{
		printf("��%d�����ʣ�������32����ĸ����", i+1);
		scanf("%s" , wdlst[i]);
	}
	
	for(i = 0 ; i < 10 ; ++i)	//�������� 
	{
		int j , max_index; char tmp[33];
		max_index = i;
		for(j = i ; j < 10 ; ++j)
			max_index = strcmp(wdlst[max_index] , wdlst[j]) < 0 ? j : max_index ;	//��¼����ߵ����� 
		
		strcpy(tmp , wdlst[i]) ; strcpy(wdlst[i] , wdlst[max_index]) ; strcpy(wdlst[max_index] , tmp) ; //��������˳�� 
	}
	
	puts("Ranked in decending sort:");	//��������� 
	for(i = 0 ; i < 10 ; ++i)
		printf("%s\t", wdlst[i]);
}

void letter_stat(const char s[])	//��Ƶͳ�� 
{
	int sta[26] = {}, i = 0 , j;	//staΪ����ĸͳ������ 
	char tmp[100];	//���ͳ��100���ַ� 
	
	while(s[i])
	{
		tmp[i] = s[i];	//���ƴ��ݽ������ַ��� 
		++i;
	}
	tmp[i] = '\0';
	i = 0;
	
	while(tmp[i])
	{
		if(tmp[i] < 97)
			tmp[i] += 32;	//����ĸתΪСд 
		if(tmp[i] >= 97 && tmp[i] <= 122)
			sta[tmp[i]-97] += 1;	//��¼���� 
		++i;
	}
	
	puts("ͳ����������");
	for(i = 0 ; i < 26 ; ++i)	//������� 
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

void saddle_point()	//���� 
{
	int i , j , k , l=0 , arr[5][5];
	puts("���ɵ��������Ϊ��");
	for(i = 0 ; i < 5 ; ++i)	//����5*5������飨���Ԫ��̫�࣬�����а��㣩 
	{
		for(j = 0 ; j < 5 ; ++j)
		{
			arr[i][j] = randf(0.0 , 10.0);
			printf("%d\t", arr[i][j]);	//�������
		}
		printf("\n");
	}
	
	for(i = 0 ; i < 5 ; ++i)
	{
		for(j = 0 ; j < 5 ; ++j)	//��������Ԫ�� 
		{
			int saddle = 1;
			for(k = 0 ; k < 5 ; ++k)	//����Ƿ�Ϊ���� 
			{
				if(arr[i][j] < arr[i][k])	//��������if������һ�����ǰ��� 
					saddle = 0;
				if(arr[i][j] > arr[k][j])
					saddle = 0;
			}
			if(saddle == 1)
			{
				printf("��%d�У���%d�е�%d�ǰ���\n",i+1 ,j+1 , arr[i][j]);	//�ǰ����������� 
				l = 1;	//��ע�а��� 
			}
		}
	}
	if(! l)
		puts("�������ް���");	//�ް�����ʾ 
}

void diag_sum()	//����Խ��� 
{
	int i , j , a[5][5];
	for(i = 0 ; i < 5 ; ++i)	//����������� 
	{
		for(j = 0 ; j < 5 ; ++j)
		{
			printf("�������%d�е�%d�е�Ԫ�أ�",i+1 , j+1);
			scanf("%d",&a[i][j]);
		}
	}
	puts("\n������ľ���Ϊ��");	//ȷ������ 
	for(i = 0 ; i < 5 ; ++i)
	{
		for(j = 0 ; j < 5 ; ++j)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	
	int sum1=0 , sum2=0;
	for(i = 0 ; i < 5 ; ++i)	//��� 
	{
		sum1 += a[i][i];
		sum2 += a[i][4-i];
	}
	printf("\n���Խ���֮��Ϊ%d�����Խ���֮��Ϊ%d", sum1 , sum2);
}

void skim(const char a[])	//ɾ������ո� 
{
	int ori_len = str_len(a) , skimed_len=0 , i;	//str_len()��ȡ���� 
	for(i = 0 ; i < ori_len ; ++i)
	{
		if(a[i] == ' ' && a[i+1] == ' ')	//��������ո� 
		{
			i++;	//���������ո�������һ���ո� 
		}
		skimed_len++ ;
	}
	
	printf("ԭ����Ϊ%d��ɾȥ����ո�󳤶�Ϊ%d��", ori_len , skimed_len);
}

int main()
{
	srand((unsigned)time(NULL));

	//ѡ������
	puts("--------ѡ����������--------");
	select_sort();
	puts("\n--------����--------\n");
	system("pause");
	
	//ʵ��strlen()
	getchar();
	char a[100];
	puts("\n--------ʵ��strlen()--------\n����һ���ַ�����������strlen()��ֵ������100����");
	gets(a);
	printf("strlen(a) = %d." , str_len(a));
	puts("\n--------����--------\n");
	system("pause");
	
	//ʵ��strcmp()
	char b[100];
	puts("\n--------ʵ��strcmp()--------\n���������ַ���������strcmp()����������ʱ�ķ���ֵ��");
	gets(a);
	gets(b);
	
	printf("strcmp(a,b) = %d" , str_cmp(a , b));
	puts("\n--------����--------\n");
	system("pause");
	
	//�������� 
	puts("\n--------������������--------\n");
	word_sort();
	puts("\n--------����--------\n");
	system("pause");
	
	//��Ƶͳ��
	getchar();
	puts("\n--------��Ƶͳ������--------\n����һ�����֣�");
	gets(a);
	letter_stat(a);
	puts("\n--------����--------\n");
	system("pause");
	
	//���鰰��
	puts("\n--------���鰰�����⣨P160 8��--------\n");
	saddle_point();
	puts("\n--------����--------\n");
	system("pause");
	
	//�Խ���֮��
	puts("\n--------����Խ���Ԫ��֮�����⣨P160 9��--------\n");
	diag_sum();
	puts("\n--------����--------\n");
	system("pause");
	
	//ɾ������ո�
	getchar();
	puts("\n--------ɾ������ո�ͳ���������⣨P160 12��--------\n����һ�����֣�");
	gets(a);
	skim(a);
	puts("\n--------����--------\n");
	
	return 0;
}
