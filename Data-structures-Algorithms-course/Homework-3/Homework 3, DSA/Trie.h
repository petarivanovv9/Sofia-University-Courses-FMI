#pragma once

#include "TrieNode.h"

class Trie {
private:
	TrieNode* root;

private:
	void copy(const Trie & other);

public:
	Trie();
	~Trie();

	Trie(const Trie & other);
	Trie& operator=(const Trie & other);

public:
	void addWord(char* str);
	bool searchWord(char* str);

	int searchPrefix(char* prefix);

	TrieNode* getRoot() const { return root; }
};

Trie::Trie() {
	root = new TrieNode(' ', false, 0);
}

Trie::~Trie() {
	delete root;
}

void Trie::addWord(char* str) {
	TrieNode* current = root;

	int strLen = strlen(str);

	if (strLen == 0) {
		current->markNode(); // recognize empty word
		return;
	}

	for (int i = 0; i < strLen; i++) {
		TrieNode* child = current->findChild(str[i]);

		if (child != NULL) {
			current = child;
			current->updateCounter();
		}
		else {
			TrieNode* temp = new TrieNode(str[i], false, 1);
			temp->setValue(str[i]);
			current->addChild(temp);
			current = temp;
		}

		if (str[i + 1] == '\0') {
			current->markNode();
			break;
		}
	}
}

int Trie::searchPrefix(char* prefix) {
	TrieNode* current = root;

	int strLen = strlen(prefix);
	int i = 0;
	for (i = 0; i < strLen; ++i) {
		current = current->findChild(prefix[i]);

		if (current == NULL)
			return false;
	}

	if (prefix[i] == '\0' || current->isFinal() == true) {
		bool statement = (prefix[i] == '\0');

		return current->getCounter();
	}
	
	return false;
}

bool Trie::searchWord(char* str) {
	TrieNode* current = root;
	
	int strLen = strlen(str);
	
	for (int i = 0; i < strLen; i++) {
		current = current->findChild(str[i]);

		if (current == NULL)
			return false;
	}

	if (current->isFinal())
		return true;

	return false;
}

void Trie::copy(const Trie & other) {
	root = other.root;
}

Trie::Trie(const Trie & other) {
	copy(other);
}

Trie& Trie::operator=(const Trie & other) {
	if (this != &other) {
		copy(other);
	}

	return *this;
}