#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mydata.h"
void changenum(struct school sch[200]);
int CheckEnrollmentSuccess(struct school sch);
int readschoolinfo()
{
	FILE * fileobj = NULL;
	int i = 0;
	struct school sch[200] = {0};
	fileobj = fopen("C:\\school.txt","r");
	for(i=0;i<12;i++)
	{
		fscanf(fileobj,"%s%s%d",sch[i].schoolname,sch[i].volunteer,&sch[i].enrollmentnum);
	}
	for(i=0;i<12;i++)
	{
		printf("%s %s %d\n",sch[i].schoolname,sch[i].volunteer,sch[i].enrollmentnum);
	}
	for(i=0;i<12;i++)
	{
		//changenum(sch,&sch[i].enrollmentnum);
	}
	for(i=0;i<12;i++)
	{
		printf("%s %s %d\n",sch[i].schoolname,sch[i].volunteer,sch[i].enrollmentnum);
	}
	return 0;
	
}
/*void changenum(struct school sch[200],int * num)
{
	int i = 0;
	for(i=0; i<12; i++)
	{
		CheckEnrollmentSuccess(sch[i],&num);
	}
}
int CheckEnrollmentSuccess(struct school sch,int ** num)
{
	int i = 0;
	int j = 0;
	struct studentvolunteer stuvol;
	struct t_student stu2[2]={0};
	FILE * fileobj = NULL;
    fileobj = fopen("C:\\volunteer.txt","r");
	for(i=0;i<2;i++)
	{
		fscanf(fileobj,"%*d%s%*d%*d%*d%*d%*d%s%d%d%d%d%d%d",stu2[i].stu_name,stuvol.studentname,stuvol.volunteer[0],\
		stuvol.volunteer[1],stuvol.volunteer[2],stuvol.volunteer[3],stuvol.volunteer[4],\
		stuvol.volunteer[5]);
	}
	for(i=0;i<2;i++)
	{
		//printf("%s %s %s %s %s %s %s %s\n",stu2[i].stu_name,stuvol.studentname,stuvol.volunteer[0],\
		stuvol.volunteer[1],stuvol.volunteer[2],stuvol.volunteer[3],stuvol.volunteer[4],\
		stuvol.volunteer[5]);
	}

	for(j=0;j<6;j++)
	{
		if(sch.enrollmentnum>0)
		{
			if(!strcmp(stuvol.volunteer[j],sch.volunteer))
			{	(** num)--;
				strcpy(stuvol.volunteer[6],sch.volunteer);
				break;
			}
		}
	}

	for(i=0;i<2;i++)
	{
		printf("%s %s %s %s %s %s %s %s %s\n",stu2[i].stu_name,stuvol.studentname,stuvol.volunteer[0],\
		stuvol.volunteer[1],stuvol.volunteer[2],stuvol.volunteer[3],stuvol.volunteer[4],\
		stuvol.volunteer[5],stuvol.volunteer[6]);
	}*/

	//return 0;
//}
