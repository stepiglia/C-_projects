//
//  main.cpp
//  aereoporto
//
//  Created by Stefano Pigliafreddo on 29/12/2020.
//


/*Ogni giorno in un grande aeroporto transitano migliaia di bagagli, la cui gestione è affidata ad uno specifico software scritto in C++. Per tale applicativo vi si chiede l’implementazione di due funzioni fondamentali: accodaBagagli e caricaBagagli.
 
 La funzione accodaBagagli, ricevuti in ingresso la lista dei bagagli ancora in giacenza in aeroporto - ordinata in funzione della destinazione e in subordine in funzione del peso - ed un nuovo bagaglio, collocherà il nuovo bagaglio all’interno della lista che dovrà mantenersi ordinata. Ogni bagaglio è caratterizzato da un identificativo numerico, da un codice di destinazione e dal peso.
 
 La funzione caricaBagagli, ricevuti la lista dei bagagli, il numero del volo su cui caricare i bagagli, la sua destinazione e la capienza massima dell’aereo, restituirà la lista dei bagagli per la destinazione specificata togliendoli di conseguenza dalla lista dei bagagli in giacenza in aeroporto. Tale lista dovrà essere costituita da tutti i bagagli ancora in giacenza in aereoporto con la destinazione specificata e la cui somma dei pesi sia compatibile con la capienza dell’aeromobile. I bagagli di maggior peso avranno precedenza di collocazione rispetto a quelli di minor peso.
 
 Eventuali bagagli che non si è riusciti a collocare per motivi di capienza, rimarranno nella lista di giacenza in attesa di un altro volo. La funzione caricaBagagli potrà anche produrre un file avente come nome il numero di volo e contenente l’elenco dei bagagli da caricare sull’aereo.*/


#include <iostream>
#include <iomanip>
#include <string.h>
#include <string>
#include <fstream>
using namespace std;


const int str = 10;

//-------VARIABILI-----------
struct node {
    int bagid;
    char destinazione[str];
    int volo;
    int peso;
    node *next;
};


//-------PROTOTIPI-----------

int accodaBagagli(node *&lista, int ins_bagid, char inserisci_destinazione[], int inserisci_volo, int inserisci_peso);
void caricaBagagli(node *&lista, int volo, char inserisci_destinazione[]);
node *cercaPrec(node *lista, char destinazione, int inserisci_peso);


//-------MAIN-----------

int main(){
         
  node *lista = NULL;
  node *tmp = NULL;
    
    
    int ins_bagid, inserisci_volo, inserisci_peso;
    char inserisci_destinazione[str];

        //Inserisce in testa
    ins_bagid=12; strcpy(inserisci_destinazione,"MXP"); inserisci_volo=123; inserisci_peso=10;
    accodaBagagli(lista, ins_bagid, inserisci_destinazione, inserisci_volo, inserisci_peso);

    //Inserisce in coda
    ins_bagid=12; strcpy(inserisci_destinazione,"MXP"); inserisci_volo=123; inserisci_peso=100;
    accodaBagagli(lista, ins_bagid, inserisci_destinazione, inserisci_volo, inserisci_peso);

    //Inserisce in mezzo
    ins_bagid=12; strcpy(inserisci_destinazione,"DUB"); inserisci_volo=123;inserisci_peso=10;
    accodaBagagli(lista, ins_bagid, inserisci_destinazione, inserisci_volo, inserisci_peso);

    
    cout << "Inserire la destinazione per cui caricare il bagaglio" << endl;
    cin >> inserisci_destinazione;


    cout << "Inserire il numero di volo del passeggero" << endl;
    cin >> inserisci_volo;
    
    
    cout << "Inserire il peso del bagaglio" << endl;
    cin >> inserisci_peso;
    
    
    cout << "Inserisci un ID per la valigia" << endl;
    cin >> ins_bagid;
    
    cout<< "Il bagaglio verrà immesso nel sistema" <<endl <<endl;
    accodaBagagli(lista, ins_bagid, inserisci_destinazione, inserisci_volo, inserisci_peso);
    
    tmp = lista;
    while(tmp!=NULL){
        cout << "ID Bagaglio "<< tmp->bagid <<endl;
        cout << "Destinazione "<< tmp->destinazione <<endl;
        cout << "Volo "<< tmp->volo <<endl;
        cout << "Peso: "<< tmp->peso <<endl <<endl;
        tmp = tmp->next;
    };
    
    
    caricaBagagli(lista, inserisci_volo, inserisci_destinazione);


   
 
    
    
};//end of main

//-------FUNZIONI-----------

node *cercaPrec(node *lista, char inserisci_destinazione[], int inserisci_peso){
    
    node *tmp, *prec=NULL;
    
    if(lista==NULL)
        return lista;
    else{
        prec=NULL;
        for (tmp=lista; tmp!=NULL; tmp = tmp->next)
            if(strcmp(inserisci_destinazione,tmp->destinazione)<0) //come fare confronto
                if(strcmp(inserisci_destinazione,tmp->destinazione)==0 && inserisci_peso >tmp->peso)
                    prec=tmp;
                else
                    return prec;
            else
                prec = tmp;
    }
    return prec;
};



void caricaBagagli(node *&lista, int inserisci_volo, char inserisci_destinazione[]){
    
    int capienza_corrente = 0; int capienza_massima = 100;
   
    cout << "Sul prossimo volo con destinazione: " << inserisci_destinazione << " verranno caricati i seguenti bagagli" <<endl;
    
    // Create and open a text file
    ofstream MyFile(to_string(inserisci_volo)+".txt");
    
    for(lista=lista; lista !=NULL && strcmp(lista->destinazione,inserisci_destinazione)==0 && lista->peso <= capienza_massima; lista=lista->next)
    {
        
        cout << "ID Bagaglio "<< lista->bagid <<endl;
        cout << "Destinazione "<< lista->destinazione <<endl;
        cout << "Volo "<< lista->volo <<endl;
        cout << "Peso: "<< lista->peso <<endl <<endl;
        // Write to the file
        MyFile << "ID Bagaglio "<< lista->bagid <<endl;
        MyFile << "Destinazione "<< lista->destinazione <<endl;
        MyFile << "Volo "<< lista->volo <<endl;
        MyFile << "Peso: "<< lista->peso <<endl <<endl;
        capienza_corrente = capienza_corrente + lista->peso;
    }
    
    // Close the file
    MyFile.close();
 
}; //end carica bagagli


int accodaBagagli(node *&lista, int ins_bagid, char inserisci_destinazione[], int inserisci_volo, int inserisci_peso){
    
    node *prec, *tmp=new node;
    
    tmp->bagid = ins_bagid;
    strcpy(tmp->destinazione, inserisci_destinazione);
    tmp->volo = inserisci_volo;
    tmp->peso = inserisci_peso;
    tmp->next = NULL;
    
    //aggiunge nuovo bagaglio, ordinato
    if(lista ==NULL)
        lista = tmp;
    else {
        prec=cercaPrec(lista, inserisci_destinazione, inserisci_peso);
        if(prec==NULL){
            tmp->next = lista;
            lista = tmp;
        }
        else{
            tmp->next = prec->next;
            prec->next= tmp;
        }
    }
    return 0;
};




