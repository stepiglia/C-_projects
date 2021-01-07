#include <iostream>
#include <iomanip>
using namespace std;


int main(){
string fiumi[] = {"Po", "Adige", "Tevere","tappo"};

int km[]= {625,410,405,-1};
int quantiFiumi = 4;
    
    //scansione
    int totale = 0;
        // opzione 1: for(int i =0; i<quantiFiumi; i+=2)
        for(int i =0; i<quantiFiumi; i++)
        totale+= (i%2) ? 0 : km[i]; //espressione condizionale: se false cioè zero è il risultato passiamo i km
    cout << "Totale in posizione pari: " << totale <<endl;
}
