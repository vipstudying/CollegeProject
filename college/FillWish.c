#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "mydata.h"
struct college getschooldata(int key)
{
	FILE * college_list = NULL;
	struct college onedata={0};	
	int i = 0;
	key = key%10000;
	college_list = fopen("C:\\college_list.txt","rb+");
	fseek(college_list,key*sizeof(onedata),SEEK_SET);
	fread (&onedata ,sizeof(onedata), 1 ,college_list);
	/*for(i=0;i<17;i++)
	{
		    printf("%s\t%d\t%s\t%d\t%d\n",onedata.name,onedata.number,onedata.school_major.majname[i],onedata.school_major.majnumber[i],
		    onedata.school_major.majquota[i]);
	}*/
	fclose(college_list);
	return onedata;
}
void writetoshoolnum(int key,int major)
{
	FILE * college_list = NULL;
	struct college onedata={0};	
	int i = 0;
	key = key%10000;
	major = major%1000000;
	college_list = fopen("C:\\college_list.txt","rb+");
	fseek(college_list,key*sizeof(onedata),SEEK_SET);
	fread (&onedata ,sizeof(onedata), 1 ,college_list);
    onedata.school_major.majquota[i]--;
	fseek(college_list,key*sizeof(onedata),SEEK_SET);
    fwrite(&onedata ,sizeof(onedata), 1 ,college_list);	
	fclose(college_list);
}
void show(int key)
{
	FILE * college_list = NULL;
	struct college onedata={0};	
	int i = 0;
	college_list = fopen("C:\\college_list.txt","rb");
	fseek(college_list,key*sizeof(onedata),SEEK_SET);
	fread (&onedata ,sizeof(onedata), 1 ,college_list);
	for(i=0;i<17;i++)
	{
		    printf("%s\t%d\t%s\t%d\t%d\n",onedata.name,onedata.number,onedata.school_major.majname[i],onedata.school_major.majnumber[i],
		    onedata.school_major.majquota[i]);
	}
	fclose(college_list);
}
void getoneschooldata(struct school *scl,struct college* coll)
{
	int i = 0;
	int j = 0;
	int post = 0;
	int a[17] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	int b[6] ={0};
	scl->schoolname = coll->number;
	srand(time(NULL));
	for(i=0; i<6; i++)
	{
		post=rand()%(17-i);
		b[i]=a[post];
		for(j=post+1;j<17-i;++j)
		{
			a[j-1]=a[j];
		}
	}
	for(i=0;i<6;++i)
	{
		post = b[i];
		scl->volunteer[i] = coll->school_major.majnumber[post];
		scl->enrollmentnum[i] = coll->school_major.majquota[post];
	}
}
void readfromtxt()
{
	int i = 0;
	int j = 0;
	int k = 0 ;
	struct t_student t = {0};
	struct school scl = {0};
	struct volunteer vol = {0};
	struct college coll = {0};
	int nCount = 0;
	int b[6]={0};
	int a[100] = {0};
	int post = 0;
	FILE * fileobj = NULL;
	FILE * volun = NULL;
	FILE * sortedFile = NULL;
    fileobj = fopen("C:\\studentscore_sort.txt","r");
	if(fileobj == NULL)
	{
		printf("can't open file!");
		exit(0);
	}
	for(k=0;k<10;k++)
	{
		fscanf(fileobj,"%d%s%d%d%d%d%d",&t.nOrder,t.stu_name,&t.sAryScore[0],\
				                    &t.sAryScore[1],&t.sAryScore[2],
									&t.sAryScore[3],&t.sAryScore[4]);
		printf("%d%s%d%d%d%d%d\n",t.nOrder,t.stu_name,t.sAryScore[0],\
				                    t.sAryScore[1],t.sAryScore[2],
									t.sAryScore[3],t.sAryScore[4]);
		
		coll = getschooldata(i);
		
		volun = fopen("C:\\studentscore_all.txt","ab+");
		if(volun == NULL)
		{
			printf("can't open file!");
			exit(0);
		}
		for(i = 0;i<100;i++);
		{
			a[i]=i;
		}
        for(i=0; i<6; i++)
		{
			post=rand()%(100-i);
			b[i]=a[post];
			for(j=post+1;j<100-i;++j)
			{
				a[j-1]=a[j];
			}
		}
		for(i = 0;i<6;i++)
		{
			coll = getschooldata(b[i]);
			getoneschooldata(&scl,&coll);
			vol.sch[i] = scl;
		}
		fwrite(&vol,sizeof(vol),1,volun);
	    fclose(volun);	
	}

	fclose(fileobj);	
}