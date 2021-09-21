/*
	This class contains the methods for implementing Binary Search Tree. It is 
	a template class and contains public/private methods for recursive operations on the
	search tree. 
*/

#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
#include "BinaryNode.h"
#include "UPC.h"

using namespace std;
template <class T>

class BST {
  private:
    BinaryNode* root;

  public:
    BST();
    BST<T> buildTree(ifstream& file); //create node with description, UPC key.
    bool performSearchBST(BST<T> tree, UPC key); //need to fix

  private:
    void buildTree(BinaryNode*&, UPC& upc);
    bool performSearchBST(BinaryNode*, UPC key);
};

template<class T>
BST<T>::BST() { //constructor
  root = NULL;
};

template<class T>
void BST<T>::buildTree(BinaryNode*& node, UPC& obj) { //inserts into binary tree
	if (node == NULL) {
		node = new BinaryNode(obj, NULL, NULL);
	} else if (obj.getKey() < node->productObj.getKey()) {
		buildTree(node->left, obj);
	} else if (obj.getKey() > node->productObj.getKey()) {
		buildTree(node->right, obj);
	}
};

template<>
BST<UPC> BST<UPC>::buildTree(ifstream& file) { //reads from file and creates each individual object
	BST<UPC> tree;
  string line;
	long long key;
	string prodDescript;
	getline(file, line); //skip the first line

  while (getline(file, line)) {
		key = stoll(line.substr(0, 12)); //separate the key
		prodDescript = line.substr(13, line.length() - 1); //separate the description
		UPC obj = UPC(key, prodDescript); //create the object
		buildTree(root, obj); //call recursive 
  }
	return tree;
};

template <class T>
bool BST<T>::performSearchBST(BST<T> tree, UPC key) { //public function that calls recursive function
  return performSearchBST(tree.root, key);
};

template <class T>
bool BST<T>::performSearchBST(BinaryNode* node, UPC key) { //searches the binary tree for the desired result
	if (node == NULL) {
		cout << "Not Found" << endl;
		return false;
	} else if (key.getKey() > node->productObj.getKey()) { //comparing UPC to long long
		return performSearchBST(node->right, key);
	} else if (key.getKey() < node->productObj.getKey()) {
		return performSearchBST(node->left, key); 
	} else {
		cout << node->productObj.getDescription() << endl;
		return true;
	}
};



