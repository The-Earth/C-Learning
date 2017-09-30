#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int triangle()
{
	double a = 0, b = 0, c = 0, area, s; 
	printf("Calculating the area of a given triangle.\nInput length of the three sides (seperated by space):");
	scanf("%lf %lf %lf", &a, &b, &c);
	if (a + b > c && a + c > b && b + c > a)
	{
		s = (a + b + c) / 2;
		area = sqrt(s * (s - a) * (s - b) * (s - c));
		printf("\nThe area of the given triangle is %.2f\n\n",area);
	}
	else
	{
		printf("It is not a triangle.\n\n");
	}
	
	return 0;
}

int ASCII()
{
	getchar();
	 
	char CH;
	printf("Give me an English character and I will tell you its ASCII:");
	scanf("%c",&CH);
	printf("\nIts ASCII number is %d\n\n",CH);
	
	return 0;
}

int change()
{
	getchar();
	
	char or, nw;
	printf("Give me an letter and I will change it in to another form:");
	scanf("%c",&or);
	if (or < 'Z' && or > 'A')
	{
		nw = or + 32;
		printf("The result is %c\n\n",nw);
	}
	else
	{
		if (or > 'a' && or < 'z')
		{
			nw = or - 32;
			printf("The result is \"%c\"\n\n",nw);
		}
		else
			puts("I can not help you!\n\n");
	}
	
	return 0;
}

int d2hob()
{
	int num;
	printf("Give I a decimal int number and I will tell you its hex, oct and bin form:");
	scanf("%d",&num);
	printf("\nHex: %x\nOct: %o\n\n",num,num,num);
	
	return 0;
}

int tenK()
{
	int num;
	printf("Input an integer between 10000 and 99999 and I will tell you something......\n:");
	scanf("%d",&num);
	
	int tk, k, h, t, o;
	tk = num / 10000;
	k = (num % 10000) / 1000;
	h = (num % 1000) / 100;
	t = (num % 100) / 10;
	o = num % 10;
	
	printf("%d(%d+%d+%d+%d+%d)\n\n",(tk + k + h + t + o), tk, k, h, t, o);
	
	return 0;
}

int error()
{
	int x=1,y=2,z=3,u=4,c=5,r=6,a=7,b=8,e=9,R=10;
	const double Pi=3.14159;
	
	printf("Errors corrected!\n");
	printf("|(x+y)(z+u)+2c|=%f\nPi r^2/(a+b)=%f\n(lnx+cosy)/3=%f\n4x^3+2e^y=%f\n4Pi R^2=%f\n\n",
	fabs((x+y)*(z+u)+2*c),
	Pi*pow(r,2)/(a+b),
	(log(x)+cos(y))/3,
	4*pow(x,3)+2*pow(e,y),
	4*Pi*pow(R,2));
	
	return 0;
}

int circle()
{
	double R;
	const double pi=3.14159;
	printf("Tell me the radius of the circle:");
	scanf("%lf",&R);
	
	printf("Its area is: %.2f\nIts circumference is: %.2f\n\n",pi*pow(R,2), 2*pi*R);
	
	return 0;
}

int f2c()
{
	int f;
	printf("Tell me a Fahreheit degree and I'll tell you its Celcius form:");
	scanf("%d",&f);
	
	printf("Its Celcius form is: %.2f\n\n",(f - 32) * 5 / 9.0);
	
	return 0;
}

int main()
{
	/*printf("Task 1:\n");
	triangle();
	printf("Task 2:\n");
	ASCII();
	printf("Task 3:\n");
	change();
	printf("Task 4:\n");
	d2hob();
	printf("Task 5:\n");
	tenK();
	printf("Task 6:\n");
	error();
	printf("Task 7:\n");
	circle();*/
	printf("Task 8:\n");
	f2c();
	
	return 0;
}
