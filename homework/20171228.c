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
		free_memory(p->next);
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
			show(p);
			break;
		case 3:
			puts("����Ҫ���ҵ�������"); 
			scanf("%s", namekey);
			search_name(p , namekey);
			break;
		case 4:
			puts("����Ҫ���ҵķ�����"); 
			scanf("%d", &markkey);
			search_mark(p , markkey);
			break;
		case 5:
			puts("����Ҫɾ����ѧ��������");
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

int main()
{
	stu_info();
	
	return 0;
}
