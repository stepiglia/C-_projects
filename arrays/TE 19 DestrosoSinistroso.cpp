//
//  main.cpp
//  destroso
//
//  Created by Stefano Pigliafreddo on 02/01/2021.


/*Si scriva, in linguaggio C++, la funzione individuaSequenza che, avendo come parametri una matrice di interi ad una sola cifra (0-9) di dimensione MxN ed un numero intero, restituisca come valore di ritorno il numero di volte in cui ha trovato le cifre del numero passato come parametro, prese nell’ordine destrorso o sinistrorso lungo la sola direzione orizzontale; la funzione deve inoltre stampare a video e su un file appositamente creato, le coordinate della cella a partire dalla quale è stata individuata la sequenza ed il suo verso. Ogni sequenza individuata non dovrà necessariamente appartenere alla stessa riga. Ad es. passati come parametri l’intero 4213 e la seguente matrice */

#include <iostream>
#include <iomanip>
using namespace std;

int const R = 6;
int const C = 8;


//---PROTOTIPI FUNZIONI
void stampaMatrice(int mat[R][C]);
int individuaSequenza(int mat[R][C], int numero[4]);
    

//----MAIN
int main() {
    int numero[4] = {4,2,1,3};
    int mat[R][C]  = {
            {7,3,5,4,2,1,3,8},
            {9,6,5,3,4,4,2,1},
            {3,7,8,1,5,6,0,2},
            {2,7,6,2,4,3,1,9},
            {0,5,1,4,5,7,9,8},
            {6,3,1,2,4,7,7,0},

            };
    
    stampaMatrice(mat);
    
    int nvolte = individuaSequenza(mat,numero);
    cout << "Il totale dei match è: " << nvolte <<endl;
}//end of main

    
//----------------------------
int individuaSequenza(int mat[R][C], int numero[4]){
    //ciclo righe
    int contatore = 0;
    int i=0,j=0,cifra=0, x, y,x0, y0;
    
    //------- DESTROSO -------
    
    //scorro righe
    for (i=0;i<R;i++)
    {//scorro colonne
        for(j=0;j<C;j++)
        {
        //parto dalla prima riga del numero cercato
        cifra=0;
            
            int match = 0; //contatore dei match
            x0 = i; //posizione riga prima che aumento
            y0 = j; //posizione colonna prima che aumento
            for(cifra=0; cifra<4; cifra++){
                x = i;
                y = j+cifra;
                
                //se sforo e vado oltre le colonne
                if(j+cifra>=C){
                    y = y-C;
                    x = x+1;
                }
                
                //mi assicuro di stare solo dentro le right
                if(x<R){
                    if(mat[x][y]==numero[cifra])
                        match++; //controllo la cifra dopo
                }
            } //chiudo for del ciclo delle cifre del numero
               
            if(match==4){
                cout << "(trovato destroso nella posizione :(" << x0+1  <<" - " << y0+1 << ")\n";
                contatore++;
            }
        }
    }
    
    //SINISTROSO
    for (i=0;i<R;i++){
        for(j=0;j<C;j++){
                cifra=3;
                
            int match = 0;
            x0 = i;
            y0 = j;
            
            for(cifra=0; cifra<4; cifra++){
                x = i;
                y = j+cifra;

                if(j+cifra>=C){
                    y = y-C;
                    x = x+1;
                }
                
                if(x<R){
                    if(mat[x][y]==numero[3-cifra])
                        match++; //controllo la cifra dopo
                }
            } //chiudo for
               
            if(match==4){
                cout << "(trovato sinistroso nella posizione :(" << x <<" - " << y << ")\n";
                contatore++;
            }
        }
    }
    return contatore;
}
    

    

void stampaMatrice(int mat[R][C]){

int i=0,j=0;
for (i=0;i<R;i++) {
    for (j=0;j<C;j++) {
        cout << mat[i][j] << " ";
    }
    cout << endl;
    }
}

        
        /* SINISTROSO
      
        //itero sulle righe
        for (i=0;i<R;i++) {
            //itero sulle colonne ma dall'ultima indietro fino alla metà compresa
            for (j=C-1;j>=C/2;j--) {
            //cifra = 0 perchè il numero si resetta controllando le cifre dalla parte zero
                cifra=0;
                if ((mat[i][j]/numero[cifra]==1)) {
         
                    //se il primo numero da sinistra a destra per le
                    if ((mat[i][j-1]/numero[cifra+1]==1)&& (mat[i][j-2]/numero[cifra+2]==1)&&(mat[i][j-3]/numero[cifra+3]==1)){
             
                        cout << "trovato sinistroso nella posizione :(" << i << " - " << j << ")\n";
                        contatore++;}
              
          }
         //Caso a capo
        }
      }
      return contatore;
  };//end fun*/

