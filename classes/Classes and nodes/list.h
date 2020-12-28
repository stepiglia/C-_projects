//
//  list.h
//  Classes and nodes
//
//  Created by Stefano Pigliafreddo on 28/12/2020.
//

#ifndef list_h
#define list_h

class List {
    
private: //all the parts that can only be accessed by the functions that we define later
    typedef struct node { //type def allows you to type just NodePtr and it would be the same thing of struct node*, so it is basically the prefix of a nodepointer, instead of Node* head; we can write NodePtr head;  (or all spelt out it was typedef struct node* NodePtr)
        int data;
        node * next;
    }* nodePtr;
    
    nodePtr head;
    nodePtr curr;
    nodePtr temp;
    
public: //functions that we use to access the private data
    
    //we declare function prototypes, the functions are going to be in defined in list.cpp
    List(); // we will define head, curr, temp here
    void AddNode (int addData);
    void DeleteNode(int delData); //it will go through the list till it finds the node with that value
    void PrintList();
};


#endif /* list_h */
