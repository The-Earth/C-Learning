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

int leap(int year) //Detecting leap year
{
	if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void days()
{
	printf("Give me a date in the following form\nYYYY-MM-DD\nI will tell you what day it is of that year. Now input the date:");
	int year, month ,day;
	scanf("%d-%d-%d", &year, &month, &day);
	
	int preday=400;
	if(year>0 && day>0 && day<31)
	{
	switch(month)
	{
		case 1 : preday = 0;	break;
		case 2 : preday = 31;	break;
		case 3 : preday = 59;	break;
		case 4 : preday = 90;	break;
		case 5 : preday = 120;	break;
		case 6 : preday = 151;	break;
		case 7 : preday = 181;	break;
		case 8 : preday = 212;	break;
		case 9 : preday = 243;	break;
		case 10 : preday = 273;	break;
		case 11 : preday = 304;	break;
		case 12 : preday = 334;	break;
		default : printf("What are you doing??\n\n");	break;
	}
	}
	else
		printf("What are you doing??\n\n");
	if(leap(year) && month > 2)
		preday += 1;
	
	if(preday < 380)
		printf("%d-%d-%d is the %d day of %d.\n\n", year, month, day, preday+day, year);
}

void type()
{
	printf("Give me A char and I will tell you its type:");
	char x;
	scanf("%c",&x);
	
	if(x == 32)
		printf("It's a space.\n\n");
	else if(x >= 48 && x <= 57)
		printf("It's a number.\n\n");
	else if((x >= 65 && x <= 90) || (x >= 97 && x < 122))
		printf("It's an English character.\n\n");
	else
		printf("It's an \"other character\".\n\n");
}

int main()
{
	printf("This is the homework for Oct. 12 lecture.\n\n");
	printf("Task 1:\n\n");
	lower();
	printf("Task 2:\n\n");
	days();
	printf("Task 3:\n\n");
	type();
	
	return 0;
}
