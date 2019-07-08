#include "mydata.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct t_student S,*K;
static int nn = 0;
/*int comp(const void *p1,const void *p2)
{
	K c= (K)p1;
	K d= (K)p2;
	if(c->sAryScore[0]!=d->sAryScore[0])
	 {
		return d->sAryScore[0] > c->sAryScore[0]?1:-1;
	 }
	else if(c->sAryScore[4]!=d->sAryScore[4]&&c->sAryScore[0]==d->sAryScore[0])
		return d->sAryScore[4] > c->sAryScore[4]?1:-1;
	else if(c->sAryScore[1]!=d->sAryScore[1]&&c->sAryScore[4]==d->sAryScore[4]&&c->sAryScore[0]==d->sAryScore[0])
	    return d->sAryScore[1] > c->sAryScore[1]?1:-1;
	else if(c->sAryScore[2]!=d->sAryScore[2]&&c->sAryScore[1]==d->sAryScore[1]&&c->sAryScore[4]==d->sAryScore[4]&&c->sAryScore[0]==d->sAryScore[0])
	     return d->sAryScore[2] > c->sAryScore[2]?1:-1;
	else
		return d->sAryScore[3] > c->sAryScore[3]?1:-1;
}*/
void sortthanwrite(struct t_student stForSort[1000],int nCount,FILE * fileobj);
void readfromfile()
{
	int i = 0;
	int j = 0;
	struct t_student t = {0};
	int nCount = 0;
	FILE * fileobj = NULL;
	FILE * sortedFile = NULL;
	struct t_student stForSort[10000] = {0};//一分一段最多每分数1000个人。
    
	
	for (i = 750;i>=250;--i)
	{
		nCount = 0;
		fileobj = fopen("C:\\studentscore.txt","r");
		if(fileobj == NULL)
		{
			printf("can't open file!");
			exit(0);
		}
		while(!feof(fileobj))
		{
			fscanf(fileobj,"%d%s%d%d%d%d%d",&t.nOrder,t.stu_name,&t.sAryScore[0],\
				                    &t.sAryScore[1],&t.sAryScore[2],
									&t.sAryScore[3],&t.sAryScore[4]);
			if(t.sAryScore[0] == i)
			{
			    stForSort[nCount].nOrder = t.nOrder;
                strcpy(stForSort[nCount].stu_name,t.stu_name);
				for(j = 0;j< 5;j++)
				{
				    stForSort[nCount].sAryScore[j] = t.sAryScore[j];
				}
				nCount++;
			}	
		}
		if(nCount!=0)
		{
			sortedFile = fopen("C:\\studentscore_sort.txt","a");
			sortthanwrite(stForSort,nCount,sortedFile);
			fclose(sortedFile);
		}
		fclose(fileobj);	
	}
}
void sortthanwrite(struct t_student stForSort[10000],int nCount,FILE * fileobj)
{
	//首先对这个分数的所有人排序，冒泡
	int i = 0;
	int j = 0;
	struct t_student t = {0};
	for ( i = 1;i< nCount;i++)
	{
		for (j = 0;j< nCount-i;j++)
		{
			if(stForSort[j].sAryScore[1]<stForSort[j+1].sAryScore[1])
			{
				t = stForSort[j];
				stForSort[j] = stForSort[j+1];
				stForSort[j+1] = t;			
			}
			else if (stForSort[j].sAryScore[1]==stForSort[j+1].sAryScore[1])
			{
				if(stForSort[j].sAryScore[2]<stForSort[j+1].sAryScore[2])
				{
					t = stForSort[j];
					stForSort[j] = stForSort[j+1];
					stForSort[j+1] = t;			
				}
				else if (stForSort[j].sAryScore[2] == stForSort[j+1].sAryScore[2])
				{
					if (stForSort[j].sAryScore[3] < stForSort[j+1].sAryScore[3])
					{
						t = stForSort[j];
						stForSort[j] = stForSort[j+1];
						stForSort[j+1] = t;	
					}				
				}				
			}
		}	
	}
	/*
	int i=0;
	qsort(stForSort,N,sizeof(stForSort[0]),comp);
	*/
	//接着在对排序后的数据写出到文件。
	for ( i = 0;i< nCount;i++)
	{
		fprintf(fileobj,"%d\t%s\t%d\t%d\t%d\t%d\t%d\n",++nn,
			                        stForSort[i].stu_name, 
			                        stForSort[i].sAryScore[0],
				                    stForSort[i].sAryScore[1],stForSort[i].sAryScore[2],
									stForSort[i].sAryScore[3],stForSort[i].sAryScore[4]);
	}

}

