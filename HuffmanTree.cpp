#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
#include <fstream>

using namespace std;
typedef basic_string<unsigned char> ustring;
#include "HuffmanNode.hpp"
#include "HuffmanTree.hpp"

template <class T>
struct cmp{
	bool operator () (const T &a, const T &b){
		return a -> val < b -> val;
	}
};

template <class T>
void HuffmanTree<T>::buildTree(T record[]) {
	priority_queue<HuffmanNode<T>*, vector< HuffmanNode<T>* >, cmp< HuffmanNode<T>* > > heap;
	for (int i = 0; i < 256; ++i) {
		if (record[i].getCounter()){
			HuffmanNode<T> *cur = new HuffmanNode<T>(record[i], NULL, NULL);
			heap.push(cur);
		}
	}

	while (heap.size() > 1) {
		HuffmanNode<T> *ch1 = heap.top(); heap.pop();
		HuffmanNode<T> *ch2 = heap.top(); heap.pop();

		HuffmanNode<T> *pnt = new HuffmanNode<T>(ch1 -> val + ch2 -> val, ch1, ch2);
		heap.push(pnt);
	}
	root = heap.top();
}

template <class T>
HuffmanTree<T>::~HuffmanTree() {
	delete root;
}

template <class T>
void HuffmanTree<T>::getCode(HuffmanNode<T> *cur, ustring decode[], ustring curCode) {
	if (!cur -> left && !cur -> right) {
		decode[cur -> val.getChar()] = curCode;
		return;
	}
	if (cur -> left ) getCode(cur -> left , decode, curCode + (unsigned char)'0');
	if (cur -> right) getCode(cur -> right, decode, curCode + (unsigned char)'1');
}

template <class T>
HuffmanNode<T> *HuffmanTree<T>::getRoot() {
	return root;
}

template <class T>
void HuffmanTree<T>::translate(ifstream &in, ofstream &os, int totalCounter) {
	unsigned char cur;
	T *p = root;
	while (in >> cur) {
 		for (int i = 7; i >= 0; --i) {
			if (!p -> left && !p -> right) {
				os << p -> val.getChar();
				p = root;
				--totalCounter;
				if (!totalCounter) {
					break;
				}
			}
			else if (cur & (1 << i)) {
				p = p -> right;
			}
			else {
				p = p -> left;
			}
		}
	}
}
