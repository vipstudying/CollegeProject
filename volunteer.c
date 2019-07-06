#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
struct volunteer
{
	char school_name[30];
	char major_name1[30];
	char major_name2[30];
	char major_name3[30];
	char major_name4[30];
	char major_name5[30];
	char major_name6[30];
};
struct score
{
	int m_score;
	int s_score;
	int e_score;
	int c_score;
	int sum_score;

};
typedef struct student
{
	char name[10];
	int ID;
	struct score list;
	struct volunteer infor;
}S,*K;
void main()
{
	int i=0;
	int j=0;
	int z=0;
	int y=0;
	int n=0;
	int s_id=0;
	S stu[2000]={0};
	srand(time(NULL));
	char * name[120]={"ÕÔ","Ç®","Ëï","Àî","ÖÜ","Îâ","Ö£","Íõ","·ë","³Â","ñÒ","ÎÀ","½¯","Éò","º«","Ñî","Öì","ÇØ","ÓÈ","Ğí","ºÎ","ÂÀ","Ê©","ÕÅ",\
	                  "¿×","²Ü","ÑÏ","»ª","½ğ","Îº","ÌÕ","½ª","Æİ","Ğ»","×Ş","Ó÷","°Ø","Ë®","ñ¼","ÕÂ","ÔÆ","ËÕ","ÅË","¸ğ","ŞÉ","·¶","Åí","ÀÉ",\
					  "Â³","Î¤","²ı","Âí","Ãç","·ï","»¨","·½","Óá","ÈÎ","Ô¬","Áø","Ûº","±«","Ê·","ÌÆ","·Ñ","Á®","á¯","Ñ¦","À×","ºØ","Äß","»İ",\
					  "ëø","Òó","ÂŞ","±Ï","ºÂ","Úù","°²","³£","ÀÖ","ÓÚ","Ê±","¸µ","Æ¤","±å","Æë","¿µ","Îé","Óà","Ôª","²·","¹Ë","ÃÏ","Æ½","»Æ",\
					  "ºÍ","ÄÂ","Ïô","Òü","Ò¦","ÉÛ","Õ¿","Íô","Æî","Ã«","Óí","µÒ","Ã×","±´","Ã÷","ê°","¼Æ","·ü","³É","´÷","Ì¸","ËÎ","Ã©","ÅÓ"};
	
	for(i=0;i<2000;i++)
	{
		FILE *fp;
		j=rand()%120;
		z=rand()%120;
		y=rand()%120;
		strcat(strcat(strcpy(stu[i].name,name[j]),name[z]),name[y]);
		n=(rand()%101)+50;
		stu[i].list.m_score=n;
		n=(rand()%201)+100;
		stu[i].list.s_score=n;
		n=(rand()%101)+50;
		stu[i].list.e_score=n;
		n=(rand()%60)+80;
		stu[i].list.c_score=n;
		stu[i].list.sum_score=(stu[i].list.m_score+stu[i].list.s_score+stu[i].list.e_score+stu[i].list.c_score);
		j=1000000+i;
		stu[i].ID=j;
		if((fp=fopen("stulist.txt","a+"))==NULL)
		{
			printf("cannot open file");
			exit(0);
		}
		fprintf(fp,"%s  %d  %d  %d  %d  %d  %d\n",stu[i].name,stu[i].ID,stu[i].list.m_score,stu[i].list.s_score,stu[i].list.e_score,\
			stu[i].list.c_score,stu[i].list.sum_score);
		fclose(fp);
	}
}
