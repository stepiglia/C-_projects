//
//  main.cpp
//  Programma Multe - II prova itinere 20_21
//
//  Created by Stefano Pigliafreddo on 26/12/2020.
//



/*In un Comune si vuole fare una valutazione statistica mensile delle contravvenzioni comminate dal corpo della polizia locale e, in particolare, si vuole creare un report che, per ogni vigile, indichi il numero di contravvenzioni effettuate.
 
 Per soddisfare la richiesta, si è stabilito di sviluppare un nuovo software, in linguaggio C++, che crei una lista di tutte le contravvenzioni inflitte dai vigili che prestano servizio nel Comune. Tale lista dovrà essere ordinata in funzione della data e dell’ora di rilevamento dell’infrazione contestata. Ogni contravvenzione conterrà, oltre all’identificativo del vigile, la data, l’ora, la targa del veicolo e un
codice di descrizione dell’infrazione.
 
Si richiede di sviluppare la funzione accodaMulta(), che ricevuta la
lista delle contravvenzioni e gli ulteriori parametri (ID_vigile, data, ora, targa, infrazione) inserirà un nuovo elemento nella lista.
 
 Come detto tale lista dovrà essere mantenuta ordinata in funzione della data e dell’ora di rilevamento dell’infrazione. Si richiede poi di sviluppare la funzione creaReport(), che ricevuta la lista delle contravvenzioni ed un mese di riferimento, stampi a video il mese di riferimento e, per ogni vigile, il suo identificativo ed il numero di contravvenzioni comminate.

 Infine si crei anche un semplice programma principale che permetta di testare il corretto funzionamento delle funzioni sviluppate.*/

#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;

const int STR=10;

struct contravv
{
    int idVigile;    //Cod numerico
    int data;    //Rappresentata come intero
    int ora;    //Rappresentata come intero
    char targa[STR];    //Alfanumerica
    char codInfraz[STR];    //Alfanumerica
    contravv *next;
};

struct agente
{
    int id;
    int count; //Contatore di contravvenzioni
    agente *next;
};

//Accoda una nuova istanza, in ordine di data e ora, nella lista delle contravvenzioni
int accodaMulta(contravv * &lista, int idVigile, int data, int ora, char targa[], char codInfraz[]);

//Individua il punto di inserimento del nuovo elemento nella lista delle contravvenzioni
//in funzione dell'ordinamento per data e ora
contravv *cercaPrec(contravv *lista, int data, int ora);

//Stampa la lista delle contravvenzioni
int stampaContravv(contravv *punt);

//Crea il report delle contravvenzioni di ogni agente per il mese indicato
int creaReport(contravv *lista, int mese);

//Stampa il report delle contravvenzioni di ogni agente
int    stampaReport(agente *lista);

//Cerca l'agente indicato, nella lista dei conteggi, che ha effettuato contravvenzioni.
//Restituisce 1 se trovato
int cercaAgente(agente *lista, int id);


int main()
{
    int ora, data, idVigile, mese;
    char targa[STR], codInfraz[STR];
    contravv *contravvenzioni=NULL; //Lista delle contravvenzioni

    //Inserisce primo elemento
    idVigile=1234; data=200312; ora=1722; strcpy(targa,"AC123CA"); strcpy(codInfraz,"CS123");
    accodaMulta(contravvenzioni, idVigile, data, ora, targa, codInfraz);
    
    //Inserisce in testa
    idVigile=1234; data=200313; ora=1722; strcpy(targa,"AB345CA"); strcpy(codInfraz,"CS123");
    accodaMulta(contravvenzioni, idVigile, data, ora, targa, codInfraz);

    //Inserisce in coda
    idVigile=5678; data=200310; ora=1722; strcpy(targa,"AC345CA"); strcpy(codInfraz,"CS172");
    accodaMulta(contravvenzioni, idVigile, data, ora, targa, codInfraz);
    
    //Inserisce in mezzo
    idVigile=1234; data=200311; ora=1722; strcpy(targa,"AF123AA"); strcpy(codInfraz,"CS123");
    accodaMulta(contravvenzioni, idVigile, data, ora, targa, codInfraz);

    //Inserisce in testa
    idVigile=5678; data=200411; ora=1726; strcpy(targa,"AS345AS"); strcpy(codInfraz,"CS225");
    accodaMulta(contravvenzioni, idVigile, data, ora, targa, codInfraz);

    //Inserisce in testa stessa data e ora
    idVigile=5678; data=200411; ora=1722; strcpy(targa,"AC123CC"); strcpy(codInfraz,"CS123");
    accodaMulta(contravvenzioni, idVigile, data, ora, targa, codInfraz);

    //Inserisce ordinando per ora in coda
    idVigile=1234; data=200312; ora=1720; strcpy(targa,"FF123CA"); strcpy(codInfraz,"CS227");
    accodaMulta(contravvenzioni, idVigile, data, ora, targa, codInfraz);

    //Inserisce ordinando per ora in testa
    idVigile=1234; data=200312; ora=1724; strcpy(targa,"GA527FF"); strcpy(codInfraz,"CS132");
    accodaMulta(contravvenzioni, idVigile, data, ora, targa, codInfraz);

    //Inserisce ordinando per ora in mezzo
    idVigile=1234; data=200312; ora=1723; strcpy(targa,"CF123BF"); strcpy(codInfraz,"CS157");
    accodaMulta(contravvenzioni, idVigile, data, ora, targa, codInfraz);

    //Inserisce in coda
    idVigile=5678; data=200211; ora=1722; strcpy(targa,"GS793CA"); strcpy(codInfraz,"CS332");
    accodaMulta(contravvenzioni, idVigile, data, ora, targa, codInfraz);

    //Inserisce ordinando per ora in coda
    idVigile=1234; data=200112; ora=1720; strcpy(targa,"DS453BF"); strcpy(codInfraz,"CS123");
    accodaMulta(contravvenzioni, idVigile, data, ora, targa, codInfraz);
    
    stampaContravv(contravvenzioni);

    cout<<"Inserire il mese di cui si vuole il report (mm): ";
    cin>>mese;
    creaReport(contravvenzioni, mese);
    
    return 0;
}


int accodaMulta(contravv * &lista, int idVigile, int data, int ora, char targa[], char codInfraz[])
{
    contravv *prec, *tmp=new contravv;

    tmp->idVigile=idVigile;
    tmp->data=data;
    tmp->ora=ora;
    strcpy(tmp->targa, targa); //used to copy one string to another, library string.h
    strcpy(tmp->codInfraz, codInfraz); //ATT! Per stringa1 = stringa2 NON  si possono assegnare con uguale 
    tmp->next=NULL;

    if(lista==NULL)
        lista=tmp;
    else{                //La lista non e' vuota
        prec=cercaPrec(lista, data, ora);
        if(prec==NULL){  //Si inserisce in testa alla lista
            tmp->next=lista;
            lista=tmp;
        }
        else{            //Inserisce dopo l'elemento puntato da prec
            tmp->next=prec->next;
            prec->next=tmp;
        }
    }

    return 0;
}

contravv *cercaPrec(contravv *lista, int data, int ora)
{
    contravv *tmp, *prec=NULL;

    if(lista==NULL) //Lista vuota
        return lista;
    else{
        prec=NULL;
        for (tmp=lista; tmp!=NULL; tmp=tmp->next)
            if(data>=tmp->data)
                if(data==tmp->data && ora<tmp->ora) //A parita' di data si ordina in funzione dell'ora
                    prec=tmp;
                else
                    return prec;
            else
                prec=tmp;
    }
    return prec;
}


int stampaContravv(contravv *punt)
{
    cout << "La lista e' cosi' costituita:" << endl;
    if (punt==NULL)
        cout << "-- Lista vuota --" << endl;
    else
    while (punt!=NULL)
    {
        cout <<"ID Agente: "<<setw(6) << punt->idVigile;
        cout << setw(8) << punt->data/10000<<"/"<<(punt->data/100)%100<<"/"<<punt->data%100;
        cout << setw(6) << punt->ora/100<<":"<<punt->ora%100<<endl;

        punt=punt->next;
    }
    cout << endl << endl;
    
    return 0;
}

/*per ogni agente della lista multe cercaAgente() nella lista di appoggio; se
non trovato aggiungiInTesta() e conta istanze nella lista multe*/
int creaReport(contravv *lista, int mese)
{
    contravv *tempContravv=lista, *temp;

    agente *tempAg, *agenti=NULL;  //Lista di agenti con conteggio contravvenzioni

    //Finche' non si finisce la lista o non si arriva ad un mese precedente a quello che interessa
    while ((tempContravv!=NULL) && ((tempContravv->data/100)%100>=mese))
    {
        //Se agente non ha ancora un'istanza
        if(!cercaAgente(agenti, tempContravv->idVigile) && (tempContravv->data/100)%100==mese){
            tempAg=new agente;
            tempAg->id=tempContravv->idVigile;
            tempAg->count=1;
            //aggiungiInTesta()
            tempAg->next=agenti;
            agenti=tempAg;
            //ContaAgenti()
            temp=tempContravv->next;
            while(temp!=NULL){
                if(temp->idVigile==tempContravv->idVigile && (temp->data/100)%100==mese)
                    agenti->count++;
                temp=temp->next;
            }
        }

        tempContravv=tempContravv->next;
    }

    stampaReport(agenti);
    return 0;
}

int cercaAgente(agente *lista, int id)
{
    agente *tmp=lista;
    while(tmp!=NULL)
        if(tmp->id==id)
            return 1;
        else
            tmp=tmp->next;
    return 0;
}

int    stampaReport(agente *lista)
{
    cout<<endl;
    while(lista!=NULL){
        cout<<"Agente ID: "<<setw(6)<<lista->id<<" N. contravvenzioni: "<<lista->count<<endl;
        lista=lista->next;
    }
    return 0;
}
