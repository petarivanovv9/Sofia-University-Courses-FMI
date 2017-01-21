///
///  main.cpp : Defines the entry point for the console application.
///  Homework 4
///
///  Created by Petar Ivanov with #45121.
///

#include <iostream>
#include <cstring>

#include <string>
#include <algorithm>

#include "TreeNode.h"
#include "Tree.h"
#include "Stack.h"


int charToNumber(char*& c);

Tree* makeTree(char* input);

void assignCanonicalNames(TreeNode* root);


int main(int argc, char* argv[]) {

	///
	/// Some examples:
	///
	/// "(5 {(9 {}) (1 {(4 {}) (12 {}) (42 {})})})" "(7 {(15 {(7 {}) (10 {}) (8 {})}) (3 {})})" -> YES
	///
	/// "(5 {(9 {}) (1 {(4 {}) (12 {}) (42 {})})})" "(7 {(15 {(7 {}) (10 {}) (8 {})})})" -> NO
	///
	/// "(1 {(2 {(5 {})(6 {(10 {})})})(3 {(7 {})})(4 {(8 {(11 {})(12 {})})(9 {})})})" "(1 {(2 {(5 {(10 {})(11 {})})(6 {})})(3 {(7 {})(8 {(12 {})})})(4 {(9 {})})})" -> YES
	///
    /// "(1 {(2 {(5 {})(6 {(10 {})})})(3 {(7 {})})(4 {(8 {(11 {})(12 {})})(9 {})})})" "(1 {(2 {(5 {(10 {})(11 {})})(6 {})})(3 {(7 {})(8 {(12 {(13 {})})})})(4 {(9 {})})})" -> NO
	///
	/// "(51 {(91 {})(11 {(41 {})(71 {})(51 {})})})" "(74 {(1521 {(712 {}) (10123 {})}) (71122 {})})" -> NO
	///

	Tree* tree_1;
	//std::cout << argv[1] << std::endl;

	tree_1 = makeTree(argv[1]);
	assignCanonicalNames(tree_1->getRoot());

	//std::cout << "-------------------------------------------------------------------------" << std::endl;

	Tree* tree_2;
	//std::cout << argv[2] << std::endl;
	
	tree_2 = makeTree(argv[2]);
	assignCanonicalNames(tree_2->getRoot());
	
	//std::cout << "-------------------------------------------------------------------------" << std::endl;

	if (tree_1->getRoot()->getTupleName() == tree_2->getRoot()->getTupleName()) {
		std::cout << "YES" << std::endl;
	}
	else {
		std::cout << "NO" << std::endl;
	}

	return 0;
}


void assignCanonicalNames(TreeNode* root) {
	if (root->getChildrenSize() == 0) {
		root->setTupleName("10");
	}
	else {
		for (int i = 0; i < root->getChildrenSize(); i++) {
			assignCanonicalNames(root->getChildren().at(i));
		}
	}

	std::vector<std::string> tupleNames;

	for (int i = 0; i < root->getChildrenSize(); i++) {
		tupleNames.push_back(root->getChildren().at(i)->getTupleName());
	}

	std::stable_sort(tupleNames.begin(), tupleNames.end());

	std::string temp = "";

	for (int i = 0; i < tupleNames.size(); i++) {
		temp += tupleNames.at(i);
	}

	root->setTupleName("1" + temp + "0");
}

Tree* makeTree(char* input) {
	Stack<TreeNode*> nodes;
	TreeNode* currentFathar;
	int counterSecondBrackets = 0; // {, }

	while (*input != '\0') {
		if (*input == '{') {
			counterSecondBrackets++;
		}
		if (*input >= '0' && *input <= '9') {
			TreeNode* currentNode = new (std::nothrow) TreeNode(charToNumber(input));
			*input--;
			if (counterSecondBrackets != 0) {
				currentFathar->addChild(currentNode);
			}
			nodes.push(currentNode);
			currentFathar = currentNode;
		}
		if (*input == '}') {
			counterSecondBrackets--;
			if (nodes.getSize() > 1) {
				nodes.pop();
				currentFathar = nodes.peek();
			}
		}

		*input++;
	}

	return new (std::nothrow) Tree(nodes.peek());
}

int charToNumber(char*& c) {
	int cval = 0;
	while (*c >= '0' && *c <= '9') {
		cval = cval * 10 + *c - '0';
		++c;
	}
	return cval;
}