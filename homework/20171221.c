#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char name[32];
	int age;
} student_1;

typedef struct
{
	char name[32];
	char id[32];
	int mark;
} student_2;

void age_sort_core(student_1 *p , int len)
{
	for(int i = 0 ; i < len ; ++i)
	{
		for(int j = len - 1 ; j > i ; --j)
		{
			if((*(p + j)).age > (*(p + j - 1)).age)
			{
				student_1 tmp;
				tmp = *(p + j) ; *(p + j) = *(p + j - 1) ; *(p + j - 1) = tmp ; 
			}
		}
	}
}

void student_sort_main()
{
	student_1 *data , *data_copy;
	int data_len;
	//input_start
	puts("输入学生数：");
	scanf("%d", &data_len);
	
	data = (student_1*)malloc(data_len*sizeof(student_1));
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
	
	puts("输入欲读取文件之路径：");
	scanf("%s",filedir);
	if((fp = fopen(filedir , "r")) == NULL)
		puts("\a文件打开失败。\n");
	else
		printf("文件中共%d行" , lines_core(fp));
	fclose(fp);
}

void show_src_main()
{
	FILE *fp;
	char filedir[128] , ctl[128];
	
	puts("输入欲读取文件之路径：");
	scanf("%s",filedir);
	if((fp = fopen(filedir , "r")) == NULL)
		puts("\a文件打开失败。\n");
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
	puts("完数结果已保存在file1.txt");
	fclose(fp);
}

void complete_read()
{
	FILE *fp;
	char txt[32];
	fp = fopen("file1.txt", "r");
	fgets(txt , 32 , fp);
	printf("file1.txt的内容如下：\n%s\n" , txt);
	
	rewind(fp);
	int tmp , i = 0;
	double sum = 0.0;
	while(fscanf(fp , "%d" , &tmp) == 1)
	{
		sum += tmp;
		i ++;
	}
	
	printf("平均值为%f" , sum / i);
	
	fclose(fp);
}

void exmres()
{
	student_2 *data , *data_copy;
	int data_len;
	//input_start
	puts("输入学生数：");
	scanf("%d", &data_len);
	
	data = (student_2*)malloc(data_len*sizeof(student_2));
	data_copy = data;
	
	for(int i = 0 ; i < data_len ; ++i)
	{
	 	printf("依输入第%d个学生的姓名、学号、成绩，空格分隔，姓名只接受ASCII：", i+1);
	 	scanf("%s %s %d" , &((*(data+i)).name) , &((*(data+i)).id) , &((*(data+i)).mark));
	}
	
	data = data_copy;
	
	FILE *dat;
	if((dat = fopen("file2.dat" , "wb"))== NULL)
		puts("打开文件失败");
	else
	{
		for(int i ; i < data_len ; ++i)
			fwrite(data+i , sizeof(student_2) , 1 , dat);
	}
	puts("内容保存于file2.dat");
	fclose(dat);
}

int main()
{
	puts("========学生年龄排序问题========"); 
	student_sort_main();
	system("pause");
	lines_main();
	system("pause"); 
	show_src_main();
	system("pause");
	complete_output();
	system("pause");
	complete_read();
	system("pause");
	exmres();
	
	
	return 0;
}
