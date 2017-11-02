#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int min(int c, int d)
{
	if (c > d)
	{
		return d;
	}
	else
	{
		return c;
	}
}

int prime(int x)
{
	int i;
	for(i = 2 ; i < x / 2 ; ++i)
	{
		if(x % i == 0)
			return 0;
	}
	return 1;
}

int complete(int x)
{
	int i, sum = 0;
	for(i = 1 ; i < x ; ++i)
	{
		if(x % i == 0)
			sum += i;
	}
	if(sum == x)
		return 1;
	else
		return 0;
}

void draw(int layers)
{
	int i, j;
	for(i = 1 ; i <= layers ; ++i)
	{
		for(j = 0 ; j <= layers - i + 1 ; ++j)
			printf(" ");
		for(j = 1 ; j <= 2 * i - 1 ; ++j)
			printf("%c", 64+j);
		puts("");
		
	}
}

void Hanoi(int disks, char start, char dest, char temp)
{
	if(disks == 1)
		printf("%c -> %c\n",start, dest);	//一个盘直接搬 
	else if(disks == 2)
		printf("%c -> %c\n%c -> %c\n%c -> %c\n",start,temp,start,dest,temp,dest);	//多个盘的基础步骤 
	else
	{
		Hanoi(disks-1, start, temp, dest);	//先把n-1个盘搬到临时位置 
		printf("%c -> %c\n",start,dest);	//搬最后一个盘 
		Hanoi(disks-1, temp, dest, start);	//再把临时位置转移到终点 
	}
}

int main()
{
	//Task 1 start
	puts("--------Task 1 : Minimum start--------");
	int a, b;
	puts("Give me two integers(seperated by space) and I'll give you the smaller one : ");
	scanf("%d %d",&a ,&b);
	printf("The smaller one is %d\n",min(a,b));
	puts("--------Task 1 end--------\n");
	// Task 1 end
	
	system("pause");
	
	//Task 3 start
	puts("\n--------Task 3 : Prime number start--------");
	puts("All prime numbers between 100 and 300 are listed as following:");
	int rows=0, n;
	for(n = 100 ; n <= 300 ; ++n)
	{
		if(prime(n))
			{
				printf("%d\t", n);
				rows++;
				if(rows == 5)
					{
						puts("\n");
						rows = 0;
					}
			}
	}
	puts("\n--------Task 3 end--------\n");
	//Task3 end
	
	system("pause");
	
	//Task 5 start
	puts("\n--------Task 5 : Complete number start");
	puts("All complete numbers under and 1000 are listed as following:");
	for(n = 1 ; n <= 1000 ; ++n)
	{
		if(complete(n))
			printf("%d\t", n);
	}
	puts("\n--------Task 5 end---------\n");
	//Task 5 end
	
	system("pause");
	
	//Task 8 start
	puts("\n--------Task 8 : Pyramid of letters start--------");
	start:puts("How many layers do you want?");
	scanf("%d",&n);
	if(n > 13)
	{
		puts("Too much layers!!!");
		goto start;
	}
	draw(n);
	puts("\n--------Task 8 end--------");
	//Task 8 end
	
	system("pause");
	
	//Task Hanoi start
	puts("--------Task Hanoi start--------");
	puts("We have three pillar named \"a\", \"b\", and \"c\".\nI will tell you how to solve it.\nHow many disks do you want?");
	scanf("%d",&n);
	Hanoi(n,'a','c','b');
	puts("--------Task Hanoi end--------");
	//Task Hanoi end
		
	return 0;
}
