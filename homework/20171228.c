#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STUDENT struct student

struct student
{
	char name[32];
	int mark;
	STUDENT *next;
};

struct stu2
{
	char name[32];
	int mark; 
};

STUDENT *init()
{
	STUDENT *head = (STUDENT*)malloc(sizeof(STUDENT));
	puts("�����һ��ѧ���������ɼ���");
	scanf("%s %d", &(head->name), &(head->mark));
	head->next = NULL;
	return head;
}

STUDENT *input_core(STUDENT *pre)
{
	STUDENT *cur = (STUDENT *)malloc(sizeof(STUDENT));
	char name_tmp[32]; int mark_tmp;
	
	puts("�������� �ɼ���");
	scanf("%s %d", &name_tmp, &mark_tmp);
	if(mark_tmp == -1)
		return NULL;
	strcpy(cur->name, name_tmp);
	cur->mark = mark_tmp;
	cur->next = NULL;
	pre->next = cur;
	
	return cur;
}

void input(STUDENT *p)
{
	puts("--------\n��������ѧ����Ϣ��"); 
	while(1)	//input
	{
		STUDENT *pre = input_core(p);
		if(pre == NULL)
			break;
		else
			p = pre;
	}
}

void show(STUDENT *p)
{
	printf("%s\t%d\n", p->name, p->mark);
	if(p->next)
		show(p->next);
}

void search_name(STUDENT *head, char key[32])
{ 
	if(strcmp(key, head->name) == 0)
		printf("%s�ĳɼ�Ϊ��%d", head->name, head->mark);
	else
	{
		if(!(head->next))
			puts("δ�ҵ�");
		else
			search_name(head->next, key);
	}
}

void search_mark(STUDENT *head, int key)
{
	if(key == head->mark)
		printf("�ɼ�Ϊ%d��ѧ���У�%s\n", key , head->name);
	else
	{
		if(head->next == NULL)
			puts("δ�ҵ�");
		else
			search_mark(head->next, key);
	}
}

void del(STUDENT *pre, STUDENT *p, STUDENT **head, char key[32])
{
	if(strcmp(key, p->name) == 0)
	{
		if(pre == NULL)
		{
			STUDENT *nxt = p->next, *head_c = *head;
			*head = nxt;
			free(head_c);
		}
		else
		{
			pre->next = p->next;
			free(p);
		}
	}
	else
		del(p, p->next, head, key);
}

void free_memory(STUDENT *p)
{
	if(p->next == NULL)
		free(p);
	else
	{
		free_memory(p->next);
		free(p);
	}
}

void stu_info()
{
	STUDENT *head = init();
	STUDENT *tail = head;
	
	func:puts("\nѡ��\n1����������\n2����ʾ��������\n3������������\n4�����ɼ�����\n5��ɾ��ָ��ѧ��\n6���˳�");
	int opt , exit = 0;
	STUDENT *p = head;
	char namekey[32];
	int markkey;
	
	scanf("%d", &opt);
	switch(opt)
	{
		case 1:
			input(tail);
			break;
		case 2:
			puts("\n����\tѧ��"); 
			show(p);
			break;
		case 3:
			puts("\n����Ҫ���ҵ�������"); 
			scanf("%s", namekey);
			search_name(p , namekey);
			break;
		case 4:
			puts("\n����Ҫ���ҵķ�����"); 
			scanf("%d", &markkey);
			search_mark(p , markkey);
			break;
		case 5:
			puts("\n����Ҫɾ����ѧ��������");
			scanf("%s", namekey);
			del(NULL, p, &head, namekey);
			break;	
		case 6:
			exit = 1;
	}
	if(exit == 0)
		goto func;
	free_memory(head);
}

struct stu2 *output(struct stu2 *a, int n, struct stu2 *(*b)(struct stu2 *x, int m))
{
	struct stu2 *p;
	p = b(a, n);

	return p;
}

struct stu2 *sort_name(struct stu2 *a, int n)
{
	struct stu2 *p = a;
	struct stu2 t;

	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (strcmp((*(p + i)).name, (*(p + j)).name) > 0)
			{
				t = *(p + i);
				*(p + i) = *(p + j);
				*(p + j) = t;
			}
		}
	}

	return a;
}

struct stu2 *sort_mark(struct stu2 *a, int n)
{
	struct stu2 *p = a;
	struct stu2 t;

	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if ((*(p + i)).mark > (*(p + j)).mark)
			{
				t = *(p + i);
				*(p + i) = *(p + j);
				*(p + j) = t;
			}
		}
	}

	return a;
}

void stu_arrange()
{
	int a2;
	puts("����ѧ������");
	scanf("%d", &a2);
	getchar();
	struct stu2 *c2 = (struct stu2 *)calloc(a2, sizeof(struct stu2));
	for (int i = 0; i < a2; ++i)
	{
		puts("�������� �ɼ�");
		scanf("%s %d",c2[i].name, &c2[i].mark);
	}

	puts("�����������£�");
	for (int i = 0; i < a2; ++i)
		printf("%s\t%d\n", output(c2, a2, *sort_name)[i].name, output(c2, a2, *sort_name)[i].mark);
	printf("\n");

	puts("�ɼ��������£�");
	for (int i = 0; i < a2; ++i)
		printf("%s\t%d\n", output(c2, a2, *sort_mark)[i].name, output(c2, a2, *sort_mark)[i].mark);
	puts("\n\n");

	free(c2);
}

int main()
{
	stu_info();
	stu_arrange();
	
	return 0;
}
