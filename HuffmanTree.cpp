#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;

struct cmp {
	bool operator () (const *letter &a, const *letter *b) {
		return a -> counter == b -> counter ? a -> ch < b -> ch : a -> counter < b -> counter;
	}
};

HuffmanTree::HuffmanTree(letter *record) {
	priority_queue<*letter, vector<*letter>, cmp> heap;
	for(int i = 0; i < 256; ++i) {
		heap.push(&record[i]);
	}
}
