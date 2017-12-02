#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

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
void dist_main();
void mul_cplx_main();
struct complex;
struct complex mul_cplx(struct complex z1 , struct complex z2);

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

void mark_sort()	//�ɼ����� 
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
				tmp = stulist[j] ; stulist[j] = stulist[j-1] ; stulist[j-1] = tmp ;
			}
		}
	}
	puts("���ɼ��Ӹߵ����������£�");
	for(int i = 0 ; i < 10 ; ++i)
		printf("%s\t%.1f\n", stulist[i].name , stulist[i].mark);
}

struct array	//�����̶������� 
{
	int index;
	int value;
};

void div_find()	//���ַ����������� 
{ 
	struct array arr[1000] , tmp;
	puts("���ɵ��������Ϊ��\n���\t��ֵ");
	system("pause");
	for(int i = 0 ; i < 1000 ; ++i)
	{
		arr[i].value = randf(0 , 999);
		arr[i].index = i;
		printf("%d\t%d\n" , i , arr[i].value);
	}
	
	for(int i = 0 ; i < 1000 ; ++i)	//���� 
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
	puts("������Ҫ���ҵ���");
	scanf("%d", &target);
	
	for(int i = 0 ; i < 1000 ; ++i)
	{
		arrval[i] = arr[i].value;
	}
	
	int res = div_find_core(arrval , target , 1000) ;
	if(res >= 0)
		printf("һ��Ŀ����������Ϊ%d", arr[res].index);
	else
		printf("δ���ҵ�Ŀ�ꡣ");
}

int div_find_core(int arr[] , int tar , int len)	//���ַ����Һ��� 
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

int randf(double min, double max)	//����������� 
{
	double r;
	r = rand();
	return (int)(r / RAND_MAX * (max - min) + min);
}

struct loc	//����
{
	double x;
	double y;
};

double dist(struct loc z1 , struct loc z2)	//���������� 
{
	return (sqrt(pow(z1.x - z2.x, 2) + pow(z1.y - z2.y , 2)));
}

void dist_main()	//���������������� 
{
	struct loc z1 , z2 ;
	puts("�����������꣬������룺\n��һ�����꣨X Y �Կո�ָ�����");
	scanf("%lf %lf" , &z1.x , &z1.y);
	puts("�ڶ������꣨X Y �Կո�ָ�����");
	scanf("%lf %lf" , &z2.x , &z2.y);
	printf("����֮��ľ���Ϊ��%.3f" , dist(z1 , z2));
}

struct complex	//���� 
{
	double x;
	double y;
};

void mul_cplx_main()	//�����ɼ������� 
{
	struct complex z1 , z2;
	puts("������������������˻���\n�ڸ����� X+iY��X Y �Կո�ָ�����");
	scanf("%lf %lf" , &z1.x , &z1.y);
	puts("�ڶ������� X+iY��X Y �Կո�ָ�����");
	scanf("%lf %lf" , &z2.x , &z2.y);
	printf("���ǳ˻�Ϊ��%.3f+%.3f i" , mul_cplx(z1 , z2).x , mul_cplx(z1 , z2).y);
}

struct complex mul_cplx(struct complex z1 , struct complex z2)	//���㸴���˻� 
{
	struct complex res;
	res.x = z1.x * z2.x - z1.y * z2.y ;
	res.y = z1.y * z2.x + z1.x * z2.y ;
	return res; 
} 

int main()
{
	srand((unsigned)time(NULL));
	
	//����ð��
	puts("======== ����ð���������� ========");
	word_sort();
	puts("\n======== ���� ========\n");
	system("pause");
	
	//�ɼ�����
	puts("======== �ɼ��������� ========");
	mark_sort();
	puts("\n======== ���� ========\n");
	system("pause");
	
	//���ַ����� 
	puts("======== ���ַ��������� ========"); 
	div_find();
	puts("\n======== ���� ========\n");
	system("pause");
	
	//P178 2
	puts("======== P178 2 ========");
	dist_main();
	puts("\n======== ���� ========\n");
	system("pause");
	
	//P178 3
	puts("======== P178 3 ========");
	mul_cplx_main();
	puts("\n======== ���� ========\n");
	
	return 0;
}
