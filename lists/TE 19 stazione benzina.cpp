/* Liste
                    
Per una stazione di servizio per il rifornimento self-service di carburante, si vogliono
implementare alcuni moduli del software C++ per la gestione delle pompe e della cassa.In
particolare vi si chiede di sviluppare la
 
funzione attivaPompa() che, ricevuti come parametri la lista dei rifornimenti in attesa di pagamento e la pompa che richiede l’abilitazione al rifornimento, restituisca tale abilitazione solo se nella lista di attesa è presente al più un
rifornimento pendente per il pagamento relativamente alla stessa pompa.
 
 La funzione
rifornimento(), ricevuti come parametri la lista dei rifornimenti già effettuati e non ancora
pagati, il numero di pompa, il numero di litri erogati ed il prezzo unitario del carburante, dopo
aver ricevuto il consenso dalla funzione attivaPompa(), dovrà erogare il carburante registrando
in coda alla lista stessa il rifornimento, indicandone litri, numero di pompa ed importo. Infine vi
si chiede di sviluppare
 
 la funzione cassa() che, ricevuti la lista dei rifornimenti erogati e non
ancora pagati ed il numero di pompa, individui nella lista il primo rifornimento da regolarizzare
presente per quella pompa, eliminandolo dalla lista stessa e stampando a video numero di
pompa ed importo. */


#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;
        
const int prezzou = 2;

//STRUCT
struct rifornimenti_struct { //rifornimenti
    int pagato; //
    int pompa;
    int litri;

    rifornimenti_struct *next;
};

struct pompe_struct{
    int pompa;
    pompe_struct *next;
};

//PROTOTIPI
int attivaPompa(rifornimenti_struct *&rifornimenti, int pompa_cercata);
/*void InserisciPrimoElemento (node *&testa, node *&coda,int pagato,int pompa,int litri,int prezzou)

node *temp = new node;
temp->pagato pagato,
temp->pompa=pompa,
temp->litri= litri,
temp->prezzou=prezzou

testa = temp;
coda = temp;

void Inserisci(node *&testa, node &*coda,int pagato,int pompa,int litri,int prezzou)
    if(isEmpty(head))
    insertAsFirstElement
*/



/*
int attivaPompa() (nodo *& inattesa , int pompa)
if ( inattesa <=1 rifornimento pendente per il pagamento relativamente alla stessa pompa)
return abilitazione
*/

/*
 int funzione rifornimento() ( nodo *& effettuatimanonpagati,  numero di pompa, litri erogati, prezzo unitario del carburante)
 
 dopo aver ricevuto il consenso dalla funzione attivaPompa()
    dovrà erogare il carburante registrando in coda alla lista stessa il rifornimento
            indicandone litri, numero di pompa ed importo.
 */

/*int funzione cassa()
 
 ricevuti la lista dei rifornimenti erogati e non ancora pagati ed il numero di pompa
    individui nella lista il primo rifornimento da regolarizzare  presente per quella pompa
       eliminandolo dalla lista stessa e stampando a video numero di pompa ed importo. */

//MAIN
int main (){
    
    rifornimenti_struct *testa = NULL;
    rifornimenti_struct *coda = NULL;
    
    rifornimenti_struct *testar = 0;
    rifornimenti_struct *codar = 0;
    //node *rifornimenti = 0;
  
 //inserisco qualche esempio
    rifornimenti_struct *rifornimenti = new rifornimenti_struct;
    rifornimenti->pagato = 0;
    rifornimenti->pompa = 1;
    rifornimenti->litri = 10;
    rifornimenti->next = 0;
    
    //è il primo e unico
    testar = rifornimenti;
    codar = rifornimenti;

// secondo esempio
    rifornimenti_struct *temp = new rifornimenti_struct;
    temp->pagato = 1;
    temp->pompa=2;
    temp->litri= 100;
    temp->next = 0;
    
    codar->next = temp; //dico come connettere i nodi
    codar = temp;
    
 //terzo esempio
    rifornimenti_struct *temp2 = new rifornimenti_struct;
    temp2->pagato = 1;
    temp2->pompa=3;
    temp2->litri= 200;
    temp2->next = 0;
    
    codar->next = temp2; //finire la lista significa che l'ultimo elemento non punta a nulla
    codar = 0;
    
    
    
    //inserisci quale pompa, quanti litri
    int inserisci_pompa;
    int inserisci_litri;
    
    cin >> inserisci_pompa;
    cin >> inserisci_litri;
    
    
    
    
    
    
    
    
    

  //visualizzo
  cout << "Sono stati effettuati i seguenti rifornimenti: \n";
  while (testar!=NULL)
  {
      cout << testar->pagato << " stato pagamento (1 = non pagato, 0= pagato)" << endl;
      cout << testar->pompa << " alla pompa" << endl;
      cout << testar->litri << " litri" << endl;
      cout << (testar->litri * prezzou)<< " importo" << endl;
      cout << "-----\n";
      testar = testar->next; //il nuovo current diventa l'elemento a cui sta puntando il mio current
  }

    /*
   int pompa_cercata;
    
    cout << "Inserisci la pompa che stai cercando " << endl;
    cin >> pompa_cercata;
    
    int stato_autorizzazione;
    int autorizza_bool = 0;
    
    stato_autorizzazione = attivaPompa(rifornimenti, pompa_cercata);
    if(stato_autorizzazione == -1 ) cout << "La lista è vuota";
    
    //okay autorizzazione
    if ((stato_autorizzazione >= 0) && (stato_autorizzazione <= 1)){
        autorizza_bool = 1;
    } else {
        cout << "Troppi pagamenti in sospeso. Si prega di attendere il pagamento";
    }
    
    cout << autorizza_bool;*/
}; //end of main





//--------FUNZIONE ATTIVA POMPA ---------//

//funzione attivaPompa() che, ricevuti come parametri la lista dei rifornimenti in attesa di pagamento e la pompa che richiede l’abilitazione al rifornimento, restituisca tale abilitazione solo se nella lista di attesa è presente al più un rifornimento pendente per il pagamento relativamente alla stessa pompa.

/*int attivaPompa(rifornimenti_struct *&rifornimenti, int pompa_cercata){
    
    int pagamenti_pendenti = -1;
    rifornimenti_struct *tmp = ;
    
    //la lista è vuota
    if (tmp != NULL) {
        cout << "Non c'è nessun rifornimento in corso" << endl;
    }
    //se non è vuota conta quanti pagamenti pendenti ci sono per la pompa cercata
    else {
        for(tmp=rifornimenti; tmp!=NULL; tmp=tmp->next)
        if (tmp->pompa == pompa_cercata && tmp->pagato == 0) {
            pagamenti_pendenti++;
        }
        return pagamenti_pendenti;
    }
    return -1; //scelta in caso di lista vuota
}*/
            
/*La funzione rifornimento(), ricevuti come parametri la lista dei rifornimenti già effettuati e non ancora pagati, il numero di pompa, il numero di litri erogati ed il prezzo unitario del carburante, dopo aver ricevuto il consenso dalla funzione attivaPompa(), dovrà erogare il carburante registrando in coda alla lista stessa il rifornimento, indicandone litri, numero di pompa ed importo. */





//--------FUNZIONE RIFERIMENTO ---------//

int rifornimento(rifornimenti_struct *&rifornimenti,rifornimenti_struct *&testa, rifornimenti_struct *&coda, int inserisci_pompa, int inserisci_litri){
   
    //TODO se la funzione autorizza me lo lascia fare inserisco
    //TODO riceve solo i rifornimenti già effettuati ma non pagati (questo lo controllo prima nel main)

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
      coda->next = temp;
      coda = tmp; //sposto temp all'ultimo elemento
    }
} // end of rifornimento


//--------FUNZIONE CASSA ---------//
