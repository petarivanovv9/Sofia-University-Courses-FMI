#include "BST.h"

void BST::insertValue(int val) {
	if (this->root == NULL) {
		this->root = new TreeNode(val);
	} else {
		insertHelper(this->root, val);
	}
}

void BST::insertHelper(TreeNode* root, int val) {
	if (root->value >= val) {
		if (root->left == NULL) {
			root->left = new TreeNode(val);
		} 
		else {
			insertHelper(root->left, val);
		}
	} 
	else {
		if (root->right == NULL) {
			root->right = new TreeNode(val);
		} 
		else {
			insertHelper(root->right, val);
		}
	}
}

void BST::print() {
	printHelper(this->root);
}

void BST::printHelper(TreeNode* root) {
	if (!root) return;
	printHelper(root->left);
	std::cout << root->value << ' ';
	printHelper(root->right);
}

bool BST::searchValue(int val) {
	if (this->root == NULL) {
		return false;
	}
	else {
		searchHelper(this->root, val);
	}
}

bool BST::searchHelper(TreeNode* current, int val) {
	if (current->value == val) {
		return true;
	}
	if (current->left == NULL || current->right == NULL) {
		return false;
	}

	if (current->value >= val) {
		searchHelper(current->left, val);
	}
	else {
		searchHelper(current->right, val);
	}
}

bool BST::removeValue(int val) {
	if ( ! searchValue(val)) {
		return false;
	}
	else {
		removeHelper(this->root, val);
	}
}

void BST::removeHelper(TreeNode*& node, int val) {
	if (val < node->value) {
		removeHelper(node->left, val);
	}

	if (val > node->value) {
		removeHelper(node->right, val);
	}

	if (val == node->value) {
		if (node->left != NULL && node->right != NULL) {
			int maxValue = findMaxValue(node->left);

			node->value = maxValue;
			removeHelper(node->left, maxValue);
		}
		else if (node->left != NULL) {
			TreeNode* toDel = node;
			node = node->left;
			delete toDel;
		}
		else {
			TreeNode* toDel = node;
			node = node->right;
			delete toDel;
		}
	}
}

int BST::findMaxValue(TreeNode*& root) {
	TreeNode* item = root;

	while (item->right != NULL) {
		item = item->right;
	}

	return item->value;
}