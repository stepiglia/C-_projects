//
//  main.cpp
//  07. Calcolo della mediana (numeri non distinti)
//
//  Created by Stefano Pigliafreddo on 18/12/2020.
//

#include <iostream>
#include <iomanip>
using namespace std;

//dimensione del vettore
const int DIM = 11;

int main() {
    int insieme[DIM];
    int i,j;
    int minori;
    int maggiori;
   
 //messaggio
    cout << endl << "Programma che calcola la mediana di " << DIM << "numeri." << endl << endl;
 //Lettura dell'insieme di numeri
    for (i = 0; i <DIM; i++){
        cout << "Inserisci il dato n." << i+1 << " ";
        cin >> insieme[i];
    }
 
// Elaborazione dell'insieme di numeri
    i = 0;
    do {
        minori = maggiori = 0;
        j = 0;
        while ((j<DIM) && !((minori > (DIM-1)/2) || (maggiori > (DIM-1)/2))){
            if (insieme[i] > insieme[j]){
                minori++;
            }
            else if(insieme[i] <insieme[j]){
                maggiori++;
            }
            j++;
        }
               i++; //incremento dell'indice per passare al numero successivo
               } while ((i <DIM) && !((minori <= (DIM-1)/2) && (maggiori <= (DIM-1)/2)));
    //Stampa del risultato
                        cout << endl <<"La mediana dell'insieme di " << DIM << "numeri è " << insieme[i] << endl << endl;
   return 0;
}
