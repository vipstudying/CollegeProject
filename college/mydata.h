#define N  3400
struct t_student
{
	int nOrder;
	char stu_name[30];
	short int sAryScore[5];
};
struct school
{
	short int schoolname;
	short int volunteer[6];
	short int enrollmentnum[6];
};

struct volunteer
{
   struct t_student stu;
   struct school sch[6];
   short int schoolname;
   short int volun;
};

struct major
{
	char majname[17][50];
	short int majnumber[17];
	short int majquota[17];
};
struct college//遗漏了typedef，提示第一行miss ;
{
	char name[25];
	short int number;
	struct major school_major;
};
