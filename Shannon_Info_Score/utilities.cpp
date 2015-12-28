#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include "utilities.h"
#include "SLLCell.h"
#include "SLList.h"
using namespace std;

// Create program to process each file to SLList
SLList readData(string filename){
    // Create ifstream and string variables to stream in words from text file 
    ifstream inFS;
    string buff; 
    
    // Use a do-while loop to ensure inputted filename is valid 
    do{
        inFS.open(filename.c_str());
        if (!inFS.is_open()){
            cout << "Hmm, couldn't read. Try again?" << endl;
            cout << "Enter the filename you wish to analyze: ";
            cin >> filename; 
        }
    }while(!inFS.is_open());
    
    // Create SLList to put in cells 
    SLList wordlist; 
    
    // Use while loop to stream in text, word-by-word, to buff string
    while(inFS >> buff){
        string newstr = ""; // Use newstr in process of cleaning up word in buff
        
        // Use for loop to filter out non-letter chars. Change letters to lowercase 
        for(int i = 0; i < buff.length(); ++i){
            if(isalpha(buff.at(i))){
                buff.at(i) = tolower(buff.at(i));
                newstr = newstr + buff.at(i); // create new string, a clean version of buff
            }
        }
        
        buff = newstr; // reassign buff to clean version 
        
        // Make sure that we are not inputting the empty string 
        if(!buff.empty()){
            
            // if a word isn't already in the wordlist, create new SLLCell
            // and add it in 
         
            
            bool status; // Boolean to see if we need to increment or not 
            SLLCell* pter = wordlist.find(buff, status); // Read in string and change status if already in wordlist
            
                if(status)
                {
                    
                    SLLCell* index;
                    index = wordlist.findAddr(buff); 
                    index -> Incred(); 
                }
                else if(pter == NULL)
                {
                    wordlist.insertAtHead(buff); 
                }
                else {
                    wordlist.Insert(buff, pter);
                }
            
        }
    }
    inFS.close();
    return wordlist; 
       
}

// Prints off report featuring each word and its frequency in SLList XXX 

void doReport(SLList& XXX, double sscore){
    cout << "Word       Frequency" << endl; 
    
    // Cycle through the linked list and obtain word name and frequency 
    for(SLLCell* ptr= XXX.getHead(); ptr != NULL; ptr = ptr -> getnext()){
        int space = 0;
        int freq;
        string nam; 
        nam = ptr -> getName(); 
        freq = ptr -> getFreq(); 
        space = 15 - nam.length();
        cout << nam << setfill(' ') << setw(space); 
        cout << freq << endl; 
    }
    
    int totalwords = 0;
    
    //Cycle through words and count total number
    for(SLLCell* ptr= XXX.getHead(); ptr != NULL; ptr = ptr -> getnext()){
        totalwords = totalwords + ptr -> getFreq(); 
    }
    
    //print off report
    cout << "Total number of words read: " << totalwords << endl; 
    cout << "Total number of distinct words: " << XXX.getSize() << endl; 
    cout << "Shannon score of file: " << sscore << endl; 
}

// Returns the Shannon score of a SLList 
double ShannonScore(SLList & XXX){
    
    int totalwords = 0;
    double sscore = 0.0; 
     for(SLLCell* ptr= XXX.getHead(); ptr != NULL; ptr = ptr -> getnext()){
        totalwords = totalwords + ptr -> getFreq(); // Calculate the total number of words in text file 
         
    }
    
     for(SLLCell* ptr= XXX.getHead(); ptr != NULL; ptr = ptr -> getnext()){
        double wordf = 0; 
        wordf = ptr -> getFreq(); 
        sscore = sscore + (wordf/totalwords)*log2(wordf/totalwords); // Calculate Shannon Score 
       }
    sscore = -1*sscore; 
    
    return sscore; 
}