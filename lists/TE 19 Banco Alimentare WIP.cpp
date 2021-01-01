//
//  main.cpp
//  banco alimentare
//
//  Created by Stefano Pigliafreddo on 31/12/2020.
//

/*Liste
Il Banco Alimentare vuole commissionare un software per la gestione dei prodotti donati e che verranno distribuiti alle persone in difficoltà.
 
Si è pensato alla realizzazione di un software che tenga traccia dei prodotti che, a mano a mano, arrivano in magazzino e che successivamente ne fuoriescono.
 
L’archivio sarà organizzato come lista di tipologia di prodotti (riso, pasta, olio, ecc., ognuno con la rispettiva unità di misura) e ad ogni prodotto saranno associati tutti i lotti presenti a magazzino, caratterizzati dal quantitativo e dalla data di scadenza. I lotti di un determinato prodotto dovranno essere ordinati in base alla data di scadenza.

 Si chiede di implementare la funzione che registri l’arrivo di un lotto di un certo tipo di prodotto in magazzino, inserendolo nella corrispondente lista che, come detto, sarà ordinata in funzione della data di scadenza. Se la tipologia di prodotto non dovesse essere tra quelle già presenti in archivio, dovrà essere aggiunta e, successivamente, ad essa dovrà essere collegato il lotto in ingresso.
 
Si implementi anche una funzione che registri l’uscita di un certo quantitativo di un determinato prodotto; nello specifico dovranno essere prelevati i lotti con la data di scadenza più ravvicinata, eliminando dall’archivio i lotti completamente esauriti ed aggiornando i quantitativi di quelli che ancora non lo sono.*/


#include <iostream>
#include <iomanip>
#include <string.h>
#include <string>
#include <cstdlib>
using namespace std;


//-------------- VARIABILI  ---------------

int const str = 10;

struct lotti {
    char prodotto[str];
    int quantità;
    int data; //rappresentata come intero
    lotti *next;
};

struct magazzino {
    char prodotto[str];
    lotti *punt_lotti;
    magazzino *next_magazzino;
};



//-------- PROTOTIPI FUNZIONI ---------------
lotti *cercaPrec(lotti *lista_lotto, char ins_prodotto, int ins_data, int ins_quantità);
void aggiungiLotto(magazzino *&lista_magazzino, char ins_prodotto[], int ins_quantità, int ins_data);


//--------------- MAIN ---------------------
int main() {
    
//variabili
    char ins_prodotto[str];
    int ins_quantità, ins_data;
    
lotti *lista_lotto = NULL;
magazzino *lista_magazzino = NULL;

    strcpy(ins_prodotto, "Pasta"); ins_quantità = 202; ins_data = 20200101;
aggiungiLotto(lista_magazzino, ins_prodotto, ins_quantità, ins_data);

    strcpy(ins_prodotto, "Pasta"); ins_quantità = 2013; ins_data = 20190101;
aggiungiLotto(lista_magazzino, ins_prodotto, ins_quantità, ins_data);
    
    strcpy(ins_prodotto, "Carne"); ins_quantità = 2022; ins_data = 20210101;
aggiungiLotto(lista_magazzino, ins_prodotto, ins_quantità, ins_data);
    
    strcpy(ins_prodotto, "Carne"); ins_quantità = 20122; ins_data = 20190201;
aggiungiLotto(lista_magazzino, ins_prodotto, ins_quantità, ins_data);

    
cout << "Inserisci il tipo di prodotto: \n";
cin >> ins_prodotto;
    
cout << "Inserisci la quantità: \n";
cin >> ins_quantità;
    
cout << "Inserisci la data di scadenza: \n";
cin >> ins_data;

aggiungiLotto(lista_magazzino, ins_prodotto, ins_quantità, ins_data);
    

    cout << "In magazzino sono disponibili i seguenti prodotti: " <<endl;
    magazzino *tmp = lista_magazzino;
    while (tmp!=NULL) {
        while(tmp->punt_lotti!=NULL)
        {
            cout << tmp->punt_lotti->prodotto << endl;
            cout << tmp->punt_lotti->quantità << endl;
            cout << tmp->punt_lotti->data << endl <<endl;
            tmp->punt_lotti= tmp->punt_lotti->next;
        }
        tmp = tmp->next_magazzino;
    }
}; //end of main




//--------------- FUNZIONI  ---------------------

// Si chiede di implementare la funzione che registri l’arrivo di un lotto di un certo tipo di prodotto in magazzino, inserendolo nella corrispondente lista che, come detto, sarà ordinata in funzione della data di scadenza. Se la tipologia di prodotto non dovesse essere tra quelle già presenti in archivio, dovrà essere aggiunta e, successivamente, ad essa dovrà essere collegato il lotto in ingresso.


//--------------- cercaPrec
lotti *cercaPrec(lotti *lista_lotto, char ins_prodotto, int ins_data, int ins_quantità){

lotti *tmp, *prec=NULL;

if(lista_lotto == NULL)
    return lista_lotto;
else{
    prec = NULL;
    for (tmp = lista_lotto; tmp!=NULL; tmp=tmp->next)
        if(ins_data <=tmp->data)
            prec = tmp;
        else
            return prec;
    }
    return prec;
}; //end of cercaPrec


//-------------- aggiungiLotto
void aggiungiLotto(magazzino *&lista_magazzino, char ins_prodotto[], int ins_quantità, int ins_data){
    
    lotti *prec = NULL;
    lotti *tmp_lotto = new lotti;
    magazzino *tmp_magazzino = new magazzino;
    
    strcpy(tmp_lotto->prodotto, ins_prodotto);
    strcpy(tmp_magazzino->prodotto, ins_prodotto);
    tmp_lotto->quantità = ins_quantità;
    tmp_lotto->data = ins_data;
    tmp_lotto->next = NULL;
    
    if(lista_magazzino==NULL) { //se la lista è nulla metto solo il lotto che sto inserendo
        lista_magazzino = new magazzino;
        lista_magazzino->punt_lotti = tmp_lotto;
        
    }
    
    else { //se non è vuota
        //cerco se c'è il prodotto nel magazzino
        for(tmp_magazzino=lista_magazzino; tmp_magazzino!=NULL; tmp_magazzino=tmp_magazzino->next_magazzino){
            //se cìè aggiungo in posizione
            if(strcmp(tmp_magazzino->prodotto,ins_prodotto)==0){
                cercaPrec(tmp_magazzino->punt_lotti, ins_prodotto[str], ins_data, ins_quantità);
                if (prec == NULL)
                {
                    tmp_lotto->next = tmp_magazzino->punt_lotti;
                    tmp_magazzino->punt_lotti = tmp_lotto;
                }
                
                else
                {
                    tmp_lotto->next = prec->next;
                    prec->next = tmp_lotto;
                }
            }
        }
        // se non c'è aggiungo un nuovo lotto
            while (tmp_magazzino->next_magazzino!=NULL) {
                tmp_magazzino=tmp_magazzino->next_magazzino;
            }
            tmp_magazzino->next_magazzino = new magazzino;
            tmp_magazzino = tmp_magazzino->next_magazzino;
        tmp_magazzino->punt_lotti = tmp_lotto;
        }
}; //end aggiungi lotto;



