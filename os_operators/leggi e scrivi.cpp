//
//  main.cpp
//  leggiFile
//
//  Created by Maristella on 24/11/2020.
//  Copyright © 2020 Andrea. All rights reserved.
//


// reading a text file
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
    char delimiter = ' ';
    size_t pos = 0;
    string codice = "";
    string descrizione = "";

    
    string line;
    ifstream myfile ("lista.txt");
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            cout << line << '\n';
            pos = line.find(delimiter);
            codice = line.substr(0, pos);
            descrizione = line.substr(pos+1);
            cout << codice <<" + " << descrizione << endl;
            
        }
        myfile.close();
    }
    
    else cout << "Unable to open file";
    
    return 0;
}


///

//
//  main.cpp
//  scriviFile
//
// //  Copyright © 2020 Andrea. All rights reserved.
//

// writing on a text file
#include <iostream>
#include <fstream>

using namespace std;

int main () {
    ofstream myfile ("exampleS.txt");
    if (myfile.is_open())
    {
        myfile << "This is a line.\n";
        myfile << "This is another line.\n";
        myfile << "Ciao.\n";
        myfile.close();
    }
    else
        cout << "Unable to open file";
    return 0;
}
