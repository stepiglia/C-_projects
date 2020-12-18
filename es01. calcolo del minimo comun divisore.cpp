//
//  main.cpp
//  ES01- calcolo del minimo comun divisore
//
//  Created by Stefano Pigliafreddo on 18/12/2020.
//

#include <iostream>
using namespace std;

int main(){
    
    int x,y; //dichiarazione variabili
    
    cout << "Calcolo del minimo comun divisore";
    cout << endl;
    
    //leggi il valore di x
    cout << "Inserire il valore di x: ";
    cin >> x;
    cout << endl;

    
    //leggi il valore di x
    cout << "Inserire il valore di y: ";
    cin >> y;
    cout << endl;
    
    //tnatoche x != y
    while (x!=y) {
        if (x > y){
            x = x-y;
        }
        else {
            y = y-x;
        }
    }

//stampa x
    cout << "Il MCD è " << x << endl;
    
}
