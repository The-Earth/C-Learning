#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int age_sort_input(student *data, int i)
{
	int age_tmp;
	printf("输入第%d个学生的姓名和年龄（姓名只接受ASCII，以空格分隔），姓名输入end以终止输入，最多输入40组：" , i);
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
	int i = 1;
	student data[39];
	do
	{
		if(age_sort_input(&data[i-1] , i) == -1)
			break;
	} while(++i < 40);
	
	int len = i - 1;
	
	age_sort_core(data , len);
	
	age_sort_output(data , len);
}

int main()
{
	//P207 6
	char s[] = "abcde" , *p = s ;
	del_pos(p , 4 , 1 , sizeof(s)-1);
	printf("%s",s);
	puts("\n");
	
	//P207 7
	char t[] = "teacher" , let='e';
	p = t;
	del_par(p , let);
	printf("%s",t);
	puts("\n");
	
	//学生年龄排序
	age_sort_main();
	
	return 0;
}
