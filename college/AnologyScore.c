#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include "mydata.h"
static void  anologyscore(int naryScore[5])
{
	naryScore[1] = rand()%101 + 50;
	naryScore[2] = rand()%101 + 50;
	naryScore[3] = rand()%101 + 50;
	naryScore[4] = rand()%201 + 100;
	naryScore[0] = naryScore[1] + naryScore[2] + naryScore[3] + naryScore[4];
}

static char * anologystudent(char * input)
{
	char * firstname[120] = {"��","Ǯ","��","��","��","��","֣","��",\
		                     "��","��","��","��","��","��","��","��",\
							 "��","��","��","��","��","��","ʩ","��",\
                             "��","��","��","��","��","κ","��","��",\
							 "��","л","��","��","��","ˮ","�","��",\
							 "��","��","��","��","��","��","��","��",\
                             "³","Τ","��","��","��","��","��","��",\
							 "��","��","Ԭ","��","ۺ","��","ʷ","��",\
							 "��","��","�","Ѧ","��","��","��","��",\
                             "��","��","��","��","��","��","��","��",\
							 "��","��","ʱ","��","Ƥ","��","��","��",\
							 "��","��","Ԫ","��","��","��","ƽ","��",\
                             "��","��","��","��","Ҧ","��","տ","��",\
							 "��","ë","��","��","��","��","��","�",\
							 "��","��","��","��","̸","��","é","��"};
	char * lastName1[20] = { "��","С","��","��","��","��","��","��","��","��",\
						     "��","��","��","��","Ҧ","��","տ","��","é","��"};
	char * lastName2[20] = { "��","÷","��","��","��","��","��","��","��","��",\
	                         "��","��","Ԭ","��","ۺ","��","ʷ","��","��","ʷ"};
	
	strcpy(input,firstname[rand()%120]);
	strcat(input,lastName1[rand()%20]);
	strcat(input,lastName2[rand()%20]);
	return input;
}
void writetofile()
{
	FILE * fileobj = NULL;
	int i = 0;
	char strname[10] = {0};
	int nAryScore[5] = {0};	
	fileobj = fopen("C:\\studentscore.txt","a");
	if(fileobj == NULL)
	{
		printf("file cant open!");
		exit(0);
	}
	srand(time(NULL));
	for (i = 0;i< N;++i)
	{		
		anologyscore(nAryScore);
		fprintf(fileobj,"%d\t%s\t%d\t%d\t%d\t%d\t%d",i+1,anologystudent(strname),\
			                           nAryScore[0],nAryScore[1],nAryScore[2],\
									   nAryScore[3],nAryScore[4]);
	    if(i != N-1)
		{
			fprintf(fileobj,"%c",10);
		}
		if((i+1) %10000 == 0)
		{		
		    fclose(fileobj);
		    fileobj = fopen("C:\\studentscore.txt","a");
			if(fileobj == NULL)
			{
				printf("file can't open!");
				exit(0);
			}
		}
	}
	fclose(fileobj);
}


