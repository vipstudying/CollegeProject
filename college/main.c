#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"mydata.h"
extern void readfromtxt();  
extern void showFillWish(int key);
extern void getschool();
extern void DecreaseEnrollmentNum(int order ,int key,int major);
extern void show(int key);
extern void showRes(int key);
void main()
{
	int i = 0;
	srand(time(NULL));
	//writetofile();
	//readfromfile();
	//getschooldata();
	//getschool();
	//show();
	//readschoolinfo();
	//CheckEnrollmentSuccess();
	//readfromtxt();
	//showFillWish(1);
	//DecreaseEnrollmentNum(1,0,0);
	//showFillWish(1);
	
	for(i=0;i<10000;i++)
	{
		//onebyoneDispose();
		printf("*********************************************************************\n");
		showRes(i);
		//show(i);
		//printf("*******************************************************************\n");
	}
	
}
