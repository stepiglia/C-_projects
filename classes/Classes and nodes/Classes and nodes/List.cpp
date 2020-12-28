//
//  List.cpp
//  Classes and nodes
//
//  Created by Stefano Pigliafreddo on 28/12/2020.
//

#include <cstdlib> //some preprocessed directives
#include <iostream>

#include "list.h" //we use " " because it's a fine we defined

using namespace std;

//To define a function from a class we need to write ClassName::

List::List(){ //we define the costructor class
    head = NULL; // we need to defined them like this otherwise we get some undesired results later
    curr = NULL;
    temp = NULL;
}

void List::AddNode(int AddData){ //we define the costructor class
    nodePtr n = new node;
    n->next = NULL;
    n->data = AddData;
    
    if(head!=NULL) {//all of our functions can access the private data (head in this case)
        curr = head; //the current pointer should point to the front of the list
        while (curr->next!=NULL) { //while we are not at the end of the list
            curr = curr->next;  //it advances the current pointer until the end of the list
        } //when that happens meaning we are at the end and we exit the while loop
        curr->next = n; //meaning we add it to the node n that we just created. IN all the iterations that are not the very first iteration we will basically add it at the end of the list
    } else { //if we don't have the list at all
        head = n; //then n will be the front
    }
}


void List::DeleteNode(int delData){
    nodePtr delPtr = NULL; //creiamo un pointer per la cancellazione
    temp = head;
    curr = head;
    
    //check if the
    while(curr != NULL && curr->data!= delData){//this condition works when we sorted thorught the whole list and we have not found the value
        temp = curr; //we keep the temp behind in case we need to patch up the list after deleting
        curr = curr->next;
    }
    //we now check which condition was false among the two in the &&
    if (curr == NULL) {//we did not find the value
        cout << delData << " was not in the list \n";
        delete delPtr; //so we don't waste memory
    } else { //we found the node with matching data
        delPtr = curr; //the deletion pointer is pointing to the node we want to delete
        curr = curr->next; //this is pointin to the node after the one we want to delete
        temp->next =curr; //we patched the node in the list
        if(delPtr == head ){
            head = head->next;
            temp = NULL;
        }
        delete delPtr; //we delete the node
        cout << "the value" << delData << "was deleted \n";
    }
}

void List::PrintList(){
    curr = head;
    while (curr != NULL){ //as long as it is not the last node
        cout << curr->data << endl;
        curr=curr->next;
    }
}
