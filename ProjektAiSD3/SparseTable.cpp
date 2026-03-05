#include "SparseTable.h"

SparseTable::SparseTable(int n, int k) : n(n), k(k) { root = new Node(); }

Node* SparseTable::findLeftmost(Node* start, Node*& parent, int& childIndex) {
	while (start->children != nullptr) {
		int xWay = (start == root ? n : k);
		bool found = false;
		for (int i = 0; i < xWay; i++) {
			if (start->children[i] != nullptr) {
				parent = start;
				childIndex = i;
				start = start->children[i];
				found = true;
				break;
			}
		}
		if (found != true) break;
	}
	return start;
}

void SparseTable::printNode(Node* x) {
	if (x == nullptr)
		return;

	if (x->key != EMPTY_KEY)
		printf("%d ", x->key);

	int xWay = (x == root ? n : k);
	if (x->children != nullptr) {
		for (int i = 0; i < xWay; ++i) {
			printNode(x->children[i]);
		}
	}
}

void SparseTable::insert(int num) {
	int value = num;
	Node* curr = root;
	while (true) {
		if (curr->key == value) {
			printf("%d exist\n", value);
			return;
		}
		if (curr->key == EMPTY_KEY) {
			curr->key = value;
			return;
		}

		int xWay = (curr == root ? n : k);
		int place = num % xWay;
		num /= xWay;

		if (curr->children == nullptr) {
			curr->children = new Node * [xWay];
			for (int i = 0; i < xWay; i++) {
				curr->children[i] = nullptr;
			}
		}

		if (curr->children[place] == nullptr) {
			curr->children[place] = new Node();
		}

		curr = curr->children[place];

	}
}

const void SparseTable::lookup(int num) {
	int value = num;
	Node* curr = root;
	while (true) {
		if (curr->key == value) {
			printf("%d exist\n", value);
			return;
		}

		int xWay = (curr == root ? n : k);
		int place = num % xWay;
		num /= xWay;

		if (curr->children == nullptr || curr->children[place] == nullptr) {
			printf("%d not exist\n", value);
			return;
		}
		curr = curr->children[place];
	}
}

void SparseTable::deletion(int num) {
	int value = num;
	Node* curr = root;
	Node* currParent = nullptr;
	int currIndex = -1;

	while (true) {
		if (curr->key == value) {
			Node* swapParent = nullptr;
			int swapIndex = -1;
			Node* toSwap = findLeftmost(curr, swapParent, swapIndex);

			if (toSwap != nullptr && toSwap->key != EMPTY_KEY) {
				if (toSwap == curr) {
					curr->key = EMPTY_KEY;
					if (curr != root) {
						currParent->children[currIndex] = nullptr;
						delete curr;
					}
					return;
				}

				curr->key = toSwap->key;
				swapParent->children[swapIndex] = nullptr;
				delete toSwap;
			}
			return;
		}

		int xWay = (curr == root ? n : k);
		int place = num % xWay;
		num /= xWay;

		if (curr->children == nullptr || curr->children[place] == nullptr) {
			printf("%d not exist\n", value);
			return;
		}

		currParent = curr;
		currIndex = place;
		curr = curr->children[place];
	}
}

void SparseTable::print() {
	printNode(root); printf("\n");
}