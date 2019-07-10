#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mydata.h"
extern void writetoshoolnum(int key,int major);
extern struct college getschooldata(int key);
void showFillWish(int key)
{
	FILE * fp = NULL;
	int j = 0;
	struct volunteer onedata={0};
	int i = 0;
	fp = fopen("C:\\studentscore_all.txt","rb");
	fseek(fp,key*sizeof(onedata),SEEK_SET);
	fread (&onedata ,sizeof(onedata), 1 ,fp);
	for(i = 0;i<6;i++)
	{
		printf("================================��%d־Ը==================================\n",i+1);
		for(j=0;j<6;j++)
		{
			printf("%d\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",onedata.stu.nOrder,onedata.stu.stu_name,\
			onedata.stu.sAryScore[0],onedata.stu.sAryScore[1],onedata.stu.sAryScore[2],\
            onedata.stu.sAryScore[3],onedata.stu.sAryScore[4],\
			onedata.sch[i].schoolname,
			onedata.sch[i].volunteer[j],
			onedata.sch[i].enrollmentnum[j],
			onedata.schoolname,
			onedata.volun);
		}
		
	}
	fclose(fp);
}

void showRes(int key)
{
	FILE * fp = NULL;
	int j = 0;
	struct volunteer onedata={0};
	int i = 0;
	fp = fopen("C:\\studentscore_all.txt","rb");
	fseek(fp,key*sizeof(onedata),SEEK_SET);
	fread (&onedata ,sizeof(onedata), 1 ,fp);
	printf("%d\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",onedata.stu.nOrder,onedata.stu.stu_name,\
	onedata.stu.sAryScore[0],onedata.stu.sAryScore[1],onedata.stu.sAryScore[2],\
    onedata.stu.sAryScore[3],onedata.stu.sAryScore[4],\
	onedata.schoolname,
	onedata.volun);
	fclose(fp);
}

void DecreaseEnrollmentNum(int order ,int key,int major)
{
	FILE * fp = NULL;
	struct volunteer onedata={0};	
	fp = fopen("C:\\studentscore_all.txt","rb+");
	fseek(fp,order*sizeof(onedata),SEEK_SET);
	fread (&onedata ,sizeof(onedata), 1 ,fp);
    onedata.schoolname = key;
	onedata.volun = major;
	fseek(fp,order*sizeof(onedata),SEEK_SET);
    fwrite(&onedata ,sizeof(onedata), 1 ,fp);	
	fclose(fp);
}

struct volunteer getOneStudentVolunteer(int key)
{
	FILE * fp = NULL;
	int j = 0;
	struct volunteer onedata={0};
	int i = 0;
	fp = fopen("C:\\studentscore_all.txt","rb");
	fseek(fp,key*sizeof(onedata),SEEK_SET);
	fread (&onedata ,sizeof(onedata), 1 ,fp);
	fclose(fp);
	return onedata;
}
short int getmajor(int major)
{
	int a = 0;
	int b = 0;
	a = major%10;
	major = major/10;
	b = major%10;
	return b*10+a;

}
void onebyoneDispose()
{
	int i = 0;
	int j = 0;
	int k = 0;
	struct volunteer onestudent = {0};
	short int schoolname = 0;
	struct t_student stu;
	int major = 0;
	int majnumber = 0;
	short int majorpost = 0;
	short int majquota = 0;
	struct college col = {0};
	for(i=0;i<10000;i++)
	{
       onestudent = getOneStudentVolunteer(i);
	   for(j=0;j<6;j++)
	   {
		   struct school scl = onestudent.sch[j];
		   stu = onestudent.stu;
		   schoolname = scl.schoolname;
		   for(k=0;k<6;k++)
		   {
			  major = scl.volunteer[k];
			  majorpost = getmajor(major);
			  col = getschooldata(schoolname%10000);
			  majnumber = col.school_major.majnumber[majorpost];
			  majquota = col.school_major.majquota[majorpost];
			  if(majquota>0)
			  {
                   writetoshoolnum(schoolname,majorpost);
				   onestudent.schoolname = schoolname;
                   onestudent.volun = major;
				   DecreaseEnrollmentNum(i,schoolname,major);
				   break;
			  }

		   }
		   if(k!=6)break;
	   }
	   if(j==6)
	   {
          printf("δ¼ȡ");
	   }

	}

}

