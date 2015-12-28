/* 
 * File:   PigLatin.cpp
 * Author: thomzi12
 *
 * Created on September 21, 2015, 9:22 PM
 */

using namespace std;
#include <iostream>
#include <string>



string pigLatin(string a) {
    
    int signal = 0; 
    // If first letter in word is uppercase, change this at end of piglatin transformation
    if (isupper(a.at(0)) > 0){
        signal = 1;
    }
    
    // Declare string variable we will eventually return 
    string output = "";
    
    // Find position of first vowel 
    int vowpos = 0;
    vowpos = a.find_first_of("aieouAIEOU");
    
    // If vowel wasn't found, check for letter y
    if (vowpos < 0){
        vowpos = a.find_first_of("yY");
    }
    
    // If no vowel found, set vowpos to zero
    if (vowpos < 0){
        vowpos = 0;
    }
    
    // Add to output the part of the word following the vowel 
    // Or, the whole word if no vowel
    for(int i = vowpos; i < a.length(); ++i){
        output.push_back(a.at(i));
    }
    // Add initial consonant cluster to end of word, if appropriate 
    for(int j = 0; j < vowpos; ++j){
        output.push_back(a.at(j));
    }
    
    // Add "ay" to end of output
    output.append("ay");
    
    // transform all characters to lowercase
    for(int i = 0; i < output.length(); ++i){
        output.at(i) = tolower(output.at(i)); 
    }
    
    // If first letter was uppercase, change case of first character of output 
    if (signal == 1){
        output.at(0) = toupper(output.at(0));
    }
    
    // Move punctuation to end of word if present 
    for (int q=0; q < output.length(); q++) {                       
        
        if (ispunct(output.at(q)) != 0) {                           
            output.push_back(output.at(q));                     
            output.erase(q,1);                                     
        }
    }
    
    // Add space to end of the word 
    output.append(" ");
    return output;
}

