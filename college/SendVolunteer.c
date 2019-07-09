#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mydata.h"
void showFillWish(int key)
{
	FILE * fp = NULL;
	int j = 0;
	struct volunteer onedata={0};
	int i = 0;
	fp = fopen("C:\\studentscore_all.txt","rb");
	fseek(fp,key*sizeof(onedata),SEEK_SET);
	fread (&onedata ,sizeof(onedata), 1 ,fp);
	/*for(i=0;i<10;i++)
	{
		for(j = 0;j<6;j++)
		{*/
			 printf("%d\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",onedata.stu.nOrder,onedata.stu.stu_name,\
				onedata.stu.sAryScore[0],onedata.stu.sAryScore[1],onedata.stu.sAryScore[2],\
                onedata.stu.sAryScore[3],onedata.stu.sAryScore[4],\
				onedata.sch[0].schoolname,
				onedata.sch[0].volunteer[0],
				onedata.sch[0].enrollmentnum[0]);
		//}
		//printf("=========================================================================\n");
	//}
	fclose(fp);
}