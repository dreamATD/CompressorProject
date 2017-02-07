#ifndef _HuffmanTree_
#define _HuffmanTree_

template <class T> class HuffmanNode;
template <class T> class HuffmanTree;

template<class T>
class HuffmanTree{
private:
	HuffmanNode<T> *root;
public:
	HuffmanTree(){}
	~HuffmanTree();
	void buildTree(T *record);
	void translate(ifstream &in, ofstream &os, int totalCounter);
	void getCode(HuffmanNode<T> *cur, ustring decode[], ustring curCode);
	HuffmanNode<T> *getRoot();
};

#endif
