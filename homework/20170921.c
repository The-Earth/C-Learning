#include<stdio.h>
#include<math.h>

int function1()
{
	int a, b;
	double res;
	printf("a = ?\n");
	scanf("%d",&a);
	printf("b = ?\n");
	scanf("%d",&b);
	
	res = sqrt((a + b + abs(a - b)) / 2);
	
	printf("The result is %.3f\n\n",res);
	
	return 0;
}

int function2()
{
	double num, squ, pw;
	
	printf("Input a real number:");
	scanf("%f",&num);
	squ = sqrt(num);
	pw = pow(num, 2.0);
	printf("Square root of the input is %.3f\nSquare of the input is %.3f\n\n",squ,pw);
	
	return 0;
}

int function3()
{
	double l[4];
	int i;
	
	for(i = 0;i < 4;i++)
	{
		printf("Calculating average:");
		scanf("%f",&l[i]);
	}
	double sum=0;
	
	for(i = 0;i < 4;i++)
		sum = sum + l[i];
	
	printf("Average value is %.2f",sum / 4.0);
	
	return 0;
}

int main()
{
	function1();
	function2();
	function3();
	return 0;
}
