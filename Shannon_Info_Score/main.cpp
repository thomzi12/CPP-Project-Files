/* 
 * File:   main.cpp
 * Author: thomzi12
 *
 */
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>
#include "utilities.h"
#include "SLLCell.h"
#include "SLList.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    // Instantiate SLList and other variables  
    SLList wordlist;
    string filename;
    double sscore; 
            
    cout << "Enter the filename you wish to analyze: ";
    cin >> filename;
    
    wordlist = readData(filename); //Read in file's data to SLLCells "stored in" wordlist
    sscore = ShannonScore(wordlist); // obtain the Shannon score from wordlist
    doReport(wordlist, sscore); // display Shannon score and other statistics about file 
    
    return 0; 
}

