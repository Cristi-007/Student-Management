struct USER
	{	
		char username[50];
		char pass[50];
		int  id;
		bool stare;
		bool type;
	};
USER usr[1000];
int nu=0;
char FILEusr[100];

struct STUDENT
	{
		char nume[100];
		char prenume[100];
		int age;
		char IDNP[15];
		char grupa[30];
		int userID;
		bool stare=1;
		int id;
	};
STUDENT stud[1000];
int ns=0;
char FILEstud[100];

struct STATISTICA
	{
		int id;				//ID user
		int nrAC=0;			//Nr. accesari - logari
		int nrUSR=0;		//Nr. utilizatori inserati
		int nrSTUD=0;		//Nr. studenti inserati
		int nrEDIT=0;		//Nr. studenti editati
		int nrSTDD=0;		//Nr. studenti dezactivati
	};
STATISTICA stat[1000];
int nst=0;
char FILEstat[100];

FILE *EE;

char collor[15];
int UID;
int SYS;
int lvl=1;
