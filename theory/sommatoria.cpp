#include <iostream>
#include <iomanip>
using namespace std;


int main(){
string fiumi[] = {"Po", "Adige", "Tevere","tappo"};

int km[]= {625,410,405,-1};
int quantiFiumi = 4;

//scansione
int totale = 0;
    for(int i =0; i<quantiFiumi; i+=2)
    totale+=km[i];
    cout << "Totale in posizione pari a: " << totale <<endl;
    
string fiumeCercato = "";
cout << "Fiume da cercare " << endl;
cin >> fiumeCercato;
    fiumi[quantiFiumi] = fiumeCercato; // in questo caso il fiume sarà alla fine della lista per cui o lo trovo o sono alla fine e il fiume non è presente. Ma ho risparmiato i confronit.

//algoritmo di ricerca con il tappo. Il tappo ci permette di eviare il confronto nel for che se gli elementi sono molti ci da un forte risparmio di calcoli.
int posFiume = 0;
for (posFiume=0; posFiume <quantiFiumi; posFiume++)
  if(fiumi[posFiume] == fiumeCercato) break;
}//end mian
