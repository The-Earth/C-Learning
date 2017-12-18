#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//########################################
//#                                      #
//#                                      #
//#   ���ڱ�Դ�����ļ�������ҵҪ���д   #
//#        û�н����û������Ż�          #
//#          ��������������            #
//#                                      #
//########################################

void del_pos(char *obj , int k , int m , int len)
{
	
	for(int i = k - 1 ; i < k + m - 1 ; ++i)
		*(obj + i) = *(obj + i + m);
	
	if(k + m > len)
		*(obj + k) = '\0';
	else
		*(obj + len - m) = '\0';
}

void move_1(char *obj , int k)
{
	int i = 0;
	do
		*(obj + k + i) = *(obj + k + i + 1);
	while(*(obj + k + i++));
		
}

void del_par(char *obj , char let)
{
	int i = -1;
	do
	{
		if(*(obj + ++i) == let)
			move_1(obj , i);
	}while(*(obj + i));
}

typedef struct
{
	char name[32];
	int age;
} student;

int age_sort_input(student *data, int i , int n)
{
	int age_tmp;
	printf("�����%d��ѧ�������������䣨����ֻ����ASCII���Կո�ָ�������������end����ֹ���룬�������%d�飺" , i , n);
	scanf("%s %d", &((*data).name) , &((*data).age));
	if(strcmp((*data).name , "end") == 0)
		return -1;
	else 
		return 0;
}

void age_sort_core(student *p , int len)
{
	for(int i = 0 ; i < len ; ++i)
	{
		for(int j = len - 1 ; j > i ; --j)
		{
			if((*(p + j)).age > (*(p + j - 1)).age)
			{
				student tmp;
				tmp = *(p + j) ; *(p + j) = *(p + j - 1) ; *(p + j - 1) = tmp ; 
			}
		}
	}
}

void age_sort_output(student *p , int len)
{
	for(int i = 0 ; i < len ; ++i)
		printf("%s\t%d\n" , (*(p + i)).name , (*(p + i)).age);
}

void age_sort_main()
{
	int i = 1 , n;
	puts("����ѧ��������");
	scanf("%d" , &n);
	student data[n];
	do
	{
		if(age_sort_input(&data[i-1] , i , n) == -1)
			break;
	} while(++i <= n);
	
	int len = i - 1;
	
	age_sort_core(data , len);
	puts("�����������£�");
	age_sort_output(data , len);
}

int main()
{
	puts("########################################\n#                                      #\n#                                      #\n#   ���ڱ�Դ�����ļ�������ҵҪ���д   #\n#        û�н����û������Ż�          #\n#          ��������������            #\n#                                      #\n########################################");
	//P207 6
	puts("P207 6");
	puts("abcde �ӵڣ����ַ���ɾ�������ַ���");
	int m , n;
	char s[] = "abcde" , *p = s ;
	scanf("%d %d" , &m ,&n);
	del_pos(p , m , n , sizeof(s)-1);
	printf("%s",s);
	puts("\n");
	
	//P207 7
	char t[] = "teacher" , let='e';
	p = t;
	del_par(p , let);
	printf("%s",t);
	puts("\n");
	
	//ѧ����������
	age_sort_main();
	
	return 0;
}
