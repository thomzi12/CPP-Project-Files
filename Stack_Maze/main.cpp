/* 
 * File:   main.cpp
 * Author: thomzi12
 *
 * Created on November 26, 2015, 11:15 AM
 */

#include <cstdlib>
#include <cstring>
#include <stack>
#include <utility> 
#include <vector>
#include <string>
#include "utilities.h"
using namespace std;

int main(int argc, char** argv) {	
    
    vector<pair<int,int> > info; // Create vector of pairs to store start and end locations, dimensions of maze
    stack<pair<int,int> > STACK; // Create stack of pairs 
    char maze[100][100]; /*two-dimensional char array to store the maze */ 
    
    string filename; 
    bool done = false; /* so we know if we're done yet */ 
    int turns  = 0; // A counter to let us know how long it took us to reach the endpoint 

    cout << "Enter in the name of the .maz file, and we'll get to work!" << endl;
    cin >> filename;  

    readData(filename, info, maze);  
    
    STACK.push(info.at(0)); // Push first position to stack 
    
        // While stack has pairs, progress through maze 
        while (!STACK.empty()){
            pair<int, int> nextPosition= STACK.top(); /* retrieves value at top */
            STACK.pop(); /* Deletes value at top of Stack */
                   
            // Obtain x and y values to mark as visited
            int xval = nextPosition.first; 
            int yval = nextPosition.second; 
            
            cout << "Here's the current position: " << xval << " " << yval << endl; 
            maze[xval][yval] = 'V'; // Mark current position on char array 
            
            printMaze(info,maze); // print mazes 

            if (nextPosition == info.at(1)){
                    done = true; 
                    break;  // exit out of loop if we have reached the end of maze
            }

            positionPush(nextPosition, STACK, info, maze); /* check and push for new position(s) */ 
            ++turns; // each turn, increment turn counter 
    }
    
    
   
    if(done){
            cout << "Congratulations! You made it to the end." << endl; 
            cout << "Number of turns it took you: " << turns << endl; 
    }
    else {
        cout << "Hmm, an error occurred with your maze program ... check it out!" << endl;}    
     
     return 0;
}
