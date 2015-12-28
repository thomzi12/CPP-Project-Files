/* 
 * File:   SLList.h
 * Author: thomzi12
 *
 * Created on October 27, 2015, 2:37 PM
 */

#ifndef SLLIST_H
#define	SLLIST_H

#include "SLLCell.h"
class SLList{
private:
        SLLCell* head;
        SLLCell* tail;
        int size; 
public: 
   // friend class SLLCell;
    SLList(); 
    SLLCell* findAddr(string &target);
    SLLCell* find(const string & target, bool & found);
    SLLCell* getHead();
    SLLCell* getTail();
    int getSize();
    void Insert(const string & target, SLLCell* ptr);
    void insertAtHead(string myWord);
};

#endif	/* SLLIST_H */
