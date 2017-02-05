#ifndef _HuffmanNode_
#define _HuffmanNode_
template <class T>
class HuffmanNode{
	friend bool operator < (const HuffmanNode &a, const HuffmanNode &b);
private:
	T val;
	HuffmanNode *left, *right;
public:
	HuffmanNode(T _Val, HuffmanNode *_left = NULL, HuffmanNode *right = NULL);
	
};
#endif
