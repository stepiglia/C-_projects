//
//  main.cpp
//  es04. Calcolo PERCENTUALE CARATTERI E CIFRE
//
//  Created by Stefano Pigliafreddo on 18/12/2020.
//

#include <iostream>
#include <iomanip> // per la cin.unsetf(os:skipws)
using namespace std;

int main() {
    
    //inizializzazioni
    const int tappo = '.';
    char ch;
    int totCaratteri;
    int totMinuscole;
    int totCifre;
    
    //in windows cin.unsetf(ios::skipws);
    cin.unsetf(ios::skipws);
    
    totCaratteri = 0;
    totMinuscole = 0;
    totCifre = 0;
    
    //istruzioni per l'utente
    cout << endl << "Introdurre un testo terminato da " << tappo << endl;
    //leggi carattere corrente
    cin >> ch;
    
    //while (il testo non è finito)
    while(ch!=tappo)
    {
      //numero totale di caratteri ++
        totCaratteri++;
      //if (il carattere corrente è minuscolo)
        if(ch>= 'a' && ch <= 'z')
        {
        //Numero caratteri minuscoli ++
            totMinuscole++;
        }
        //else if (il carattere corrente è una cifra)
        else if (ch>='0' && ch <='9')
        {
          //numero cifre++
            totCifre++;
        }
        //leggi il carattere corrente
        cin>>ch; //NOTA: bisogna leggere il carattere successivo perchè il ciclo while a differenza del ciclo for, non ha l'incremento automatico delle variabili
    }
    //if (numero caratteri totale > 0
    if (totCaratteri>0){//stampa i risultati
        cout << endl << "La percentuale di lettere minuscole è ";
        cout << 100*totMinuscole/totCaratteri << " % " << endl;
        cout << endl << "La percentuale di cifre è ";
        cout << 100*totCifre/totCaratteri << " %" << endl;
    } else {
       //stampa "Non sono stati introdotti caratteri
        cout << endl << "Non sono stati introdotti caratteri" << endl;
    } return 0;
}
