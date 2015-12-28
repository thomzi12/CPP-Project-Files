/* 
 * File:   SLLCell.h
 * Author: thomzi12
 *
 * Created on October 27, 2015, 2:43 PM
 */

#ifndef SLLCELL_H
#define	SLLCELL_H

#include <iostream>
#include <string>
using namespace std;


class SLLCell{
private:
    string word;
    int freq;
    SLLCell* next; 
public: 
    //friend class SLList;
    SLLCell();
    SLLCell(const SLLCell& orig);
    SLLCell(const string newWord, SLLCell* head); 
    //SLLCell(const string newWord, const SLLCell*);
    //virtual ~SLLCell();
    
    int getFreq() const; 
    string getName();
    //SLLCell(string myWord, SLLCell* newNext);
    void Incred();
    bool wordMatch(string target);
    SLLCell* getnext(); 
    void setnext(SLLCell* ptr);
    
};

#endif	/* SLLCELL_H */
