#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void string_del(char *obj , int k , int m , int len)
{
	
	for(int i = k - 1 ; i < k + m - 1 ; ++i)
	{
		*(obj + i) = *(obj + i + m);
	}
	
	if(k + m > len)
		*(obj + k) = '\0';
	else
		*(obj + len - m) = '\0';
}

int main()
{
	char s[] = "abcde" , *p = s ;
	string_del(p , 4 , 1 , sizeof(s)-1);
	printf("%s",s);
	return 0;
}
