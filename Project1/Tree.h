#pragma once

#include "Sequence.h"

#include <cassert>

using namespace std;

template<typename T> class BinaryTree {
private:
	struct BinaryTreeNode {
		BinaryTreeNode* left;
		BinaryTreeNode* right;
		T key;
	};

	BinaryTreeNode* root = nullptr;
	int iteration = 0;

	void insertRecursive(BinaryTreeNode* curNode, BinaryTreeNode* nodeToInsert, int (*cmp) (T, T)) {
		assert(curNode != nullptr);

		if (cmp(curNode->key, nodeToInsert->key) > 0) {
			if (curNode->left == nullptr) {
				curNode->left = nodeToInsert;
			}
			else {
				insertRecursive(curNode->left, nodeToInsert, cmp);
			}
		}
		else {
			if (curNode->right == nullptr) {
				curNode->right = nodeToInsert;
			}
			else {
				insertRecursive(curNode->right, nodeToInsert, cmp);
			}
		}
	}

	void visitRecursive(BinaryTreeNode* curNode, Sequence<T>& seq) {
		assert(curNode != nullptr);

		if (curNode->left != nullptr) {
			visitRecursive(curNode->left, seq);
		}

		seq[this->iteration] = curNode->key;
		this->iteration++;

		if (curNode->right != nullptr) {
			visitRecursive(curNode->right, seq);
		}
	}
public:
	void visit(Sequence<T>& seq) {
		this->iteration = 0;

		if (this->root == nullptr) {
			return;
		}
		this->visitRecursive(this->root, seq);

		this->iteration = 0;
	}

	void insert(T key, int (*cmp) (T, T)) {
		BinaryTreeNode* nodeToInsert = new BinaryTreeNode();
		nodeToInsert->key = key;

		if (this->root == nullptr) {
			this->root = nodeToInsert;
			return;
		}

		this->insertRecursive(this->root, nodeToInsert, cmp);
	}
};