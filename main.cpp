#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <iomanip>
#include <cstring>
#include <windows.h>

using namespace std;

#include "class.cpp"
#include "funct.cpp"
#include "menu.cpp"

int main()
{
	readFILEconf();
	
	nu = readFILE(FILEusr, usr);
	ns = readFILE(FILEstud, stud);
	nst = readFILE(FILEstat, stat);
	system(collor);
	
	UID=login();
	stat[UID].nrAC++;
	
	while (1)
		{
		switch (usr[UID].type)
			{
			case 1:	SYS = MENIUadm(); break;
			case 0:	SYS = MENIUusr(); break;
			}

		switch(SYS)
			{
			case 101: insertUSER(); break;
			case 102: findUSER(1); break;
			case 103: findUSER(2); break;
			case 104: editUSER(); break;
			case 105: showStats(); break;
			case 106: showUSER(1); break;
			case 107: showUSER(2); break;
			case 108: showUSER(3); break;
			
			case 201: insertSTUD();	break;
			case 202: showSTUD(1); break;
			case 203: showSTUD(2); break;
			case 204: showSTUD(3); break;
			case 205: findSTUD(1); break;
			case 206: findSTUD(2); break;
			case 207: findSTUD(3); break;
			case 208: findSTUD(4); break;
			case 209: editSTUD(); break;

			case 301: raport(1); break;
			case 302: raport(2); break;
			case 303: raport(3); break;
			case 304: writeFILE(FILEusr,usr,nu); 
					  writeFILE(FILEstud,stud,ns); 
					  writeFILE(FILEstat,stat,nst);
			
			case 99: writeFILE(FILEusr,usr,nu); 
					 writeFILE(FILEstud,stud,ns); 
					 writeFILE(FILEstat,stat,nst); 
					 exit(0);
			}
		}	

	return 0;
}
