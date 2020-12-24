/* POLITECNICO DI MILANO
Corso di Fondamenti di Informatica
pigliafreddo
 */

#include <iostream>
#include <iomanip>
using namespace std;

const int N=6; //Righe della matrice
const int M=5; //Colonne della matrice
const int TREMINUTI=180;
const int QUINDICIMINUTI=900;
const int SPAZIOVUOTO=0;
const int OSTACOLO=-1;

struct persona{
	int codice;
	int secondi;
};

int rilevaVicinanze(persona stanza[N][M]);
int massimo(int a, int b);
int minimo(int a, int b);
void stampaSchema(persona stanza[N][M]);

int main()
{
	persona sala1[N][M]={{{0,0},{0,0},{0,0},{0,0},{0,0}},
						 {{27,235},{0,0},{83,105},{0,0},{0,0}},
						 {{0,0},{48,190},{0,0},{0,0},{0,0}},
						 {{0,0},{0,0},{0,0},{0,0},{0,0}},
						 {{0,0},{0,0},{0,0},{0,0},{12,935}},
						 {{0,0},{0,0},{72,1209},{94,1045},{0,0}}
						};
						
	stampaSchema(sala1);
	
	rilevaVicinanze(sala1);
	
	return 0;
	
}

int rilevaVicinanze(persona stanza[N][M])
{
//Per evitare doppioni nella stampa finale, dovuta alla reciprocita' degli elementi, 
//si effettua il controllo su meta' dell'intorno

	int i, j, k;

	for(i=0; i<N; i++)
		for(j=0; j<M; j++)
			//Se nella posizione corrente c'e' una persona da almeno tre minuti
			if((stanza[i][j].codice!=SPAZIOVUOTO)&&(stanza[i][j].codice!=OSTACOLO)
				&&(stanza[i][j].secondi>=TREMINUTI))
			{
				//se non siamo in fondo alla riga
				if(j+1<M)
					//se c'e' una persona da almeno tre minuti
					if((stanza[i][j+1].codice!=SPAZIOVUOTO)&&
					(stanza[i][j+1].codice!=OSTACOLO)&&
					(stanza[i][j+1].secondi>=TREMINUTI))
						//Stabilisco in che situazione sono e stampo il 
						//messaggio opportuno
						if((stanza[i][j].secondi>=QUINDICIMINUTI)&&
						(stanza[i][j+1].secondi>=QUINDICIMINUTI))
						 	cout<<"Vicinanza CRITICA fra "<<
						 	stanza[i][j].codice<<" e "<<
						 	stanza[i][j+1].codice<<endl;
						else
							cout<<"Vicinanza fra "<<
						 	stanza[i][j].codice<<" e "<<
						 	stanza[i][j+1].codice<<endl;
					//se c'e' una riga sottostante
					if(i+1<N)
						//controllo le celle adiacenti sulla riga sottostante
						//valutando i "casi ai bordi"
						for(k=massimo(0,j-1); k<=minimo(M-1,j+1); k++)
						{
							//... e se c'e' una persona da almeno tre minuti
							if((stanza[i+1][k].codice!=SPAZIOVUOTO)&&
							(stanza[i+1][k].codice!=OSTACOLO)&&
							(stanza[i+1][k].secondi>=TREMINUTI))
								//Stabilisco in che situazione sono e stampo il 
								//messaggio opportuno
								if((stanza[i][j].secondi>=QUINDICIMINUTI)&&
								(stanza[i+1][k].secondi>=QUINDICIMINUTI))
						 			cout<<"Vicinanza CRITICA fra "<<
						 			stanza[i][j].codice<<" e "<<
						 			stanza[i+1][k].codice<<endl;
								else
									cout<<"Vicinanza fra "<<
						 			stanza[i][j].codice<<" e "<<
						 			stanza[i+1][k].codice<<endl;
						}
			}
			
	return 0;
}

int massimo(int a, int b)
{
	if(a>=b)
		return a;
	else
		return b;
}

int minimo(int a, int b)
{
	if(a<=b)
		return a;
	else
		return b;
}

void stampaSchema(persona stanza[N][M])
{
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
	 		//cout<<setw(4)<<std::right<<stanza[i][j].codice<<"-"
			 //<<setw(4)<<std::left<<stanza[i][j].secondi;
			cout<<setw(4)<<right<<stanza[i][j].codice<<"-"
				<<setw(4)<<left<<stanza[i][j].secondi;
		cout<<endl;
	}
	
	cout<<endl;
	
	return;
}
