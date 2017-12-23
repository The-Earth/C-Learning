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
	fclose(fp);
}

void show_src_main()
{
	FILE *fp;
	char filedir[128] , ctl[128];
	
	puts("��������ȡ�ļ�֮·����");
	scanf("%s",filedir);
	if((fp = fopen(filedir , "r")) == NULL)
		puts("\a�ļ���ʧ�ܡ�\n");
	else
	{
		int i=0;
		while(fgets(ctl  , 128 , fp))
		{
			printf("%d | %s", ++i,ctl);
		}
	}
	fclose(fp);
}

int is_complete(int n)
{
	int sum = 0;
	for(int i = 1 ; i < n ; ++i)
	{
		if(n % i == 0)
			sum += i;
	}
	
	if(sum == n)
		return 1;
	else
		return 0;
}

void complete_output()
{
	FILE *fp;
	fp = fopen("file1.txt" , "w");

	for(int i = 2 ; i <= 1000 ; ++i)
	{
		if(is_complete(i))
			fprintf(fp , "%d\t" , i);
	}
	puts("��������ѱ�����file1.txt");
	fclose(fp);
}

void complete_read()
{
	FILE *fp;
	char txt[32];
	fp = fopen("file1.txt", "r");
	fgets(txt , 32 , fp);
	printf("file1.txt���������£�\n%s\n" , txt);
	
	rewind(fp);
	int tmp , i = 0;
	double sum = 0.0;
	while(fscanf(fp , "%d" , &tmp) == 1)
	{
		sum += tmp;
		i ++;
	}
	
	printf("ƽ��ֵΪ%f" , sum / i);
	
	fclose(fp);
}

int main()
{
	/*
	student_sort_main();
	system("pause");
	lines_main();
	system("pause"); 
	show_src_main();
	system("pause");*/
	complete_output();
	complete_read();
	
	return 0;
}
