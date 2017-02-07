#ifndef _HuffmanNode_
#define _HuffmanNode_

#define LL long long

class letter{
	friend bool operator < (const letter &a, const letter &b);
	friend letter operator + (const letter &a, const letter &b);
private:
	unsigned char c;
	LL counter;
public:
	letter(unsigned char _c = 0, LL _counter = 0);
	unsigned char getChar();
	LL getCounter();
	void initialize(unsigned char x);
	letter &operator ++ ();
};

template <class T>
class HuffmanNode{
	friend bool operator < (const HuffmanNode<T> &a, const HuffmanNode<T> &b);
public:
	T val;
	HuffmanNode<T> *left, *right;
	HuffmanNode(){}
	HuffmanNode(T _val, HuffmanNode *_left = NULL, HuffmanNode *_right = NULL): val(_val), left(_left), right(_right){}
	~HuffmanNode(){};
};

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

#endif
