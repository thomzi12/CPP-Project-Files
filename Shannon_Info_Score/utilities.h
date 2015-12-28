/* 
 * File:   utilities.h
 * Author: thomzi12
 *
 * Created on October 20, 2015, 3:02 PM
 */

#ifndef UTILITIES_H
#define	UTILITIES_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "SLLCell.h"
#include "SLList.h"

using namespace std;

SLList readData(string filename);
int findindex(const SLList & XXX, const string target);
void doReport(SLList & XXX, double sscore);
double ShannonScore(SLList & XXX);
#endif	/* UTILITIES_H */
