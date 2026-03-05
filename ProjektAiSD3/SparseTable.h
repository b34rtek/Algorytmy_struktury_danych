#ifndef SPARSETABLE_H
#define SPARSETABLE_H

#include <stdio.h>

#define EMPTY_KEY -1
#define INT_MAX 2147483647
#define INT_MIN -2147483647 -1

typedef struct Node {
	int key;
	Node** children;
	explicit Node() : key(EMPTY_KEY), children(nullptr) {};
} Node;

typedef struct SparseTable {
	Node* root;
	int n, k;

	SparseTable(int n, int k);

	Node* findLeftmost(Node* start, Node*& parent, int& childIndex);

	void printNode(Node* x);

	void insert(int num);

	const void lookup(int num);

	void deletion(int num);

	void print();

} SparseTable;

#endif