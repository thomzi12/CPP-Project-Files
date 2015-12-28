/* 
 * File:   utilities.h
 * Author: thomzi12
 *
 * Created on November 26, 2015, 11:24 AM
 */

#ifndef UTILITIES_H
#define	UTILITIES_H

#include <cstdlib>
#include <cstring>
#include <stack>
#include <utility> 
#include <string>
using namespace std;

void readData(string filename, vector<pair<int,int> >& info, char maze[100][100]);
void printMaze(const vector<pair<int,int> >& info, char maze[100][100]);
void positionPush(pair<int,int> nextPosition, stack<pair<int,int> >& STACK, const vector<pair<int,int> > info, char maze[100][100]); 
pair<int,int>& operator+(const pair<int,int>& a,const pair<int,int>& b); 

#endif	/* UTILITIES_H */
