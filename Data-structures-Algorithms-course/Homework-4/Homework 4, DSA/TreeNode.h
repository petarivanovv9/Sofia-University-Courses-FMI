#pragma once

#include "Vector.h"

#include <vector>

#include <string>

class TreeNode {
private:
	std::string tupleName;

public:
	std::string getTupleName() const { return this->tupleName; }
	void setTupleName(std::string newTupleName) { this->tupleName = newTupleName; }

private:
	int key;
	//Vector<TreeNode*> children;
	std::vector<TreeNode*> children;

private:
	void copy(const TreeNode & other);

public:
	TreeNode();
	TreeNode(int _val);
	~TreeNode();

	TreeNode(const TreeNode & other);
	TreeNode& operator=(const TreeNode & other);

public:
	void addChild(TreeNode* child) { children.push_back(child); }
	void setKey(int _key) { key = _key; }
	int getKey() { return this->key; }
	//Vector<TreeNode*> getChildren() { return this->children; }
	std::vector<TreeNode*> getChildren() { return this->children; }

	int getChildrenSize() { return children.size(); }
};


TreeNode::TreeNode() : key(0) {
}

TreeNode::TreeNode(int _key) : key(_key) {
}

TreeNode::~TreeNode() {
	children.clear();
}

void TreeNode::copy(const TreeNode & other) {
	this->key = other.key;
	
	this->children = other.children;
}

TreeNode::TreeNode(const TreeNode & other) {
	copy(other);
}

TreeNode& TreeNode::operator=(const TreeNode & other) {
	if (this != &other) {
		copy(other);
	}

	return *this;
}