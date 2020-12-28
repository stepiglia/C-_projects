//
//  main.cpp
//  Classes and nodes
//
//  Created by Stefano Pigliafreddo on 28/12/2020.
//

#include <cstdlib>
#include <iostream>

#include "list.h"

using namespace std;

int main(int argc, char** argv) {
    
    List Paul; //we created a list object name pf the class + name of the object
    
    Paul.AddNode(3);
    Paul.AddNode(5);
    Paul.AddNode(7);
    Paul.PrintList();
    
    Paul.DeleteNode(5);
    Paul.PrintList();
}
