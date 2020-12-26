//
//  main.cpp
//  ES02 - Calcolo della media
//
//  Created by Stefano Pigliafreddo on 18/12/2020.
//

#include <iostream>
using namespace std;

int main() {
    
 //definisci variabili
    int n, counter;
    float media, numero, somma;
    
 //inserisci un numero
    cout << "Quanti numeri vuoi inserire? ";
    cin >> n;

    
    if (n == 0){
        cout << "La media non è definita";
        cout << endl;
    }
    else { //somma
        cout << "Okay ora dovrai inserire " << n << " elementi";
        cout << endl;
        somma = 0;
        counter = n;
        while (counter !=0){
            cout << "Inserisci un numero ";
            cin >> numero;
            somma = somma + numero;
            counter = counter-1;
        }
        
        media = somma/n;
        cout << "La media è " << media;
        cout << endl;
        
    }
}
