//
//  main.cpp
//  ES08 - Giustificazione di una riga di testo
//
//  Created by Stefano Pigliafreddo on 19/12/2020.
//

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int const maxlungh = 40;
    char const blank = ' ';
    char riga[maxlungh], rigag[maxlungh];
    int i,j,k,p;
    int nparole, nspazi, resto, quoziente;
    
    //riempo gli array di spazi
    for (i=0; i<maxlungh; i = i+1){
        riga[i]=blank;
        rigag[i]=blank;
    }
    
    //acquisizione
    i = 0;
    cout << "Inserire una riga da giustificare" <<endl;
    do{
        riga[i]= cin.get();
        i = i+1;
    } while ((riga[i-1] != '\n') && (i<maxlungh));
    //si può uscire dalla fase di inserimento o perchè l'utente ha premuto enter oppure perchè si è riempito l'array
   
    nspazi = maxlungh-i;
    nparole = 0;
    i=0;
    
    
    //finchè non sei a fine riga
    while ((i<maxlungh) && (riga[i] != '\n'))
    { //per fine riga si intende che si trova il carattere '\n' oppure si arriva alla fine dell'array -- questo controllo sarà sempre presente per evitare errori di run-time
        
        //conta spazi
        while((i<maxlungh) && (riga[i] == blank))
        { //si può uscire dal ciclo while o perchè si è a fine riga o perchè si è trovato un carattere diverso da blank
            nspazi = nspazi+1;
            i = i+1;
        }
     //se inizio parola
        if((i<maxlungh) && (riga[i] != '\n'))
        {
        //conta parola
        nparole = nparole+1;
        }
        
      //salta caratteri parola
      while ((i<maxlungh) && (riga[i] != '\n') && (riga[i] != blank))
      {
        i = i+1;
      }
    } //close while
    

    
    //definisco quoziente e resto
    quoziente = nspazi / (nparole-1);
    resto = nspazi % (nparole-1);
    i=0;
    j=0;
    
    
    //per tutte le parole tranne l'ultima
    for(p=1; p<nparole;p=p+1)
    {
        //salta spazi in prima riga
        while((i<maxlungh) && (riga[i] == blank))
        {
            i = i+1;
        }
        //copia caratteri parola in riga-g
        while((i<maxlungh) && (riga[i]!= blank)){
            rigag[j] = riga[i];
            i =i+1;
            j =j+1;
        }
        //aggiungi int spazi in riga-g
        for(k=1; k<= quoziente; k=k+1)
        {
            rigag[j]= blank; //si usa il ciclo for perchè si sa quanto sono le iterazioni da fare. L'indice k è solo un contatore
            j=j+1;
        }
        
    //se resto<>0 aggiungi un carattere in riga-g e decrementa resto
        if(resto>0)
        {
            rigag[j]=blank;
            j=j+1;
            resto = resto-1;
        }
    }

//salta spazi in riga i
while ((i<maxlungh) && (riga[i] == blank))
{
    i = i+1;
}
    
//copia l'ultima parola in riga g
while ((i<maxlungh) && (riga[i] != blank))
{
    rigag[j] = riga[i];
    i = i+1;
    j = j+1;
}
    
//stampa risultato
for (j=0; j<maxlungh;j=j+1)
    {
    cout<< rigag[j];
    }
cout <<endl;
    
}//end of main
