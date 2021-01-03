//
//  main.cpp
//  destroso
//
//  Created by Stefano Pigliafreddo on 02/01/2021.


//Si scriva, in linguaggio C++, la funzione individuaSequenza che, avendo come parametri una //matrice di interi ad una sola cifra (0-9) di dimensione MxN ed un numero intero, //restituisca come valore di ritorno il numero di volte in cui ha trovato le cifre del //numero passato come parametro, prese nell’ordine destrorso o sinistrorso lungo la sola //direzione orizzontale; la funzione deve inoltre stampare a video e su un file //appositamente creato, le coordinate della cella a partire dalla quale è stata //individuata la sequenza ed il suo verso. Ogni sequenza individuata non dovrà //necessariamente appartenere alla stessa riga.
//Ad es. passati come parametri l’intero 4213 e la seguente matrice
//

#include <iostream>
#include <iomanip>
#include <iostream>
#include <cstdlib>
using namespace std;


int const R = 6;
int const C = 8;

//----VARIABILI
int individuaSequenza(int matrice[R][C], int ins_numero[]);

//----PROTOTIPI FUNZIONI

//----MAIN
int main (){
    
    int N = 0;
    
    int matrice[R][C] = {
        {7,3,5,4,2,1,3,8},
        {9,6,5,3,4,4,2,1},
        {3,7,8,1,5,6,0,2},
        {2,7,6,2,4,3,1,9},
        {0,5,1,4,5,7,9,8},
        {6,3,1,2,4,7,7,0},
    };
    
    cout << "Di quante cifre è il numero che stai cercando?" << endl;
    cin >> N;
    
    int ins_numero[N];
    
    cout << "Inserisci il numero intero che vuoi cercare" << endl;
   
    int i = 0;
    for(i=0; i<N; i++){
        cout << "Inserisci la cifra : " << i << "-esima" <<endl;
        cin >> ins_numero[i];
    };

    individuaSequenza(matrice,ins_numero);
    
   
}; //end main

//----FUNZIONI

int individuaSequenza(int matrice[R][C], int ins_numero[]){
    
    int contatore = 0;
    int i = 0, j=0, z = j -(C+1)*((j-2)/C), y = 0;
    
        for (z=0; z<C*R; z++) {
        //casi in cui andiamo oltre al bordo
     
        
            
        //prima riga prima colonna
        if(ins_numero[0]/matrice[i+y][j+z] == 1){
            if(ins_numero[1]/matrice[i+y][j+z] == 1);
                if(ins_numero[1]/matrice[i+y][j+z] == 1);
                    if(ins_numero[1]/matrice[i+y][j+z] == 1);
        }
           
           
           //FORMULA 
            
            
            
            //se giusto controllo il secondo numero
            
            //altrimenti incremento la cella
            
            
        if ()
            cout << "qui" << matrice[i+y][j+z] << endl;
            
           };
       // };
    //controlla seconda cifra
    return 0;
}; //end fun


//Si scriva, in linguaggio C++, la funzione individuaSequenza che, avendo come parametri una //matrice di interi ad una sola cifra (0-9) di dimensione MxN ed un numero intero, //restituisca come valore di ritorno il numero di volte in cui ha trovato le cifre del //numero passato come parametro, prese nell’ordine destrorso o sinistrorso lungo la sola //direzione orizzontale; la funzione deve inoltre stampare a video e su un file //appositamente creato, le coordinate della cella a partire dalla quale è stata //individuata la sequenza ed il suo verso. Ogni sequenza individuata non dovrà //necessariamente appartenere alla stessa riga.
//Ad es. passati come parametri l’intero 4213 e la seguente matrice
