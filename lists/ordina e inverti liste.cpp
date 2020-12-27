// Esercitazione 17
// Si realizzi una funzione c++ che riceva in ingresso una lista di interi e restituisca una lista
// contenente gli stessi numeri, ma in ordine inverso ripetto alla lista di ingresso

#include <iostream>
using namespace std;

struct Nodo
{
    int valore;
    Nodo *nextPtr;
};

void invertiLista(Nodo *testa, Nodo *&testaInv);
void inserisciInTesta(Nodo *&testaInv, int valore);
void invertiListaDistruttivo(Nodo *&testa);
void stampaLista(Nodo *testa);
Nodo *inserisciLista();
Nodo *inserisciLista2();
void deleteLista(Nodo *testa);

int main()
{
    Nodo *testa, *testaInv = nullptr;
    int algoritmo;
    
    // Legge la lista da invertire
    testa = inserisciLista();
    cout << endl;
    
    // Intercetta una lista vuota
    if (testa == nullptr)
    {
        cout << "Lista vuota" << endl;
        return -1;
    }
    
    // Inverte e stampa la lista invertita
    cout << "Quale metodo si vuole usare per invertire la lista:" << endl;
    cout << "1 - Non distruttivo" << endl;
    cout << "2 - Distruttivo" << endl;
    cout << ">";
    cin >> algoritmo;
    if (algoritmo == 2) {
        invertiListaDistruttivo(testa);
        cout << "Lista invertita: ";
        stampaLista(testa);
    }
    else
    {
        invertiLista(testa, testaInv);
        cout << "Lista invertita: ";
        stampaLista(testaInv);
    }
    cout << endl;
    
    // Distrugge la lista
    deleteLista(testa);
    deleteLista(testaInv);
    
    return 0;
}

Nodo *inserisciLista()
{
    Nodo *testa = nullptr;      // Primo elemento della list
    Nodo *last = nullptr;       // ultimo elemento della lista
    Nodo *newNodo;              // Nuovo nodo creato
    
    int len, valore;
    
    cout << "Quanti valori si vogliono inserire: ";
    cin >> len;
    
    for (int i = 0; i < len; i++)
    {
        cout << "Inserire il termine " << i << ": ";
        cin >> valore;
        
        // Crea il nuovo nodo
        newNodo = new Nodo;
        newNodo->valore = valore;
        newNodo->nextPtr = nullptr;
        
        // Il primo elemento va in testa
        if (i == 0)
            testa = newNodo;
        else
            last->nextPtr = newNodo;
        
        last = newNodo;
    }

    return testa;
}

void invertiLista(Nodo *testa, Nodo *&testaInv)
{
    Nodo *item = testa;         // Parte dall'inizio della lista
    testaInv = nullptr;
    
    while (item != nullptr)
    {
        inserisciInTesta(testaInv, item->valore);
        item = item->nextPtr;
    }
}

void inserisciInTesta(Nodo *&testaInv, int valore)
{
    Nodo *newItem = new Nodo;
    newItem->valore = valore;
    
    // Se la lista non è vuota fa diventare la testa il secondo elemento
    if (testaInv == nullptr)
        newItem->nextPtr = nullptr;
    else
        newItem->nextPtr = testaInv;
    
    testaInv = newItem;
}

void invertiListaDistruttivo(Nodo *&testa)
{
    Nodo *item = testa;                 // Parte dall'inizio della lista
    Nodo *prevItem = nullptr;           // Elemento precendete
    Nodo *nextitem = testa->nextPtr;    // Elemento successivo
    item->nextPtr = prevItem;

    while (nextitem != nullptr)
    {
        prevItem = item;
        item = nextitem;
        nextitem = item->nextPtr;
        item->nextPtr = prevItem;
    }
    
    testa = item;
}

void stampaLista(Nodo *testa)
{
    Nodo *item = testa;         // Parte dall'inizio della lista
    
    while (item != nullptr)
    {
        cout << item->valore << " ";
        item = item->nextPtr;
    }
}

void deleteLista(Nodo *testa)
{
    Nodo *item = testa;         // Parte dall'inizio della lista
    Nodo *nextItem;
    
    while (item != nullptr)
    {
        nextItem = item->nextPtr;
        delete item;
        item = nextItem;
    }
}
