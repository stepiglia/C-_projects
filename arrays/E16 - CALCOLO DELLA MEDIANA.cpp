#include <iostream>
using namespace std;
#include <iomanip>
 
/*
Scrivere una funzione il cui prototipo Ë int calcolaMediana(Nodo *testa);
che calcola la mediana di un insieme non vuoto di numeri interi memorizzato in una lista il cui inizio Ë puntato da testa.
 
*/
 
struct Nodo
       {
             int valore;
             Nodo *nextPtr;     
       };
 
       Nodo *testa;
 
int calcolaMediana(Nodo *testa, int elementi);
int calcoloMediana2(Nodo *testa, int elementi);
void inserisciInCoda(Nodo *&testa, int valoreDaInserire);
void stampa(Nodo *testa);
 
int main()
{
       int elementi, valoreDaInserire;
      

       cout << "Quanti elementi vuoi inserire? ";
       cin >> elementi;
 
       for (int i=0; i<elementi; i++)
       {
             cout << "inserisci elemento al nodo " << i << " ";
             cin >> valoreDaInserire;

             inserisciInCoda(testa, valoreDaInserire);
       }
    

       stampa(testa);

	   calcolaMediana(testa, elementi);

	   calcoloMediana2(testa, elementi);
 
      
 
return 0;
}
 
void stampa(Nodo *testa)
{
       Nodo *cursore;
       cursore = testa;
 
       int i = 0;
    
       while (cursore != NULL )
       {
             cout << "elemento al nodo " << i << " = " << cursore->valore << " " << endl;
             cursore = cursore->nextPtr;     
             i++;
       }
}
 
// La funzione restituisce un puntatore alla struttura nodo mentre passo il puntatore alla struttura nodo testa ed un valore da inserire
void inserisciInCoda(Nodo *&testa, int valoreDaInserire)
{
	Nodo *nuovo = new Nodo;				// creo un puntatore ad una struttura Nodo che si chiama nuovo ed alloco con uguale lo spazio necessario per la struttura di tipo Nodo
	nuovo->valore = valoreDaInserire;	// inserisco il valore da inserire nel campo valore della struttura nuovo del tipo Nodo
	nuovo->nextPtr = NULL;				// poichË nuovo dovr‡ essere l'ultimo definisco che nuovo->nextPtr debba puntare a NULL

	if(testa == NULL)
		testa = nuovo;					// verifico se la struttura Ë vuota e se lo Ë semplicemente modifico testa perchË Ë stata passato come indirizzo Nodo *&testa
	else
	{
		Nodo *cursore = testa;			// altrimenti creo cursore di tipo puntatore a Nodo e lo eguaglio a testa
		while(cursore->nextPtr != NULL)	// scorro la struttura con cursore fino a quando non trovo l'ultimo elemento
			cursore = cursore->nextPtr;	// avanzando con cursore = cursore->nextPtr

		cursore->nextPtr = nuovo;		// quando esco dal while sono sicuro di essere in fondo ed inserisco nuovo
	}

}

int calcolaMediana(Nodo *testa, int elementi)
{
//	int i,j;
	Nodo *cursore;
	Nodo *cursore2;

	int mediana = -1;
	int val;
	int minori = 0, maggiori = 0;
	
	// cout << endl << "tasta = " << testa << "\ncursore = " << cursore << endl << endl; 
	// cout << endl << "cursore->valore = " << cursore->valore << endl << "cursore->nextPtr->valore = " << cursore->nextPtr->valore << endl;

//	i=0;

	cursore = testa;

	while (cursore != NULL && mediana == -1) 
	{
        int minori = 0, maggiori = 0;

        val = cursore->valore;

        for (cursore2 = testa; cursore2->nextPtr != NULL; cursore2 = cursore2->nextPtr) 
		{
            if (cursore2->valore <= val) minori++;
            if (cursore2->valore >= val) maggiori++;
        }
        if (minori >= (elementi)/2 && maggiori >= (elementi)/2) 
            mediana = val;

        cursore = cursore->nextPtr;
    }
    
	cout << "La mediana e' " << mediana << endl;


	//for(cursore = testa;cursore != NULL;cursore = cursore->nextPtr)   


	return 0;

}
 
int calcoloMediana2(Nodo *testa, int elementi)
{
	Nodo *cursore;
	Nodo *cursore2;

	// int i, j;
	int contatore;

	cursore = testa;
do
	{
		contatore = 0;


	//	j = 0;
		cursore2 = testa;

		while ((cursore2->nextPtr != 0) && (contatore <= (elementi)/2))
		{
			if (cursore->valore > cursore2->valore)
				{
					contatore++;
				}
			cursore2 = cursore2->nextPtr;
		}

		cursore = cursore->nextPtr;

	} while ((contatore != ((elementi - 1)/2)) && (cursore->nextPtr != 0));	

	//Stampa del risultato
	cout << endl << "La mediana dell'insieme di " << elementi << " numeri e' " << cursore->valore << endl << endl;

	return 0;

}
