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
	
	printf("The result is %.3f",res);
	
	return 0;
}

int main()
{
	function1();
}
