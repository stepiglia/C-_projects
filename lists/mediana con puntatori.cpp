/*
  Esercitazione 16
  Calcolo Mediana con puntatori

*/

#include <iostream>
using namespace std;

struct Nodo
{
   int valore;
   Nodo *nextPtr;
};

// prototipi
int calcolaMediana(Nodo *testa);
void inserimento(Nodo * &testa, int numero);

int main(void)
{
        int numero;
        int n;

        Nodo *lista=0; //Inizializzo la lista a zero

        cout << endl << "Quanti numeri si vogliono inserire nella lista?";
        cin >> n;

        for (int i=0; i<n; i++)
        {
           cout << "lista["<<i<<"] = ";
           cin >> numero;
           inserimento(lista,numero);
        }

        cout << endl << "La mediana della lista vale "<<calcolaMediana(lista) << endl;
        return 0;
}

void inserimento(Nodo * &testa, int numero)
{
        Nodo *ptr=testa;  //testa è di tipo puntatore a nodo
        while ((ptr!=0)&&(numero!=ptr->valore)) //fin tanto che puntatore non è zero e il numero è diverso dal puntatore di valore
              ptr=ptr->nextPtr; //il puntatore diventa il puntatore al nuovo oggetto

        if (ptr==0){ //se il puntatore è zero
           Nodo *temp=new Nodo; //creo un nuovo nodo temp
           temp->valore=numero; //assegno il numero
           temp->nextPtr=testa; //e lo faccio puntare alla testa della lista
           testa=temp; //che non è altro che temp
    }
}

int calcolaMediana(Nodo *testa)
{
        Nodo *ptr1;     //puntatore ad un nodo della lista
        int mediana,    //valore della mediana che verrà restituito
                        //dalla funzione
            minori, maggiori;

        int n = 0;      //numero di elementi contenuti nella lista
        
        //conteggio del numero di elementi contenuti nella lista
        for(ptr1 = testa; ptr1 != 0; ptr1 = ptr1->nextPtr) //scorro la lista
                n++;

        ptr1 = testa;    //posizionamento all'inizio della lista
                        // con un secondo puntatore
        do {

           //Conteggio di quanti elementi dell'insieme
           //sono minori o maggiori dell'elemento corrente

                minori = 0;
                maggiori = 0;

                //scansione della lista per contare i minori ed i
                //maggiori
                for (Nodo *ptr2 = testa; ptr2 != 0;
                     ptr2 = ptr2->nextPtr)

                     if (ptr1->valore > ptr2->valore)
                         minori++;
                     else if (ptr1->valore < ptr2->valore)
                         maggiori++;

                mediana= ptr1->valore; //salva il valore prima di
                                       //procedere

                ptr1 = ptr1->nextPtr;  //nodo successivo

        } while (!(((minori    <= (n - 1)/2) && (maggiori <= n/2))
                   ||((maggiori <= (n - 1)/2) && (minori    <= n/2))));
        
        return mediana;
}
