#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char name[32];
	int age;
} student;

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

void student_sort_main()
{
	student *data , *data_copy;
	int data_len;
	//input_start
	puts("输入学生数：");
	scanf("%d", &data_len);
	
	data = (student*)malloc(data_len*sizeof(student));
	data_copy = data;
	
	for(int i = 0 ; i < data_len ; ++i)
	{
	 	printf("输入第%d个学生的姓名年龄，空格分隔，姓名只接受ASCII：", i+1);
	 	scanf("%s %d" , &((*(data+i)).name) , &((*(data+i)).age));
	}
	
	data = data_copy;
	//start end
	
	age_sort_core(data , data_len);
	
	//output
	puts("姓名\t年龄");
	for(int i = 0 ; i < data_len ; ++i)
		printf("%s\t%d\n" , (*(data + i)).name , (*(data + i)).age);
	
	free(data);
}

int main()
{
	student_sort_main();
	return 0;
}
