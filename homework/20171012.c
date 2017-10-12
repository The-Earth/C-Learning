#include <stdio.h>
#include <stdlib.h>

void lower()
{
	printf("Give me an English character and I will tell you something:");
	char lec;
	scanf("%c",&lec);
	
	if (lec >= 'A' && lec <= 'Z')
	{
		printf("The result is \"%c\"\n\n",lec+32);
	}
	else if (lec >= 'a' && lec <= 'z')
	{
		printf("The result is \"%c\"\n\n",lec);
	}
	else
	{
		printf("What are you doing??\n\n");
	}
}

int main()
{
	printf("This is the homework for Oct. 12 lecture.\n\n");
	printf("Task 1:\n\n");
	lower();
	
	return 0;
}
