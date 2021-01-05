//
//  main.cpp
//  PI III canottaggio
//
//  Created by Stefano Pigliafreddo on 05/01/2021.
//


//Classi
//Annualmente, fra le varie università, viene svolta una //competizione di canottaggio fra imbarcazioni
//che prevedono otto canottieri più un timoniere. Per gestire //tali competizioni, vi viene chiesto di
//realizzare, in linguaggio C++, le classi “Atleta” ed //“Imbarcazione” descritte di seguito.
//L’atleta è caratterizzato da cognome, nome, università //d’appartenenza e ruolo, ossia l’essere o un
//canottiere o un timoniere. La rispettiva classe deve prevedere //le seguenti operazioni:
//- creazione di un atleta caratterizzato da cognome, nome, //università e ruolo;
//- modifica dell’università d’appartenenza di un atleta;
//- stampa a video di tutte le informazioni relative un //determinato atleta.
//L’imbarcazione è caratterizzata dal nome dell’università //d’appartenenza e dagli atleti che la
//compongono. La classe corrispondente deve prevedere le seguenti //operazioni:
//- creazione di una imbarcazione caratterizzata dal nome //dell’università;
//- aggiunta di un canottiere ad un’imbarcazione verificando la //corrispondenza dell’università e la
//disponibilità sull’imbarcazione di un posto libero;
//- eliminazione di un canottiere da un’imbarcazione;
//- aggiunta del timoniere ad un’imbarcazione verificando la //corrispondenza dell’università e la
//disponibilità del posto;
//- modifica del timoniere di un’imbarcazione;
//- stampa a video di tutte le informazioni relative una //determinata imbarcazione (ossia università
//d’appartenenza e lista degli atleti con l’indicazione del //timoniere);
//- stampa di tutte le informazioni relative una determinata //imbarcazione su un file il cui nome viene
//passato come parametro.
//Si chiede di realizzare anche un breve programma principale per //testare le due classi.

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string.h>
using namespace std;

const int STR = 20;


//--- CLASSE NODO ATLETA --


//--- CLASSE ATLETA --
class Atleta {
    
    friend ostream& operator<<(ostream &out, const Atleta &);

    public:
        Atleta();
        Atleta(char cognome[], char nome[], char università[], int canottiere);
        int CambiaUni(char ins_università[]);
        int stampaAtleta(char ins_cognome[], char ins_nome[]);
        
        
    private:
        char cognome[STR];
        char nome[STR];
        char università[STR];
        int canottiere; //1
    };

    struct struct_atleti{
        char cognome[STR];
        char nome[STR];
        char università[STR];
        int canottiere; //1
        struct_atleti *next;
    };


//- creazione di un atleta caratterizzato da cognome, nome, //università e ruolo;
Atleta::Atleta(char ins_cognome[], char ins_nome[], char ins_università[], int ins_canottiere)
{
    strcpy(cognome, ins_cognome);
    strcpy(nome, ins_nome);
    strcpy(università, ins_università);
    canottiere = ins_canottiere;
    
}

//- modifica dell’università d’appartenenza di un atleta;
int Atleta::CambiaUni(char ins_università[])
{
    strcpy(università, ins_università);
    return 0;
}


//- stampa a video di tutte le informazioni relative un //determinato atleta.
int Atleta::stampaAtleta(char ins_cognome[], char ins_nome[]){
    
    if(strcmp(cognome,ins_cognome) == 0 && strcmp(nome,ins_nome) == 0){

       cout << this->cognome;
       cout << this->nome;
       cout << this->università;
       cout << this->canottiere;
    }
    return 0;
};
    

// Funzione friend

ostream& operator<<(ostream &out, const Atleta &at)
{
    out << setw(6) << at.cognome << setw(30) << at.nome << setw(10);
    out    << at.università << setw(10) << at.canottiere;
    return out;
};




//--- CLASSE IMBARCAZIONE --
class Imbarcazione{};


int main() {
    
    struct_atleti *lista = NULL;
    
    char ins_cognome[STR];
    char ins_nome[STR];
    char ins_università[STR];
    int ins_canottiere;
    
    cout << "Inserisci un nuovo atleta, Ctrl+D per uscire" <<endl;
    
    while(cin.eof() != 1){
        cout << "Inserisci cognome";
        cin >> ins_cognome;
        cout << "Inserisci nome";
        cin >> ins_nome;
        cout << "Inserisci Università";
        cin >> ins_università;
        cout << "Inserisci Ruolo";
        cin >> ins_canottiere;
        
        //creo atleta
        Atleta at1(ins_cognome,ins_nome,ins_università,ins_canottiere);
        
        
        
        if(lista == NULL){
            lista = at1
        } else
            
            tmp = at1;
            tmp->next;
        
            
            
            tmp = lista;
            
        
            };
    
    
    
    
    
    //Aggiungi a lista
   
    
    
    
    Atleta at1(ins_cognome,ins_nome,ins_università,ins_canottiere);
    at1.CambiaUni("PoliMi");
    Atleta at2("Rossi","Stefano","Bocconi",0);
    Atleta at3("Gialli","Stefano","Bocconi",1);
    
   // cout << at1 << endl << at2 << endl << at3;
    at1.stampaAtleta("Pigliafreddo", "Stefano");
    at2.stampaAtleta("Pigliafreddo", "Stefano");
    at3.stampaAtleta("Pigliafreddo", "Stefano");
   
    
}

