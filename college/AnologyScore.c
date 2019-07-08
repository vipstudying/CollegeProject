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
	char * firstname[120] = {"赵","钱","孙","李","周","吴","郑","王",\
		                     "冯","陈","褚","卫","蒋","沈","韩","杨",\
							 "朱","秦","尤","许","何","吕","施","张",\
                             "孔","曹","严","华","金","魏","陶","姜",\
							 "戚","谢","邹","喻","柏","水","窦","章",\
							 "云","苏","潘","葛","奚","范","彭","郎",\
                             "鲁","韦","昌","马","苗","凤","花","方",\
							 "俞","任","袁","柳","酆","鲍","史","唐",\
							 "费","廉","岑","薛","雷","贺","倪","惠",\
                             "滕","殷","罗","毕","郝","邬","安","常",\
							 "乐","于","时","傅","皮","卞","齐","康",\
							 "伍","余","元","卜","顾","孟","平","黄",\
                             "和","穆","萧","尹","姚","邵","湛","汪",\
							 "祁","毛","禹","狄","米","贝","明","臧",\
							 "计","伏","成","戴","谈","宋","茅","庞"};
	char * lastName1[20] = { "连","小","旭","金","修","想","崔","子","伍","余",\
						     "和","穆","萧","尹","姚","邵","湛","汪","茅","庞"};
	char * lastName2[20] = { "风","梅","修","花","明","东","海","涛","毕","郝",\
	                         "俞","任","袁","柳","酆","鲍","史","唐","邬","史"};
	
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


