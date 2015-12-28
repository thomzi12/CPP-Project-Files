/* 
 * File:   main.cpp
 * Author: thomzi12
 *
 * Created on September 21, 2015, 9:11 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include "PigLatin.h"
        
using namespace std;

int main(int argc, char** argv) {
    
    // Declare variables to use later in program 
    ifstream custfile; 
    string txtWord = ""; 
    string filename = ""; 
    string line = "";
    
    // Obtain file name 
    cout << "Please enter file name (with extension):"<< endl; 
    cin >> filename; 
    
    // convert contents of filename to null terminated C string 
    custfile.open(filename.c_str());
    
    // Read file line-by-line, parse out words, run them through pig latin function,
    // and print off the result 
    
    while(getline(custfile, line)){
        istringstream xx(line);                     
        while (xx >> txtWord) {                   
            cout << pigLatin(txtWord);            
        }
        cout << endl;
    }
    // Close file
    
    custfile.close();
    return 0;
}


