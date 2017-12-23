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
	puts("����ѧ������");
	scanf("%d", &data_len);
	
	data = (student*)malloc(data_len*sizeof(student));
	data_copy = data;
	
	for(int i = 0 ; i < data_len ; ++i)
	{
	 	printf("�����%d��ѧ�����������䣬�ո�ָ�������ֻ����ASCII��", i+1);
	 	scanf("%s %d" , &((*(data+i)).name) , &((*(data+i)).age));
	}
	
	data = data_copy;
	//start end
	
	age_sort_core(data , data_len);
	
	//output
	puts("����\t����");
	for(int i = 0 ; i < data_len ; ++i)
		printf("%s\t%d\n" , (*(data + i)).name , (*(data + i)).age);
	
	free(data);
}

int lines_core(FILE *file)
{
	int i=0;
	char c;
	while(1)
	{
		c = fgetc(file);
		if(c == EOF)
			break;
		if(c == 10)
			i++;
	}
	
	return i;
}

void lines_main()
{
	FILE *fp;
	char filedir[128];
	
	puts("��������ȡ�ļ�֮·����");
	scanf("%s",filedir);
	if((fp = fopen(filedir , "r")) == NULL)
		puts("\a�ļ���ʧ�ܡ�\n");
	else
		printf("�ļ��й�%d��" , lines_core(fp));
}

int main()
{
	//student_sort_main();
	lines_main();
	
	return 0;
}
