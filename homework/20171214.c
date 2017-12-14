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
	
	
	return 0;
}
