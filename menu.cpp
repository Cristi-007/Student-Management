int adm_1()
	{
		lvl=1;
		system("cls");
		cout<<"\n\n\t\t\t MENIU "<<endl<<endl;
		cout<<"\t 1.   Management Utilizatori "<<endl;
		cout<<"\t 2.   Management Studenti "<<endl;
		cout<<"\t 3.   Rapoarte "<<endl;
		cout<<"\t 4.   Salvati datele modificate "<<endl<<endl;
		cout<<"     ESC. EXIT"<<endl;
		int K;
		while (1)
		{
			K=_getch();
			if (K==49 || K==50 || K==51 || K==52 || K==27) break;
		}
		switch (K)
			{
				case 49: lvl=2; break;
				case 50: lvl=5; break;
				case 51: lvl=8; break;
				case 52: return 304;
				
				case 27: return 99;
			}
		return 0;
	}

//**************UTILIZATORI**************//
int adm_2()
	{
		lvl=2;
		system("cls");
		cout<<"\n\n\t\t MANAGEMENT UTILIZATORI "<<endl<<endl;
		cout<<"\t 1.   Inserati Utilizator Nou "<<endl;
		cout<<"\t 2.   Editati Utilizator "<<endl;
		cout<<"\t 3.   Cautati Utilizator "<<endl;
		cout<<"\t 4.   Afisati Utilizatori "<<endl<<endl;
		cout<<"     ESC. Back "<<endl;
		int K;
		while (1)
		{
			K=_getch();
			if (K==49 || K==50 || K==51 || K==52 || K==27) break;
		}
		switch (K)
			{
				case 49: return 101;
				case 50: return 104;
				case 51: lvl=3; break;
				case 52: lvl=4; break;
				
				case 27: lvl=1; break;
			}
		return 0;
	}
	
int adm_3()
	{
		lvl=3;
		system("cls");
		cout<<"\n\n\t\t CAUTARE UTILIZATORI "<<endl<<endl;
		cout<<"\t 1.   .. dupa numele de utilizator "<<endl;
		cout<<"\t 2.   .. dupa ID "<<endl<<endl;
		cout<<"     ESC. Back"<<endl;
		int K;
		while (1)
		{
			K=_getch();
			if (K==49 || K==50 || K==51 || K==52|| K==27) break;
		}
		switch (K)
			{
				case 49: return 102;
				case 50: return 103;
				
				case 27: lvl=2; break;
			}
		return 0;
	}

	
int adm_4()
	{
		lvl=4;
		system("cls");
		cout<<"\n\n\t\t AFISARE UTILIZATORI "<<endl<<endl;
		cout<<"\t 1.   Toti "<<endl;
		cout<<"\t 2.   Activi "<<endl;
		cout<<"\t 3.   Inactivi "<<endl<<endl;
		cout<<"     ESC. Back"<<endl;
		int K;
		while (1)
		{
			K=_getch();
			if (K==49 || K==50 || K==51 || K==27) break;
		}
		switch (K)
			{
				case 49: return 106;
				case 50: return 107;
				case 51: return 108;
				
				case 27: lvl=2; break;
			}
		return 0;
	}


//**************STUDENTI**************//
int adm_5()
	{
		lvl=5;
		system("cls");
		cout<<"\n\n\t\t MANAGEMENT STUDENTI "<<endl<<endl;
		cout<<"\t 1.   Inserati Student Nou "<<endl;
		cout<<"\t 2.   Afisati Studenti "<<endl;
		cout<<"\t 3.   Cautati Studenti "<<endl;
		cout<<"\t 4.   Editati Studenti "<<endl<<endl;
		cout<<"     ESC. Back"<<endl;
		int K;
		while (1)
		{
			K=_getch();
			if (K==49 || K==50 || K==51 || K==52 || K==27) break;
		}
		switch (K)
			{
				case 49: return 201;
				case 50: lvl=6; break;
				case 51: lvl=7; break;
				case 52: return 209;
				
				case 27: lvl=1; break;
			}
		return 0;
	}	
	
	
int adm_6()
	{
		lvl=6;
		system("cls");
		cout<<"\n\n\t\t AFISARE STUDENTI "<<endl<<endl;
		cout<<"\t 1.  Toti "<<endl;
		cout<<"\t 2.  Activi  "<<endl;
		cout<<"\t 3.  Inactivi "<<endl<<endl;
		cout<<"     ESC. Back"<<endl;
		int K;
		while (1)
		{
			K=_getch();
			if (K==49 || K==50 || K==51 || K==27) break;
		}
		switch (K)
			{
				case 49: return 202;
				case 50: return 203;
				case 51: return 204;
				
				case 27: lvl=5; break;
			}
		return 0;
	}
	
	
int adm_7()
	{
		lvl=7;
		system("cls");
		cout<<"\n\n\t\t CAUTARE STUDENTI "<<endl<<endl;
		cout<<"\t 1.   .. dupa nume "<<endl;
		cout<<"\t 2.   .. dupa prenume "<<endl;
		cout<<"\t 3.   .. dupa IDNP "<<endl;
		cout<<"\t 4.   .. dupa grupa "<<endl<<endl;
		cout<<"     ESC. Back"<<endl;
		int K;
		while (1)
		{
			K=_getch();
			if (K==49 || K==50 || K==51 || K==52|| K==27) break;
		}
		switch (K)
			{
				case 49: return 205;
				case 50: return 206;
				case 51: return 207;
				case 52: return 208;
				
				case 27: lvl=5; break;
			}
		return 0;
	}
	

//**************STATISTICA**************//
int adm_8()
	{
		lvl=8;
		system("cls");
		cout<<"\n\n\t\t\t RAPOARTE "<<endl<<endl;
		cout<<"\t 1.   Lista studentilor confom virstei "<<endl;
		cout<<"\t 2.   Lista studentilor confom grupei "<<endl;
		cout<<"\t 3.   Lista tuturor studentilor "<<endl;
		if(usr[UID].type==1) cout<<"\t 4.   Rapoarte statistice "<<endl; // trebue submeniu
		cout<<"\n     ESC. EXIT"<<endl;
		int K;
		while (1)
		{
			K=_getch();
			if (K==49 || K==50 || K==51 || K==52 || K==27) break;
		}
		switch (K)
			{
				case 49: return 301;
				case 50: return 302;
				case 51: return 303;
				case 52: if(usr[UID].type==1) return 105;
							else lvl=8; break;
				
				case 27: lvl=1; break;
			}
		return 0;
	}

		
int MENIUadm()
	{
		switch(lvl)
		{
			case 1: return adm_1();
			case 2: return adm_2();
			case 3: return adm_3();
			case 4: return adm_4();
			case 5: return adm_5();
			case 6: return adm_6();
			case 7: return adm_7();
			case 8: return adm_8();
		}
	return 0;
	}


//////////////////////////USER
int usr_1()
	{
		lvl=1;
		system("cls");
		cout<<"\n\n\t\t\t MENIU "<<endl<<endl;
		cout<<"\t 1.   Cautare Studenti "<<endl;
		cout<<"\t 2.   Afisare Studenti "<<endl;
		cout<<"\t 3.   Editare Studenti "<<endl;
		cout<<"\t 4.   Rapoarte "<<endl;
		cout<<"\t 5.   Salvati datele modificate "<<endl<<endl;
		cout<<"     ESC. EXIT"<<endl;
		int K;
		while (1)
		{
			K=_getch();
			if (K==49 || K==50 || K==51 || K==52 || K==53 || K==27) break;
		}
		switch (K)
			{
				case 49: lvl=2; break;
				case 50: return 203;
				case 51: return 209;
				case 52: lvl=8; break;
				case 53: return 304;
				
				case 27: return 99;
			}
		return 0;
	}


int usr_2()
	{
		lvl=2;
		system("cls");
		cout<<"\n\n\t\t CAUTARE STUDENTI "<<endl<<endl;
		cout<<"\t 1.   .. dupa nume "<<endl;
		cout<<"\t 2.   .. dupa prenume "<<endl;
		cout<<"\t 3.   .. dupa IDNP "<<endl;
		cout<<"\t 4.   .. dupa grupa "<<endl<<endl;
		cout<<"     ESC. Back"<<endl;
		int K;
		while (1)
		{
			K=_getch();
			if (K==49 || K==50 || K==51 || K==52|| K==27) break;
		}
		switch (K)
			{
				case 49: return 205;
				case 50: return 206;
				case 51: return 207;
				case 52: return 208;
				
				case 27: lvl=1; break;
			}
		return 0;
	}



int MENIUusr()
	{
		switch(lvl)
		{
			case 1: return usr_1();
			case 2: return usr_2();
			case 8: return adm_8();
		}
	return 0;	
	}

