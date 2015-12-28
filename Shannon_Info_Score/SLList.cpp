#include <iostream>
#include <fstream>
#include "SLLCell.h"
#include "SLList.h"

// Constructor
SLList::SLList(){
    head = NULL;
    tail = NULL;
    size = 0; 
}

//"Getter" methods 
SLLCell* SLList::getTail(){
    return tail; 
}

SLLCell* SLList::getHead(){
    return head; 
}

int SLList::getSize(){
    return size; 
}

// Inserts a SLLCell object at the head of the list 
void SLList::insertAtHead(string myWord){
    SLLCell* lv = new SLLCell(myWord, head);
    head = lv; 
    size++;
    if(tail == NULL){
        tail = head;
    }
}

void SLList::Insert(const string & target, SLLCell* ptr){
    SLLCell* lv = new SLLCell(target, ptr->getnext());
    ptr -> setnext(lv);             
    size++;
}


// Returns the pointer of word if it exists in SLList. Otherwise, return NULL  
SLLCell* SLList::findAddr(string &target){
    for(SLLCell* ptr= head; ptr != NULL; ptr = ptr -> getnext()){
        if(ptr -> wordMatch(target)){
            return ptr; 
        }
    }
    return NULL; 
}

SLLCell* SLList::find(const string & target, bool & found){
    SLLCell* myptr;
    SLLCell* lag; 
    lag = NULL;
    found = false; 
    if (head == NULL){
        return lag;
    }
    else{
        for(myptr = head; (myptr != NULL) && (myptr->getName() <= target) ; myptr = myptr ->getnext()){
            lag = myptr;      
            if (myptr -> getName() == target){
                found = true;
                return myptr;
                }
        }
        if(!found){
                return lag;
            }
    }
}     