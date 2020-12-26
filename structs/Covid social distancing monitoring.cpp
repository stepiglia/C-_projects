//
//  main.cpp
//  Covid social distancing monitoring
//
//  Created by Stefano Pigliafreddo on 24/12/2020.
//

#include <iostream>
#include <iomanip>
using namespace std;


const int N=6; //Righe della matrice
const int M=5; // colonne della matrice
const int TREMINUTI = 60*3;
const int QUINDICIMINUTI = 60*15;

struct persona {
    int codice;
    int secondi;
};

//intesto funzioni
int rileveVicinanze(persona stanza[N][M]);

// rilevaVicinanze che, avendo come parametro una matrice di dimensioni N e M, stampi a video l’indicazione di ogni coppia di persone che si trovino vicine da almeno 3 minuti, segnalando come critici i casi in cui la vicinanza supera i 15 minuti.

//main
int main(){
        
    persona sala1[N][M]={{{0,0},{0,0},{0,0},{0,0},{0,0}},
                         {{27,235},{0,0},{83,105},{0,0},{0,0}},
                         {{0,0},{48,190},{0,0},{0,0},{0,0}},
                         {{0,0},{0,0},{0,0},{0,0},{0,0}},
                         {{0,0},{0,0},{0,0},{0,0},{12,935}},
                         {{0,0},{0,0},{72,1209},{94,1045},{0,0}}
                        };
                            
    rileveVicinanze(sala1);
                        
    return 0;
    
} // end main

//definisco le funzioni
int rileveVicinanze(persona stanza[N][M]){
    //se c'è persona a destra
int i, j;
 
                
 for (i=0; i<N-1; i++)
    for (j=0;j<M; j++) {
    
        //se c'è persona sotto
             if((stanza[i][j].secondi >= QUINDICIMINUTI) && (stanza[i+1][j].secondi >= QUINDICIMINUTI))
                 cout << "Vicinanza CRITICA fra " << stanza[i][j].codice << " e " << stanza[i+1][j].codice << endl << i << "- " << j <<endl;
             else if  ((stanza[i][j].secondi >= TREMINUTI) && (stanza[i+1][j].secondi >= TREMINUTI))
                 cout << "Vicinanza fra " << stanza[i][j].codice << " e " <<stanza[i+1][j].codice << endl << i << "- " << j <<endl;
    }
        
        //se c'è persona a destro
for (i=0; i<N; i++)
       for (j=0;j<M-1; j++) {
            if((stanza[i][j].secondi >= QUINDICIMINUTI) && (stanza[i][j+1].secondi >= QUINDICIMINUTI))
                cout << "Vicinanza CRITICA fra " << stanza[i][j].codice << " e " <<stanza[i][j+1].codice << endl << i << "- " << j <<endl;
            else if  ((stanza[i][j].secondi >= TREMINUTI) && (stanza[i][j+1].secondi >= TREMINUTI))
                cout << "Vicinanza fra " << stanza[i][j].codice << " e " <<stanza[i][j+1].codice << endl << i << "- " << j <<endl;
       }
    
        //se c'è persona in obliquo sotto
for (i=0; i<N-1; i++)
   for (j=0;j<M-1; j++) {
            if((stanza[i][j].secondi >= QUINDICIMINUTI) && (stanza[i+1][j+1].secondi >= QUINDICIMINUTI))
                cout << "Vicinanza CRITICA fra " << stanza[i][j].codice << " e " <<stanza[i+1][j+1].codice << endl << i << "- " << j <<endl;
            else if  ((stanza[i][j].secondi >= TREMINUTI) && (stanza[i+1][j+1].secondi >= TREMINUTI))
                cout << "Vicinanza fra " << stanza[i][j].codice << " e " <<stanza[i+1][j+1].codice << endl << i << "- " << j <<endl;
   }
    
        //se c'è persona in obliquo sopra
for (i=0; i<N; i++)
   for (j=0;j<M-1; j++) {
            if((stanza[i][j].secondi >= QUINDICIMINUTI) && (stanza[i-1][j+1].secondi >= QUINDICIMINUTI))
                cout << "Vicinanza CRITICA fra " << stanza[i][j].codice << " e " <<stanza[i-1][j+1].codice << endl << i << "- " << j <<endl;
            else if ((stanza[i][j].secondi >= TREMINUTI) && (stanza[i-1][j+1].secondi >= TREMINUTI))
                cout << "Vicinanza fra " << stanza[i][j].codice << " e " <<stanza[i-1][j+1].codice << endl << i << "- " << j <<endl;
   }
    
    
cout << "QUI " << QUINDICIMINUTI;
cout << TREMINUTI;
                    
return 0;
} //end rileveVicinanze

//int stampaSchema(?????)






