/**
 *  Colin Zhou
 *  Fatma Serce
 *  Assignment 4
 * 11/4/2020
 * This file is the main file with the test cases.
 * */


#include <iostream>
#include "SLLString.h"

int main(){
    SLLString str("Hello world!"); 
    SLLString newStr;

    newStr = str; //calls assignment operator 
    newStr += SLLString(" CS@BC"); 
    newStr[6] = 'W';
    
    cout << newStr << endl; // Hello World! CS@BC
    cout << newStr.length() << endl; //18
    
    int loc = newStr.findSubstring("World");
    cout << loc << endl; // 6
    
    newStr.erase('l'); //erase the letter l.
    cout << newStr << endl; // Heo Word! CS@BC
    
    newStr.erase('C');
    cout << newStr << endl; // Heo Word! S@B
    return 0;
}