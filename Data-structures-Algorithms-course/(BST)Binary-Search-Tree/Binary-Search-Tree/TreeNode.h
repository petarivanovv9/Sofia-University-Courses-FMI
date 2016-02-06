#pragma once

#include <iostream>

class TreeNode {
public:
	TreeNode(int _val = 0) {
		this->value = _val;
		this->left = NULL;
		this->right = NULL;
	}

	//TreeNode(int _val, TreeNode* _left, TreeNode* _right) {
	//	this->value = _val;
	//	this->left = _left;
	//	this->right = _right;
	//}

	TreeNode(const TreeNode & other) {
		copy(other);
	}

	TreeNode& operator=(const TreeNode & other) {
		if (this != &other) {
			copy(other);
		}

		return *this;
	}

	~TreeNode() {
		this->value = 0;
		this->left = NULL;
		this->right = NULL;
	}

private:
	void copy(const TreeNode & other) {
		this->value = other.value;
		this->left = other.left;
		this->right = other.right;
	}

public:
	int value;
	TreeNode* left;
	TreeNode* right;
};