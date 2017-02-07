#ifndef _HuffmanNode_
#define _HuffmanNode_

#define LL long long

class letter;

template <class T> class HuffmanNode;
template <class T> bool operator < (const HuffmanNode<T> &a, const HuffmanNode<T> &b);
template <class T> class HuffmanNode;
template <class T> class HuffmanTree;

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
	HuffmanNode(T _Val, HuffmanNode *_left = NULL, HuffmanNode *right = NULL);
	~HuffmanNode();
};

#endif
