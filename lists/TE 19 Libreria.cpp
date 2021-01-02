//
//  main.cpp
//  libreria
//
//  Created by Stefano Pigliafreddo on 01/01/2021.
//

/*In una libreria dove si vendono libri scolastici, c’è la necessità di rinnovare il software per la gestione del magazzino. Ogni volume è caratterizzato dal codice ISBN (che identifica in modo univoco il libro e che, per semplicità, assumiamo come intero), dall’autore, dal titolo, dalla casa editrice e dal prezzo di copertina.
La lista che implementa l'archivio dei libri a magazzino è costituita da elementi concatenati tra loro e ordinati in funzione del codice ISBN. Ogni elemento della lista, oltre ai campi che caratterizzano il libro di testo, conterrà anche il numero di copie esistenti a magazzino.
Il software usa anche una lista delle scuole della provincia, in cui per ogni scuola compare la sottolista delle rispettive sezioni, e per ogni sezione la sottolista dei codici ISBN dei testi adottati. Vi viene chiesto di implementare le seguenti funzioni:
 la funzione numeroAdozioni per ricercare se un determinato testo, identificato mediante il codice ISBN, è in adozione nelle scuole della provincia e in caso affermativo da quante scuole e quante sezioni;
 la funzione ricercaInMagazzino per verificare se un determinato testo, identificato mediante il codice ISBN, è già presente a magazzino e, nel caso, in quante copie.
Sulla base delle informazioni ottenute usando le funzioni numeroAdozioni e ricercaInMagazzino il gestore della libreria, con la sua esperienza, decide il numero di copie da acquistare ed inserire a magazzino.
Quindi, per aggiornare il magazzino con le copie acquistate, vi si chiede di implementare la funzione inserisciVolume per inserire un certo numero di copie di un determinato libro, con i dati che lo caratterizzano, nell’archivio del magazzino, valutando se il libro è già o meno presente: nel primo caso aggiornerà unicamente il numero di copie, nel secondo inserirà il nuovo elemento nella lista.*/

#include <iostream>
#include <iomanip>
#include <string.h>
#include <cstdlib>

using namespace std;

//------VARIABLES--------

int const str = 10;

struct libri {
    int isbn; //campo per cui si ordina
    char autore[str];
    char titolo[str];
    char casa[str];
    float prezzo;
};

struct magazzino {
    libri libri;
    int quantità;
    magazzino *next;
};

struct adozioni{
    int isbn[str];
};


struct sez{
    int sezioni[str];
    adozioni isbn;
};


struct scuole{
    char scuole[str];
    sez sezioni;
};



//------FUNCTION PROTOTIPES--------
//int numeroAdozioni(scuole *lista_scuole, int ins_isbn );
int ricercaInMagazzino(magazzino *lista_magazzino, int ins_isbn);
int inserisciVolume(magazzino *&lista_magazzino, int ins_isbn, int ins_quantità );
magazzino *cercaPrec(magazzino *lista_magazzino, int ins_isbn);
int numeroAdozioni(scuole lista_scuola[], int ins_isbn);
        

//void inserisciVolume(magazzino *&lista_magazzino);


//------MAIN--------
int main() {
    
    //VARIABILI
    int ins_isbn = 0, ins_quantità = 0;
    magazzino *lista_magazzino = NULL;
    
    struct adozioni{
        int isbn[str];
    };

    scuole lista_scuola[str] = {
        {"Bramante"},{
                {1,{555,787233}},
                {2,{555,787233}}
        }
    }
    };
        
                
   // {{"Bramante"},{{2},{123,4533}}},
   //     {{"Quasimodo"},{{1},{1234,4533}}},
   //     {{"Quasimodo"},{{2},{123,4533}}},
   //     {{"Quasimodo"},{{3},{123,4533}}},
   //     };
    
    
  //  cout << lista_scuola[0].scuole << "Ciao";
   // cout << lista_scuola[1].sezioni.isbn.isbn[1] << "Ciao";
  //  cout << lista_scuola[0].sezioni.sezioni[1] << "Ciao";
    //cout << lista_scuola[0].sezioni.sezioni[1] << "Ciao";
  
    
    ins_isbn = 1; ins_quantità = 100;
    inserisciVolume(lista_magazzino, ins_isbn, ins_quantità);
    
    ins_isbn = 3; ins_quantità = 100;
    inserisciVolume(lista_magazzino, ins_isbn, ins_quantità);
    
    ins_isbn = 4; ins_quantità = 100;
    inserisciVolume(lista_magazzino, ins_isbn, ins_quantità);
    
    ins_isbn = 2; ins_quantità = 100;
    inserisciVolume(lista_magazzino, ins_isbn, ins_quantità);
    
    ins_isbn = 5; ins_quantità = 100;
    inserisciVolume(lista_magazzino, ins_isbn, ins_quantità);

    
    cout << "Inserisci il codice ISBN cercato" << endl;
    cin >> ins_isbn;
    
    cout << endl;
    magazzino *tmp = lista_magazzino;
    while (tmp!=NULL) {
        cout << tmp->libri.isbn << endl;
        cout << tmp->quantità << endl;
        tmp = tmp->next;
    }
    
    numeroAdozioni(lista_scuola, ins_isbn);
    ricercaInMagazzino(lista_magazzino, ins_isbn);
    
 
    
};//end of main



//------FUNCTIONS--------
int ricercaInMagazzino(magazzino *lista_magazzino, int ins_isbn){
    //cerca se c'è libro
    magazzino *tmp = lista_magazzino;
    
    while(tmp!=NULL){
        if (tmp->libri.isbn == ins_isbn){
            cout << "Il libro " << tmp->libri.isbn << " è in magazzino con il seguente numero di copie: " <<  tmp->quantità <<endl;
            return tmp->quantità;
           }
        else
            tmp = tmp->next;
    }
    cout << "Il libro non è in magazzino" <<endl;
    return 0;
}; //end ricerca


//------PRECE--------

magazzino *cercaPrec(magazzino *lista_magazzino, int ins_isbn){

    magazzino *tmp, *prec = NULL;
    
    //se nullo
    if(lista_magazzino==NULL){
        return lista_magazzino;
    }
    else {
        prec=NULL;
        for(tmp=lista_magazzino; lista_magazzino!= NULL; lista_magazzino = lista_magazzino->next)
                    if (ins_isbn > tmp->libri.isbn){
                    return prec;
                        }
                else {
                    prec = tmp;
                }
        }
    return prec;
}; //end fun



//------FUNCTIONS--------
int inserisciVolume(magazzino *&lista_magazzino, int ins_isbn, int ins_quantità){
    
    magazzino *prec, *tmp = new magazzino;
    
    tmp->libri.isbn = ins_isbn;
    tmp->quantità = ins_quantità;
    tmp->next = NULL;
    
    if(lista_magazzino == NULL)
        lista_magazzino = tmp;
    else {
        prec = cercaPrec(lista_magazzino, ins_isbn);
        if(prec==NULL){
            tmp->next = lista_magazzino;
            lista_magazzino = tmp;
        }
        else{
            tmp->next = prec->next;
            prec->next = tmp;
        }
    }
    return 0;
};//end fun
  

//------FUNCTIONS--------
int numeroAdozioni(scuole lista_scuola[], int ins_isbn){
    //cerca ins_ibns
    
    int i=0, j=0, k=0;
    int conta_scuole = 0, conta_sezioni = 0;
    
    //itera tra le scuole
    for (i=0; i<str; i++){
        //itera le sezioni
        
        if(lista_scuola[i].sezioni.isbn.isbn[0]  == ins_isbn){
            cout << lista_scuola[i].scuole << endl;
        }
    }

    
    //la funzione numeroAdozioni per ricercare se un determinato testo, identificato mediante il codice ISBN, è in adozione nelle //scuole della provincia e in caso affermativo da quante scuole e quante sezioni;
    //
    
   //for (i=0; i<str; i++){
   //     if(lista_scuola[i].sezioni.isbn.isbn[0]  == ins_isbn){
   //         return 0;
   //     }
   // }
            
    
    
    
    
    //itera tra le classi
    
    //itera tra libri

        
    
    

    return 0;
   
    //itera tra le sezioni se cè in sezione sezione++
    
};//end fun

 
 
 
 
 /*scuole lista_scuola[str] = {
     {{"Bramante"},{{1},{123,4533}}},
     {{"Bramante"},{{1},{123,5542}}},
     {{"Bramante"},{{2},{123,4533}}},
     {{"Quasimodo"},{{1},{123,4533}}},
     {{"Quasimodo"},{{2},{123,4533}}},
     {{"Quasimodo"},{{3},{123,4533}}},
     };*/
 
 
