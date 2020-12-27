/*
	Scrivere un programma per la gestione degli esami degli studenti
	di un corso universitario. Ogni studente Ë caratterizzato da 
	cognome, nome, numero di matricola e anno di corso a cui Ë
	correntemente iscritto (lo studente puÚ essere in corso oppure 
	fuori corso). Degli esami sostenuti si conoscono il nome del 
	corso, il voto (eventualmente con la lode) e la data dellíappello.
	Il programma deve consentire di effettuare le seguenti 
	operazioni:

		1-inserimento e ricerca (con visualizzazione) dei dati di uno 
		  studente di cui si conosce la matricola;

		2-inserimento dei dati di un esame sostenuto da uno studente di 
		  cui si conosce la matricola;

		3-dato il numero di matricola di uno studente, fornire il numero 
		  di esami sostenuti dallo studente assieme alla media dei voti;

		4-determinare nome e cognome degli studenti che hanno superato 
		  gli esami con media superiore ad un certo valore fissato.

	Si ipotizzi che il numero massimo di studenti sia 100 e che ognuno 
	debba sostenere al pi˘ 30 esami.
*/

#include<iostream>
#include<iomanip>
using namespace std;



const int FALSO=0;
const int VERO=1;

struct Data
	{   int giorno;
		int mese; 
		int anno;
    };

struct Esame
	{   char corso [25];
		int voto;
		int lode;         //1=lode, 0=no lode
		Data dataEsame;
	};

int DIM=30;

struct Esami
	{int numesami;
	// int media;
	 Esame esamiStud[30];
	};

struct Studente
	{char cognome[15];
	 char nome[15];
	 int matr;
	  int aacorso;
	  int incorso;
	  Esami sostenuti;
	};

const int MAX=100;

struct Studenti
	{int numstudenti;
	// int media;
	 Studente universit‡ [MAX];
	};

Studenti inizializzaTabella();
void stampaTabella(Studenti &);
int cercaposizione(int,int &,Studenti&);
int insertnew(Studenti&);
int Delete(Studenti&);
char menu(Studenti &);


Studenti inizializzaTabella()
{
	Studenti elenco=
				{
					3,
					{
						{"Pirro","Carlo",252,3,1,{
													3,
														{
															{"Fisica",25,0,{25,5,2012}},
															{"Chimica",30,1,{30,4,2013}},
															{"Analisi",27,0,{12,9,2013}}
														}
												  }
						},

						{"Lotti","Piera",289,2,0,{
													2,
														{
															{"Geometria",29,0,{23,12,2012}},
															{"Laboratorio",30,1,{30,7,2011}},
						
														}
												  }
						},

						{"Leto","Ugo",299,1,1,{
													4,
															{
																{"Elettronica",27,0,{2,8,2012}},
																{"Elettrotecnica",30,0,{3,3,2013}},
																{"Reti",28,0,{13,5,2013}},
																{"Calcolo",26,0,{31,8,2012}}
															}
											  }
						}
					}
	             };
		
	return elenco;
}

void stampaTabella(Studenti &elenco)
	{cout<<"\n\nStampa Tabella attuale:\n";
     
		for(int a=0; a<elenco.numstudenti;a++)
		{cout<<"Cognome= "<<elenco.universit‡[a].cognome<<". Nome= "<<elenco.universit‡[a].nome<<". Matr= "
		     <<elenco.universit‡[a].matr<<". Anno Corso= "<<elenco.universit‡[a].aacorso<<". In corso= "
			 <<elenco.universit‡[a].incorso<<endl;
		     for(int b=0;b<elenco.universit‡[a].sostenuti.numesami;b++)
				 {cout<<"Corso= "<<elenco.universit‡[a].sostenuti.esamiStud[b].corso
				      <<". Voto= "<<elenco.universit‡[a].sostenuti.esamiStud[b].voto
					  <<". Lode= "<<elenco.universit‡[a].sostenuti.esamiStud[b].lode
					  <<". Data= "<<elenco.universit‡[a].sostenuti.esamiStud[b].dataEsame.giorno
					  <<"/"<<elenco.universit‡[a].sostenuti.esamiStud[b].dataEsame.mese
					  <<"/"<<elenco.universit‡[a].sostenuti.esamiStud[b].dataEsame.anno
					  <<endl;

				 }
			 cout<<endl;
	   
		}
	}

int cercaposizione(int neomatr, int & eguale, Studenti &ragazzi)
	{cout<<"\nEntrata in cercaposizione. Neomatr= "<<neomatr<<" - eguale= "<<eguale<<endl;
	 int position;

	 for (int p=0;p<ragazzi.numstudenti;p++)

		 {if(ragazzi.universit‡[p].matr==neomatr)
			 {position=p;
			  eguale=VERO;
			  cout<<"\nMatr gia' presente!! Posizione="<<position<<" eguale="<<eguale<<endl;
			  return position;
			 }
		  if(ragazzi.universit‡[p].matr>neomatr)
		  {position=p-1;
			  
			  cout<<"\nMatr non presente!! Posizione="<<position<<" eguale="<<eguale<<endl;
			  return position;}
		  position=p;
		 }
	// position=p;
	 cout<<"\nMatr non presente!! Neo matricola in ultima Posizione="<<position<<" eguale="<<eguale<<endl;
	 return position;


	}

int insertnew(Studenti &lista)
	{int posizione=0;          

	 cout<<"\nPassaggio a insertnew.\n"
	     <<"Inserire matricola nuovo studente:";
	 int newmatr;
     cin>>newmatr;
	 int uguale=FALSO;

	 posizione= cercaposizione(newmatr, uguale, lista);

	 if(uguale==VERO)
	 {cout<<"Matricola gia' presente!! uguale="<<uguale<<" posizione="<<posizione<<endl;
	  return 0;}

	 cout<<"Matricola non presente!! uguale="<<uguale<<" posizione="<<posizione<<endl;

	 if(lista.numstudenti<=MAX)
		 {cout<<"Inserimento di  nuovo studente con matr. "<<newmatr<<endl;
	      Studente nuovoStudente;

		  cout<<"Cognome "; cin>>nuovoStudente.cognome;
		  cout<<"\nNome "; cin>>nuovoStudente.nome;
		  nuovoStudente.matr=newmatr;
		  cout<<"\naa corso ";cin>>nuovoStudente.aacorso;
		  cout<<"\nin corso? "; cin>>nuovoStudente.incorso;
		  cout<<"\nEsami superati? ";cin>>nuovoStudente.sostenuti.numesami;
		  for(int l=0;l<nuovoStudente.sostenuti.numesami;l++)
			  {cout<<"\n\nEsame nro "<<l+1<<"Nome corso ";cin>>nuovoStudente.sostenuti.esamiStud[l].corso;
			   cout<<"\nVoto ";cin>>nuovoStudente.sostenuti.esamiStud[l].voto;
			   cout<<"\nLode ";cin>>nuovoStudente.sostenuti.esamiStud[l].lode;
			   cout<<"\nData esame. Giorno ";cin>>nuovoStudente.sostenuti.esamiStud[l].dataEsame.giorno;
			   cout<<" Mese ";cin>>nuovoStudente.sostenuti.esamiStud[l].dataEsame.mese;
			   cout<<" Anno "; cin>>nuovoStudente.sostenuti.esamiStud[l].dataEsame.anno;
			  }

			int temp=posizione+1;
			for(int i=lista.numstudenti-1;i>=temp;i--)
			{lista.universit‡[i+1]=lista.universit‡[i];}
			lista.universit‡[temp]=nuovoStudente;
			lista.numstudenti++;

			stampaTabella(lista);
		      
		 }


  
	 return 0;
	}

int Delete(Studenti& lista)
{int posizione=0;          

	 cout<<"\nPassaggio a Delete.\n"
	     <<"Inserire matricola dello studente da eliminare:";
	 int newmatr;
     cin>>newmatr;
	 int uguale=FALSO;

	 posizione= cercaposizione(newmatr, uguale, lista);

	 if(uguale==FALSO)
	 {cout<<"Matricola non presente!! uguale="<<uguale<<" posizione="<<posizione<<endl;
	  return 0;}
	 int aux=posizione+1;
	 for(int k=aux+1;k<lista.numstudenti;k++)
	 {lista.universit‡[k-1]=lista.universit‡[k];}
	 lista.numstudenti--;

	 stampaTabella(lista);


 return 0;
}
char menu(Studenti &elenco)
	{char fine='f';
	char inserimento='i';
	char cancellazione='c';
	char operazione;

	while(1)

	{cout<<"\nOperazione?\n(i=inserimento nuovo studente, c=cancellazione studente, f=fine)\n";
	
	 cin>>operazione;
	
			if (operazione==inserimento)
				{cout<<"\nINSERIMENTO!\n";
			     insertnew(elenco);
			}
			if (operazione==cancellazione)
				{cout<<"CANCELLAZIONE!\n";
			     Delete(elenco);}

			if (operazione==fine)
			{break;}
			if(operazione!=inserimento&&operazione!=cancellazione&&operazione!=fine)
			{cout<<"\nDigitato carattere errato reinserirlo.";}
				
	}

	if(operazione=fine)
	{return 0;}

	return 0;
}

int main()
{   Studenti iscritti;
	iscritti=inizializzaTabella();
	stampaTabella(iscritti);
    
	menu(iscritti);
    
	
 return 0;
}
