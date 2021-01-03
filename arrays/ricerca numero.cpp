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
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <string.h>

using namespace std;


//----VARIABILI
//int individuaSequenza(int matrice[R][C], int ins_numero[]);

//----PROTOTIPI FUNZIONI

//----MAIN
int main(void){
    
    int const R = 6;
    int const C = 8;
    
    int A[4] = {4,2,1,3};
    int B[R][C] = {
        {7,3,5,4,2,1,3,8},
        {9,6,5,3,4,4,2,1},
        {3,7,8,1,5,6,0,2},
        {2,7,6,2,4,3,1,9},
        {0,5,1,4,5,7,9,8},
        {6,3,1,2,4,7,7,0},
    };
    
    size_t i, j, size, rows, cols;
    int founded = 0;

    size = sizeof(A) / sizeof(A[0]);
    rows = sizeof(B) / sizeof(B[0]);
    cols = sizeof(B[0]) / sizeof(B[0][0]);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols - size; j++) {
            if (memcmp(A, &B[i][j], sizeof(A)) == 0) {
                founded = 1;
                break;
            }
        }
        if (founded) break;
    }
    if (founded) printf("Row: %zu Col: %zu\n", i, j);
    return 0;
};


