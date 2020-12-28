/*
                    
Per una stazione di servizio per il rifornimento self-service di carburante, si vogliono implementare alcuni moduli del software C++ per la gestione delle pompe e della cassa.In particolare vi si chiede di sviluppare:
 
La funzione attivaPompa() che, ricevuti come parametri la lista dei rifornimenti in attesa di pagamento e la pompa che richiede l’abilitazione al rifornimento, restituisca tale abilitazione solo se nella lista di attesa è presente al più un rifornimento pendente per il pagamento relativamente alla stessa pompa.
 
La funzione rifornimento(), ricevuti come parametri la lista dei rifornimenti già effettuati e non ancora pagati, il numero di pompa, il numero di litri erogati ed il prezzo unitario del carburante, dopo aver ricevuto il consenso dalla funzione attivaPompa(), dovrà erogare il carburante registrando in coda alla lista stessa il rifornimento, indicandone litri, numero di pompa ed importo.
 
La funzione cassa() che, ricevuti la lista dei rifornimenti erogati e non ancora pagati ed il numero di pompa, individui nella lista il primo rifornimento da regolarizzare presente per quella pompa, eliminandolo dalla lista stessa e stampando a video numero di pompa ed importo. */

#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;
        
//STRUCT
struct rifornimenti_struct { //rifornimenti
    int pagato; //
    int pompa;
    int litri;
    rifornimenti_struct *next;
};

const int prezzou = 2;
int pagamenti_pendenti = 0;
int autorizzazione = 0;

//PROTOTIPI
void VisualizzaRifornimenti(rifornimenti_struct *&rifornimenti);
int attivaPompa(rifornimenti_struct *&rifornimenti, int pompa_cercata);
void rifornimento(rifornimenti_struct *&rifornimenti, rifornimenti_struct *&codar, int inserisci_pompa, int inserisci_litri);
void cassa(rifornimenti_struct *&rifornimenti, int inserisci_pompa);

//MAIN
int main (){
    
//inizializzo rifornimenti
    rifornimenti_struct *testar = NULL;
    rifornimenti_struct *codar = NULL;
    //node *rifornimenti = 0;
  
 //inserisco qualche esempio
    rifornimenti_struct *rifornimenti = new rifornimenti_struct;
    rifornimenti->pagato = 1;
    rifornimenti->pompa = 1;
    rifornimenti->litri = 10;
    rifornimenti->next = 0;

//è il primo e unico
    testar = rifornimenti;
    codar = rifornimenti;

// secondo esempio
    rifornimenti_struct *temp = new rifornimenti_struct;
    temp->pagato = 0;
    temp->pompa=1;
    temp->litri= 100;
    temp->next = NULL;
    
    codar->next = temp; //dico come connettere i nodi
    codar = temp;
    
//terzo esempio
    rifornimenti_struct *temp2 = new rifornimenti_struct;
    temp2->pagato = 1;
    temp2->pompa=3;
    temp2->litri= 200;
    temp2->next = NULL;
    
    codar->next = temp2; //finire la lista significa che l'ultimo elemento non punta a nulla
    codar = temp2;
    
//visualizzo
    VisualizzaRifornimenti(rifornimenti);

    int inserisci_pompa = 0;
    int inserisci_litri = 0;
    
    cout << "Scegliere la pompa desiderata (1-20) \n";
    cin >> inserisci_pompa;
   
    attivaPompa(rifornimenti,inserisci_pompa);
    if (pagamenti_pendenti == -1) {
        cout << "La lista è vuota";
        autorizzazione = 1;
    }
    
    if (pagamenti_pendenti > 1) {
        cout << "Ci sono troppi pagamenti pendenti, seleziona un'altra pompa";
    }
    
    if (pagamenti_pendenti == 1 || pagamenti_pendenti == 0) {
        cout << "La pompa è disponibile\n";
        autorizzazione = 1;
        cout << "Selezionare la quantità di carburante desiderata (in L) \n";
        cin >> inserisci_litri;
        
        rifornimento(rifornimenti,codar,inserisci_pompa,inserisci_litri);
        
        //visualizzo
        VisualizzaRifornimenti(rifornimenti);
        
        //cassa
        cassa(rifornimenti, inserisci_pompa);
        cout << "Inizializziamo il pagamento \n" << endl << endl;
        
        
        //visualizzo
        VisualizzaRifornimenti(rifornimenti);
        
        autorizzazione = 0;
        
    } //chiudi if autorizza
};//end of main


//--------FUNZIONE ATTIVA POMPA ---------//
//funzione attivaPompa() che, ricevuti come parametri la lista dei rifornimenti in attesa di pagamento e la pompa che richiede l’abilitazione al rifornimento, restituisca tale abilitazione solo se nella lista di attesa è presente al più un rifornimento pendente per il pagamento relativamente alla stessa pompa.

int attivaPompa(rifornimenti_struct *&rifornimenti, int inserisci_pompa) {
        
    rifornimenti_struct *tmp = rifornimenti;
    
    //la lista è vuota
    if (tmp == NULL) {
        cout << "Non c'è nessun rifornimento in corso QUI" << endl;
        return -1;
    }
    //se non è vuota conta quanti pagamenti pendenti ci sono per la pompa cercata
    else {
        for(tmp=rifornimenti; tmp!=NULL; tmp=tmp->next)
        if (tmp->pompa == inserisci_pompa && tmp->pagato == 1) {
            pagamenti_pendenti++;
        }
        return pagamenti_pendenti;
    }
    return pagamenti_pendenti; //scelta in caso di lista vuota
}
            

//--------FUNZIONE RIFORNIMENTO ---------//
void rifornimento(rifornimenti_struct *&rifornimenti, rifornimenti_struct *&codar,int inserisci_pompa, int inserisci_litri)
    {
        
    rifornimenti_struct *testa= rifornimenti;
    rifornimenti_struct *coda= rifornimenti;
   
    if(rifornimenti==NULL){
      rifornimenti_struct *tmp= new rifornimenti_struct;
      tmp->pagato = 0;
      tmp->pompa = inserisci_pompa;
      tmp->litri = inserisci_litri;
      tmp->next=NULL; //perchè non c'è niente dopo
      testa = tmp;
      coda = tmp;
        
    } else{
      rifornimenti_struct *tmp= new rifornimenti_struct;
      tmp->pagato = 0;
      tmp->pompa = inserisci_pompa;
      tmp->litri = inserisci_litri;
      tmp->next = NULL;
      codar->next = tmp; //
      codar = tmp; //sposto temp all'ultimo elemento
    }
} // end of rifornimento


//--------FUNZIONE CASSA ---------//
void cassa(rifornimenti_struct *&rifornimenti, int inserisci_pompa){
       
    rifornimenti_struct *tmp = rifornimenti;
    
    //la lista è vuota
    if (tmp == NULL) {
        cout << "Non c'è nessun rifornimento in lista" << endl;
    }
    //se non è vuota scorri fino a quando trovi il primo rifornimento della pompa cercata non pagato
    //ed eliminalo + stampa a video
    for(tmp=rifornimenti; tmp!=NULL; tmp=tmp->next) {
    if(tmp->pompa == inserisci_pompa && tmp->pagato ==  1){
        cout << "Stiamo regolarizzando il pagamento della pompa: " <<  inserisci_pompa << " per un importo di " << tmp->litri * prezzou;
        rifornimenti = rifornimenti->next;
        break;
    } else {
        tmp=tmp->next; //scorro
     }
    }
};


//--------FUNZIONE VISUALIZZA ---------//
void VisualizzaRifornimenti(rifornimenti_struct *&rifornimenti){
    cout << "As ora sono stati effettuati i seguenti rifornimenti: \n";

    rifornimenti_struct *tmp = rifornimenti;
    while (tmp!=NULL)
    {
        cout << tmp->pagato << " stato pagamento (1 = non pagato, 0= pagato)" << endl;
        cout << tmp->pompa << " alla pompa" << endl;
        cout << tmp->litri << " litri" << endl;
        cout << (tmp->litri * prezzou)<< " importo" << endl;
        cout << "-----\n";
        tmp = tmp->next; //il nuovo current diventa l'elemento a cui sta puntando il mio current
    };
};
