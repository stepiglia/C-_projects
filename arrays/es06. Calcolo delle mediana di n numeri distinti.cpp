//
//  main.cpp
//  06. Calcolo della Mediana
//
//  Created by Stefano Pigliafreddo on 18/12/2020.
//

#include <iostream>
#include <iomanip>
using namespace std;

//definisco a priori la dimensione del vettore
const int DIM = 11;

int main() {
    int insieme[DIM];
    int i,j;
    int contatore;
    
    //messaggio
    cout << endl << "Programma che calcola la media di " << DIM << " numeri distinti" <<endl;
    
    //lettura dell'insieme di numeri
    for (i=0; i< DIM; i++){
        cout << "Inserisci il dato n." << i + 1 << " ";
        cin >> insieme[i];
    }
    //Eleaborazione dell'insieme di numeri
    i = 0;
    
    do {
        contatore = 0;
        
        /*        //      for (j=0; j<DIM; j++){ //con questo ciclo vengono letti tutti i numeri del vettore dalla posizione 0 fino all'ultima posizione corrispondente all'indice DIM-1. Di questi numeri si conta quanti sono minori del numero corrente insieme[i], per poter verificare se insieme[i] è la mediana
            if(insieme[i] > insieme[j]){
                contatore++;
            }
         */
        
        //una seconda alternativa, utilizzo del ciclo while = soluzioen più efficiente
            j = 0;
            while ((j<DIM) && (contatore <= (DIM-1)/2)){
                if (insieme[i] > insieme[j]){
                    contatore++;
                }
                j++;
            }
            i++;
    } while ((contatore != ((DIM-1)/2)) && (i<DIM));
    //quando questa condizione è soddisfatta significa che il numero in posizione i-1 è la mediana
    
    //Stampa del risultato
    cout << endl << "La mediana dell'insieme di " << DIM << "numeri è " << insieme[i-1] << endl << endl;
    
    return 0;
}
