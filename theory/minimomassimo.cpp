#include <iostream>
#include <iomanip>
using namespace std;


int main(){
string fiumi[] = {"Po", "Adige", "Tevere","tappo"};

int km[]= {625,410,405};
int quantiFiumi = 4;
    
    
    //inizializziamo perchè non sappiamo
    int posizioneMin = 0, posizioneMax=0;
    
    //min. Nota che partiamo da 1 perchè non avrebbe senso confrontare il primo elemento con se stesso
    for(int posizione = 1; posizione<quantiFiumi; posizione++)
    if(km[posizione] <=km[posizioneMin])
        posizioneMin = posizione;
    
    //max
    for(int posizione = 1; posizione<quantiFiumi; posizione++)
    if(km[posizione] >= km[posizioneMax])
        posizioneMax = posizione;
    
    cout << "Primo fiume più corto in ordine di scansione" << endl;
    cout << fiumi[posizioneMin]  << endl;

}
