#define N  34000
struct t_student
{
	int nOrder;
	char stu_name[7];
	short int sAryScore[5];
};
struct school
{
	short int schoolname;
	int volunteer[6];
	short int enrollmentnum[6];
};

struct volunteer
{
   struct t_student stu;
   struct school sch[6];
   short int schoolname;
   int volun;
};

struct major
{
	char majname[17][50];
	int majnumber[17];
	short int majquota[17];
};
struct college//遗漏了typedef，提示第一行miss ;
{
	char name[25];
	short int number;
	struct major school_major;
};
