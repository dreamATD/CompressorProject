#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
typedef basic_string<unsigned char> ustring;
#include "HuffmanNode.hpp"
#include "HuffmanTree.hpp"

bool operator < (const letter &a, const letter &b) {
	return a.counter == b.counter ? a.c < b.c : a.counter < b.counter;
}

letter::letter(unsigned char _c, LL _counter): c(_c), counter(_counter) {}

unsigned char letter::getChar(){
	return c;
}

LL letter::getCounter(){
	return counter;
}
void letter::initialize(unsigned char k) {
	counter = 0;
	c = k;
}

letter &letter::operator ++ () {
	++counter;
	return *this;
}

letter operator + (const letter &a, const letter &b) {
	return letter(0, a.counter + b.counter);
}
