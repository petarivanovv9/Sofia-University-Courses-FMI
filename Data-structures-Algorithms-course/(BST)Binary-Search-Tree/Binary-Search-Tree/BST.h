#pragma once

#include "TreeNode.h"

class BST {
public:
	BST() : root(NULL){};
	~BST(){};

public:
	void insertValue(int val);
	bool removeValue(int val);
	bool searchValue(int val);
	
	void print();

private:
	void insertHelper(TreeNode* root, int val);
	void removeHelper(TreeNode*& current, int val);
	bool searchHelper(TreeNode* current, int val);

	void printHelper(TreeNode* root);

	int findMaxValue(TreeNode*& root);
	
public:
//private:
	TreeNode* root;
};