/*
	Colin Zhou
	Fatma Serce
	Assignment 5
	11/18/2020
	This file contains the main driver where all the output is collected from user.

*/

#include <ctime>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <exception>
#include "BinaryNode.h"
#include "UPC.h"
#include "BST.h"

using namespace std;


int main() {
	try { //error handling for file that is not open
		ifstream filename;
		filename.open("grocery_upc_database.csv");
		BST<UPC> tree;
		tree.buildTree(filename);  //build binary search tree of UPC objects

		string code;
		cout << "Please enter a UPC code(! to quit): ";
		while (code != "!") {
			cin >> code;
			clock_t time;
			time = clock();
			
			long long entry = stoll(code); //convert user inputted string to type long int
			UPC key(entry);

			if (tree.performSearchBST(tree, key) == false) {
				cout << "\nPlease enter a UPC code(! to quit): ";
				continue;			
			} 

			time = clock() - time;
			cout << "Lookup Time: " << time << " milliseconds"; 
			cout << "\nPlease enter a UPC code(! to quit): ";			
		}

	} catch(exception& e) {
		cout << "Exception caught, please try again!: " << e.what() << endl;
	}	
	return 0;
} 
