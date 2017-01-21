#pragma once

#include "TreeNode.h"

class Tree {
private:
	TreeNode* root;

private:
	void copy(const Tree & other);

public:
	Tree();
	Tree(TreeNode* _root);
	~Tree();

	Tree(const Tree & other);
	Tree& operator=(const Tree & other);

public:
	TreeNode* getRoot() const { return root; }
};

Tree::Tree() {
	root = new TreeNode();
}

Tree::Tree(TreeNode* _root) {
	root = _root;
}

Tree::~Tree() {
	delete root;
}

void Tree::copy(const Tree & other) {
	root = other.root;
}

Tree::Tree(const Tree & other) {
	copy(other);
}

Tree& Tree::operator=(const Tree & other) {
	if (this != &other) {
		copy(other);
	}

	return *this;
}