#include <string>
#include "SLLCell.h"
using namespace std;

// Initialize constructors 
SLLCell::SLLCell(){
    
}

SLLCell::SLLCell(const SLLCell& orig){
    word = orig.word;
    freq = orig.freq;
    next = orig.next; 
}

SLLCell::SLLCell(const string newWord, SLLCell* head){
    word = newWord; 
    freq = 1; 
    next = head; 
}

string SLLCell::getName(){
    return word; 
}

int SLLCell::getFreq() const{ 
    return freq; 
}

void SLLCell::Incred()
{
    freq = freq + 1;
}

// If a string is the word in a SLLCell, return true 
bool SLLCell::wordMatch(string target){
    return target == word; 
}

SLLCell* SLLCell::getnext(){
    return next;
}
void SLLCell::setnext(SLLCell* ptr){
    next = ptr; 
}