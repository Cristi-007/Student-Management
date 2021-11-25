void readFILEconf()
	{
	char name[2];
	EE = fopen("conf.ini", "r+");
		if (EE == NULL) { cout<<"\n\n\t\t Fisierul -conf.ini- nu exista "<<endl; exit(0);}
		fscanf(EE, "%s%s%s%s", &FILEusr, &FILEstud, &FILEstat, &name);
		strcpy(collor,"color ");
		strcat(collor,name);
	fclose(EE);
	}

template <typename F>
int readFILE(char *p, F str[])
	{
	EE = fopen(p, "r+b");
		if (EE == NULL) { cout<<"\n\n\t\t Fisierul "<<p<<" nu exista "<<endl; exit(0);}
		int n = fread(str, sizeof(str[0]), 1000, EE);
	fclose(EE);
	return n;
	}


template <typename F>
void writeFILE(char *p, F str[], int num)
	{
	EE = fopen(p, "w+b");
		if (EE == NULL) { cout<<"\n\n\t\t Erroare inscriere in fisier "<<endl; exit(0);}
		fwrite ( str, sizeof(str[0]), num, EE);
	fclose(EE);
	}


int insertNUMBER()
	{
	int ID=0, N[20], i=0;
	while(1)
		{
			switch(_getch())
        		{
            		case 48: cout<<"0"; ID=ID*10+0; N[i]=0; i++; break;
            		case 49: cout<<"1"; ID=ID*10+1; N[i]=1; i++; break;
            		case 50: cout<<"2"; ID=ID*10+2; N[i]=2; i++; break;
            		case 51: cout<<"3"; ID=ID*10+3; N[i]=3; i++; break;
            		case 52: cout<<"4"; ID=ID*10+4; N[i]=4; i++; break;
            		case 53: cout<<"5"; ID=ID*10+5; N[i]=5; i++; break;
           			case 54: cout<<"6"; ID=ID*10+6; N[i]=6; i++; break;
           			case 55: cout<<"7"; ID=ID*10+7; N[i]=7; i++; break;
            		case 56: cout<<"8"; ID=ID*10+8; N[i]=8; i++; break;
            		case 57: cout<<"9"; ID=ID*10+9; N[i]=9; i++; break;
            		
            		case 8: if(ID>0 || i>0 && N[i-1]==0){cout<<"\b \b"; ID=(ID-N[i-1])/10; i--; break;}
            					else break;
            			
            		case 13: if(i==0) break;
								else return ID;
            			
            		case 27: return 27;
            	}
		}
	}


int login()
{
		char user[100];
 		char pass[100];
 		int i=0,j=NULL,IDD=NULL;

 		while(1)
 		{
 		system("cls");
 		cout<<"\n\n\t Utilizator: ";
		cin>>user;
 		cout<<"\n\t Parola: ";
		 
			while(1)
			{
				pass[i]=_getch();
				
				if(int(pass[i]) == 27) { j=-3; break;}
				
				else if(int(pass[i]) == 8)
 				{
 					if (i>0){cout<<"\b \b"; i--;}	
				}		
				
				else if(int(pass[i]) == 13) 
 				{
					pass[i]=0;
					i=0;
							
					for (j=0; j<nu; j++)
					{
						if(strcmp(usr[j].username,user)==0)
						{
							if (strcmp(usr[j].pass,pass)==0) {IDD=j;break;}
							else {j=-1;break;}
						}
						else if (j==(nu-1)) {j=-2; break;}
					}
					
				if (IDD==j) break;
			
				if (j==-1)
					{
						system("cls");
						cout<<"\n\n\t Parola introdusa este incorecta ";
						Sleep(1000);
						system("cls");
						cout<<"\n\n\t Parola: ";
					}
			 	if (j==-2)
					{
						system("cls");
						cout<<"\n\n\t Acest utilizator nu exista ";
						Sleep(1000);
						break;
					}
				}
				else 
				{
					cout<<"*";
					i++;
				}
 		}
	if (IDD==j) 
		{
			system("cls");
			cout<<"\n\n\t Autentificare reusita ";
			Sleep(500);
			return IDD;	
			break;	
		}
	}
}


void insertUSER()
	{
		do
		{
			int j=1;
			while(j)
				{
				system("cls");	
				cout<<"\n\n\t Numele de utilizator: "; cin>>usr[nu].username;
				for (int i=0; i<nu; i++)
					{
						if (strcmp(usr[nu].username, usr[i].username)==0)
							{
								system("cls");
								cout<<"\n\n\t Acest nume de utilizator exista, alegeti altul "<<endl;
								Sleep(1000);
								break;
							}						
						if(i==nu-1){j=0; break;}				
					}	
				}
			cout<<"\t Parola: "; cin>>usr[nu].pass;
			cout<<"\t Starea (1-activ / 0-inactiv): "; cin>>usr[nu].stare;
			cout<<"\t Tipul (1-admin / 0-user): "; cin>>usr[nu].type;
			usr[nu].id=nu;
			stat[nst].id==usr[nu].id;
			stat[nst].nrAC=0;
			stat[nst].nrUSR=0;
			stat[nst].nrSTUD=0;
			stat[nst].nrEDIT=0;
			stat[nst].nrSTDD=0;
			nu++;
			nst++;
			stat[UID].nrUSR++;
			cout<<"\n   Interati alt utilizator? Any key (continue) or ESC (exit)";
		}while(_getch() != 27);
	}


void insertSTUD()
	{
		do
		{
			int j=1;
			while(j)
				{
					system("cls");
					cout<<"\n\n\t Nume: "; cin>>stud[ns].nume;
					cout<<"\t Prenume: "; cin>>stud[ns].prenume;
					cout<<"\t Virsta: "; cin>>stud[ns].age;	
					cout<<"\t IDNP: "; cin>>stud[ns].IDNP;
				for (int i=0; i<ns; i++)
					{
						if (strcmp(stud[ns].IDNP, stud[i].IDNP)==0)
							{
								system("cls");
								cout<<"\n\n\t Student cu un astfel de IDNP exista.\n\t\tInserati alt student."<<endl;
								Sleep(1200);
								break;
							}						
						if(i==ns-1){j=0; break;}				
					}	
				}
				cout<<"\t Grupa: "; cin>>stud[ns].grupa;
				cout<<"\t Starea (1-activ / 0-inactiv): "; cin>>stud[ns].stare;
				stud[ns].id=ns;
				stud[ns].userID=UID;
				ns++;
				stat[UID].nrSTUD++;
				cout<<endl<<"\n   Interati alt student? Any key (continue) or ESC (exit)";
		}while(_getch() != 27);
	}


void showUSER(int ID)
{
	int KEY=43, strt=0, pas=2, j=1, activ=0;
	
	for(int i=0;i<nu;i++) if(usr[i].stare==1) activ++;
	int W[activ/pas+5];	
	for(int i=0; i<activ/pas+5; i++) W[i]=0;
			
		while(1)
		{
			system("cls");	
			cout<<"\n\n\t\t  Lista Utilizatorilor "<<endl<<endl;
			cout<<setw(3)<<" Nr. "<<setw(3)<<" ID. "<<setw(12)<<" Username "<<setw(15)<<" Password "<<setw(10)<<" Tipul "<<setw(10)<<" Starea "<<endl;
    		cout<<"---------------------------------------------------------"<<endl;
    	switch (ID)
			{
			case 1:	// All
				for(int i=0; strt<nu; strt++ )
    			{
    				cout<<setw(2)<<++W[1]<<setw(6)<<usr[strt].id<<setw(12)<<usr[strt].username<<setw(17)<<usr[strt].pass<<setw(7)<<usr[strt].type<<setw(10)<<usr[strt].stare<<endl;
					cout<<"---------------------------------------------------------"<<endl;
					i++;
					KEY==45 ? W[0]-- : W[0]++;
					if(i==pas) {strt+=1; break;}
  				}
  					cout<<"\n\t\t\t\t\t   PAGINA "<<j<<" din ";
					if (nu%2==0)cout<<nu/pas;
					if (nu%2!=0)cout<<nu/pas+1;
  					cout<<"\n (+)-urmatorul, (-)-precedent, (ESC)-EXIT";
  				break;
  				
			case 2: // Activi
				for(int i=0; strt<nu; strt++ )
    			{
    				if(i==pas) {W[j]=strt; W[activ/pas+4]=0; break;}
    				if(usr[strt].stare==1)
    				{
    					cout<<setw(2)<<++W[activ/pas+2]<<setw(6)<<usr[strt].id<<setw(12)<<usr[strt].username<<setw(17)<<usr[strt].pass<<setw(7)<<usr[strt].type<<setw(10)<<usr[strt].stare<<endl;
						cout<<"---------------------------------------------------------"<<endl;
						i++;
						if(KEY==43 || W[activ/pas+3]==0) {W[activ/pas+3]++; W[activ/pas+4]++;}	
					}
  				}
  					cout<<"\n\t\t\t\t\t   PAGINA "<<j<<" din ";
					if (nu%2==0)cout<<nu/pas;
					if (nu%2!=0)cout<<nu/pas+1;
  					cout<<"\n (+)-urmatorul, (-)-precedent, (ESC)-EXIT";
  				break;
  				
			case 3: // Inactivi
				for(int i=0; strt<nu; strt++ )
    			{
    				if(i==pas) {W[j]=strt; W[activ/pas+4]=0; break;}
    				if(usr[strt].stare==0)
    					{
    					cout<<setw(2)<<++W[activ/pas+2]<<setw(6)<<usr[strt].id<<setw(12)<<usr[strt].username<<setw(17)<<usr[strt].pass<<setw(7)<<usr[strt].type<<setw(10)<<usr[strt].stare<<endl;
						cout<<"---------------------------------------------------------"<<endl;
						i++;
						if(KEY==43 || W[activ/pas+3]==0) {W[activ/pas+3]++; W[activ/pas+4]++;}
						} 
  				}
  					cout<<"\n\t\t\t\t\t   PAGINA "<<j<<" din ";
					if (nu%2==0)cout<<nu/pas;
					if (nu%2!=0)cout<<nu/pas+1;
  					cout<<"\n (+)-urmatorul, (-)-precedent, (ESC)-EXIT";
					break;	
			}
		A:
		KEY=_getch();
  
		if( KEY == 43 )//+
			{
				switch(ID)
					{
						case 1: if(strt>=nu) goto A; else j++; break;
						case 2: if(W[activ/pas+3]==activ && j==activ/pas || W[activ/pas+3]==activ && j==activ/pas+1 || j==activ/pas-1) goto A;
									else j++; break;
						case 3: if(W[activ/pas+3]==ns-activ && j==(ns-activ)/pas || W[activ/pas+3]==ns-activ && j==(ns-activ)/pas+1 || j==(ns-activ)/pas-1) goto A;
									else j++; break;
					}
			 }
	
		if( KEY == 45 )//-
			{
				switch(ID)
					{
						case 1:	if(j==1 && W[0]==pas) goto A;
									else if(j==1) goto A;
									else { j--; strt-=(pas*2); }
								break;
									
						case 2: if(j==1 && strt==W[1]) goto A;
									else if(j==1) goto A;
									else { if(W[activ/pas+4]<pas && W[activ/pas+4]>0) {W[activ/pas+3]-=W[activ/pas+4]; W[activ/pas+2]-=(W[activ/pas+4]+pas);} 
												else {W[activ/pas+3]-=pas; W[activ/pas+2]-=(pas*2);}
											j--; 
											strt=W[j-1]; 
										} break;
								
						case 3: if(j==1 && strt==W[1]) goto A;
									else if(j==1) goto A;
									else { if(W[activ/pas+4]<pas && W[activ/pas+4]>0) {W[activ/pas+3]-=W[activ/pas+4]; W[activ/pas+2]-=(W[activ/pas+4]+pas);} 
												else {W[activ/pas+3]-=pas; W[activ/pas+2]-=(pas*2);}
											j--; 
											strt=W[j-1]; 
										} break;
						}
			}
		if( KEY == 27 ) break;
		if( KEY != 43 &&  KEY != 45 &&  KEY != 27 ) goto A;
		}
}


void showSTUD(int ID)
{
	int KEY=43, strt=0, pas=2, j=1, activ=0;
	
	for(int i=0;i<ns;i++) if(stud[i].stare==1) activ++;
	int W[activ/pas+5];	
	
	for(int i=0; i<activ/pas+5; i++) W[i]=0;
			
		while(1)
		{
			system("cls");	
			cout<<"\n\n\t\t\t\t\t  LISTA STUDENTILOR "<<endl<<endl;
			cout<<setw(3)<<" Nr. "<<setw(3)<<" ID. "<<setw(10)<<" Nume "<<setw(15)<<" Prenume "<<setw(15)<<" Virsta "<<setw(20)<<" IDNP "<<setw(20)<<" Grupa "<<setw(15)<<" Starea "<<endl;
    		cout<<"---------------------------------------------------------------------------------------------------------"<<endl;
    	switch (ID)
			{
			case 1:	// All
				for(int i=0; strt<ns; strt++ )
    			{
    				cout<<setw(2)<<++W[1]<<setw(6)<<stud[strt].id<<setw(12)<<stud[strt].nume<<setw(14)<<stud[strt].prenume<<setw(13)<<stud[strt].age<<setw(26)<<stud[strt].IDNP<<setw(18)<<stud[strt].grupa<<setw(11)<<stud[strt].stare<<endl;
					cout<<"---------------------------------------------------------------------------------------------------------"<<endl;
					i++;
					KEY==45 ? W[0]-- : W[0]++;
					if(i==pas) {strt+=1; break;}
					if(strt==ns-1) W[2]=i;
  				}
  					cout<<"\n (+) - urmatorul, (-) - precedent, (ESC) - EXIT";
					cout<<"\t\t\t\t\t\t   PAGINA "<<j<<" din ";
					if (ns%2==0)cout<<ns/pas;
					if (ns%2!=0)cout<<ns/pas+1;	
  				break;
  				
			case 2: // Activi
				for(int i=0; strt<ns; strt++ )
    			{
    				if(i==pas) {W[j]=strt; W[activ/pas+4]=0; break;}
    				if(stud[strt].stare==1)
    				{
    					cout<<setw(2)<<++W[activ/pas+2]<<setw(6)<<stud[strt].id<<setw(12)<<stud[strt].nume<<setw(14)<<stud[strt].prenume<<setw(13)<<stud[strt].age<<setw(26)<<stud[strt].IDNP<<setw(18)<<stud[strt].grupa<<setw(11)<<stud[strt].stare<<endl;
						cout<<"---------------------------------------------------------------------------------------------------------"<<endl;
						i++;
						if(KEY==43 || W[activ/pas+3]==0) {W[activ/pas+3]++; W[activ/pas+4]++;}	
					}
  				}
  					cout<<"\n (+) - urmatorul, (-) - precedent, (ESC) - EXIT";
  					cout<<"\t\t\t\t\t\t   PAGINA "<<j<<" din ";
					if (activ%2==0)cout<<activ/pas;
					if (activ%2!=0)cout<<activ/pas+1;
  				break;
  				
			case 3: // Inactivi
				for(int i=0; strt<ns; strt++ )
    			{
    				if(i==pas) {W[j]=strt; W[activ/pas+4]=0; break;}
    				if(stud[strt].stare==0)
    					{
    					cout<<setw(2)<<++W[activ/pas+2]<<setw(6)<<stud[strt].id<<setw(12)<<stud[strt].nume<<setw(14)<<stud[strt].prenume<<setw(13)<<stud[strt].age<<setw(26)<<stud[strt].IDNP<<setw(18)<<stud[strt].grupa<<setw(11)<<stud[strt].stare<<endl;
						cout<<"---------------------------------------------------------------------------------------------------------"<<endl;
						i++;
						if(KEY==43 || W[activ/pas+3]==0) {W[activ/pas+3]++; W[activ/pas+4]++;}
						} 
  				}
  					cout<<"\n (+) - urmatorul, (-) - precedent, (ESC) - EXIT";
  					cout<<"\t\t\t\t\t\t   PAGINA "<<j<<" din ";
					if ((ns-activ)%2==0)cout<<(ns-activ)/pas;
					if ((ns-activ)%2!=0)cout<<(ns-activ)/pas+1;
					break;	
			}
		A:
		KEY=_getch();
  
		if( KEY == 43 )//+
			{
				switch(ID)
					{
						case 1: if(strt>=ns) goto A; else j++; break;
						case 2: if(W[activ/pas+3]==activ && j==activ/pas || W[activ/pas+3]==activ && j==activ/pas+1 ) goto A;
									else j++; break;

						case 3: if(W[activ/pas+3]==ns-activ && j==(ns-activ)/pas || W[activ/pas+3]==ns-activ && j==(ns-activ)/pas+1 || j==(ns-activ)/pas-1) goto A; 
									else j++; break;
					}
			 }
	
		if( KEY == 45 )//-
			{
				switch(ID)
					{
						case 1:	if(j==1 && W[0]==pas) goto A;
									else if(j==1) goto A;
									else { j--; strt-=((pas*2)-W[2]); W[1]-=((pas*2)-W[2]);W[2]=0; }	
								break;
									
						case 2: if(j==1 && strt==W[1]) goto A;
									else if(j==1) goto A;
									else { if(W[activ/pas+4]<pas && W[activ/pas+4]>0) {W[activ/pas+3]-=W[activ/pas+4]; W[activ/pas+2]-=(W[activ/pas+4]+pas);} 
												else {W[activ/pas+3]-=pas; W[activ/pas+2]-=(pas*2);}
											j--; 
											strt=W[j-1]; 
										} break;
								
						case 3: if(j==1 && strt==W[1]) goto A;
									else if(j==1) goto A;
									else { if(W[activ/pas+4]<pas && W[activ/pas+4]>0) {W[activ/pas+3]-=W[activ/pas+4]; W[activ/pas+2]-=(W[activ/pas+4]+pas);} 
												else {W[activ/pas+3]-=pas; W[activ/pas+2]-=(pas*2);}
											j--; 
											strt=W[j-1]; 
										} break;
						}
			}

		if( KEY == 27 ) break;
		if( KEY != 43 &&  KEY != 45 &&  KEY != 27 ) goto A;
		}
}


void findUSER(int ID)		
	{
	bool x=true;
	int k=0, U;
	char num[100];
					
	if(ID==1) {cout<<"\n\n\t Introduceti Numele de Utilizator: "; cin>>num; } 
	if(ID==2) {cout<<"\n\n\t Introduceti ID-ul Utilizatorului: "; cin>>U; }

		system("cls"); cout<<endl;
		cout<<"\n\n\t\t  REZULTATUL CAUTARII "<<endl<<endl;
		cout<<setw(3)<<" Nr. "<<setw(3)<<" ID. "<<setw(12)<<" Username "<<setw(15)<<" Password "<<setw(10)<<" Tipul "<<setw(10)<<" Starea "<<endl;
    	cout<<"---------------------------------------------------------"<<endl;
	switch(ID)
		{
		case 1: 
			for (int i=0; i<nu; i++)
			{
				if (strcmp(usr[i].username, num)==0)
				{
				x=false;					
       			cout<<setw(2)<<++k<<setw(6)<<usr[i].id<<setw(12)<<usr[i].username<<setw(17)<<usr[i].pass<<setw(7)<<usr[i].type<<setw(10)<<usr[i].stare<<endl;
				cout<<"---------------------------------------------------------"<<endl;
				}
			}
			break;
		case 2:
			for (int i=0; i<nu; i++)
			{
				if (usr[i].id==U)
				{
				x=false;					
       			cout<<setw(2)<<++k<<setw(6)<<usr[i].id<<setw(12)<<usr[i].username<<setw(17)<<usr[i].pass<<setw(7)<<usr[i].type<<setw(10)<<usr[i].stare<<endl;
				cout<<"---------------------------------------------------------"<<endl;
				}
			}
			break;
		}
	if(x)
		{
			cout<<"   Date introduse sunt incorecte sau acestea nu exista "<<endl; 
			cout<<"---------------------------------------------------------"<<endl;
		}
		cout<<"\t\t\t\tPress any key to continue ";
		int KEY=_getch();
		switch (KEY){default: return;}
	}


void findSTUD(int ID)		
	{
	bool x=true;
	char num[100];
					
	if(ID==1) cout<<"\n\n\t Introduceti Numele (conform datelor oficiale): ";
	if(ID==2) cout<<"\n\n\t Introduceti Prenumele (conform datelor oficiale): ";
	if(ID==3) cout<<"\n\n\t Introduceti IDNP (conform datelor oficiale): ";
	if(ID==4) cout<<"\n\n\t Introduceti Grupa (conform datelor oficiale): ";
		cin>>num;
		
		system("cls"); cout<<endl;
		cout<<"\n\n\t\t\t Rezultatul cautarii "<<endl<<endl;
		cout<<setw(3)<<" ID. "<<setw(10)<<" Nume "<<setw(15)<<" Prenume "<<setw(15)<<" Virsta "<<setw(20)<<" IDNP "<<setw(20)<<" Grupa "<<setw(15)<<" Starea "<<endl;
    	cout<<"------------------------------------------------------------------------------------------------------"<<endl;
	switch(ID)
		{
		case 1:
			if(usr[UID].type==1)
				{
					for (int i=0; i<ns; i++)
						{
						if (strcmp(stud[i].nume, num)==0)
							{
							x=false;					
       						cout<<setw(3)<<stud[i].id<<setw(12)<<stud[i].nume<<setw(14)<<stud[i].prenume<<setw(13)<<stud[i].age<<setw(26)<<stud[i].IDNP<<setw(18)<<stud[i].grupa<<setw(11)<<stud[i].stare<<endl;
							cout<<"------------------------------------------------------------------------------------------------------"<<endl;
							}
						}
				}
					else 
					{
						for (int i=0; i<ns; i++)
						{
						if (strcmp(stud[i].nume, num)==0 && stud[i].stare==1)
							{
							x=false;					
       						cout<<setw(3)<<stud[i].id<<setw(12)<<stud[i].nume<<setw(14)<<stud[i].prenume<<setw(13)<<stud[i].age<<setw(26)<<stud[i].IDNP<<setw(18)<<stud[i].grupa<<setw(11)<<stud[i].stare<<endl;
							cout<<"------------------------------------------------------------------------------------------------------"<<endl;
							}
						}
					}
			
			break;
		case 2:
			if(usr[UID].type==1) {
					for (int i=0; i<ns; i++)
					{
					if (strcmp(stud[i].prenume, num)==0)
						{
						x=false;					
       					cout<<setw(3)<<stud[i].id<<setw(12)<<stud[i].nume<<setw(14)<<stud[i].prenume<<setw(13)<<stud[i].age<<setw(26)<<stud[i].IDNP<<setw(18)<<stud[i].grupa<<setw(11)<<stud[i].stare<<endl;
						cout<<"------------------------------------------------------------------------------------------------------"<<endl;
						}
					}
				}
				else {
					for (int i=0; i<ns; i++)
						{
					if (strcmp(stud[i].prenume, num)==0 && stud[i].stare==1)
						{
						x=false;					
       					cout<<setw(3)<<stud[i].id<<setw(12)<<stud[i].nume<<setw(14)<<stud[i].prenume<<setw(13)<<stud[i].age<<setw(26)<<stud[i].IDNP<<setw(18)<<stud[i].grupa<<setw(11)<<stud[i].stare<<endl;
						cout<<"------------------------------------------------------------------------------------------------------"<<endl;
						}
						}	
					}
			break;
		case 3:
			if(usr[UID].type==1) {
				for (int i=0; i<ns; i++)
				{
					if (strcmp(stud[i].IDNP, num)==0)
					{
					x=false;					
       				cout<<setw(3)<<stud[i].id<<setw(12)<<stud[i].nume<<setw(14)<<stud[i].prenume<<setw(13)<<stud[i].age<<setw(26)<<stud[i].IDNP<<setw(18)<<stud[i].grupa<<setw(11)<<stud[i].stare<<endl;
					cout<<"------------------------------------------------------------------------------------------------------"<<endl;
					}
				}
			}
			else {
				for (int i=0; i<ns; i++)
				{
					if (strcmp(stud[i].IDNP, num)==0 && stud[i].stare==1)
					{
					x=false;					
       				cout<<setw(3)<<stud[i].id<<setw(12)<<stud[i].nume<<setw(14)<<stud[i].prenume<<setw(13)<<stud[i].age<<setw(26)<<stud[i].IDNP<<setw(18)<<stud[i].grupa<<setw(11)<<stud[i].stare<<endl;
					cout<<"------------------------------------------------------------------------------------------------------"<<endl;
					}
				}
			}
			break;
		case 4:
			if(usr[UID].type==1) {
				for (int i=0; i<ns; i++)
				{
					if (strcmp(stud[i].grupa, num)==0)
					{
					x=false;					
       				cout<<setw(3)<<stud[i].id<<setw(12)<<stud[i].nume<<setw(14)<<stud[i].prenume<<setw(13)<<stud[i].age<<setw(26)<<stud[i].IDNP<<setw(18)<<stud[i].grupa<<setw(11)<<stud[i].stare<<endl;
					cout<<"------------------------------------------------------------------------------------------------------"<<endl;
					}
				}
			}
			else{
				for (int i=0; i<ns; i++)
				{
					if (strcmp(stud[i].grupa, num)==0 && stud[i].stare==1)
					{
					x=false;					
       				cout<<setw(3)<<stud[i].id<<setw(12)<<stud[i].nume<<setw(14)<<stud[i].prenume<<setw(13)<<stud[i].age<<setw(26)<<stud[i].IDNP<<setw(18)<<stud[i].grupa<<setw(11)<<stud[i].stare<<endl;
					cout<<"------------------------------------------------------------------------------------------------------"<<endl;
					}
				}
				}
			break;	
		}
				

	if(x)
		{
			cout<<"\t Datele introduse sunt incorecte sau acestea nu exista "<<endl; 
			cout<<"------------------------------------------------------------------------------------------------------"<<endl;
		}
		cout<<"\t\t\t\t\t\t\t\t\t     Press any key to continue "<<endl;
		int KEY=_getch();
		switch (KEY){default: return;}
	}


void editUSER()
	{
	char X; int ID=0;
		system("cls");
		cout<<"\n\t\t Pentru a edita datele unui utilizator aveti nevoie de ID. "<<endl<<endl;
		cout<<" Cunoasteti ID-ul utilizatorului? [D]A / [N]U "<<endl<<endl;
		while(1)
		{
			X=_getch();
			if(toupper(X)=='D') 
				{
				cout<<" Inserati ID: ";
				ID=insertNUMBER();
				
				if(ID==27) return;
				else if(ID>nu){system("cls"); cout<<"\n\n\t Utilizator cu un astfel de ID nu exista."<<endl; Sleep(1000); return;}
					else break;
				}		
			else if(toupper(X)=='N') return;
		}	

	do{
		system("cls");
		cout<<"\n\n\t\t EDITARE UTILIZATOR "<<endl<<endl;
		cout<<"\t 1.   Schimbati Parola "<<endl;
		cout<<"\t 2.   Schimbati Tipul "<<endl;
		cout<<"\t 3.   Schimbati Starea "<<endl<<endl;
		cout<<"     ESC. Back"<<endl;
		while (1)
		{
			X=_getch();
			if (X==49 || X==50 || X==51 || X==27) break;
		}
		
		switch (X)
			{
				case 49:
					system("cls");
					cout<<"\n\tOld - "<<usr[ID].pass<<" | Parola noua - "; cin>>usr[ID].pass;
					break;
					
				case 50:
					system("cls");
					cout<<"\n\tOld - "<<usr[ID].stare<<" | Starea noua - "; cin>>usr[ID].stare;
					break;
				case 51:
					system("cls");
					cout<<"\n\tOld - "<<usr[ID].type<<" | Tip nou - "; cin>>usr[ID].type;
					break;
	
				case 27: break;
			}
		cout<<endl<<" Any key (continue) or ESC (exit)";
		}while(_getch() != 27);
	return;
	}


void editSTUD()
	{
	char X; int SID=0;
		system("cls");
		cout<<endl<<"\n\t\t Pentru a edita datele unui student aveti nevoie de ID. "<<endl<<endl;
		cout<<" Cunoasteti ID-ul studentului? [D]A / [N]U "<<endl<<endl;
		while(1)
		{
			X=_getch();
			if(toupper(X)=='D') 
				{
				cout<<" Inserati ID: ";
				SID=insertNUMBER();

				if(SID==27) return;
				else if(SID>ns){system("cls"); cout<<"\n\n\t Student cu un astfel de ID nu exista."<<endl; Sleep(1000); return;}
				else if(usr[UID].type!=1 && stud[SID].stare!=1) {system("cls"); cout<<"\n\n\t Studentul cu acest de ID nu mai este activ."<<endl; Sleep(1000); return;}
					else break;
				}
			else if(toupper(X)=='N') return;
		}

	do{
		system("cls");
		cout<<"\n\n\t\t EDITARE STUDENT "<<endl<<endl;
		cout<<"\t 1.   Editati Toate Datele "<<endl;
		cout<<"\t    2.   Editare Nume "<<endl;
		cout<<"\t    3.   Editare Prenume "<<endl;
		cout<<"\t    4.   Editare Grupa "<<endl;
		cout<<"\t    5.   Editare Virsta "<<endl;
		if(usr[UID].type==1) cout<<"\t    6.   Editare Stare "<<endl<<endl;
		cout<<"     ESC. Back"<<endl;
		while (1)
		{
			A:
			X=_getch();
			if (X==49 || X==50 || X==51 || X==52 || X==53 || X==54 || X==27) break;
		}
		
		switch (X)
			{
				case 49:
					system("cls");
					cout<<"\n\t\tEditati Nume?  [D]A / [N]U"<<endl;
					X=_getch();
					if(toupper(X)=='D') {cout<<"\tOld - "<<stud[SID].nume<<" | Nume nou - "; cin>>stud[SID].nume;}
  	
					cout<<"\n\t\tEditati Prenume?  [D]A / [N]U"<<endl;
					X=_getch();
					if(toupper(X)=='D') {cout<<"\tOld - "<<stud[SID].prenume<<" | Prenume nou - "; cin>>stud[SID].prenume;}
  	
  				  	cout<<"\n\t\tEditati Grupa? [D]A / [N]U"<<endl;
  					X=_getch();
  					if(toupper(X)=='D') {cout<<"\tOld - "<<stud[SID].grupa<<" | Grupa noua - "; cin>>stud[SID].grupa;}
	
  					cout<<"\n\t\tEditati Virsta? [D]A / [N]U"<<endl;
  					X=_getch();
  					if(toupper(X)=='D') {cout<<"\tOld - "<<stud[SID].age<<" | Virsta noua - "; cin>>stud[SID].age;}
					if(usr[UID].type==1)
						{
							cout<<"\n\t\tEditati Starea? [D]A / [N]U"<<endl;
  							X=_getch();
  							if(toupper(X)=='D') {
							  					cout<<"\tOld - "<<stud[SID].stare<<" | Stare noua - "; 
												cin>>stud[SID].stare;
													if(stud[SID].stare==0) stat[UID].nrSTDD++;
												}
  							else if(toupper(X)=='N') return;
						}
					return;
					
				case 50:
					system("cls");
					cout<<"\n\tOld - "<<stud[SID].nume<<" | Nume nou - "; cin>>stud[SID].nume;
					break;
				case 51:
					system("cls");
					cout<<"\n\tOld - "<<stud[SID].prenume<<" | Prenume nou - "; cin>>stud[SID].prenume;
					break;
				case 52:
					system("cls");
					cout<<"\n\tOld - "<<stud[SID].grupa<<" | Grupa noua - "; cin>>stud[SID].grupa;
					break;
				case 53:
					system("cls");
					cout<<"\n\tOld - "<<stud[SID].age<<" | Virsta noua - "; cin>>stud[SID].age;
					break;
				case 54:
					if(usr[UID].type==1){system("cls");	cout<<"\n\tOld - "<<stud[SID].stare<<" | Stare noua - "; cin>>stud[SID].stare;break;}
					else goto A;
	
				case 27: break;
			}
		cout<<endl<<" Any key (continue) or ESC (exit)";
		}while(_getch() != 27);
	return;
	}


void showStats()
	{
	char X, file[10]; int ID=0;
		system("cls");
		cout<<endl<<"\n\t\t Pentru a vizualiza statisica aveti nevoie de ID-ul utilizatorului "<<endl<<endl;
		cout<<" Cunoasteti ID-ul? [D]A / [N]U "<<endl<<endl;
	
	while(1)
		{
			X=_getch();
			if(toupper(X)=='D') 
				{
				cout<<" Inserati ID: ";
				ID=insertNUMBER();
				
				if(ID==27) return;
				else if(ID>nu){system("cls"); cout<<"\n\n\t Utilizator cu un astfel de ID nu exista"<<endl; Sleep(1000); return;}
					else break;	
				}
			else if(toupper(X)=='N') return;
		}
		
		system("cls");	
		cout<<"\n\n\t  STATISTICA UTILIZATORULUI: "<<usr[ID].username<<" [ID-"<<ID<<", Tip-"<<usr[ID].type<<", Stare-"<<usr[ID].stare<<']'<<endl<<endl;
		cout<<setw(3)<<" Logari "<<setw(24)<<" Utilizatori inserati "<<setw(21)<<" Studenti inserati "<<setw(20)<<" Studenti editati "<<setw(23)<<" Studenti dezacivati "<<endl;
    	cout<<"------------------------------------------------------------------------------------------------"<<endl;
		cout<<setw(4)<<stat[ID].nrAC<<setw(18)<<stat[ID].nrUSR<<setw(22)<<stat[ID].nrSTUD<<setw(21)<<stat[ID].nrEDIT<<setw(21)<<stat[ID].nrSTDD<<endl;
		cout<<"------------------------------------------------------------------------------------------------"<<endl;
		cout<<endl<<"   Salvati datele intr-un fisier? [D]A / [N]U "<<endl;
		X=_getch();
       		if(toupper(X)=='D')
        		{
        		cout<<endl<<"\t Introduceti numele fisierului ce va fi salvat: ";
        		cin>>file;
        		strcat(file,".txt");
        		EE = fopen(file, "w+");
        		fprintf(EE,"\n\n\t\t  STATISTICA UTILIZATORULUI: %s [ID-%d, Tip-%d, Stare-%d]\n\n", usr[ID].username,ID,usr[ID].type,usr[ID].stare);
        		fprintf(EE,"%3s%24s%21s%20s%23s\n", "Logari","Utilizatori inserati","Studenti inserati","Studenti editati","Studenti dezacivati");
				fprintf(EE,"-----------------------------------------------------------------------------------------------\n");
				fprintf(EE,"%4d%18d%22d%21d%21d\n", stat[ID].nrAC,stat[ID].nrUSR,stat[ID].nrSTUD,stat[ID].nrEDIT,stat[ID].nrSTDD);
				fprintf(EE,"-----------------------------------------------------------------------------------------------\n");
				fclose(EE);
				}
        			else if(toupper(X)=='N') return;
	}


void raport(int ID)
{
	int K, l=0, o=2;
	char u, name[10]="Raport", select[30]="True";
	
	if(usr[UID].type==1)
		{
			system("cls");
			cout<<"\n\n\t\t GENERATI RAPORT "<<endl<<endl;
			cout<<"\t 1.   Toti "<<endl;
			cout<<"\t 2.   Activi "<<endl;
			cout<<"\t 3.   Inactivi "<<endl;
			cout<<"\n     ESC. EXIT"<<endl;
			while (1)
			{
				K=_getch();
				if (K==49 || K==50 || K==51 || K==27) break;
			}
			switch (K)
				{
					case 49: o=1; break;
					case 50: o=2; break;
					case 51: o=3; break;

					case 27: return;
				}
		}
			system("cls");
			cout<<"\n\n\t\t FORMAT RAPORT "<<endl<<endl;
			cout<<"\t 1.   .txt "<<endl;
			cout<<"\t 2.   .doc "<<endl;
			cout<<"\t 3.   .xls "<<endl;
			cout<<"\n     ESC. EXIT"<<endl;
			while (1)
				{
					K=_getch();
					if (K==49 || K==50 || K==51 || K==27) break;
				}
				switch (K)
					{
						case 49: strcat(name,".txt"); u='t'; break;
						case 50: strcat(name,".doc"); u='d'; break;
						case 51: strcat(name,".xls"); u='x'; break;

						case 27: return;
					}		
		EE = fopen(name, "w+");
		switch(ID)
			{
			case 1:
				system("cls");
				cout<<"\n\n\tInserati Virsta: ";
				K=insertNUMBER();
				if(K==27) return;

				switch (u)
					{
					case 't':
							fprintf(EE,"\n\t\t\t\t  RAPORT \n\n\n");
							fprintf(EE,"%s%5s%10s%13s%10s%12s%16s%10s\n","NR.","ID.","NUME","PRENUME","VIRSTA","IDNP","GRUPA","STAREA");
							fprintf(EE,"-------------------------------------------------------------------------------\n");
							switch (o)
								{
									case 1:// All
										for(int i=0; i<ns; i++ )
    										{
    											if(stud[i].age==K)
    											{
												fprintf(EE,"% d%5d%11s%13s%8d%19s%13s%6d\n",i+1,stud[i].id,stud[i].nume,stud[i].prenume,stud[i].age,stud[i].IDNP,stud[i].grupa,stud[i].stare);	
												fprintf(EE,"-------------------------------------------------------------------------------\n");
												}
  											}
										break;
					
									case 2: //Activi
										for(int i=0,j=0; i<ns; i++ )
    										{
    										if(stud[i].age==K && stud[i].stare==1)
    											{
												fprintf(EE,"% d%5d%11s%13s%8d%19s%13s%6d\n",++j,stud[i].id,stud[i].nume,stud[i].prenume,stud[i].age,stud[i].IDNP,stud[i].grupa,stud[i].stare);	
												fprintf(EE,"-------------------------------------------------------------------------------\n");
												}
  											}
										break;

									case 3: //Inactivi
										for(int i=0,j=0; i<ns; i++ )
    									{
    										if(stud[i].age==K && stud[i].stare==0)
    										{
											fprintf(EE,"% d%5d%11s%13s%8d%19s%13s%6d\n",++j,stud[i].id,stud[i].nume,stud[i].prenume,stud[i].age,stud[i].IDNP,stud[i].grupa,stud[i].stare);	
											fprintf(EE,"-------------------------------------------------------------------------------\n");
											}
  										}
									break;
								}
							break;
					case 'd':
							fprintf(EE,"\t\t\t\t\t\tRAPORT \n\n");
							fprintf(EE,"%s%4s%10s%13s%10s%11s%13s%9s\n","NR.","ID.","NUME","PRENUME","VIRSTA","IDNP","GRUPA","STAREA");
							fprintf(EE,"-------------------------------------------------------------------------\n");
								switch (o)
								{
									case 1:// All
										for(int i=0; i<ns; i++ )
    										{
    											if(stud[i].age==K)
    											{
    											fprintf(EE,"% d%4d%11s%13s%8d%17s%11s%5d\n",i+1,stud[i].id,stud[i].nume,stud[i].prenume,stud[i].age,stud[i].IDNP,stud[i].grupa,stud[i].stare);	
												fprintf(EE,"-------------------------------------------------------------------------\n");	
												}	
  											}
										break;
					
									case 2: //Activi
										for(int i=0,j=0; i<ns; i++ )
    										{
    										if(stud[i].age==K && stud[i].stare==1)
    											{
												fprintf(EE,"% d%4d%11s%13s%8d%17s%11s%5d\n",++j,stud[i].id,stud[i].nume,stud[i].prenume,stud[i].age,stud[i].IDNP,stud[i].grupa,stud[i].stare);	
												fprintf(EE,"-------------------------------------------------------------------------\n");
												}
  											}
										break;

									case 3: //Inactivi
										for(int i=0,j=0; i<ns; i++ )
    									{
    										if(stud[i].age==K && stud[i].stare==0)
    										{
											fprintf(EE,"% d%4d%11s%13s%8d%17s%11s%5d\n",++j,stud[i].id,stud[i].nume,stud[i].prenume,stud[i].age,stud[i].IDNP,stud[i].grupa,stud[i].stare);	
											fprintf(EE,"-------------------------------------------------------------------------\n");
											}
  										}
									break;
								}
							break;
						
					case 'x':
							fprintf(EE,"\t\t\t\t  RAPORT \n\n");
							fprintf(EE,"%s\t%10s\t%8s\t%7s\t%10s\t%9s\t%9s\t%10s\n","NR.","ID.","NUME","PRENUME","VIRSTA","IDNP","GRUPA","STAREA");
								switch (o)
								{
									case 1:// All
									for(int i=0; i<ns; i++ ) 
										{
										if(stud[i].age==K) fprintf(EE,"%d\t%d\t%s\t%s\t%d\t%s\t%s\t%d\n",i+1,stud[i].id,stud[i].nume,stud[i].prenume,stud[i].age,stud[i].IDNP,stud[i].grupa,stud[i].stare);
										}
									break;
					
									case 2: //Activi
										for(int i=0,j=0; i<ns; i++ )
    										{
    										if(stud[i].age==K && stud[i].stare==1) fprintf(EE,"%d\t%d\t%s\t%s\t%d\t%s\t%s\t%d\n",++j,stud[i].id,stud[i].nume,stud[i].prenume,stud[i].age,stud[i].IDNP,stud[i].grupa,stud[i].stare);	
  											}
										break;

									case 3: //Inactivi
										for(int i=0,j=0; i<ns; i++ )
    									{
    										if(stud[i].age==K && stud[i].stare==0) fprintf(EE,"%d\t%d\t%s\t%s\t%d\t%s\t%s\t%d\n",++j,stud[i].id,stud[i].nume,stud[i].prenume,stud[i].age,stud[i].IDNP,stud[i].grupa,stud[i].stare);
  										}
									break;
								}
							break;	
							}
						break;	
			case 2:
				system("cls");
				cout<<"\n\n\t\t Introduceti grupa: "; cin>>select;
				switch (u)
					{
					case 't':
							fprintf(EE,"\n\t\t\t\t  RAPORT \n\n\n");
							fprintf(EE,"%s%5s%10s%13s%10s%12s%16s%10s\n","NR.","ID.","NUME","PRENUME","VIRSTA","IDNP","GRUPA","STAREA");
							fprintf(EE,"-------------------------------------------------------------------------------\n");
							switch (o)
								{
									case 1:// All
										for(int i=0; i<ns; i++ )
    										{
    											if(strcmp(stud[i].grupa,select)==0)
    											{
												fprintf(EE,"% d%5d%11s%13s%8d%19s%13s%6d\n",i+1,stud[i].id,stud[i].nume,stud[i].prenume,stud[i].age,stud[i].IDNP,stud[i].grupa,stud[i].stare);	
												fprintf(EE,"-------------------------------------------------------------------------------\n");
												}
  											}
										break;
					
									case 2: //Activi
										for(int i=0,j=0; i<ns; i++ )
    										{
    										if(strcmp(stud[i].grupa,select)==0 && stud[i].stare==1)
    											{
												fprintf(EE,"% d%5d%11s%13s%8d%19s%13s%6d\n",++j,stud[i].id,stud[i].nume,stud[i].prenume,stud[i].age,stud[i].IDNP,stud[i].grupa,stud[i].stare);	
												fprintf(EE,"-------------------------------------------------------------------------------\n");
												}
  											}
										break;

									case 3: //Inactivi
										for(int i=0,j=0; i<ns; i++ )
    									{
    										if(strcmp(stud[i].grupa,select)==0 && stud[i].stare==0)
    										{
											fprintf(EE,"% d%5d%11s%13s%8d%19s%13s%6d\n",++j,stud[i].id,stud[i].nume,stud[i].prenume,stud[i].age,stud[i].IDNP,stud[i].grupa,stud[i].stare);	
												fprintf(EE,"-------------------------------------------------------------------------------\n");
											}
  										}
									break;
								}
							break;
						
					case 'd':
							fprintf(EE,"\t\t\t\t\t\tRAPORT \n\n");
							fprintf(EE,"%s%4s%10s%13s%10s%11s%13s%9s\n","NR.","ID.","NUME","PRENUME","VIRSTA","IDNP","GRUPA","STAREA");
							fprintf(EE,"-------------------------------------------------------------------------\n");
								switch (o)
								{
									case 1:// All
										for(int i=0; i<ns; i++ )
    										{
    											if(strcmp(stud[i].grupa,select)==0)
    											{
    											fprintf(EE,"% d%4d%11s%13s%8d%17s%11s%5d\n",i+1,stud[i].id,stud[i].nume,stud[i].prenume,stud[i].age,stud[i].IDNP,stud[i].grupa,stud[i].stare);	
												fprintf(EE,"-------------------------------------------------------------------------\n");	
												}	
  											}
										break;
					
									case 2: //Activi
										for(int i=0,j=0; i<ns; i++ )
    										{
    										if(strcmp(stud[i].grupa,select)==0 && stud[i].stare==1)
    											{
												fprintf(EE,"% d%4d%11s%13s%8d%17s%11s%5d\n",++j,stud[i].id,stud[i].nume,stud[i].prenume,stud[i].age,stud[i].IDNP,stud[i].grupa,stud[i].stare);	
												fprintf(EE,"-------------------------------------------------------------------------\n");
												}
  											}
										break;

									case 3: //Inactivi
										for(int i=0,j=0; i<ns; i++ )
    									{
    										if(strcmp(stud[i].grupa,select)==0 && stud[i].stare==0)
    										{
											fprintf(EE,"% d%4d%11s%13s%8d%17s%11s%5d\n",++j,stud[i].id,stud[i].nume,stud[i].prenume,stud[i].age,stud[i].IDNP,stud[i].grupa,stud[i].stare);	
											fprintf(EE,"-------------------------------------------------------------------------\n");
											}
  										}
									break;
								}
							break;
						
					case 'x':
							fprintf(EE,"\t\t\t\t  RAPORT \n\n");
							fprintf(EE,"%s\t%10s\t%8s\t%7s\t%10s\t%9s\t%9s\t%10s\n","NR.","ID.","NUME","PRENUME","VIRSTA","IDNP","GRUPA","STAREA");
								switch (o)
								{
									case 1:// All
									for(int i=0; i<ns; i++ ) 
										{
										if(strcmp(stud[i].grupa,select)==0) fprintf(EE,"%d\t%d\t%s\t%s\t%d\t%s\t%s\t%d\n",i+1,stud[i].id,stud[i].nume,stud[i].prenume,stud[i].age,stud[i].IDNP,stud[i].grupa,stud[i].stare);
										}
									break;
					
									case 2: //Activi
										for(int i=0,j=0; i<ns; i++ )
    										{
    										if(strcmp(stud[i].grupa,select)==0 && stud[i].stare==1) fprintf(EE,"%d\t%d\t%s\t%s\t%d\t%s\t%s\t%d\n",++j,stud[i].id,stud[i].nume,stud[i].prenume,stud[i].age,stud[i].IDNP,stud[i].grupa,stud[i].stare);	
  											}
										break;

									case 3: //Inactivi
										for(int i=0,j=0; i<ns; i++ )
    									{
    										if(strcmp(stud[i].grupa,select)==0 && stud[i].stare==0) fprintf(EE,"%d\t%d\t%s\t%s\t%d\t%s\t%s\t%d\n",++j,stud[i].id,stud[i].nume,stud[i].prenume,stud[i].age,stud[i].IDNP,stud[i].grupa,stud[i].stare);
  										}
									break;
								}
							break;
					}
				break;
			case 3:
				switch (u)
					{
					case 't':
							fprintf(EE,"\n\t\t\t\t  RAPORT \n\n\n");
							fprintf(EE,"%s%5s%10s%13s%10s%12s%16s%10s\n","NR.","ID.","NUME","PRENUME","VIRSTA","IDNP","GRUPA","STAREA");
							fprintf(EE,"-------------------------------------------------------------------------------\n");
							switch (o)
								{
									case 1:// All
										for(int i=0; i<ns; i++ )
    										{
												fprintf(EE,"% d%5d%11s%13s%8d%19s%13s%6d\n",i+1,stud[i].id,stud[i].nume,stud[i].prenume,stud[i].age,stud[i].IDNP,stud[i].grupa,stud[i].stare);	
												fprintf(EE,"-------------------------------------------------------------------------------\n");
  											}
										break;
					
									case 2: //Activi
										for(int i=0,j=0; i<ns; i++ )
    										{
    										if(stud[i].stare==1)
    											{
												fprintf(EE,"% d%5d%11s%13s%8d%19s%13s%6d\n",++j,stud[i].id,stud[i].nume,stud[i].prenume,stud[i].age,stud[i].IDNP,stud[i].grupa,stud[i].stare);	
												fprintf(EE,"-------------------------------------------------------------------------------\n");
												}
  											}
										break;

									case 3: //Inactivi
										for(int i=0,j=0; i<ns; i++ )
    									{
    										if(stud[i].stare==0)
    										{
											fprintf(EE,"% d%5d%11s%13s%8d%19s%13s%6d\n",++j,stud[i].id,stud[i].nume,stud[i].prenume,stud[i].age,stud[i].IDNP,stud[i].grupa,stud[i].stare);	
												fprintf(EE,"-------------------------------------------------------------------------------\n");
											}
  										}
									break;
								}
							break;
						
					case 'd':
							fprintf(EE,"\t\t\t\t\t\tRAPORT \n\n");
							fprintf(EE,"%s%4s%10s%13s%10s%11s%13s%9s\n","NR.","ID.","NUME","PRENUME","VIRSTA","IDNP","GRUPA","STAREA");
							fprintf(EE,"-------------------------------------------------------------------------\n");
								switch (o)
								{
									case 1:// All
										for(int i=0; i<ns; i++ )
    										{
												fprintf(EE,"% d%4d%11s%13s%8d%17s%11s%5d\n",i+1,stud[i].id,stud[i].nume,stud[i].prenume,stud[i].age,stud[i].IDNP,stud[i].grupa,stud[i].stare);	
												fprintf(EE,"-------------------------------------------------------------------------\n");
  											}
										break;
					
									case 2: //Activi
										for(int i=0,j=0; i<ns; i++ )
    										{
    										if(stud[i].stare==1)
    											{
												fprintf(EE,"% d%4d%11s%13s%8d%17s%11s%5d\n",++j,stud[i].id,stud[i].nume,stud[i].prenume,stud[i].age,stud[i].IDNP,stud[i].grupa,stud[i].stare);	
												fprintf(EE,"-------------------------------------------------------------------------\n");
												}
  											}
										break;

									case 3: //Inactivi
										for(int i=0,j=0; i<ns; i++ )
    									{
    										if(stud[i].stare==0)
    										{
											fprintf(EE,"% d%4d%11s%13s%8d%17s%11s%5d\n",++j,stud[i].id,stud[i].nume,stud[i].prenume,stud[i].age,stud[i].IDNP,stud[i].grupa,stud[i].stare);	
											fprintf(EE,"-------------------------------------------------------------------------\n");
											}
  										}
									break;
								}
							break;
						
					case 'x':
							fprintf(EE,"\t\t\t\t  RAPORT \n\n");
							fprintf(EE,"%s\t%10s\t%8s\t%7s\t%10s\t%9s\t%9s\t%10s\n","NR.","ID.","NUME","PRENUME","VIRSTA","IDNP","GRUPA","STAREA");
								switch (o)
								{
									case 1:// All
									for(int i=0; i<ns; i++ ) fprintf(EE,"%d\t%d\t%s\t%s\t%d\t%s\t%s\t%d\n",i+1,stud[i].id,stud[i].nume,stud[i].prenume,stud[i].age,stud[i].IDNP,stud[i].grupa,stud[i].stare);
									break;
					
									case 2: //Activi
										for(int i=0,j=0; i<ns; i++ )
    										{
    										if(stud[i].stare==1) fprintf(EE,"%d\t%d\t%s\t%s\t%d\t%s\t%s\t%d\n",++j,stud[i].id,stud[i].nume,stud[i].prenume,stud[i].age,stud[i].IDNP,stud[i].grupa,stud[i].stare);	
  											}
										break;

									case 3: //Inactivi
										for(int i=0,j=0; i<ns; i++ )
    									{
    										if(stud[i].stare==0) fprintf(EE,"%d\t%d\t%s\t%s\t%d\t%s\t%s\t%d\n",++j,stud[i].id,stud[i].nume,stud[i].prenume,stud[i].age,stud[i].IDNP,stud[i].grupa,stud[i].stare);
  										}
									break;
								}
							break;
					}
			break;	
		}

    fclose(EE);
	
	system(name);
	return;
}
