//
//  main.cpp
//  ES03 - Calcolo del massimo
//
//  Created by Stefano Pigliafreddo on 18/12/2020.
//

#include <iostream>
using namespace std;

int main(){
    //dichiarazione delle variabili
    const int tappo = 0;
    int num, max;
    
    //stampa del titolo
    cout << endl;
    cout << "Calcolo del massimo" <<endl <<endl;
    cout << "Inserisci una sequenza di numeri interi positivi terminata da 0" << endl;
    
    //Leggi il primo numero
    cin >> num;
    cout << endl;
    
    max = 0; //inizializzo la variabile. I numeri sono positivi per cui 0 va bene

    while(num != tappo){
        //se l'ultimo numero letto è > del massimo tra i numeri giàletti
        if (num > max){
            max = num;
        }
        //Leggi un altro numero
        cin >> num;
    } //fine while
    if(max != tappo){
        cout << endl << "Il massimo è: " << max << endl << endl;
    }
    else {
     //non sono stati introdotti numeri
        cout << endl << "Non sono stati introdotti numeri " << endl << endl;
    } //fine else
    return 0;
}

