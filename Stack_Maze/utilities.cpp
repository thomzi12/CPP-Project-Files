#include <cstdlib>
#include <cstring>
#include <stack>
#include <iostream>
#include <fstream>
#include <sstream>
#include <utility> 
#include <vector>
#include <string>
using namespace std;

void readData(string filename, vector<pair<int,int> >& info, char maze[100][100]){ 
    
    /* Create temporary variables to store info about maze */
    int b1,b2,s1,s2,e1,e2; 
    pair<int, int> startc; 
    pair<int, int> endc; 
    pair<int, int> boundc; 
    
    // Create string and streaming variables to stream in maze information 
    ifstream custfile;
    string line = "";
    string mazebuff; 
    
    /* Read in file with maze in it, return error if appropriate*/
    do{
        custfile.open(filename.c_str());
        if (!custfile.is_open()){
            cout << "Hmm, couldn't read. Try again?" << endl;
            cout << "Enter the filename you wish to analyze: ";
            cin >> filename; 
        }
    }while(!custfile.is_open());
    
    // Read in top of maze file to int variables 
    custfile >> b1;
    custfile >> b2; 
    custfile >> s1; 
    custfile >> s2; 
    custfile >> e1; 
    custfile >> e2; 
    
    // Assign appropriate variables to info pair vector 
    
    startc = make_pair(s1,s2); //starting coordinates
    endc = make_pair(e1,e2); // ending coordinates
    boundc = make_pair(b1,b2); // maze dimensions/boundaries
    
    // push pairs to info pair vector 
    info.push_back(startc);
    info.push_back(endc);
    info.push_back(boundc);
    
    // Read in the rest of the file into the two-dimensional array 
    int row = 0; 
    while(getline(custfile, line)){
        istringstream xx(line);                     
        while (xx >> mazebuff) {                   
           //Loop through streamed in line, add to maze string
            for(int i = 0; i<mazebuff.length(); ++i){
                maze[row][i] = mazebuff[i];
            }
            ++row; 
        }
        }
    custfile.close();
  
return; 

}

/* Overload "+" operator for pair objects */
pair<int,int>& operator+(const pair<int,int>& a,const pair<int,int>& b){
    pair<int,int> c; 
    c = pair<int,int> (a.first+b.first, a.second+b.second);
    return c; 
}

/* Print out current maze*/
void printMaze(const vector<pair<int,int> >& info, char maze[100][100]){
    pair<int, int> bounds = info.at(2); // dimensions of maze
    
    const int itr1 = bounds.first; 
    const int itr2 = bounds.second; 
    
    /* Loop that prints out the maze*/
    for(int i=0; i < itr1; ++i){
        for(int j=0; j < itr2; ++j){
            cout << maze[i][j]; 
            }
        cout << endl; 
    }
}

void positionPush(pair<int,int> nextPosition, stack<pair<int,int> >& STACK, const vector<pair<int,int> > info, char maze[100][100]){
    vector<pair<int,int> > adjster; // Create pair vector to hold adjusting pairs  
    pair<int, int> north, east, south, west, bounds; // pairs to hold transformations and boundaries  
    
    bounds = info.at(2); // dimensions of the maze
  
    north = make_pair(-1,0);
    east = make_pair(0,1);
    south = make_pair(1,0);
    west = make_pair(0,-1); 
    
    /* Push back to adjster vector*/
    adjster.push_back(north);
    adjster.push_back(east);
    adjster.push_back(south);
    adjster.push_back(west);
    
for(int i = 0; i < adjster.size(); ++i){
    pair<int,int> t; 
    t = nextPosition + adjster.at(i); // Look at NESW points as appropriate 
    
    if(t.first >= 0 && t.second >= 0 && t.first < bounds.first && t.second <= bounds.second && maze[t.first][t.second] != '*' && maze[t.first][t.second] != 'V' && maze[t.first][t.second] != 'M'){ 
        STACK.push(t); 
        maze[t.first][t.second] = 'M'; 
        cout << "point put in stack: " << t.first << " " << t.second << endl; 
        
        if(t == info.at(1)){
            break; // If we've reached the end point, break out of loop
        }
        
        /* Optional user-directed pause */
//        string delet; 
//        cout << "Continue?" << endl;
//        cin >> delet; 
    }
    
    
}
}