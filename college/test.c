#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"mydata.h"
void fun2(int *a)
{
	*a = 4;
}
void fun1(int *a)
{
	fun2(a);

}
/*void main()
{
	int a = 5;
	fun1(&a);
	printf("%d\n",a);
}*/