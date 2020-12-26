//
//  main.cpp
//  Calcolo Prezzo Zone
//
//  Created by Stefano Pigliafreddo on 23/12/2020.
//

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    const char CENTRO = 'c', PERIFERIA = 'p';
    const int MAXDIM = 100;
    char zona; //zona della rilevazione corrente
    int prezzo, //prezzo della rilevazione corrent
    prezziC[MAXDIM], prezziP[MAXDIM], // prezzi rilevati nelle due zone
    numC, numP, sommaC, sommaP, //numero e somma dei prezzi delle due zone
    i;
    float media, deviazione;
    
    cout << setw(53) << "acquisizione rilevazioni" << endl;
    numC = 0; numP = 0; sommaC = 0; sommaP = 0;
    
    while(1)// ciclo di acquiisizione zona e prezzo per ogni rilevazione
    {cout << "zona della nuova rilevazione:"; cin >> zona;
        
        if (cin.eof() || (zona == CENTRO && numC > MAXDIM) || (zona == PERIFERIA && numP >= MAXDIM))
            break;
        
        if (zona == CENTRO || zona == PERIFERIA)
        { cout << "prezzo della nuova rilevazione: "; cin >>prezzo;
            if (zona == CENTRO)
            { sommaC += prezzo; prezziC[numC] = prezzo; numC++;}
            if (zona == PERIFERIA)
            { sommaP += prezzo; prezziP[numP] = prezzo; numP++;}
        }
        else
            cout << "zona non corretta: inserire un nuovo valore";
    }//end while
    
    if (numC != 0) // se c'è almeno una rilevazione della zona centro
    { cout << endl << setw(20)
        << "rilevazione zona " // crea intestazione
        << setw(10) << "centro" << endl << endl //tabella
        << setw(20) << "prezzi rilevati" // per zona centro
        << setw(40) << "deviazione rispetto al prezzo medio" << endl;
        media = (float)sommaC/numC; // ne calcola il prezzo medio
        for (i=0; i < numC; i++)    // per ogni rilevazione, stampa una
        { deviazione = prezziC[i] - media; //riga contenten il
            cout << setw(20) << prezziC[i]
            << setw(40) << setprecision(2)
            << setiosflags(ios::fixed | ios::showpoint)
            << deviazione
            << endl;
        }
    }
    
    //stesso per la periferia
    { cout << endl << setw(20)
        << "rilevazione zona " // crea intestazione
        << setw(10) << "periferia" << endl << endl //tabella
        << setw(20) << "prezzi rilevati" // per zona centro
        << setw(40) << "deviazione rispetto al prezzo medio" << endl;
        media = (float)sommaP/numP; // ne calcola il prezzo medio
        for (i=0; i < numP; i++)    // per ogni rilevazione, stampa una
        { deviazione = prezziP[i] - media; //riga contenten il
            cout << setw(20) << prezziP[i]
            << setw(40) << setprecision(2)
            << setiosflags(ios::fixed | ios::showpoint)
            << deviazione
            << endl;
        }
    }
}
